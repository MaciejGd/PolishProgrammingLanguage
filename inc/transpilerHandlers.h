#ifndef HANDLERS
#define HANDLERS

#include <string>
#include <deque>
#include <sstream>
#include "production.h"


template<typename T>
bool search(std::vector<T> vec, T value) {
  return (std::find(vec.begin(), vec.end(), value)!=vec.end());
}


class Handler {
protected:
  bool p_active;
  std::deque<std::string> p_record;
public:
  Handler():p_active(true), p_record(std::deque<std::string>()){}
  virtual void processRecord(std::ostringstream& ss) = 0;
  virtual void analyze(std::ostringstream& ss, const std::string& head) = 0;
  //actially can provide implementation of this one
  const bool isActive() const { return p_active; };
  void activate() { p_active = true; };
  void deactivate() { p_active = false; };
  void addToRecord(const std::string& element) { p_record.push_back(element); };
};

class FunctionHandler : public Handler{
  int m_colons;
  //are they really needed? i gues not
  void m_increaseColons() { m_colons++; };
  void m_resetColons() { m_colons = 0; };
  const int m_getColons() const { return m_colons; };
public:
  FunctionHandler(): m_colons(0){};
  //potenatial of adding other implementation of the same function to another handler
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class FunctionCallHandler : public Handler {
  bool m_args;
public:
  FunctionCallHandler():m_args(false){};
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& node_val) override;
};

class IfHandler : public Handler {
public:
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class ForHandler : public Handler {
  std::string m_loop_iterator;
  bool m_keyword;
public:
  ForHandler():m_keyword(false){};
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class WhileHandler : public Handler {
public:
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class PrintHandler : public Handler {
public:
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

#endif