#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'noPrefix' function below.
 *
 * The function accepts STRING_ARRAY words as parameter.
 */

void noPrefix(vector<string> words) {
    unordered_set<string> part, full;
    int len = words.size();
    for (int i = 0; i < words.size(); ++i) {
        string temp = words[i];
        if (part.count(temp) > 0) {
            cout<<"BAD SET\n"<<temp;
            return;
        }
        for (int j = 1; j <= temp.length(); ++j) {
            string substring = temp.substr(0, j);
            if (full.count(substring) > 0) {
                cout<<"BAD SET\n"<<temp;
                return;
            }
            part.emplace(substring);
        }
        full.emplace(words[i]);
    }
    cout<<"GOOD SET";
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<string> words(n);

    for (int i = 0; i < n; i++) {
        string words_item;
        getline(cin, words_item);

        words[i] = words_item;
    }

    noPrefix(words);

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
