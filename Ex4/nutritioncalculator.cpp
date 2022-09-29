#include <iostream>
#include <vector>
using namespace std;

int main()
{
    double deadlyAmountToMice = 5;
    double massOfMouse = 35;
    // A can weighs 350 g and contains 0.1% (0.001) artificial sweetner therefore it contains 0.001 * 350 g of artificial sweetner
    double singleCanArtificialContent = 0.001 * 350;
    double endWeight;

    cout << "What weight would you like to stop dieting at? (in pounds)" << endl;
    cin >> endWeight;

    endWeight *= 454; // Get weight in grams

    double amountToKillHuman = (deadlyAmountToMice * endWeight) / massOfMouse;

    cout << "The amount of sodas you can have before death is: " << amountToKillHuman / singleCanArtificialContent;
    return 0;
}