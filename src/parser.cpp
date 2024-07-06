#include "../inc/parser.h"

using std::string, std::vector, std::cout, std::cin, std::endl, std::find;

int analyze_identifier()
{
	return 0;
}


int parse(const vector<Token>& tokens)
{
	int counter = 0;
	int error = 0;

	std::vector<Identifier> global_ids;
	std::vector<Identifier> local_ids;
	Symbol prev_sym;
	std::stack<Symbol> statement_stack;
	statement_stack.push(END);
	statement_stack.push(START);
	while (!statement_stack.empty())
	{
		Symbol parse_symbol = statement_stack.top();
		//debug purpose only
		std::stack<Symbol> temp = statement_stack;
		statement_stack.pop();
		if (parse_symbol == EPSILON)
		{
			continue;
		}
		else if (isTerminal(parse_symbol) && (parse_symbol))
		{
			//if (terminals_map[tokens[counter]]==parse_symbol)
			//need to check for a logic in checking
			counter++;
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
				cout << "Parsing table indexes: " << parse_symbol << ":" << terminal_index << "\n";
				//errror indicator
				error = 1;
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
	return error;
}

