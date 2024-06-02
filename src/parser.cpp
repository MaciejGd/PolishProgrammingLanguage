#include "../inc/parser.h"

using std::string, std::vector, std::cout, std::cin, std::endl, std::find;

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
			//count x and y coordinates from parsing table
			int terminal_index;
			if (tokens[counter].type == TYPE::Id)
				terminal_index = 5;
			else if (tokens[counter].type == TYPE::Str || tokens[counter].type == TYPE::Int || tokens[counter].type == TYPE::Float)
				terminal_index = 6;
			else 
				terminal_index = std::find(terminals.begin(), terminals.end(), tokens[counter].value) - terminals.begin();
			//from the parsing table get a grammar rule to parse
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

