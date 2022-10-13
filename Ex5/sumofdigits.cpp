#include <iostream>
using namespace std;
// Calculate the sum of digits of a number.
// The program prompts the user to enter the number. For example:
//  Enter number: 7865 The output should be 7+ 8 + 6 + 5 = 26
int main()
{
    int num;
    cout << "Please enter a number" << endl;
    cin >> num;

    int currNum = 0;

    while (num != 0)
    {
        currNum += num % 10;
        num /= 10;
    }

    cout << currNum;

    return 1;
}