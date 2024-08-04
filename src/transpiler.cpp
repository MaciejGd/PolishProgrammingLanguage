#include "../inc/transpiler.h"

void addNewLine(std::ostringstream &ss, const std::string &sign)
{
  if (sign == ";" || sign == "{" || sign == "}")
  {
    ss << "\n";
  }
}

Transpiler::Transpiler(const std::string& file_name, const Symbol* head)
{
  system("mkdir TRANSPILER");
  //preparing .cpp file
  std::string temp_file = file_name.substr(0,file_name.length()-4) + ".cpp";
  auto it = temp_file.find_last_of('/');
  if (it != temp_file.npos)
  {
    temp_file = temp_file.substr(it, temp_file.length()-1);
  }
  m_transpiler("./TRANSPILER/"+ temp_file, head);
}

void Transpiler::m_transpiler_rec(const Symbol *head)
{
  //if node is down node with value
  std::string node_val = head->getValue();
  if (node_val != "")
  { 
    //if handler is actually set to active, process it 
    if (m_handler && m_handler->isActive())
    {
      m_handler->analyze(ss, node_val);
      return;
    }
    //check if handler need to be set
    if (m_chooseHandler(node_val))
    {
      m_handler->analyze(ss, node_val);
      return;
    }
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      return;
    }
    //skipping "wywolaj" keyword and end of file symbol
    if (node_val == "$" || node_val == "wywolaj")
    {
      return;
    }
    
    ss << node_val << " ";
    addNewLine(ss, node_val);
  }
  //else go down from right to left in rhs
  for (int i = head->getRhsSize() - 1; i >= 0; i--)
  {
    m_transpiler_rec(head->getRhsNode(i));
  }
} 

void Transpiler::m_transpiler(const std::string& file_name, const Symbol* head)
{
  ss << init_code;
  m_transpiler_rec(head);
  //todo open a file and place a string stream
  std::fstream file(file_name, std::ios::out);
  if (file.fail())
  {
    std::cout << "[ERROR]Could not open a file: " << file_name << " in function transpiler in transpiler.cpp\n";
    return;
  }
  file << ss.str();
  ss.str(std::string());
  file.close();
}

int Transpiler::m_chooseHandler(const std::string& node_val)
{
  if (node_val == "funkcja")
  {
    m_handler.reset(new FunctionHandler{});
    return 1;
  }
  if (node_val == "dla")
  {
    m_handler.reset(new ForHandler{});
    return 1;
  }
  if (node_val == "dopoki")
  {
    m_handler.reset(new WhileHandler{});
    return 1;
  }
  if (node_val == "jesli" || node_val == "inaczej")
  {
    m_handler.reset(new IfHandler{});
    return 1;
  }
  if (node_val == "wypisz")
  {
    m_handler.reset(new PrintHandler{});
    return 1;
  }
  if (node_val == "wpisz")
  {
    m_handler.reset(new InputHandler{});
    return 1;
  }
  if (node_val == "globalne")
  {
    m_handler.reset(new GlobalHandler{});
    return 1;
  }
  if (node_val == "dodaj")
  {
    m_handler.reset(new IncludeHandler{});
    return 1;
  }
  
  return 0;
}
