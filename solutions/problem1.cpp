
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream gridFile("../inputs/grid.txt");
    ifstream dirFile("../inputs/directions.txt");
    
    if (!gridFile.is_open() || !dirFile.is_open()) {
        cout << "Error opening files\n";
        return 1;
    }

    vector<string> grid;
    string line;
    while (getline(gridFile, line)) {
        if (!line.empty())
            grid.push_back(line);
    }
    gridFile.close();

    string directions;
    getline(dirFile, directions);
    dirFile.close();

    int dirIndex = 0;
    for (int i = 0; i < grid.size(); i++) {
        if (dirIndex < directions.length()) {
            char dir = directions[dirIndex];
            if (dir == 'R') {
             
                if (!grid[i].empty()) {
                    char last = grid[i].back();
                    grid[i] = last + grid[i].substr(0, grid[i].length()-1);
                }
            } else if (dir == 'L') {
                
                if (!grid[i].empty()) {
                    char first = grid[i][0];
                    grid[i] = grid[i].substr(1) + first;
                }
            }
            dirIndex += 2; 
        }
    }

 
    int centralIndex = grid.size() / 2;
    string centralRow = grid[centralIndex];

    
    int sum = 0;
    for (char c : centralRow) {
        sum += (int)c;
    }

    cout << "Clue 1 = " << sum << endl;
    return 0;
}
