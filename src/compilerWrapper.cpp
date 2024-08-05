#include "../inc/compilerWrapper.h"

CompilerWrapper::CompilerWrapper(const std::vector<std::string>& command):exe_name("program"),clean_build(false)
{
  if (m_analyzeCommand(command))
  {
    std::cout << ERROR_LOG << "Aborting program execution with exit code 1\n";
    exit(1);
  };
  std::cout << INFO_LOG << "Processing command\n";
  std::vector<std::thread> t;
  for (const auto&x : files)
  {
    t.push_back(std::thread([this, x](){ m_processFile(x);}));
    std::cout << INFO_LOG << "Started new thread for processing " << x << "file.\n";
  }
  //join created threads  
  for (auto& x : t)
  {
    if (x.joinable())
      x.join();
  }
  //after files processing ended successfully run compile on created files
  //can actually wrap this into a separate function to make code more clear
  std::vector<string> cpp_files;
  for (const auto& file : files)
  {
    std::string temp_file = file.substr(0,file.length()-4) + ".cpp";
    auto it = temp_file.find_last_of('/');
    if (it != temp_file.npos)
    {
      temp_file = temp_file.substr(it, temp_file.length()-1);
    }
    cpp_files.push_back("./.TRANSPILER/"+temp_file);
    std::cout << INFO_LOG << "[" << cpp_files.back() << "]\n";
  }
  std::string files_to_compile = "";
  for (const auto& file : cpp_files)
  {
    files_to_compile+=(" " + file);
  }
  system(("g++ --std=c++20 " + extra_flags + files_to_compile + " -o " + exe_name).c_str());
  if(clean_build)
    system("rm -r ./.TRANSPILER/");
}

int CompilerWrapper::m_analyzeCommand(const std::vector<std::string>& command)
{
  //if command is empty, skip the process of analyzis and quit
  if (command.empty())
  {
    std::cout << ERROR_LOG << "pollang command needs input arguments, no input has been specified, quiting\n";
    return 1;
  }
  std::string prev = "";
  std::string temp;
  bool defaultExe = true;
  for (const auto& arg: command)
  {
    //handle flag occurance
    if (arg[0] == '-')
    {
      flags.push_back(arg);
      if (arg=="-czysty")
        clean_build = true;
      else if (arg=="-extra")
        extra_flags = " -Wextra -Wall --pedantic ";
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
        std::cout << ERROR_LOG << "[" << arg << "]Passed argument does not have .pol extension. Check your spelling.\n";
        return 1;
      }
      files.push_back(arg);
    }
    prev = arg;
  }
  std::cout << INFO_LOG << "Printing out flags vector:\n";
  for (const auto& x : flags)
  {
    std::cout << x << " ";
  }
  std::cout << "\n" << INFO_LOG << "Printing out files vector:\n";
  for (const auto& x : files)
  {
    std::cout << x << " ";
  }
  std::cout << "\n";
  std::cout << "Exe name: " << exe_name << "\n";
  //signal error when no files has been speicfied
  if (files.empty())
  {
    std::cout << ERROR_LOG << "pollang: no files has been specified\n";
    return 1;
  }
  return 0;
}


void CompilerWrapper::m_processFile(const std::string& file_name)
{
  Lexer lexer(file_name);
  Parser parser(file_name, lexer.getTokens());
  Transpiler transpiler(file_name, parser.getHead());
}