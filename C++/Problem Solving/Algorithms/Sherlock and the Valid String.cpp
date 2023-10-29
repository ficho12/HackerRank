#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    map<char, int> charFreq;
    for(int i=0;i<s.size();++i){
        charFreq[s[i]]++;
    }
    int maxFreq = 1;
    int minFreq = s.size(); 
    map<int,int> freqFreq;
    for (const auto & c: charFreq) {
        freqFreq[c.second]++; 
        if (c.second < minFreq) { 
            minFreq = c.second; 
        }
        if (c.second > maxFreq) { 
            maxFreq = c.second; 
        }
    }
    if (freqFreq.size() == 1) return "YES";
    if (freqFreq.size() == 2) {
        if (minFreq == 1 && freqFreq[minFreq] == 1) 
            return "YES";
        if ((maxFreq-minFreq) == 1 && freqFreq[maxFreq] == 1)
            return "YES";
    }
    return "NO";
}



int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}