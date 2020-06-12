/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/11 */
#ifndef SINGLE_RESPONSIBILITY_PRINCIPLE
#define SINGLE_RESPONSIBILITY_PRINCIPLE

# include <string>
# include <vector>

using std::string;
using std::vector;

class Journal
{
    public:
        Journal(const string& title);

        void addEntry(const string& entry);

        vector<string>& getEntries();

    private:
        string m_title;
        vector<string> m_entries;
        static int s_count;
};

class PersistenceManager
{
    public:
        static void save(Journal& journal, const string& fileName);
};

#endif
