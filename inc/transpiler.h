#ifndef TRANSPILER
#define TRANSPILER

#include <unordered_map>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <memory>
#include <sstream>
#include <mutex>
#include <filesystem>

#include "grammar.h"
#include "transpilerHandlers.h"
#include "production.h"

//helper function for adding new line character after wanted strings
void addNewLine(std::ostringstream& ss, const std::string& sign);

class Transpiler {
  //for testing purpose
  std::string init_code = "#include <string>\n#include <iostream>\n#include <vector>\n";
  std::ostringstream ss;
  std::unique_ptr<Handler> m_handler;
  std::mutex m_mutex;
  void m_transpiler_rec(const Symbol* head);
  void m_transpiler(const std::string& file_name, const Symbol* head);
  int m_chooseHandler(const std::string& node_val);
public:
  Transpiler(const std::string& file_name, const Symbol* head);
};


#endif