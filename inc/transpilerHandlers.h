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
public:
  FunctionHandler(): m_colons(0){};
  void increaseColons() { m_colons++; };
  void resetColons() { m_colons = 0; };
  const int getColons() const { return m_colons; };
  //potenatial of adding other implementation of the same function to another handler
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class IfHandler : public Handler {
public:
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class ForHandler : public Handler {
public:
  ForHandler();
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class WhileHandler : public Handler {
public:
  WhileHandler();
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class ElseIfHandler {
public:
  ElseIfHandler();
};
#endif