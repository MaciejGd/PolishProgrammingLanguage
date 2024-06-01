#include "inc/lex.h"
#include "inc/parser.h"

using std::vector;

int main(int argc, char **argv)
{
	//here should be a file name to scan token from
	string path_file;
	if (argc == 1)
		path_file = "ref/test";
	else {
		string file = argv[1];
		path_file = "ref/" + file;
	}
	vector<Token> vec = tokensScan(path_file);
	for (int i = 0; i < vec.size(); i++)
		vec[i].printToken();

	parse(vec);
	return 0;
}
