#include "../inc/parser.h"

using std::string, std::vector, std::cout, std::cin, std::endl, std::find;

Parser::Parser(const std::string& file_name, const std::vector<Token>& tokens):head(new Start{}), file_name(file_name)
{
	if (m_parse(tokens))
	{
		std::cout << ERROR_LOG << "Parsing error, exiting program\n";
		m_chopTree(head);
		exit(1); 
	}
}

Parser::~Parser()
{
	m_chopTree(head);
}

//below code is needed for parsing Abstract Syntax Tree. I need to add function that slightly differs in terms of algorithm and serves a function of adding 
int Parser::m_rec_parse(Symbol* head, const std::vector<Token>& tokens, int &counter)
{
	int result = head->evaluate(tokens[counter]);
	if (result == 2)
	{
		head->setValue(tokens[counter].value);
		counter++;
		return 0;
	}
	//check if properly evaluated
	else if (result == 1)
	{
		std::cout << ERROR_LOG << "[" << file_name << "]Problem in line: " << tokens[counter].line  << " parsing symbol: [" << head->getName() << "] in token: " << tokens[counter].value << std::endl;
		return 1;
	}
	for (int i = head->getRhsSize()-1; i >= 0; i--)
	{
		result = m_rec_parse(head->getRhsNode(i), tokens, counter);
		if (result == 1)
		{
			return 1;			
		}
	}
	return result;
}

int Parser::m_parse(const vector<Token>& tokens)
{
	head = new Start{};
	int counter = 0;
	if (!m_rec_parse(head, tokens, counter))
	{
		return 0;
	}
	return 1;
}

//recursive function used in printing AST to a file
void printRec(std::ostringstream& ss, const Symbol* head, int incantation)
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
void printAST(const char* file_arg, const Symbol* head)
{
	std::ostringstream ss;
	printRec(ss, head, 0);
	//std::cout << ss.str();
	std::string file_name = file_arg;
	file_name = "./AST/" + file_name + ".AST";
	std::ofstream file(file_name);
	if (file.fail())
	{
		std::cout << ERROR_LOG << "[" << file_name << "]Opening file for printing AST failed!";
		return;
	}
	file << ss.str();
	file.close();
	//file handling (redirecting stringstream to a textfile)
}


void Parser::m_chopTree(Symbol *head)
{
	if (head->getRhsSize()==0)
	{
		delete head;
		return;
	}
	for (int i = 0; i < head->getRhsSize(); i++)
	{
		m_chopTree(head->getRhsNode(i));
	}
	delete head;
} 