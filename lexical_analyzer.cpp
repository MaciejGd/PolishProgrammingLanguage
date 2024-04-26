#include <cctype>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <unistd.h>

using std::string, std::vector, std::cout, std::cin, std::endl;

//token moze miec kilka roznych wartosci ktore przyjmuje
vector<char> operators = {'=','+','-','*','/','&','|','>','<'};
vector<char> separators = {';','[',']','{','}',':','(',')',','};
//corresponding keywords in cpp: void, int, float, bool, const, break, continue, if, while, for, struct, return
vector<string> keywords = {"nic","dycha", "przecinek", "binarna", "stała", "przestań","dalej","jesli","dopoki","dla", "liga", "zwroc"};

enum TYPE {
	op,
	sep,
	id,
	con,
	key,
	lit
};

string typeToString(TYPE type)
{
	switch(type)
	{
		case TYPE::op: return "op";
		case TYPE::sep: return "sep";
		case TYPE::id: return "id";
		case TYPE::con: return "con";
		case TYPE::key: return "key";
		case TYPE::lit: return "lit";
		default: return "";
	}
}

class Token {
	TYPE type;	
	string value;
public:
	Token(TYPE _type):type(_type){}
	Token(TYPE _type, string val):type(_type),value(val){}
	virtual void printToken() const
	{
		cout << "[ " << typeToString(type) << ", " << value << " ]" << endl;
	}
};

template<typename T>
class Con : public Token {
	T value;
public:
	Con (T val):Token(TYPE::con), value(val){}
	void printToken() const override
	{
		cout << "[ con" << ", " << value << " ]" << endl;
	}
};

//function for checking if lexem is constant integer or float if return value is equal to 2 it is a float, if it returns 1 it is integer and when 0 it is not
int isConstant(string lexem)
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

//function to create tokens from created previously lexemes
//have to add checking for closing the parenthesses
void createToken(vector<string>& lexemes, vector<Token*>& tokens)
{
	for (int i = 0; i < lexemes.size(); i++)
	{
		if (lexemes[i].length()==1)
		{
			if (find(operators.begin(), operators.end(),lexemes[i].at(0))!=operators.end())		
				tokens.push_back(new Token(TYPE::op, lexemes[i]));
			else if (find(separators.begin(), separators.end(),lexemes[i].at(0))!=separators.end())	
				tokens.push_back(new Token(TYPE::sep, lexemes[i]));
		}
		else 
		{
			int is_constant_state;
			if (find(keywords.begin(), keywords.end(), lexemes[i])!=keywords.end())		
				tokens.push_back(new Token(TYPE::key, lexemes[i]));
			else if (lexemes[i].at(0)=='"' && lexemes[i].at(lexemes[i].length()-1)=='"')
				tokens.push_back(new Con(lexemes[i]));
			else if ((is_constant_state=isConstant(lexemes[i]))==1)
				tokens.push_back(new Con(std::stoi(lexemes[i])));
			else if (is_constant_state==2)
				tokens.push_back(new Con(std::stof(lexemes[i])));
			else 
				tokens.push_back(new Token(TYPE::id, lexemes[i]));
		}
	}
}

//function to divide processed line to words to be turned to a tokens 
void divideToWords(string line, vector<string> &words)
{
	string actual_word;
	int i = 0;
	//remove leading whitespaces from a line
	while (line.at(i)==' ' || line.at(i)=='\t' || line.at(i)=='\v' || line.at(i)=='\r')
	{
		i++;	
	}
	//iterate over chars in lines to form the words
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
		else if (char_at==' ' || char_at=='\t' || char_at=='\v' || char_at=='\r')
		{
			if (!actual_word.empty())		words.push_back(actual_word);
			actual_word = "";
		}
		//checking for mathematical, logical operators and separators using std::find for finding special sign in vector initialized earlier
		else if (find(operators.begin(), operators.end(), char_at)!=operators.end() || find(separators.begin(), separators.end(), char_at)!=separators.end())
		{
			if (!actual_word.empty()) words.push_back(actual_word);
			actual_word = "";
			actual_word+=char_at;
			words.push_back(actual_word);
			actual_word="";
		}	
		else	actual_word+=char_at;
	}
}


int main(int argc, char **argv)
{
	vector<string> words;
	vector<Token*> tokens;
	//input file loading
	std::ifstream input_file;
	if (argc < 2) input_file.open("test");
	else if (argc == 2) input_file.open(argv[1]);
	else 
	{
		std::cout << "To much input arguments, I accept one or nor arguments" << std::endl;
		exit(0);
	}

	if (input_file.fail())
	{
		std::cout << "Could not load input file" << std::endl;
	}
	//variable to store line of text to analyze 
	string line;
	while (std::getline(input_file, line))
	{
		if (!line.empty())
			divideToWords(line, words);		
	}	
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}

	createToken(words, tokens);
	for (int i = 0; i < tokens.size(); i++)
	{
		tokens[i]->printToken();
	}

	return 0;
}
