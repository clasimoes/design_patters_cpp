#include "PrototypePattern.h"

#include <iostream>

Point::Point()
{
}

Point::Point(const int x, const int y):
    m_x{x},
    m_y{y}
{
}

Line::Line(const Point* start, const Point* end)
    : m_start(start), m_end(end)
{
}

Line::~Line()
{
    delete m_start;
    delete m_end;
}

Line Line::deep_copy() const
{
    Point* m_startCopy = new Point { this->m_start->m_x,
                                     this->m_start->m_y };
    Point* m_endCopy = new Point { this->m_end->m_x,
                                   this->m_end->m_y };
    Line lineCopy = Line { m_startCopy, m_endCopy };

    return lineCopy;
}

int main()
{
    Point x{1, 2};
    Point y{3, 4};
    Line l1 {&x, &y};
    Line l2 {l1};

    std::cout << "l1 start: " << l1.m_start->m_x << " " << l1.m_start->m_y << "\n";
    std::cout << "l1 end: " << l1.m_end->m_x << " " << l1.m_end->m_y << "\n";
    std::cout << "l2 start: " << l2.m_start->m_x << " " << l2.m_start->m_y << "\n";
    std::cout << "l2 end: " << l2.m_end->m_x << " " << l2.m_end->m_y << "\n";

    return 0;
}