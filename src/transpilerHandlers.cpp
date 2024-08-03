#include "../inc/transpilerHandlers.h"

void FunctionHandler::processRecord(std::ostringstream& ss) 
{
  std::string return_type = p_record.back();
  p_record.pop_back();
  p_record.push_front(return_type);
  for (const auto& node_val : p_record)
  {
    if (search(common_signs, node_val))
    {
      ss << node_val << " ";
      continue;
    }
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

// IfHandler::IfHandler()
// {
//   p_record.push_back("if ");
//   p_record.push_back("( ");
// }

void IfHandler::processRecord(std::ostringstream& ss)
{
  for (const auto& node_val : p_record)
  {
    if (search(common_signs, node_val))
    {
      ss << node_val << " ";
      continue;
    }
    auto it = keyword_map.find(node_val);
    if (it != keyword_map.end())
    {
      ss << keyword_map[node_val] << " ";
      continue;
    }
    ss << node_val << " ";
  }
}

void IfHandler::analyze(std::ostringstream& ss, const std::string& node_val)
{
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
  //if end of expression
  if (node_val != ":")
  {
    p_record.push_back(node_val);
    return;
  }
  //do not add closing bracket when it is simple else
  if (p_record.size() > 1)
    p_record.push_back(")");
  processRecord(ss);
  p_active = false;
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
  p_record.push_back(node_val);
}