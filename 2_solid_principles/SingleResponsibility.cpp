/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/11 */

#include "SingleResponsibility.h"

#include <sstream>
#include <fstream>

using std::ofstream;
using std::stringstream;

int Journal::s_count = 0;

Journal::Journal(const string& title): m_title(title)
{
}

void Journal::addEntry(const string& entry)
{
    stringstream ss;
    ss << (++s_count) << ": " << entry;
    m_entries.push_back(ss.str());
}

vector<string>& Journal::getEntries()
{
    return m_entries;
}

void PersistenceManager::save(Journal& journal, const string& fileName)
{
    ofstream ofs;
    ofs.open(fileName);
    vector<string>& entries = journal.getEntries();
    for (const auto& entry: entries)
    {
        ofs << entry << "\n";
    }
    ofs.close();
}

int main()
{
    Journal journal("Dear Diary");
    journal.addEntry("Today I've started the Design Patterns in Modern C++ course");
    journal.addEntry("It's a very good course");

    PersistenceManager::save(journal, "myJournal.txt");
}