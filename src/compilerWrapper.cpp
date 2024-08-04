#include "../inc/compilerWrapper.h"

CompilerWrapper::CompilerWrapper(const std::vector<std::string>& command):exe_name("program")
{
  if (m_analyzeCommand(command))
  {
    std::cout << "[ERROR]Aborting program execution with exit code 1\n";
    exit(1);
  };
  std::cout << "[INFO]Processing command\n";
  std::vector<std::thread> t;
  for (const auto&x : files)
  {
    t.push_back(std::thread([this, x](){ m_processFile(x);}));
    std::cout << "[INFO]Started new thread for processing " << x << "file.\n";
  }
  //join created threads  
  for (auto& x : t)
  {
    if (x.joinable())
      x.join();
  }
}

int CompilerWrapper::m_analyzeCommand(const std::vector<std::string>& command)
{
  //can actually filter out wrong usage of program at the stage of passing input arguments
  //if error return 1
  std::string prev = "";
  std::string temp;
  bool defaultExe = true;
  for (const auto& arg: command)
  {
    //handle flag occurance
    if (arg[0] == '-')
    {
      flags.push_back(arg);
    }
    //handle custom exe name 
    else if (prev == "-nazwa")
    {
      exe_name = arg;
    }
    //handle file name
    else 
    {
      auto it = arg.find_last_of('.');
      //check if file extension is .pol
      if (arg.substr(it+1, arg.length()) != "pol")
      {
        std::cout << "[ERROR][" << arg << "] Passed argument does not have .pol extension. Check your spelling.\n";
        return 1;
      }
      files.push_back(arg);
    }
    prev = arg;
  }
  std::cout << "[INFO]Printing out flags vector:\n";
  for (const auto& x : flags)
  {
    std::cout << x << " ";
  }
  std::cout << "\n[INFO]Printing out files vector:\n";
  for (const auto& x : files)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  std::cout << "Exe name: " << exe_name << "\n";
  return 0;
}


void CompilerWrapper::m_processFile(const std::string& file_name)
{
  Lexer lexer(file_name);
  Parser parser(file_name, lexer.getTokens());
  Transpiler transpiler(file_name, parser.getHead());
}