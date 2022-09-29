#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    string input;
    vector<string> vec;
    cout << "Please enter a sequence of words! Enter . at the end of the sequence." << endl;

    while (cin >> input)
    {
        if (input == ".")
            break;
        vec.push_back(input);
    }

    int counter = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i][0] = toupper(vec[i][0]);
        cout << vec[i] << " ";
        if (counter++ % 8 == 0)
            cout << endl;
    }

    return 0;
}