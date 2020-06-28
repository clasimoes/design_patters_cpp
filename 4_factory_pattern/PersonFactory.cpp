#include "PersonFactory.h"

#include <iostream>
#include <sstream>

using std::cout;
using std::endl;
using std::stringstream;

Person::Person (const int id, const string& name):
    m_id(id),
    m_name(name)
{    
}
string Person::toString() const
{
    stringstream ss;
    ss << m_id << ": " << m_name;
    return ss.str();
}

PersonFactory::PersonFactory(): m_id(0)
{
}

Person PersonFactory::createPerson(const string& name)
{
    Person p {m_id++, name};
    return p;
}

int main()
{
    PersonFactory factory;
    Person p1 = factory.createPerson("Mei");
    Person p2 = factory.createPerson("Luke");
    cout << p1.toString() << endl;
    cout << p2.toString() << endl;

    return 0;
}