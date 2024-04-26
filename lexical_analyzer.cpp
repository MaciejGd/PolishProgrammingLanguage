#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using std::string, std::vector, std::cout, std::cin, std::endl;

//token moze miec kilka roznych wartosci ktore przyjmuje
vector<char> operators = {'+','-','*','/','&','|','>','<'};
vector<char> separators = {'[',']','{','}',';'};
vector<string> keywords = {"", ""};

enum TYPE {
	op,
	id,
	con,
	key,
	lit
};

class Token {
	TYPE type;	
public:
	Token(){}
};

class Op: public Token {
	char value;
public:
	Op(char val):value(val){}
};

void createToken()
{

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
	bool comment_found = false;
	for (; i < line.length() && !comment_found; i++)
	{

		char char_at = line.at(i);
		char prev_char;
		auto it_operators = std::find(operators.begin(), operators.end(), char_at);
		auto it_separators = std::find(separators.begin(), separators.end(), char_at);
		if (char_at=='#')	break;
		else if (char_at=='\n')	break;
		//checking for whitespaces
		else if (char_at==' ' || char_at=='\t' || char_at=='\v' || char_at=='\r')
		{
			if (!actual_word.empty())		words.push_back(actual_word);
			actual_word = "";
		}
		//checking for mathematical, logical operators and separators
		else if (it_operators!=operators.end() || it_separators!=separators.end())
		{
			if (!actual_word.empty()) words.push_back(actual_word);
			words.push_back(std::to_string(char_at));
			actual_word = "";
		}	
		else	actual_word+=char_at;
		prev_char = char_at;
	}
}


int main(int argc, char **argv)
{
	vector<string> words;
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
		divideToWords(line, words);		
	}	
	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i] << endl;
	}
	return 0;
}
