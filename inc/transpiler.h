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
  //for testing purpose
  std::string init_code = "#include <string>\n#include <iostream>\n#include <vector>\n";
  std::ostringstream ss;
  std::unique_ptr<Handler> m_handler;
  void m_transpiler_rec(const Symbol* head);
public:
  void transpiler(const char* file_name, const Symbol* head);
  int chooseHandler(const std::string& node_val);
};


#endif