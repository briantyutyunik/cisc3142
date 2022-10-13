#include <iostream>
using namespace std;
// Write a program that finds and prints all
// the prime numbers between 3 and 100. A prime number is a
// number such that 1 and itself are the only numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17,...).
int main()
{
    int currSum = 0;
    for (int i = 3; i <= 100; i += 2)
    {
        bool prime = true;
        for (int j = 3; j < i; j += 2)
        {
            if (i % j == 0)
                prime = false;
        }
        if (prime)
            cout << i << endl;
    }
    return 1;
}