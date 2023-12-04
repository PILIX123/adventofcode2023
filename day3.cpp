#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
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
    return 0;
}