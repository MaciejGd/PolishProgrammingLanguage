#ifndef TRANSPILER
#define TRANSPILER

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>

#include "grammar.h"

#define TABULATION 2

extern std::unordered_map<std::string, std::string> polCmap;
extern std::vector<std::string> common_signs;
extern std::unordered_map<std::string, std::string> keyword_map;

//void transpiler(const char* file_name, Symbol* head);

//simple helper function to search for an vector element
template<typename T>
bool search(std::vector<T> vec, T value) {
  return (std::find(vec.begin(), vec.end(), value)!=vec.end());
}

//helper function needed in function procesing, 
//used for switching last element in deque to a first 
//position and place it in a string stream
void processFunctionRecord(std::ostringstream& ss, std::deque<std::string>& func_record);

//helper function for adding new line character after wanted strings
void addNewLine(std::ostringstream& ss, const std::string& sign);

class Handler {
protected:
  bool p_active;
  std::deque<std::string> p_record;
public:
  virtual void processRecord(std::ostringstream& ss, const std::string& head) = 0;
  //actially can provide implementation of this one
  virtual void addToRecord();
}


class FunctionHandler {
  bool m_active;
  int m_colons;
  std::deque<std::string> m_record;
public:
  FunctionHandler(): m_active(false), m_colons(0), m_record(std::deque<std::string>()){};
  void increaseColons() { m_colons++; };
  void resetColons() { m_colons = 0; };
  void activate() {  m_active = true; };
  void deactivate() {  m_active = false; };
  const bool isActive() const { return  m_active; };
  const int getColons() const { return m_colons; };
  void addToRecord(std::string element) { m_record.push_back(element); };
  //potenatial of adding other implementation of the same function to another handler
  void processRecord(std::ostringstream& ss);
  void analyzeFunction(std::ostringstream& ss, const std::string& head);
};

class Transpiler {
  FunctionHandler m_function;
  void m_transpiler_rec(std::ostringstream& ss, Symbol* head);
public:
  Transpiler():m_function(FunctionHandler()){};
  void transpiler(const char* file_name, Symbol* head);
};


#endif