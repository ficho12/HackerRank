#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);



/*
 * Complete the 'componentsInGraph' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts 2D_INTEGER_ARRAY gb as parameter.
 */

vector<int> componentsInGraph(vector<vector<int>> gb) {
    int n = gb.size();
    vector<int> parent(2 * n + 1, 0);
    vector<int> size(2 * n + 1, 1);

    for (int i = 1; i <= 2 * n; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < n; i++) {
        int u = gb[i][0];
        int v = gb[i][1];

        while (parent[u] != u) {
            u = parent[u];
        }

        while (parent[v] != v) {
            v = parent[v];
        }

        if (u != v) {
            parent[v] = u;
            size[u] += size[v];
            size[v] = 0;
        }
    }

    int minSize = 2 * n;
    int maxSize = 1;

    for (int i = 1; i <= 2 * n; i++) {
        if (size[i] > 1) {
            minSize = min(minSize, size[i]);
            maxSize = max(maxSize, size[i]);
        }
    }

    // Ensure the minimum size is at least 2
    if (minSize == 2 * n) {
        minSize = 2;
    }

    return {minSize, maxSize};
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> gb(n);

    for (int i = 0; i < n; i++) {
        gb[i].resize(2);

        string gb_row_temp_temp;
        getline(cin, gb_row_temp_temp);

        vector<string> gb_row_temp = split(rtrim(gb_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int gb_row_item = stoi(gb_row_temp[j]);

            gb[i][j] = gb_row_item;
        }
    }

    vector<int> result = componentsInGraph(gb);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << " ";
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
