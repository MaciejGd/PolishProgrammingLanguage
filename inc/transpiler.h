#ifndef TRANSPILER
#define TRANSPILER

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>


#include "grammar.h"

extern std::unordered_map<std::string, std::string> polCmap;
extern std::vector<std::string> common_signs;
extern std::unordered_map<std::string, std::string> keyword_map;

void transpiler(const char* file_name, Symbol* head);

//simple helper function to search for an vector element
template<typename T>
bool search(std::vector<T> vec, T value) {
  return (std::find(vec.begin(), vec.end(), value)!=vec.end());
}

//helper function needed in function procesing, 
//used for switching last element in deque to a first 
//position and place it in a string stream
void processFunctionRecord(std::ostringstream& ss, std::deque<std::string>& func_record);

#endif