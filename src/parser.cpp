#include "../inc/parser.h"
#include "../inc/grammar.h"
#include <fstream>
#include <sstream>

using std::string, std::vector, std::cout, std::cin, std::endl, std::find;

//below code is needed for parsing Abstract Syntax Tree. I need to add function that slightly differs in terms of algorithm and serves a function of adding 
int rec_parse(Symbol* head, const std::vector<Token>& tokens, int &counter)
{
	int result = head->evaluate(tokens[counter]);
	// std::cout << "************\n";
	// for (size_t i = 0; i < head->getRhsSize(); i++)
	// 	std::cout << head->getRhsNode(i)->getName() << std::endl;
	// std::cout << "************\n";
	//check if no children
	if (result == 2)
	{
		head->setValue(tokens[counter].value);
		counter++;
		return 0;
	}
	//check if properly evaluated
	else if (result == 1)
	{
		return 1;
	}
	for (int i = head->getRhsSize()-1; i >= 0; i--)
	{
		// std::cout << "************\n";
		// std::cout << "i value: " << i << std::endl;
		// std::cout << "Resolving Symbol: " << head->getName() << std::endl;
		// std::cout << "Child node: " << head->getRhsNode(i)->getName() << std::endl;
		// std::cout << "Token value: " << tokens[counter].value << std::endl;
		// std::cout << "************\n";
		int result = rec_parse(head->getRhsNode(i), tokens, counter);
		//check if parsing child node failed and return if so
		if (result == 1)
		{
			return 1;			
		}
	}
	return 0;
}

Symbol* parse(const vector<Token>& tokens)
{
	Symbol* head = new Start{};
	int counter = 0;
	if (!rec_parse(head, tokens, counter))
	{
		return head;
	}
	return nullptr;
}

//recursive function used in printing AST to a file
void printRec(std::ostringstream& ss, Symbol* head, int incantation)
{
	std::string inc_string(incantation, ' ');
	if (!head)
		return;
	
	ss << inc_string;
	ss << head->getName();
	ss << ":\n" ;
	ss << inc_string;
	ss << "{\n";
	incantation+=2;
	for (int i = head->getRhsSize()-1; i >= 0; i--)
	{
		printRec(ss, head->getRhsNode(i), incantation);
	}
	if (head->getValue()!="")
	{	
		ss << inc_string << "  ";
		ss << "*** " << head->getValue() << " ***\n";
	}
	ss << inc_string;
	ss << "}\n";
}
//printing AST to a file in debug purposes
void printAST(const char* file_arg, Symbol* head)
{
	std::ostringstream ss;
	printRec(ss, head, 0);
	//std::cout << ss.str();
	std::string file_name = file_arg;
	file_name = "./AST/" + file_name + ".AST";
	std::ofstream file(file_name);
	if (file.fail())
	{
		std::cout << "[ERROR]Opening file " << file_name << " for printing AST failed!";
		return;
	}
	file << ss.str();
	file.close();
	//file handling (redirecting stringstream to a textfile)
}


void chopTree(Symbol *head)
{
	if (head->getRhsSize()==0)
	{
		delete head;
		return;
	}
	for (int i = 0; i < head->getRhsSize(); i++)
	{
		chopTree(head->getRhsNode(i));
	}
	delete head;
} 

// int parse(const vector<Token>& tokens)
// {
// 	int counter = 0;
// 	std::vector<Symbol*> sym_stack = {new End{}, new Start{}};
// 	while (!sym_stack.empty())
// 	{
// 		Symbol* temp = sym_stack.back();
// 		sym_stack.pop_back();
// 		// std::cout << "***********\n";
// 		// for (int i = 0; i < sym_stack.size(); i++)
// 		// {
// 		// 	std::cout << "STACK EL. " << i << " : " << sym_stack[i]->getName() << "\n";
// 		// }
// 		// std::cout << "***********\n";
// 		// std::cout << "[LOG]Parsed symbol: " << temp->getName() << " " << "TOKEN: " << tokens[counter].value << "\n";
// 		// std::cout << "***********\n";
// 		// std::cout << "***********\n";
// 		int return_code = temp->evaluate(sym_stack, tokens[counter]);
// 		if (return_code == 1)
// 		{
// 			// std::cout << "***********\n";
// 			// std::cout << "[LOG]Parsed symbol: " << temp->getName() << " " << "TOKEN: " << tokens[counter].value << "\n";
// 			// std::cout << "***********\n";
// 			// std::cout << "***********\n";
// 			// std::cout << "[ERROR]Failed parsing symbol: " << temp->getName() << " in token: " << tokens[counter].value << " counter equal to " << counter << "\n";
// 			// std::cout << "[ERROR]Context of failure: " << tokens[counter-1].value << " " << tokens[counter].value << " " << tokens[counter+1].value << std::endl;
// 			return 1;
// 		}
// 		else if (return_code == 2)
// 		{
// 			counter++;
// 		}
// 		delete temp;
// 	}
// 	return 0;
// }

