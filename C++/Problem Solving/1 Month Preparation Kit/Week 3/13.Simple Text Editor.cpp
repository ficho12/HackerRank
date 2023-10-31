#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

string s;
vector<string> history;

void append(string w) {
    history.push_back(s);
    s += w;
}

void deleteLast(int k) {
    history.push_back(s);
    s = s.substr(0, s.length() - k);
}

void print(int k) {
    cout << s[k - 1] << endl;
}

void undo() {
    s = history.back();
    history.pop_back();
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            string w;
            cin >> w;
            append(w);
        } else if (type == 2) {
            int k;
            cin >> k;
            deleteLast(k);
        } else if (type == 3) {
            int k;
            cin >> k;
            print(k);
        } else if (type == 4) {
            undo();
        }
    }
    return 0;
}
