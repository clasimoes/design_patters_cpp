/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/14 */

#ifndef INTERFACE_SEGREGATION_PRINCIPLE
#define INTERFACE_SEGREGATION_PRINCIPLE

struct Document {};

/* Segregated interfaces */

struct IPrinter
{
    virtual void print(Document& document) = 0;
};

struct IScanner
{
    virtual void scan(Document& document) = 0;
};

struct IFax
{
    virtual void fax(Document& document) = 0;
};

/* Usage of interfaces */

struct Printer: IPrinter {
    void print(Document& document);
};

struct IMachine: IPrinter, IScanner {};

struct Machine: IMachine
{
    Machine(IPrinter& printer, IScanner& scanner);

    void print(Document& doc) override;
    void scan(Document& doc) override;

    IPrinter& m_printer;
    IScanner& m_scanner;
};

#endif