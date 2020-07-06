#include "ExpressionVisitor.h"

#include <iostream>

using namespace std;

Value::Value(const int value): m_value(value)
{
}

void Value::accept(ExpressionVisitor& expressionVisitor)
{
    expressionVisitor.visit(*this);
}

AdditionExpression::AdditionExpression(Expression& lhs, Expression& rhs)
    : m_lhs(lhs), m_rhs(rhs)
{
}

void AdditionExpression::accept(ExpressionVisitor& expressionVisitor)
{
    expressionVisitor.visit(*this);
}

MultiplicationExpression::MultiplicationExpression(Expression& lhs, Expression& rhs)
    : m_lhs(lhs), m_rhs(rhs)
{
}

void MultiplicationExpression::accept(ExpressionVisitor& expressionVisitor)
{
    expressionVisitor.visit(*this);
}

void ExpressionPrinter::visit(Value& value)
{
    m_oss << value.m_value;
}

void ExpressionPrinter::visit(AdditionExpression& additionExpression)
{
    m_oss << "(";
    additionExpression.m_lhs.accept(*this);
    m_oss << "+";
    additionExpression.m_rhs.accept(*this);
    m_oss << ")";
}

void ExpressionPrinter::visit(MultiplicationExpression& multiplicationExpression)
{
    multiplicationExpression.m_lhs.accept(*this);
    m_oss << "*";
    multiplicationExpression.m_rhs.accept(*this);
}

string ExpressionPrinter::str() const
{
    return m_oss.str();
}

int main()
{
    Value v1 {2};
    Value v2 {3};
    Value v3 {5};
    auto a1 = AdditionExpression {v1, v2};
    auto a2 = AdditionExpression {v2, v3};
    auto exp = MultiplicationExpression { a1, a2 };

    ExpressionPrinter printer;
    printer.visit(exp);
    std::cout << printer.str() << "\n";

    return 0;
}