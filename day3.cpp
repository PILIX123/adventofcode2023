#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
bool isSymbol(char c)
{
    return c != '.' && !isdigit(c);
}

bool isPartNumber(int i, int start, int end, const vector<string> &schematic)
{
    int rows = schematic.size();
    int cols = schematic[0].size();

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            for (int j = start; j < end; ++j)
            {
                int x = i + dx;
                int y = j + dy;

                if (x >= 0 && x < rows && y >= 0 && y < cols && isSymbol(schematic[x][y]))
                {
                    return true;
                }
            }
        }
    }

    return false;
}

int partOne(vector<string> schematic)
{
    int sum = 0;

    for (int i = 0; i < schematic.size(); ++i)
    {
        for (int j = 0; j < schematic[i].size();)
        {
            if (isdigit(schematic[i][j]))
            {
                int end = j;

                while (end < schematic[i].size() && isdigit(schematic[i][end]))
                {
                    ++end;
                }

                int partNumber = stoi(schematic[i].substr(j, end - j));

                if (isPartNumber(i, j, end, schematic))
                {
                    sum += partNumber;
                }

                j = end;
            }
            else
            {
                ++j;
            }
        }
    }
    return sum;
}

int main()
{
    vector<string> schematic;
    ifstream file("input/inputday3.txt");

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            schematic.push_back(line);
        }
        file.close();
    }
    else
    {
        cout << "Unable to open file";
        return 1; // Exit with an error code
    }

    cout << "PartOne: " << partOne(schematic) << endl;

    return 0;
}