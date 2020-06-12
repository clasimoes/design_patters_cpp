/* Design Patterns in Modern C++ - Clarisse Simoes Ribeiro - 2020/06/11 */

#ifndef OPEN_CLOSED_PRINCIPLE
#define OPEN_CLOSED_PRINCIPLE

#include <string>
#include <vector>

using std::string;
using std::vector;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product
{
    string m_name;
    Color m_color;
    Size m_size;
};

template <typename T>
struct Specification
{
    virtual bool isSatisfied(const T* item) = 0;
};

template <typename T>
struct Filter
{
    virtual vector<T*> filter(vector<T*> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product>
{
    vector<Product*> filter(vector<Product*> items,
                             Specification<Product> &spec) override;
};

struct ColorSpecification: Specification<Product>
{
    explicit ColorSpecification(Color color);
    bool isSatisfied(const Product* item) override;

    Color m_color;
};

struct SizeSpecification: Specification<Product>
{
    explicit SizeSpecification(Size size);
    bool isSatisfied(const Product* item) override;

    Size m_size;
};


#endif