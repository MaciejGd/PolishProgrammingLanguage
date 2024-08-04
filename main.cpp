#include "inc/lex.h"
#include "inc/parser.h"
#include "inc/grammar.h"
#include "inc/transpiler.h"
#include <string.h>
#include <filesystem>

namespace fs = std::filesystem;

//have to consider moving test functions to another file and then just link it
// int runTests(Transpiler* trans)
// {
// 	const char *test_path = "./tests/";
// 	const char *suffix = ".pol";
// 	if (!fs::exists(test_path))
// 	{
// 		std::cout << "Test directory does not exist, could not perform tests" << std::endl;	
// 		return 1;
// 	}
// 	std::vector<fs::directory_entry> test_files;
// 	for (auto const& entry: fs::directory_iterator{test_path})
// 	{
// 		//checking for .pol suffix
// 		std::string file_name = entry.path().filename();
// 		if (file_name.find(suffix) == (file_name.length() - strlen(suffix)))
// 			test_files.push_back(entry);
// 	}
// 	//sorting in alphabetical order
// 	std::sort(test_files.begin(), test_files.end(), [](const auto& a, const auto& b){
// 			return a.path().filename() < b.path().filename();
// 			});
// 	std::cout << "File names alphabetically" << std::endl;
// 	for (const auto& entry: test_files)
// 	{
// 		std::cout << "Parsing file: " << entry.path().filename() << "...\n";
// 		std::vector<Token> file_tokens = tokensScan(entry.path());
// 		Symbol *result;
// 		if (!(result = parse(file_tokens)))
// 		{
// 			std::cout << "Parsing file: " << entry.path() << " failed\n";
// 			std::cout << "Return status code: 1\n\n";
// 		}
// 		else {
// 			std::string trans_file = "./TRANSPIL/" + entry.path().filename().string();
// 			std::cout << "[LOG]" << trans_file << std::endl;
// 			size_t dot_place = trans_file.find_last_of('.');
// 			trans_file = trans_file.substr(0, dot_place+1);
// 			trans_file += "cpp";
// 			printAST(entry.path().filename().c_str(), result);
// 			std::cout << "Successfully parsed file: " << entry.path() <<"\n\n";
// 			trans->transpiler(trans_file.c_str(), result);
// 			chopTree(result);
// 		}
// 	}
// 	return 0;
// }


int main(int argc, char **argv)
{
	//here should be a file name to scan token from
	std::string path_file;
	std::string suffix = ".pol";
	Transpiler* trans = new Transpiler{};
	//run all tests from tests directory if no argument has been passed
	// if (argc == 1)
	// {
	// 	runTests(trans);
	// 	return 0;
	// }
	// else {
	// 	std::string file = argv[1];
	// 	path_file = "ref/" + file;
	// }
	for (int i = 1; i < argc; i++)
	{
		
		std::string path_to_test = "./tests/" + std::string(argv[i]);
		Lexer lexer{path_to_test};
		std::vector<Token> token_list = lexer.getTokens();
		Symbol* error_code;
		if ((error_code = parse(token_list)))
		{
			std::string trans_file = argv[i];
			trans_file = "./TRANSPIL/" + trans_file;
			size_t dot_place = trans_file.find_last_of('.');
			trans_file = trans_file.substr(0, dot_place+1);
			trans_file += "cpp";
			std::cout << "[LOGS]trans_file value: " << trans_file << std::endl;
			printAST(argv[i], error_code);
			trans->transpiler(trans_file.c_str(), error_code);
			chopTree(error_code);
			std::cout << "File: " << argv[i]<< " parsed with no errors\n";
			// executing g++ on output file
			// std::string command_str = "g++ " + trans_file + " -o ./TRANSPIL/";
			// command_str = command_str+argv[i];
			// system(command_str.c_str());
			
		}
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
	delete trans;
	return 0;
}
