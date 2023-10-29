#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;

vector<string> split(const string &str) {
    vector<string> tokens;
    istringstream iss(str);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    queue<int> q1;
    vector <string> stringVector;
    
    for (string line; std::getline(std::cin, line);) {
        stringVector = split(line);
        if (stringVector.empty()) {
            continue;  // Skip empty lines
        }

        switch(stringVector[0][0]) {
            case '1':
                if (stringVector.size() < 2) {
                    cerr << "Invalid input format for '1'" << endl;
                    break;
                }
                try {
                    q1.push(stoi(stringVector[1]));
                } catch (const std::invalid_argument& ia) {
                    std::cerr << "Invalid argument: " << ia.what() << '\n';
                } catch (const std::out_of_range& oor) {
                    std::cerr << "Out of range: " << oor.what() << '\n';
                }
                break;
        
            case '2':
                if (!q1.empty()) {
                    q1.pop();
                }
                break;

            case '3':
                if (!q1.empty()) {
                    cout << q1.front() << endl;
                }
                break;

            default:
                return 0;
        }
    }
    return 0;
}
