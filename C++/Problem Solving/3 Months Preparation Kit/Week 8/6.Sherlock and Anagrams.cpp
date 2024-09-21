#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'sherlockAndAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

int sherlockAndAnagrams(string s) {

}
int sherlockAndAnagrams(string s) {
    unordered_map<string, int> substr_count;
    int n = s.length();
    int anagram_pairs = 0;

    // Generate all possible substrings
    for (int i = 0; i < n; ++i) {
        for (int len = 1; len <= n - i; ++len) {
            string substr = s.substr(i, len);
            sort(substr.begin(), substr.end());
            substr_count[substr]++;
        }
    }

    // Count pairs of anagrams
    for (const auto& pair : substr_count) {
        int count = pair.second;
        anagram_pairs += (count * (count - 1)) / 2;
    }

    return anagram_pairs;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = sherlockAndAnagrams(s);

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
