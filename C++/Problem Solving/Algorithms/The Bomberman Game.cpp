#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'bomberMan' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING_ARRAY grid
 */
vector<string> bomberMan(int n, vector<string> grid) {
    int r = grid.size();
    int c = grid[0].size();
    int secondsPassed = 1;

    vector<string> lastGrid = grid;
    vector<string> fullGrid(r, string(c, 'O'));

    if (n == 1) { // If n is 1 then the grid will be the same as the initial grid.
        return grid;
    }else if(n%2 == 0) { // If n is even, then the grid will be full of bombs. We don't need to calculate the outcome.
        return fullGrid;
    }else if(n%4 == 3)  // If if n = 3, 7, 11, 15, 19,23 = if (n)%4==3 -> flip once
    {
        n = 3;
    } else if (n%4 == 1) // If n = 5, 9, 13, 17, 21, 25 = if (n)%4==1 -> flip twice
    {
        n = 5;
    }
    // If n is odd and 2 seconds have passed, then we need to calculate the outcome.
    do{
        grid = fullGrid;
        secondsPassed++;
        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++) {
                //grid[i][j] = 'O';
                if(lastGrid[i][j] == 'O') {
                    grid[i][j] = '.';
                    if(i-1 >= 0)
                        grid[i-1][j] = '.';
                    if(i+1 < r)
                        grid[i+1][j] = '.';
                    if(j-1 >= 0)
                        grid[i][j-1] = '.';
                    if(j+1 < c)
                        grid[i][j+1] = '.';
                }
            }
        }
        lastGrid = grid;
        secondsPassed++;
    }while(secondsPassed < n);

    return grid;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int r = stoi(first_multiple_input[0]);

    int c = stoi(first_multiple_input[1]);

    int n = stoi(first_multiple_input[2]);

    vector<string> grid(r);

    for (int i = 0; i < r; i++) {
        string grid_item;
        getline(cin, grid_item);

        grid[i] = grid_item;
    }

    vector<string> result = bomberMan(n, grid);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
