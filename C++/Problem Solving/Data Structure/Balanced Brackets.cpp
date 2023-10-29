#include <bits/stdc++.h>
#include <stack>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isBalanced(string S) {
    if (S.empty()) {
        return "YES";
    }
    // Create a new empty stack to track brackets
    stack<char> bracketStack;

    // Iterate over each character in the string
    for (char c : S) {
        if (c == '(' || c == '{' || c == '[') {
            // If the character is an opening bracket, push it onto the stack
            bracketStack.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            // If the character is a closing bracket, check if the top of the stack matches
            // If it does, pop the top of the stack and continue iterating.
            // If it doesn't, return 0 (invalid).
            if (bracketStack.empty()) return "NO";
            char top = bracketStack.top();
            bracketStack.pop();
            if (c == ')' && top != '(') return "NO";
            if (c == '}' && top != '{') return "NO";
            if (c == ']' && top != '[') return "NO";
        }
    }

    // If the stack is empty at the end of iteration, the string is valid
    // Otherwise, return "NO" (invalid).
    return bracketStack.empty() ? "YES" : "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

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
