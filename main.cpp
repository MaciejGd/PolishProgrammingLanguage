#include "inc/lex.h"
#include "inc/parser.h"
#include "inc/grammar.h"
#include <string.h>
#include <filesystem>

namespace fs = std::filesystem;

//have to consider moving test functions to another file and then just link it
int runTests()
{
	const char *test_path = "./tests/";
	const char *suffix = ".pol";
	if (!fs::exists(test_path))
	{
		std::cout << "Test directory does not exist, could not perform tests" << std::endl;	
		return 1;
	}
	std::vector<fs::directory_entry> test_files;
	for (auto const& entry: fs::directory_iterator{test_path})
	{
		//checking for .pol suffix
		std::string file_name = entry.path().filename();
		if (file_name.find(suffix) == (file_name.length() - strlen(suffix)))
			test_files.push_back(entry);
	}
	//sorting in alphabetical order
	std::sort(test_files.begin(), test_files.end(), [](const auto& a, const auto& b){
			return a.path().filename() < b.path().filename();
			});
	std::cout << "File names alphabetically" << std::endl;
	for (const auto& entry: test_files)
	{
		std::cout << "Parsing file: " << entry.path().filename() << "...\n";
		std::vector<Token> file_tokens = tokensScan(entry.path());
		Symbol *result;
		if (!(result = parse(file_tokens)))
		{
			std::cout << "Parsing file: " << entry.path() << " failed\n";
			std::cout << "Return status code: 1\n\n";
		}
		else {
			std::cout << "Successfully parsed file: " << entry.path() <<"\n";
			std::cout << "Head node -> " << result->getName() << "\n\n";
		}
	}
	return 0;
}


int main(int argc, char **argv)
{
	//here should be a file name to scan token from
	std::string path_file;
	std::string suffix = ".pol";
	//run all tests from tests directory if no argument has been passed
	if (argc == 1)
	{
		runTests();
		return 0;
	}
	else {
		std::string file = argv[1];
		path_file = "ref/" + file;
	}
	for (int i = 1; i < argc; i++)
	{
		std::string path_to_test = "./tests/" + std::string(argv[i]);
		std::vector<Token> token_list = tokensScan(path_to_test);
		Symbol* error_code;
		if ((error_code = parse(token_list)))
			std::cout << "File: " << argv[i]<< " parsed with no errors\n";
		else {
			std::cout << "File: " << argv[i] << " could not be parsed!!! Error code: " << error_code << "\n";
		}
	}
	//debug purpose all files checking at once
	//check for path being regular file
	//code to be used
	//if (!fs::is_regular_file(path_file))
	//{
	//	std::cerr << "There is no such file path in the system, please provide .pol file" << "\n";
	//	return 1;
	//}
	////file extension check
	//else if (path_file.rfind(suffix)!=(path_file.length()-suffix.length()))
	//{
	//	std::cerr << "In order to compile, save your file with .pol extension" << "\n";
	//	return 1;
	//}
	//std::vector<Token> vec = tokensScan(path_file);
	//for (int i = 0; i < vec.size(); i++)
	//	vec[i].printToken();

	//parse(vec);
	return 0;
}
