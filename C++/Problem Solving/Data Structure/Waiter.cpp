#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'waiter' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY number
 *  2. INTEGER q
 */

vector<int> waiter(vector<int> number, int q) {
    vector<int> result;
    vector<int> primes;
    vector<int> A, B;  // Use vectors instead of stacks

    // Generate prime numbers up to q
    int i = 2;
    while (primes.size() < q) {
        bool isPrime = true;
        for (int j = 2; j <= sqrt(i); j++) {
            if (i % j == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) primes.push_back(i);
        i++;
    }

    for (int i = 0; i < q; i++) {
        vector<int> newA, newB;  // Use vectors for newA and newB

        for (int j = number.size() - 1; j >= 0; j--) {
            int n = number[j];

            if (n % primes[i] == 0) {
                newB.push_back(n);
            } else {
                newA.push_back(n);
            }
        }

        // Append elements from newB to the result
        for (int j = newB.size() - 1; j >= 0; j--) {
            result.push_back(newB[j]);
        }

        // Set newA as the new number stack for the next iteration
        number = newA;
    }

    // Append remaining elements from the number vector to the result
    for (int i = number.size() - 1; i >= 0; i--) {
        result.push_back(number[i]);
    }

    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int q = stoi(first_multiple_input[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split(rtrim(number_temp_temp));

    vector<int> number(n);

    for (int i = 0; i < n; i++) {
        int number_item = stoi(number_temp[i]);

        number[i] = number_item;
    }

    vector<int> result = waiter(number, q);

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
