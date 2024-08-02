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
  std::cout << "[DEBUG] node_val: " << node_val << std::endl;
  if (node_val != ":")
  {
    p_record.push_back(node_val);
    return;
  }
  m_colons++;
  std::cout << "Colons: " << m_colons << std::endl;
  if (m_colons == 2)
  {
    processRecord(ss);
    m_colons = 0;
    p_active = 0;   
  }
  return;
}


