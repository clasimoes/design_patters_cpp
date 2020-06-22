#include "CodeBuilder.h"

using std::cout;

CodeBuilder::CodeBuilder(const string& className)
{
    m_className = className;
}

CodeBuilder& CodeBuilder::add_field(const string& name, const string& type)
{
    m_fields.emplace_back(std::make_pair(name, type));
    return *this;
}

ostream& operator<<(ostream& os, const CodeBuilder& obj)
{
    os << "class " << obj.m_className << "\n";
    os << "{" << "\n";
    for (const auto& field: obj.m_fields)
    {
        os << "  " << field.second << " " << field.first << ";\n";
    }
    os << "};" << "\n";

    return os;
}

int main()
{
    auto cb = CodeBuilder{"Person"}.add_field("name", "string").add_field("age","int");
    std::cout << cb;
    return 0;
}