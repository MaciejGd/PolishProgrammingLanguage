#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <mutex>
#include <algorithm>

//macros for colour logging on linux systems
#ifdef __linux__
#define ERROR_LOG "\033[1;31m[ERROR]\033[0m"
#define INFO_LOG "\033[1;32m[INFO]\033[0m"
#elif
#define ERROR_LOG "[ERROR]"
#define INFO_LOG "[INFO]"
#endif

template<typename T>
bool search(const std::vector<T>& compare_set, T lexeme)
{
	return (std::find(compare_set.begin(), compare_set.end(), lexeme)!=compare_set.end());
}

//needed by lexer
extern std::vector<char> operators;
extern std::vector<char> separators;
extern std::vector<std::string> keywords;
//needed by trabnspiler
extern std::unordered_map<std::string, std::string> keyword_map;



