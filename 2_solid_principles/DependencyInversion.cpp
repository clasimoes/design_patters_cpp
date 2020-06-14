/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/14 */

#include "DependencyInversion.h"

#include <iostream>

using std::cout;
using std::endl;

void Relationships::addParentAndChild(const Person& parent, const Person& child)
{
    m_relations.push_back({parent, Relationship::parent, child});
    m_relations.push_back({child, Relationship::child, parent});
}

vector<Person> Relationships::findAllChildrenOf(const string& name)
{
    vector<Person> result;

    for (const auto& relation: m_relations)
    {
        auto& person1 = std::get<0>(relation);
        auto& relationship = std::get<1>(relation);

        if (person1.name == name && relationship == Relationship::parent)
        {
            auto& person2 = std::get<2>(relation);
            result.push_back(person2);
        }
    }

    return result;
}

void Research::research(RelationshipBrowser& rBrowser)
{
    for (auto& child : rBrowser.findAllChildrenOf("John"))
    {
        cout << "John has a child called " << child.name << endl;
    }
}

int main()
{
    Person parent{"John"};
    Person child1{"Chris"};
    Person child2{"Matt"};

    Relationships relationships;
    relationships.addParentAndChild(parent, child1);
    relationships.addParentAndChild(parent, child2);

    Research::research(relationships);
}