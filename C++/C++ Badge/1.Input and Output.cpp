#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> numbers;
    int num;
    while(cin >> num) {
        numbers.push_back(num);
    }
    
    cout << accumulate(numbers.begin(), numbers.end(), 0) << endl;
}
