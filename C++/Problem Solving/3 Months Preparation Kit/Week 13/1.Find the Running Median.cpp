#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'runningMedian' function below.
 *
 * The function is expected to return a DOUBLE_ARRAY.
 * The function accepts INTEGER_ARRAY a as parameter.
 */

vector<double> runningMedian(vector<int> a) {
    vector<double> medians;
    priority_queue<int> lowers; // Max-heap for the lower half
    priority_queue<int, vector<int>, greater<int>> highers; // Min-heap for the upper half

    for (int num : a) {
        if (lowers.empty() || num < lowers.top()) {
            lowers.push(num);
        } else {
            highers.push(num);
        }

        // Balance the heaps
        if (lowers.size() > highers.size() + 1) {
            highers.push(lowers.top());
            lowers.pop();
        } else if (highers.size() > lowers.size()) {
            lowers.push(highers.top());
            highers.pop();
        }

        // Calculate the median
        if (lowers.size() == highers.size()) {
            medians.push_back((lowers.top() + highers.top()) / 2.0);
        } else {
            medians.push_back(lowers.top());
        }
    }

    return medians;
}
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string a_count_temp;
    getline(cin, a_count_temp);

    int a_count = stoi(ltrim(rtrim(a_count_temp)));

    vector<int> a(a_count);

    for (int i = 0; i < a_count; i++) {
        string a_item_temp;
        getline(cin, a_item_temp);

        int a_item = stoi(ltrim(rtrim(a_item_temp)));

        a[i] = a_item;
    }

    vector<double> result = runningMedian(a);

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
