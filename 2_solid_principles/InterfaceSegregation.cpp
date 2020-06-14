/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/14 */

#include "InterfaceSegregation.h"

void Printer::print(Document& document)
{
}

Machine::Machine(IPrinter& printer, IScanner& scanner):
    m_printer(printer),
    m_scanner(scanner)
{
}

void Machine::print(Document& doc)
{
    m_printer.print(doc);
}

void Machine::scan(Document& doc)
{
    m_scanner.scan(doc);
}

int main()
{
}