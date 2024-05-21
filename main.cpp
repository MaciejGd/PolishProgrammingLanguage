#include "inc/lex.h"
#include "inc/parser.h"
#include "inc/parsing_table.h"
#include "inc/production.h"
#include "inc/parsing_table.h"
#include <stack>

using std::vector;

int main()
{
	//here should be a file name to scan token from
	string path_file = "ref/test";
	vector<Token> vec = tokensScan(path_file);
	for (int i = 0; i < vec.size(); i++)
		vec[i].printToken();

	std::cout << grammar.size() << std::endl;
	return 0;
}
