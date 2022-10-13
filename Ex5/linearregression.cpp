#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// Write a program that reads a file containing a pair of numbers in each line(representing x y coordinates);
// at the end of reading this file compute the linear regression for this set of numbers.
// Please use to the linear regression formulas mentioned in class (if you missed class, find a classmate to get notes).

struct coordinates
{
    vector<double> xCoordinates;
    vector<double> yCoordinates;
};

coordinates
saveCoordinatesToVector()
{
    double x, y;
    vector<double> xCoordinates;
    vector<double> yCoordinates;

    while (cin >> x >> y)
    {
        xCoordinates.push_back(x);
        yCoordinates.push_back(y);
    }
    return {xCoordinates, yCoordinates};
}
double calculateMean(vector<double> vec)
{
    double currMean = 0;
    for (double val : vec)
    {

        currMean += val;
    }
    return currMean / vec.size();
}

double calculateSlope(vector<double> xCoordinates, vector<double> yCoordinates, double xMean, double yMean)
{
    double slopeNumerator = 0;
    double slopeDenominator = 0;
    for (int i = 0; i < xCoordinates.size(); i++)
    {
        slopeNumerator += (xCoordinates[i] - xMean) * (yCoordinates[i] - yMean);
        slopeDenominator += pow((xCoordinates[i] - xMean), 2.0);
    }
    return slopeNumerator / slopeDenominator;
}

double calculateIntercept(double yMean, double xMean, double slope)
{
    return yMean - slope * xMean;
}

int main()
{
    // double slope, intercept, numCount;
    coordinates currCoordinates = saveCoordinatesToVector();
    double xMean = calculateMean(currCoordinates.xCoordinates);
    double yMean = calculateMean(currCoordinates.yCoordinates);
    double slope = calculateSlope(currCoordinates.xCoordinates, currCoordinates.yCoordinates, xMean, yMean);
    double intercept = calculateIntercept(yMean, xMean, slope);

    cout << "The simple linear regression model is: y = " << intercept << " + " << slope << "x";
    return 1;
}