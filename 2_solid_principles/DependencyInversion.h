/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/14 */

#ifndef DEPENDENCY_INVERSION_PRINCIPLE
#define DEPENDENCY_INVERSION_PRINCIPLE

#include <string>
#include <tuple>
#include <vector>

using std::string;
using std::tuple;
using std::vector;

enum class Relationship
{
    parent,
    child,
    sibling
};

struct Person
{
    string name;
};

struct RelationshipBrowser
{
    virtual vector<Person> findAllChildrenOf(const string& name) = 0;
};

struct Relationships: RelationshipBrowser
{
    void addParentAndChild(const Person& parent, const Person& child);
    vector<Person> findAllChildrenOf(const string& name) override;

    vector<tuple<Person, Relationship, Person>> m_relations;
};

struct Research
{
    static void research(RelationshipBrowser& rBrowser);
};

#endif