#pragma once 
#include <vector>
#include <string>
#include <thread>
#include <mutex>

#include "lex.h"
#include "parser.h"
#include "transpiler.h"


//main wrapper for 

class CompilerWrapper {
  std::vector<std::string> flags;
  std::vector<std::string> files;
  std::string exe_name;
  std::string extra_flags;
  bool clean_build;
  int m_analyzeCommand(const std::vector<std::string>& command);
  void m_processFile(const std::string& file_name);
public: 
  CompilerWrapper(const std::vector<std::string>& command);

};
