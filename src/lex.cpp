#include "../inc/lex.h"

using std::string, std::vector, std::cout, std::cin, std::endl;

string typeToString(TYPE type)
{
	switch(type)
	{
		case TYPE::Op: return "Op";
		case TYPE::Sep: return "Sep";
		case TYPE::Id: return "Id";
		case TYPE::Int: return "Int";
		case TYPE::Str: return "Str";
		case TYPE::Float: return "Float";
		case TYPE::Key: return "Key";
		default: return "";
	}
}

Token::Token(TYPE _type, string val):type(_type), value(val)
{}

void Token::printToken() const
{
	cout << "[ " << typeToString(type) << " ," << value << " ]\n";
}


Lexer::Lexer(std::string _file):file_name(_file){
	std::cout << INFO_LOG << "Starting process of tokenizing " << file_name << "\n"; 
	m_tokensScan();
}

void Lexer::m_tokensScan()
{
	vector<string> words;
	vector<string> lexemes;
	//input file loading
	std::ifstream input_file(file_name);
	if (input_file.fail())
	{
		std::cout << ERROR_LOG << "[" << file_name << "]Could not load input file.\n";
		//abort if file could not be load
		exit(1);
	}
	//variable to store line of text to analyze 
	string line;
	int line_counter = 0;
	while (std::getline(input_file, line))
	{
		if (!line.empty())
			m_divideToWords(line_counter, line, words);
		line_counter++;		
	}	
	m_createTokens(words);
	//pushing back end of file token after scanning all file -> necessary for parsing tre
	tokens.push_back(Token(TYPE::Sep, "$"));	
}

//have to reconsider merging createToken with divideToWords functions
//function to divide processed line to words to be turned to a tokens 
void Lexer::m_divideToWords(int line_counter, const string& line, vector<string> &words)
{
	
	string actual_word;
	int i = 0;
	//remove leading whitespaces from a line
	while (line.at(i)==' ' || line.at(i)=='\t' || line.at(i)=='\v' || line.at(i)=='\r')
	{
		i++;	
		//ensures skipping empty lines with whitespaces only
		if (i==line.length())
			return;
	}
	//iterate over chars in lines to form the words
	bool string_const = false;
	for (; i < line.length(); i++)
	{

		char char_at = line.at(i);
		if (char_at=='#')	
		{
			if (!actual_word.empty()) words.push_back(actual_word);
			break;
		}
		else if (char_at=='\n')	break;
		//checking for whitespaces
		else if (!string_const && (char_at==' ' || char_at=='\t' || char_at=='\v' || char_at=='\r'))
		{
			if (!actual_word.empty())		words.push_back(actual_word);
			actual_word = "";
		}
		//checking for mathematical, logical operators and separators using std::find for finding special sign in vector initialized earlier
		else if (!string_const && (find(operators.begin(), operators.end(), char_at)!=operators.end() || find(separators.begin(), separators.end(), char_at)!=separators.end()))
		{
			if (!actual_word.empty()) 
				words.push_back(actual_word);
			actual_word = "";
			actual_word+=char_at;	
			if (char_at == '=' || char_at == '<' || char_at == '>' || char_at == '!')
			{
				if (line.at(i+1)=='=')
					actual_word+=line.at(++i);
			}
			words.push_back(actual_word);
			actual_word="";
		}
		else if (char_at=='"')
		{
			if (!string_const)
			{
				if (!actual_word.empty()) 
					words.push_back(actual_word);
				actual_word = "";
				actual_word+=char_at;
				string_const=true;
			}
			else 
			{
				actual_word+=char_at;
				words.push_back(actual_word);
				actual_word="";
				string_const=false;
			}
		}	
		else	actual_word+=char_at;
	}
	if (!actual_word.empty())
		words.push_back(actual_word);
	if (string_const)
	{
		cout << ERROR_LOG << "No closing quotation mark spotted in line" << ++line_counter << endl;
		exit(1);
	}
}

void Lexer::m_createTokens(const vector<string>& lexemes)
{
	TYPE lexeme_type;
	//here need to add some logic responsible for proper processing of minus values
	for (int i = 0; i < lexemes.size(); i++)
	{
		int is_constant_state = m_isConstant(lexemes[i]);
		if (is_constant_state==1)
			lexeme_type = TYPE::Int;
		else if (is_constant_state==2)
			lexeme_type = TYPE::Float; 
		else if (search(keywords, lexemes[i]))
			lexeme_type = TYPE::Key;
		else if (lexemes[i].length() == 1)
		{
			if (search(separators, lexemes[i].at(0)))
				lexeme_type = TYPE::Sep;
			else if (search(operators, lexemes[i].at(0)))
				lexeme_type = TYPE::Op;
		}
		else if (lexemes[i] == "==" || lexemes[i] == "<=" || lexemes[i] == ">=" || lexemes[i] == "!=")
			lexeme_type = TYPE::Op;
		else if (lexemes[i].at(0)=='"' && lexemes[i].at(lexemes[i].size()-1)=='"')
		{
			lexeme_type = TYPE::Str;
		}
		else 
		{lexeme_type = TYPE::Id;}
		tokens.push_back(Token{lexeme_type, lexemes[i]});
	}
}


//function for checking if lexem is constant integer or float if return value is equal to 2 it is a float, if it returns 1 it is integer and when 0 it is not
int Lexer::m_isConstant(const string& lexem)
{
	bool dot = false;
	for (int i = 0; i < lexem.length(); i++)
	{
		if (lexem.at(i)=='.')
		{
			if (!dot)
				dot = true;
			else
				return 0;
		}
		else if (!std::isdigit(lexem.at(i)))
			return 0;			
	}
	if (dot)
		return 2;
	return 1;
}





