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
  if (node_val == "jesli")
  {
    p_record.push_back("if ");
    p_record.push_back("( ");
    return;
  }
  if (node_val == "inaczej")
  {
    p_record.push_back("else ");
    return;
  }

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

// ElseIfHandler::ElseIfHandler()
// {
//   p_record.push_back("inaczej");
//   p_record.push_back();
//   p_record.push_back();
// }
