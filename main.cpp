#include "inc/lex.h"
#include "inc/parser.h"
#include <filesystem>

using std::vector;
namespace fs = std::filesystem;

int main(int argc, char **argv)
{
	//here should be a file name to scan token from
	string path_file;
	string suffix = ".pol";
	if (argc == 1)
		path_file = "ref/test";
	else {
		string file = argv[1];
		path_file = "ref/" + file;
	}
	if (!fs::is_regular_file(path_file))
	{
		std::cerr << "There is no such file path in the system, please provide .pol file" << "\n";
		return 1;
	}
	else if (path_file.rfind(suffix)!=(path_file.length()-suffix.length()))
	{
		std::cerr << "File name has to end with .pol suffix, could not compile the code" << "\n";
		return 1;
	}
	vector<Token> vec = tokensScan(path_file);
	for (int i = 0; i < vec.size(); i++)
		vec[i].printToken();

	parse(vec);
	return 0;
}
