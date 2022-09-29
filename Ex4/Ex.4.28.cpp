#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "Size of short: " << sizeof(short) << endl
         << "Size of int: " << sizeof(int) << endl
         << "Size of int*: " << sizeof(int *) << endl
         << "Size of bool: " << sizeof(bool) << endl
         << "Size of char: " << sizeof(char) << endl
         << "Size of wchar_t: " << sizeof(wchar_t) << endl
         << "Size of char16_t: " << sizeof(char16_t) << endl
         << "Size of char32_t: " << sizeof(char32_t) << endl
         << "Size of long: " << sizeof(long) << endl
         << "Size of long long: " << sizeof(long long) << endl
         << "Size of long long: " << sizeof(long long) << endl
         << "Size of long double: " << sizeof(long double) << endl
         << "Size of double: " << sizeof(double) << endl
         << "Size of float: " << sizeof(float) << endl;
    return 0;
}