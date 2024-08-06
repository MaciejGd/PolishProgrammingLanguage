#ifndef HANDLERS
#define HANDLERS

#include <string>
#include <deque>
#include <sstream>

#include "production.h"

class Handler {
protected:
  bool p_active;
  std::deque<std::string> p_record;
public:
  Handler():p_active(true), p_record(std::deque<std::string>()){}
  virtual void processRecord(std::ostringstream& ss) = 0;
  virtual void analyze(std::ostringstream& ss, const std::string& head) = 0;
  //actially can provide implementation of this one
  inline const bool isActive() const { return p_active; };
  inline void activate() { p_active = true; };
  inline void deactivate() { p_active = false; };
  inline void addToRecord(const std::string& element) { p_record.push_back(element); };
};

class FunctionHandler : public Handler{
  int m_colons;
  //are they really needed? i gues not
  inline void m_increaseColons() { m_colons++; };
  inline void m_resetColons() { m_colons = 0; };
  inline const int m_getColons() const { return m_colons; };
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
  //variable needed for analyzing a function call in printing
  int m_brackets;
public:
  PrintHandler():m_brackets(0){};
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class InputHandler : public Handler {
public: 
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class GlobalHandler : public Handler {
public:
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

class IncludeHandler : public Handler {
public:
  void processRecord(std::ostringstream& ss) override;
  void analyze(std::ostringstream& ss, const std::string& head) override;
};

#endif