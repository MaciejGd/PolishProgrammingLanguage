#ifndef TRANSPILER
#define TRANSPILER

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <memory>

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
  Handler():p_active(true), p_record(std::deque<std::string>()){}
  virtual void processRecord(std::ostringstream& ss) = 0;
  virtual void analyze(std::ostringstream& ss, const std::string& head) = 0;
  //actially can provide implementation of this one
  const bool isActive() const { return p_active; };
  void activate() { p_active = true; };
  void deactivate() { p_active = false; };
  void addToRecord(const std::string& element) { p_record.push_back(element); };
};




class FunctionHandler : public Handler{
  int m_colons;
public:
  FunctionHandler(): m_colons(0){};
  void increaseColons() { m_colons++; };
  void resetColons() { m_colons = 0; };
  const int getColons() const { return m_colons; };
  //potenatial of adding other implementation of the same function to another handler
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class Transpiler {
  //to bo replaced with a unique_ptr to a Handler object
  std::unique_ptr<Handler> m_function;
  void m_transpiler_rec(std::ostringstream& ss, Symbol* head);
public:
  Transpiler():m_function(new FunctionHandler()){};
  void transpiler(const char* file_name, Symbol* head);
};


#endif