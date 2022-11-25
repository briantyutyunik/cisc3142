#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<vector<string>> read_from_file(string filename)
{
    vector<vector<string>> vec;
    ifstream iFile(filename);

    string month;
    string temp;
    int x;
    while (iFile.good())
    {
        vector<string> curr_vec;
        getline(iFile, month, ',');
        getline(iFile, temp, '\n');

        curr_vec.push_back(month);
        curr_vec.push_back(temp);

        // cout << "Month: " << month << '\n';
        // cout << "Temp: " << temp << '\n';

        vec.push_back(curr_vec);
    }

    iFile.close();
    return vec;
}

void write_to_file(string filename, double simple_average, vector<double> moving_averages, vector<double> weighted_moving_averages)
{
    ofstream oFile(filename);

    oFile << "Simple Average: " << simple_average << endl;

    oFile << "Moving Averages: " << endl;
    for (double average : moving_averages)
    {
        oFile << average << endl;
    }
    oFile << "Weighted Moving Averages: " << endl;
    for (double average : weighted_moving_averages)
    {
        oFile << average << endl;
    }

    oFile.close();
}

double find_simple_average(vector<vector<string>> vec)
{
    double avg = 0;
    for (vector<string> v : vec)
    {
        avg += stoi(v[1]);
    }
    return avg / vec.size();
}

vector<double> find_moving_average(vector<vector<string>> vec)
{
    vector<double> moving_averages;
    double curr_avg = stoi(vec[0][1]) + stoi(vec[1][1]), count = 0;
    for (int i = 2; i < vec.size(); i++)
    {
        curr_avg += stoi(vec[i][1]);
        moving_averages.push_back(curr_avg / 3);
        curr_avg -= stoi(vec[i - 2][1]);
    }

    return moving_averages;
}
double find_weighted_average(vector<vector<string>> vec, int start_index)
{
    return double(stoi(vec[start_index][1]) + stoi(vec[start_index + 1][1]) * 2 + stoi(vec[start_index + 2][1]) * 3) / 6;
}

vector<double> find_weighted_moving_average(vector<vector<string>> vec)
{
    vector<double> weighted_averages;

    for (int i = 0; i < vec.size() - 2; i++)
    {
        weighted_averages.push_back(find_weighted_average(vec, i));
    }

    return weighted_averages;
}

int main()
{
    vector<vector<string>> vec = read_from_file("weather.csv");
    double simple_avg = find_simple_average(vec);
    vector<double> moving_averages = find_moving_average(vec);
    vector<double> weighted_moving_averages = find_weighted_moving_average(vec);

    write_to_file("results.txt", simple_avg, moving_averages, weighted_moving_averages);
    return 1;
}