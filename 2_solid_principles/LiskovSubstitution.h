/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/14 */

#ifndef LISKOV_SUBSTITUTION_PRINCIPLE
#define LISKOV_SUBSTITUTION_PRINCIPLE

class Rectangle
{
    public:
        Rectangle(const unsigned width, const unsigned height);

        virtual void setWidth(const unsigned width);
        virtual unsigned getWidth() const;

        virtual void setHeight(const unsigned height);
        virtual unsigned getHeight() const;

        virtual unsigned area() const;

    protected:
        unsigned m_width;
        unsigned m_height;
};

class Square: public Rectangle
{
    public:
        Square(const unsigned size);

        void setWidth(const unsigned width) override;
        void setHeight(const unsigned width) override;
};

#endif