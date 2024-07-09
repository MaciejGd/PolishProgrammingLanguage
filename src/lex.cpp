#include "../inc/lex.h"

using std::string, std::vector, std::cout, std::cin, std::endl;

//operators and separators list
vector<char> operators = {'=','+','-','*','/','&','|','>','<', '!'};
vector<char> separators = {';','[',']','{','}',':','(',')',','};
//corresponding keywords in cpp: void, int, float, bool, const, break, continue, if, while, for, struct, return
vector<string> keywords = {"funkcja" ,"nic","dycha", "przecinek", "tekst","wywolaj", "przestań","dalej","jesli", "inaczej", "dopoki","dla", "liga", "zwroc", "do", "zakres", "dodaj", "globalne"};

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

//function for checking if lexem is constant integer or float if return value is equal to 2 it is a float, if it returns 1 it is integer and when 0 it is not
int isConstant(const string& lexem)
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
		//have to make some changes to a lexer to properly create token from a minus number
		else if (lexem.at(0)=='-')
			continue;
		else if (!std::isdigit(lexem.at(i)))
			return 0;			
	}
	if (dot)
		return 2;
	return 1;
}

void createToken(vector<string>& lexemes, vector<Token>& tokens)
{
	TYPE lexeme_type;
	for (int i = 0; i < lexemes.size(); i++)
	{
		int is_constant_state = isConstant(lexemes[i]);
		if (is_constant_state==1)
			lexeme_type = TYPE::Int;
		else if (is_constant_state==2)
			lexeme_type = TYPE::Float; 
		else if (vector_search(keywords, lexemes[i]))
			lexeme_type = TYPE::Key;
		else if (lexemes[i].length() == 1)
		{
			if (vector_search(separators, lexemes[i].at(0)))
				lexeme_type = TYPE::Sep;
			else if (vector_search(operators, lexemes[i].at(0)))
				lexeme_type = TYPE::Op;
		}
		else if (lexemes[i] == "==" || lexemes[i] == "<=" || lexemes[i] == ">=" || lexemes[i] == "!=")
			lexeme_type = TYPE::Op;
		else if (lexemes[i].at(0)=='"' && lexemes[i].at(lexemes[i].size()-1)=='"')
		{
			lexemes[i].erase(lexemes[i].end()-1);
			lexemes[i].erase(lexemes[i].begin());
			lexeme_type = TYPE::Str;
		}
		else 
		{lexeme_type = TYPE::Id;}
		tokens.push_back(Token{lexeme_type, lexemes[i]});
	}
}

//function to divide processed line to words to be turned to a tokens 
void divideToWords(int line_counter, const string& line, vector<string> &words)
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
		cout << "[ERROR]No closing quotation mark spotted in line" << ++line_counter << endl;
		exit(1);
	}
}

vector<Token> tokensScan(const string& file_name)
{
	vector<string> words;
	vector<Token> tokens;
	//input file loading
	std::ifstream input_file(file_name);
	if (input_file.fail())
	{
		std::cout << "Could not load input file" << std::endl;
	}
	//variable to store line of text to analyze 
	string line;
	int line_counter = 0;
	while (std::getline(input_file, line))
	{
		if (!line.empty())
			divideToWords(line_counter, line, words);
		line_counter++;		
	}	
	createToken(words, tokens);
	//pushing back end of file token after scanning all file -> necessary for parsing tre
	tokens.push_back(Token(TYPE::Sep, "$"));	
	return tokens;
}
