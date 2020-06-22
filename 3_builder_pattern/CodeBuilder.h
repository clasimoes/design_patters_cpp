/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/11 */

#ifndef BUILDER_PATTERN
#define BUILDER_PATTERN

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::ostream;
using std::pair;
using std::string;
using std::vector;

class CodeBuilder
{
public:
  CodeBuilder(const string& className);

  CodeBuilder& add_field(const string& name, const string& type);

  friend ostream& operator<<(ostream& os, const CodeBuilder& obj);

private:
    string m_className;
    vector<pair<string, string>> m_fields;
};

#endif