/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/11 */

#include "OpenClosed.h"

#include <iostream>

vector<Product*> BetterFilter::filter(vector<Product*> items,
                                      Specification<Product> &spec)
{
    vector<Product*> result;
    for (auto &item : items)
    {
        if (spec.isSatisfied(item))
        {
            result.push_back(item);
        }
    }

    return result;
}

ColorSpecification::ColorSpecification(Color color):m_color(color)
{
}

bool ColorSpecification::isSatisfied(const Product* item)
{
    return (m_color == item->m_color);
}

SizeSpecification::SizeSpecification(Size size):m_size(size)
{
}

bool SizeSpecification::isSatisfied(const Product* item)
{
    return (m_size == item->m_size);
}

int main()
{
    Product apple{"Apple", Color::green, Size::small};
    Product tree{"Tree", Color::green, Size::large};
    Product house{"House", Color::blue, Size::large};

    const vector<Product*> items {&apple, &tree, &house};
    BetterFilter bf;
    ColorSpecification greenSpec(Color::green);
    SizeSpecification sizeSpec(Size::small);

    for (auto& item: bf.filter(items, greenSpec))
    {
        std::cout << item->m_name << " is green.\n";
    }

    for (auto& item: bf.filter(items, sizeSpec))
    {
        std::cout << item->m_name << " is small.\n";
    }

    return 0;
}