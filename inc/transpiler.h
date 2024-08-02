#ifndef TRANSPILER
#define TRANSPILER

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <memory>
#include <sstream>

#include "grammar.h"
#include "transpilerHandlers.h"
#include "production.h"

//to be done -> adding tabulation to transpilled cpp files
#define TABULATION 2



//simple helper function to search for an vector element


//helper function for adding new line character after wanted strings
void addNewLine(std::ostringstream& ss, const std::string& sign);

class Transpiler {
  //to bo replaced with a unique_ptr to a Handler object
  std::ostringstream ss;
  std::unique_ptr<Handler> m_handler;
  void m_transpiler_rec(Symbol* head);
public:
  void transpiler(const char* file_name, Symbol* head);
  void chooseHandler(const std::string& node_val);
};


#endif