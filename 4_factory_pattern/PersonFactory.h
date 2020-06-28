#include <string>

using std::string;

class Person
{
    private:
        Person (const int id, const string& name);
        friend class PersonFactory;

    public:
        string toString() const;

    private:
        const int m_id;
        string m_name;
};

class PersonFactory
{
    public:
        PersonFactory();

        Person createPerson(const string& name);

    private:
        int m_id;
};