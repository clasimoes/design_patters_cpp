/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/14 */

#include "LiskovSubstitution.h"

#include <iostream>

Rectangle::Rectangle(const unsigned width, const unsigned height):
    m_width(width),
    m_height(height)
{
}

unsigned Rectangle::getWidth() const
{
    return m_width;
}

void Rectangle::setWidth(const unsigned width)
{
    m_width = width;
}

unsigned Rectangle::getHeight() const
{
    return m_height;
}

void Rectangle::setHeight(const unsigned height)
{
    m_height = height;
}

unsigned Rectangle::area() const
{
    return m_height * m_width;
}

Square::Square(const unsigned size)
    : Rectangle(size, size)
{
}

// Violates Liskov substitution principle
void Square::setWidth(const unsigned size)
{
    m_height = size;
    m_width = size;
}

// Violates Liskov substitution principle
void Square::setHeight(const unsigned size)
{
    m_height = size;
    m_width = size;
}

void process(Rectangle& r)
{
    unsigned h = 10;
    auto w = r.getWidth();
    r.setHeight(h);

    std::cout << "Expected area: " << (w*h) << ", got " << r.area() << "\n";
}

int main()
{
    Rectangle rectangle{3,4};
    Square square{5};
    process(rectangle);
    process(square);
}