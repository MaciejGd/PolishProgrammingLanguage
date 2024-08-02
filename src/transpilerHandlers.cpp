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
    return;
  if (node_val != ":")
  {
    p_record.push_back(node_val);
    return;
  }
  p_record.push_back(")");
  processRecord(ss);
  p_active = false;
}


