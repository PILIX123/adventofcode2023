#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;
int main()
{
    ifstream infile("input/debuginput.txt");
    vector<string> inputList{};
    string line;
    while (getline(infile, line))
    {
        inputList.push_back(line);
    }
    infile.close();

    for (string line : inputList)
    {
        regex game("Game\\s(\\d+)");
        smatch game_match;
        int id;
        if (regex_search(line, game_match, game))
        {
            id = stoi(game_match[1]);
        }

        line = game_match.suffix().str();

        regex color("(\\d+)\\s(blue|red|green)");
        smatch color_match;
        stringstream colorStream(line);
        string draw;
        vector<pair<int, vector<pair<int, string>>>> draws{};
        int draw_number = 1;
        while (getline(colorStream, draw, ';'))
        {
            vector<pair<int, string>> colors{};
            while (regex_search(draw, color_match, color))
            {
                int amount = stoi(color_match[1]);
                string color = color_match[2];
                colors.push_back({amount, color});
                draw = color_match.suffix().str();
            }
            draws.push_back({draw_number++, colors});
        }
    }

    return 0;
}