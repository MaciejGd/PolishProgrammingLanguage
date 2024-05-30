#include "../inc/parser.h"

using std::string, std::vector, std::cout, std::cin, std::endl, std::find;

TYPE stringToType(string key)
{
	TYPE ret_val;
	if (key == "Op")
		ret_val = TYPE::Op;
	else if (key=="Sep")
		ret_val = TYPE::Sep;
	else if (key=="Id")
		ret_val = TYPE::Id;
	else if (key=="Int")
		ret_val = TYPE::Int;
	else if (key=="Float")
		ret_val = TYPE::Float;
	else if (key=="Str")
		ret_val = TYPE::Str;
	else if (key=="Float")
		ret_val = TYPE::Float;
	else if (key=="Bool")
		ret_val = TYPE::Bool;
	else if (key=="Key")
		ret_val = TYPE::Key;
	else if (key=="Lit")
		ret_val = TYPE::Lit;
	return ret_val;
}

void loadTokenList(vector<Token>& tokens)
{
	std::ifstream token_file("../ref/tokens");
	if (token_file.fail())
	{
		cout << "Failed to open a file containing tokens" << endl;
		exit(1);
	}
	string line;
	bool desc = true;
	string descriptor;
	string value;
	while (getline(token_file, line))
	{
		for (int i = 0; i < line.length(); i++)
		{
			if (desc && line.at(i)=='$')
				desc = false;
			else if (desc)
				descriptor+=line.at(i);
			else if (!desc)
				value+=line.at(i);
		}
		tokens.push_back(Token{stringToType(descriptor), value});	
		descriptor="";
		value="";
		desc = true;
	}
	token_file.close();
}

int getElement(vector<vector<int>>& prod, vector<string> token_types, Token* curr_token)
{
	string token_val;
	if (curr_token->type == TYPE::Id)
		token_val = "id";
	else if (curr_token->type == TYPE::Str || curr_token->type == TYPE::Int || curr_token->type == TYPE::Float)
		token_val = "const";
	else 
		token_val = curr_token->value;
	auto index = std::find(token_types.begin(), token_types.end(), token_val);
	return 0;	
}

void parse(vector<Token>& tokens)
{
	int counter = 0;
	std::stack<Symbol> statement_stack;
	statement_stack.push(END);
	statement_stack.push(START);
	while (!statement_stack.empty())
	{
		Symbol parse_symbol = statement_stack.top();
		statement_stack.pop();
		if (isTerminal(parse_symbol))
		{
			if (parse_symbol == translateTokenToSymbol(tokens[counter]))
				counter++;
		}	
		else if (parse_symbol == EPSILON)
		{
			continue;
		}
		else 
		{
			//get from parsing table wanted expression
			int terminal_index;
			if (tokens[counter].type == TYPE::Id)
				terminal_index = 5;
			else if (tokens[counter].type == TYPE::Str || tokens[counter].type == TYPE::Int || tokens[counter].type == TYPE::Float)
				terminal_index = 6;
			else 
				terminal_index = std::find(terminals.begin(), terminals.end(), tokens[counter].value) - terminals.begin();
			int statement_index = parsing_table[parse_symbol][terminal_index];
			
			if (statement_index == 0)
			{
				cout << " Error while parsing non-terminal: " << symbols_map[parse_symbol] << " in token: " << tokens[counter].value << "\n";
			}
			else {
				//pushing on stack Symbols in reverse order
				Production prod = grammar[statement_index-1];
				for (int i = prod.rhs.size()-1; i >= 0; i--)
				{
					statement_stack.push(prod.rhs[i]);
				}
			}
		}
	}
}

