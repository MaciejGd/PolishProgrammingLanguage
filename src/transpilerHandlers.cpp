#include "../inc/transpilerHandlers.h"

void FunctionHandler::processRecord(std::ostringstream& ss) 
{
  std::string return_type = p_record.back();
  p_record.pop_back();
  p_record.push_front(return_type);
  for (const auto& node_val : p_record)
  {
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      continue;
    }
    ss << node_val << " ";
  }
  ss << "\n";
  p_record.clear();
}

void FunctionHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{
  if (node_val == "funkcja")
    return;
  if (node_val != ":")
  {
    p_record.push_back(node_val);
    return;
  }
  m_colons++;
  if (m_colons == 2)
  {
    processRecord(ss);
    m_colons = 0;
    p_active = false;   
  }
}

void FunctionCallHandler::processRecord(std::ostringstream& ss)
{

}

void FunctionCallHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{
  // if (node_val == "wywolaj")
  // {
  //   return;
  // }
  // if (node_val == "(")
  // {
  //   m_args++;
  // }
  // if (node_val == ")")
  // {
  //   m_args--;
  // }
  // if ()
}


void IfHandler::processRecord(std::ostringstream& ss)
{
  for (const auto& node_val : p_record)
  {
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      continue;
    }
    ss << node_val << " ";
  }
  p_record.clear();
}

void IfHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{  
  if (node_val == ":")
  {
    if (p_record.size() > 1)
      p_record.push_back(")");
    processRecord(ss);
    p_active = false;
  }
  //analyze if
  if (node_val == "jesli")
  {
    p_record.push_back("if ");
    p_record.push_back("( ");
    return;
  }
  //analyze else
  if (node_val == "inaczej")
  {
    p_record.push_back("else ");
    return;
  }

  p_record.push_back(node_val);
  return;
  
}

void ForHandler::processRecord(std::ostringstream& ss)
{
  std::string left_range;
  std::string right_range;
  bool bound_reached = false;
  for (const auto& x : p_record)
  {
    if (x == ",")
    {
      bound_reached = true;
      continue;
    }
    if (bound_reached)
    {
      right_range+=x;
      continue;
    }
    left_range+=x;
  }
  if (right_range.empty())
    right_range = "0";
  //IMPLEMENTATION
  // for (int i = num_1; i != num_2; i+=((num_1 > num_2)? -1 : 1))
  // {
  //   std::cout << i << std::endl;
  // }
  ss << "for (int " << m_loop_iterator << " = (" << left_range << "); " << m_loop_iterator << " != (" << right_range << "); " << 
      m_loop_iterator << " += (((" << left_range << ") > (" << right_range << "))? -1 : 1))\n";
  p_record.clear();
}

void ForHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{
  //after all this checkings only range would be added to a p_record deque
  if (node_val == ":")
  {
    processRecord(ss);
    p_active = false;
  }
  if (node_val == "dla")
  {
    //start recording for id
    m_keyword = true;
    return;
  }
  if (node_val == "zakres")
  {
    //stop recording for id
    m_keyword = false;
    return;
  }
  //start  retrieve data about loop bounds
  if (m_keyword)
  {
    m_loop_iterator = node_val;
    m_keyword = false;
    return;
  }
  if (node_val == "(" || node_val == ")")
    return;
  p_record.push_back(node_val);
}

void WhileHandler::processRecord(std::ostringstream& ss)
{
  for (const auto& node_val: p_record)
  {
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      continue;
    }
    ss << node_val << " ";
  }
  p_record.clear();
}

void WhileHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{
  if (node_val == ":")
  {
    p_record.push_back(")");
    p_active = false;
    processRecord(ss);
    return;
  }
  if (node_val == "dopoki")
  {
    p_record.push_back("while ");
    p_record.push_back("(");
    return;
  }
  p_record.push_back(node_val);
}

void PrintHandler::processRecord(std::ostringstream& ss) 
{
  ss << "std::cout << ";
  for (const auto& node_val: p_record)
  {
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      continue;
    }
    ss << node_val << " ";
  }
  p_record.clear();
}

void PrintHandler::analyze(std::ostringstream& ss, const std::string& head)
{
  if (head == "wypisz")
  {
    return;
  }
  if (head == "(")
  {
    if (m_brackets)
      p_record.push_back(head);
    m_brackets++;
    return;
  }
  if (head == ")")
  {
    m_brackets--;
  }
  if (!m_brackets)
  {
    deactivate();
    processRecord(ss);
    return;
  }
  if (head == "wywolaj")
    return;
  p_record.push_back(head);
}

void InputHandler::processRecord(std::ostringstream& ss) 
{
  ss << "std::cin >> ";
  for (const auto& x: p_record)
  {
    ss << x;
  }  
  p_record.clear();
}

void InputHandler::analyze(std::ostringstream& ss, const std::string& head) 
{
  if (head == "wpisz")
  {
    return;
  }
  if (head == "(")
  {
    return;
  }
  if (head == ")")
  {
    deactivate();
    processRecord(ss);
  }
  p_record.push_back(head);
}


//this one can be a function of Handler class i guess (will be inherited by the rest)
void GlobalHandler::processRecord(std::ostringstream& ss)
{
  for (const auto& x: p_record)
  {
    auto it = keyword_map.find(x);
    if (it != keyword_map.end())
    {
      ss << keyword_map[x] << " "; 
      continue;
    }
    ss << x << " ";
  }
  ss << "\n";
  p_record.clear();
}

void GlobalHandler::analyze(std::ostringstream& ss, const std::string& head)
{
  if (head == "globalne")
    return;
  if (head == "{")
    return;
  if (head == "}")
  {
    deactivate();
    processRecord(ss);
  }
  p_record.push_back(head);
}

void IncludeHandler::processRecord(std::ostringstream& ss) 
{
  
}

void IncludeHandler::analyze(std::ostringstream& ss, const std::string& head) 
{
  //processing of includes so simple that it does not requaire calling processRecordFunction
  if (head == "dodaj")
  {
    p_record.push_back("#include");
    ss << "#include ";
    return;
  }
  ss << '"';
  ss << head;
  p_record.push_back(head);
  ss << '"';
  ss << '\n';
  deactivate();
}