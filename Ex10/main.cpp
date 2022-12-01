#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <numeric>

using namespace std;

struct FilmData
{
    int year;
    int length;
    string title;
    string subject;
    string actor;
    string actress;
    string directors;
    string popularity;
    int awards;
    string image;
};
vector<FilmData> read_from_file(string filename)
{
    vector<FilmData> vec;
    ifstream iFile(filename);
    FilmData currData;
    string line, tempstring = "";

    while (getline(iFile, line))
    {
        stringstream inputString(line);

        getline(inputString, tempstring, ';');
        currData.year = atoi(tempstring.c_str());
        getline(inputString, tempstring, ';');
        currData.length = atoi(tempstring.c_str());
        getline(inputString, currData.title, ';');
        getline(inputString, currData.subject, ';');
        getline(inputString, currData.actor, ';');
        getline(inputString, currData.actress, ';');
        getline(inputString, currData.directors, ';');
        getline(inputString, currData.popularity, ';');
        getline(inputString, tempstring, ';');
        currData.awards = atoi(tempstring.c_str());
        getline(inputString, currData.image);

        vec.push_back(currData);
    }

    iFile.close();
    return vec;
}

int sum_of_lengths(int accumulator, const FilmData &fd)
{
    return accumulator + fd.length;
}

int use_accumulate(vector<FilmData> vec)
{
    return accumulate(vec.begin(), vec.end(), 0, sum_of_lengths);
}

bool compare_by_popularity(const FilmData &a, const FilmData &b)
{
    return a.popularity > b.popularity;
}

bool use_unique(vector<FilmData> vec)
{
    vector<FilmData> action;
    vector<FilmData> comedy;

    for (FilmData fd : vec)
    {
        if (fd.subject == "Action")
            action.push_back(fd);
        else if (fd.subject == "Comedy")
            comedy.push_back(fd);

        vector<FilmData>::iterator action_iterator = unique(action.begin(),
                                                            action.end(),
                                                            [](const FilmData &a, const FilmData &b)
                                                            {
                                                                return a.year == b.year;
                                                            });
        vector<FilmData>::iterator comedy_iterator = unique(comedy.begin(),
                                                            comedy.end(),
                                                            [](const FilmData &a, const FilmData &b)
                                                            {
                                                                return a.year == b.year;
                                                            });
        return equal(action.begin(), action.end(), comedy.begin(), [](const FilmData &a, const FilmData &b)
                     { return a.year == b.year; });
    }
}

int main()
{
    vector<FilmData> vec = read_from_file("filmdata.csv");
    int accumulation = use_accumulate(vec);

    cout << "Accumulation: " << accumulation << endl;

    vector<FilmData> vec_to_sort = vec;

    sort(vec_to_sort.begin(), vec_to_sort.end(), compare_by_popularity);

    for (FilmData fd : vec_to_sort)
    {
        cout << fd.year << " " << fd.length << " " << fd.title << " " << fd.subject << " " << fd.actor << " " << fd.actress << " " << fd.directors << " " << fd.popularity << " " << fd.awards << " " << fd.image << endl;
    }

    auto first_occurance = find_if(vec.begin(), vec.end(), [](const FilmData &fd)
                                   { return 1946 == fd.year; });
    cout << first_occurance->year << " " << first_occurance->length << " " << first_occurance->title << " " << first_occurance->subject << " " << first_occurance->actor << " " << first_occurance->actress << " " << first_occurance->directors << " " << first_occurance->popularity << " " << first_occurance->awards << " " << first_occurance->image << endl;

    string isEqual = use_unique(vec) ? "Equal" : "Not Equal";

    cout << "The Action and Comedy lists are: " << isEqual << endl;

    return 1;
}