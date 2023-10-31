#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Failing Test case 8 & 9 due to time limit exceeded.

priority_queue<int, vector<int>, greater<int>> heap;

void addElementToHeap(int x) {
    heap.push(x);
}

void deleteElementFromHeap(int x) {
    priority_queue<int, vector<int>, greater<int>> newHeap;
    while (!heap.empty()) {
        int top = heap.top();
        heap.pop();
        if (top != x) {
            newHeap.push(top);
        }
    }
    heap = newHeap;
}

void printMinElementFromHeap() {
    cout << heap.top() << endl;
}

int main() {
    int q;
    cin >> q;
    int element, type;

    while (q--) {
        cin >> type;
        switch (type) {
            case 1:
                cin >> element;
                addElementToHeap(element);
                break;
            case 2:
                cin >> element;
                deleteElementFromHeap(element);
                break;
            case 3:
                printMinElementFromHeap();
                break;
        }
    }

    return 0;
}