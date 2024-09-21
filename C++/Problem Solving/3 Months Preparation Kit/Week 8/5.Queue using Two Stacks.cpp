#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>

class QueueUsingTwoStacks {
private:
    stack<int> stackNewestOnTop, stackOldestOnTop;

    void shiftStacks() {
        if (stackOldestOnTop.empty()) {
            while (!stackNewestOnTop.empty()) {
                stackOldestOnTop.push(stackNewestOnTop.top());
                stackNewestOnTop.pop();
            }
        }
    }

public:
    void enqueue(int x) {
        stackNewestOnTop.push(x);
    }

    void dequeue() {
        shiftStacks();
        if (!stackOldestOnTop.empty()) {
            stackOldestOnTop.pop();
        }
    }

    int front() {
        shiftStacks();
        if (!stackOldestOnTop.empty()) {
            return stackOldestOnTop.top();
        }
        return -1; // or throw an exception
    }
};

int main() {
    QueueUsingTwoStacks q;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            q.enqueue(x);
        } else if (type == 2) {
            q.dequeue();
        } else if (type == 3) {
            cout << q.front() << endl;
        }
    }
    return 0;
}