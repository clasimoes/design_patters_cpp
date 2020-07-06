struct Point
{
    Point();

    Point(const int x, const int y);

    int m_x{0}, m_y{0};
};

struct Line
{
    Line(const Point* start, const Point* end);

    ~Line();

    Line deep_copy() const;

    const Point* m_start;
    const Point* m_end;
};