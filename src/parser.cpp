//#include "../inc/parser.h"
#include "../inc/grammar.h"

using std::string, std::vector, std::cout, std::cin, std::endl, std::find;



int parse(const vector<Token>& tokens)
{
	int counter = 0;
	std::vector<Symbol*> sym_stack = {new End{}, new Start{}};
	while (!sym_stack.empty())
	{
		Symbol* temp = sym_stack.back();
		sym_stack.pop_back();
		// std::cout << "***********\n";
		// for (int i = 0; i < sym_stack.size(); i++)
		// {
		// 	std::cout << "STACK EL. " << i << " : " << sym_stack[i]->getName() << "\n";
		// }
		// std::cout << "***********\n";
		// std::cout << "[LOG]Parsed symbol: " << temp->getName() << " " << "TOKEN: " << tokens[counter].value << "\n";
		// std::cout << "***********\n";
		// std::cout << "***********\n";
		int return_code = temp->evaluate(sym_stack, tokens[counter]);
		if (return_code == 1)
		{
			// std::cout << "***********\n";
			// std::cout << "[LOG]Parsed symbol: " << temp->getName() << " " << "TOKEN: " << tokens[counter].value << "\n";
			// std::cout << "***********\n";
			// std::cout << "***********\n";
			// std::cout << "[ERROR]Failed parsing symbol: " << temp->getName() << " in token: " << tokens[counter].value << " counter equal to " << counter << "\n";
			// std::cout << "[ERROR]Context of failure: " << tokens[counter-1].value << " " << tokens[counter].value << " " << tokens[counter+1].value << std::endl;
			return 1;
		}
		else if (return_code == 2)
		{
			counter++;
		}
		delete temp;
	}
	return 0;
}

// int parse(const vector<Token>& tokens)
// {
// 	int counter = 0;
// 	int error = 0;

// 	std::vector<Identifier> global_ids;
// 	std::vector<Identifier> local_ids;
// 	Symbol prev_sym;
// 	std::stack<Symbol> statement_stack;
// 	statement_stack.push(END);
// 	statement_stack.push(START);
// 	while (!statement_stack.empty())
// 	{
// 		Symbol parse_symbol = statement_stack.top();
// 		//debug purpose only
// 		std::stack<Symbol> temp = statement_stack;
// 		statement_stack.pop();
// 		if (parse_symbol == EPSILON)
// 		{
// 			continue;
// 		}
// 		else if (isTerminal(parse_symbol))
// 		{
// 			Symbol current_token = translateTokenToSymbol(tokens[counter]);
// 			if (current_token != parse_symbol)
// 			{
// 				std::cout << "[PARSING_ERROR][WRONG_TERMINAL_USED] Used terminal: " << symbols_map[translateTokenToSymbol(tokens[counter])] << " should be used: " << symbols_map[parse_symbol]<<"\n";	
// 				error = 1;
// 				for (int i = statement_stack.size()-1; i >= 0; i--)
// 				{
// 					std::cout << "Stack symbol at index: " << i << " -> " << symbols_map[statement_stack.top()] << std::endl;
// 					statement_stack.pop();
// 				}
// 			}
// 			counter++;

// 		}	
// 		else 
// 		{
// 			//count x and y coordinates from parsing table
// 			int terminal_index;
// 			if (tokens[counter].type == TYPE::Id)
// 				terminal_index = 5;
// 			else if (tokens[counter].type == TYPE::Str || tokens[counter].type == TYPE::Int || tokens[counter].type == TYPE::Float)
// 				terminal_index = 6;
// 			else 
// 				terminal_index = std::find(terminals.begin(), terminals.end(), tokens[counter].value) - terminals.begin();
// 			//from the parsing table get a grammar rule to parse
// 			int statement_index = parsing_table[parse_symbol][terminal_index];
// 			if (statement_index == 0)
// 			{
// 				cout << " Error while parsing non-terminal: " << symbols_map[parse_symbol] << " in token: " << tokens[counter].value << "\n";
// 				cout << "Parsing table indexes: " << parse_symbol << ":" << terminal_index << "\n";
// 				//errror indicator
// 				error = 1;
// 			}
// 			else {
// 				//pushing on stack Symbols in reverse order
// 				Production prod = grammar[statement_index-1];
// 				for (int i = prod.rhs.size()-1; i >= 0; i--)
// 				{
// 					statement_stack.push(prod.rhs[i]);
// 				}
// 			}
// 		}
// 	}
// 	return error;
// }

