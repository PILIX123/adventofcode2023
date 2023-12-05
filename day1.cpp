#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>

using namespace std;
int partOne(vector<string> inputList)
{
    int output = 0;
    for (int x = 0; x < inputList.size(); x++)
    {
        string currLine = inputList[x];
        int val = 0;
        vector<int> listOfInt = {};
        for (string::iterator it = currLine.begin(); it != currLine.end(); ++it)
        {
            if (isdigit(*it))
            {
                int i = *it - '0';
                listOfInt.push_back(i);
            }
        }

        if (listOfInt.size() == 0)
        {
            break;
        }
        if (listOfInt.size() < 2)
        {
            val += listOfInt[0] * 10 + listOfInt[0];
        }
        else
        {
            val += listOfInt[0] * 10 + listOfInt[listOfInt.size() - 1];
        }
        output += val;
    }

    return output;
}

int partTwo(vector<string> inputList)
{
    map<string, int> numbers = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };
    int output = 0;

    vector<string> keys;
    for (const auto &pair : numbers)
    {
        keys.push_back(pair.first);
    }

    for (int x = 0; x < inputList.size(); x++)
    {
        vector<pair<int, int>> posValList = {};
        int val = 0;
        for (string key : keys)
        {
            size_t pos = 0;
            while ((pos = inputList[x].find(key, pos)) != std::string::npos)
            {
                posValList.push_back({pos, numbers.at(key)});
                pos += key.length();
            }
        }
        for (int i = 0; i < inputList[x].size(); ++i)
        {
            if (isdigit(inputList[x][i]))
            {
                int val = inputList[x][i] - '0';
                posValList.push_back({i, val});
            }
        }
        sort(posValList.begin(), posValList.end(), [](const auto &a, const auto &b)
             { return a.first < b.first; });
        if (posValList.size() == 0)
        {
            break;
        }
        if (posValList.size() < 2)
        {
            val += get<1>(posValList[0]) * 10 + get<1>(posValList[0]);
        }
        else
        {
            val += get<1>(posValList[0]) * 10 + get<1>(posValList[posValList.size() - 1]);
        }
        output += val;
    }

    return output;
}

int main()
{
    ifstream infile("input/inputday1.txt");
    vector<string> inputList{};
    string line;
    while (getline(infile, line))
    {
        inputList.push_back(line);
    }
    infile.close();

    cout << partOne(inputList) << endl;
    cout << partTwo(inputList) << endl;
}