#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
bool isSymbol(char c)
{
    return c != '.' && !isdigit(c);
}
bool isGear(char c)
{
    return c == '*';
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
std::vector<int> findAdjacentPartNumbers(int i, int j, const std::vector<std::string> &schematic)
{
    int rows = schematic.size();
    int cols = schematic[0].size();
    std::vector<int> partNumbers;

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            if (dx == 0 && dy == 0)
                continue;

            int x = i + dx;
            int y = j + dy;

            if (x >= 0 && x < rows && y >= 0 && y < cols && isdigit(schematic[x][y]))
            {
                int start = y;
                while (start > 0 && isdigit(schematic[x][start - 1]))
                {
                    --start;
                }

                int end = y;
                while (end < cols - 1 && isdigit(schematic[x][end + 1]))
                {
                    ++end;
                }

                if ((start == 0 || !isdigit(schematic[x][start - 1])) &&
                    (end == cols - 1 || !isdigit(schematic[x][end + 1])))
                {
                    int partNumber = std::stoi(schematic[x].substr(start, end - start + 1));
                    partNumbers.push_back(partNumber);
                }
            }
        }
    }

    return partNumbers;
}
int partTwo(const std::vector<std::string> &schematic)
{
    int sum = 0;

    for (int i = 0; i < schematic.size(); ++i)
    {
        for (int j = 0; j < schematic[i].size();)
        {
            if (schematic[i][j] == '*')
            {
                std::vector<int> partNumbers = findAdjacentPartNumbers(i, j, schematic);

                if (partNumbers.size() == 2)
                {
                    sum += partNumbers[0] * partNumbers[1];
                }

                ++j;
            }
            else if (isdigit(schematic[i][j]))
            {
                int end = j;

                while (end < schematic[i].size() && isdigit(schematic[i][end]))
                {
                    ++end;
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
    ifstream file("input/debuginput.txt");

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
    cout << "PartTwo: " << partTwo(schematic) << endl;

    return 0;
}