#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    // Complete the code.
    vector<int> numbers;
    int num;
    while(cin >> num) {
        numbers.push_back(num);

        for(int i = numbers[0]; i< numbers[1]+1; i++)
        {
            switch(i){
                case 1:
                    cout << "one" << endl;
                    break;
                case 2:
                    cout << "two" << endl;
                    break;
                case 3:
                    cout << "three" << endl;
                    break;
                case 4:
                    cout << "four" << endl;
                    break;
                case 5:
                    cout << "five" << endl;
                    break; 
                case 6:
                    cout << "six" << endl;
                    break;
                case 7: 
                    cout << "seven" << endl;
                    break; 
                case 8: 
                    cout << "eight" << endl;
                    break;
                case 9:
                    cout << "nine" << endl;
                    break;
                default:
                    if(i%2 == 0)
                    {
                        cout << "even" << endl;
                    }
                    else
                    {
                        cout << "odd" << endl;
                    }
                    break;
            }
        }
    }

    return 0;
}
