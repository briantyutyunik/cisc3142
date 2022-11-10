#include <iostream>

using namespace ::std;
class Rectangle
{
public:
    float length = 0, width = 0;

    Rectangle(float length, float width)
    {
        this->length = length;
        this->width = width;
    }
    void setlength(float length)
    {
        this->length = length;
    }

    void setwidth(float width)
    {
        this->width = width;
    }
    float perimeter()
    {
        return 2 * (length + width);
    }
    float area()
    {
        return length * width;
    }
    void show()
    {
        cout << "Length: " << length << " Width: " << width << endl;
    }
    int sameArea(Rectangle rec)
    {
        if (area() == rec.area())
        {
            cout << "These rectangles have the same area." << endl;
            return 1;
        }
        cout << "These rectangles do not have the same area." << endl;
        return 0;
    }
};

int main()
{
    Rectangle rec1(5, 2.5);
    rec1.show();
    cout << "Perimeter: " << rec1.perimeter() << " Area: " << rec1.area() << endl;
    Rectangle rec2(5, 18.9);
    rec2.show();
    cout << "Perimeter: " << rec2.perimeter() << " Area: " << rec2.area() << endl;
    rec1.sameArea(rec2);
    rec1.setlength(15);
    rec1.setwidth(6.3);
    rec1.sameArea(rec2);
    return 1;
}