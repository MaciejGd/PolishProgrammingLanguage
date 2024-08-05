#include "lex.h"
#include "parser.h"
#include "transpiler.h"
#include <vector>
#include <string>
#include <thread>
#include <mutex>

//here, argument to a compiler wrapper would be input string (command used to invoke compiler)

class CompilerWrapper {
  std::vector<std::string> flags;
  std::vector<std::string> files;
  std::string exe_name;
  std::string extra_flags;
  bool clean_build;
  int m_analyzeCommand(const std::vector<std::string>& command);
  void m_processFile(const std::string& file_name);
  // void m_tokenizeFiles();
  // void m_parseFiles();
  // void m_transpilFiles();
public: 
  //cast chain of responsibility in here is it really that necessary????
  CompilerWrapper(const std::vector<std::string>& command);

};
