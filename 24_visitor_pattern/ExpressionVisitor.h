#include <string>
#include <sstream>

struct Value;
struct AdditionExpression;
struct MultiplicationExpression;

struct ExpressionVisitor
{
    virtual void visit(Value& value) = 0;
    virtual void visit(AdditionExpression& additionExpression) = 0;
    virtual void visit(MultiplicationExpression& multiplicationExpression) = 0;
};

struct Expression
{
    virtual void accept(ExpressionVisitor& expressionVisitor) = 0;
};

struct Value : Expression
{
    Value(const int value);

    void accept(ExpressionVisitor& expressionVisitor) override;

    const int m_value;
};

struct AdditionExpression : Expression
{
    AdditionExpression(Expression& lhs, Expression& rhs);

    void accept(ExpressionVisitor& expressionVisitor) override;

    Expression& m_lhs;
    Expression& m_rhs;
};

struct MultiplicationExpression : Expression
{
    MultiplicationExpression(Expression& lhs, Expression& rhs);

    void accept(ExpressionVisitor& expressionVisitor) override;

    Expression& m_lhs;
    Expression& m_rhs;
};

struct ExpressionPrinter : ExpressionVisitor
{
    virtual void visit(Value& value) override;
    virtual void visit(AdditionExpression& additionExpression) override;
    virtual void visit(MultiplicationExpression& multiplicationExpression) override;

    std::string str() const;

    std::ostringstream m_oss;
};