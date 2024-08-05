#include "inc/lex.h"
#include "inc/parser.h"
#include "inc/grammar.h"
#include "inc/transpiler.h"
#include "inc/compilerWrapper.h"
#include <string.h>
#include <filesystem>

int main(int argc, char **argv)
{
	//WRAPPER INITIAL TESTING
	std::vector<std::string> command;
	for (int i = 1; i < argc; i++)
	{
		command.push_back(argv[i]);
	}
	CompilerWrapper comp = CompilerWrapper(command);
	return 0;
}
