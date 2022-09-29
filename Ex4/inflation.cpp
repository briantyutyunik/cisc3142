#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double costOfItem, rateOfInflation;
    int numOfYears;

    cout << "Please enter the cost of the item: " << endl;
    cin >> costOfItem;
    cout << "Please enter the rate of inflation as a percentage (ex: 5.6): " << endl;
    cin >> rateOfInflation;
    cout << "Please enter the number of years from this year: " << endl;
    cin >> numOfYears;
    rateOfInflation /= 100;

    for (int i = 0; i < numOfYears; i++)
    {
        costOfItem += costOfItem * rateOfInflation;
    }
    cout << "The estimated cost after " << numOfYears << " is $" << costOfItem;

    return 0;
}