#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// Needs to be done again
/*
 * Complete the 'legoBlocks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER m
 */

const int MOD = 1e9 + 7;

int legoBlocks(int n, int m) {
    
    vector<int> permutations = {1, 1, 2, 4, 8};
    for (int i = 5; i <= m; i++) {
        int sum = 0;
        for (int j = i - 4; j < i; j++) {
            sum += permutations[j];
            sum %= MOD;
        }
        permutations.push_back(sum);
    }

    vector<int> totals;
    for (int perm : permutations) {
        long long total = 1;
        for (int row = 0; row < n; row++) {
            total = (total * perm) % MOD;
        }
        totals.push_back(static_cast<int>(total));
    }

    vector<int> invalid = {0, 0};
    for (int i = 2; i <= m; i++) {
        int j = i;
        int sum = 0;
        for (int t = 1; t < j; t++) {
            long long var = (totals[t] - invalid[t] + MOD) % MOD;
            sum += (var * totals[j - t]) % MOD;
            sum %= MOD;
        }
        invalid.push_back(sum);
    }

    int result = totals[m] - invalid[m];
    return result < 0 ? result + MOD : result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int result = legoBlocks(n, m);

        fout << result << "\n";
    }

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
