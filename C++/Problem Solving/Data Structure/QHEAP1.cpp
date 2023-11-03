#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Failing Test case 8 & 9 due to time limit exceeded.

// priority_queue<int, vector<int>, greater<int>> heap;

// void addElementToHeap(int x) {
//     heap.push(x);
// }

// void deleteElementFromHeap(int x) {
//     priority_queue<int, vector<int>, greater<int>> newHeap;
//     while (!heap.empty()) {
//         int top = heap.top();
//         heap.pop();
//         if (top != x) {
//             newHeap.push(top);
//         }
//     }
//     heap = newHeap;
// }

// void printMinElementFromHeap() {
//     cout << heap.top() << endl;
// }

// int main() {
//     int q;
//     cin >> q;
//     int element, type;

//     while (q--) {
//         cin >> type;
//         switch (type) {
//             case 1:
//                 cin >> element;
//                 addElementToHeap(element);
//                 break;
//             case 2:
//                 cin >> element;
//                 deleteElementFromHeap(element);
//                 break;
//             case 3:
//                 printMinElementFromHeap();
//                 break;
//         }
//     }

//     return 0;
// }

void heapifyUp(vector<int> & qheap){
    int n = qheap.size() - 1;
    
    while (n > 0) {
        if (qheap[(n - 1) / 2] > qheap[n]) {
            int temp = qheap[n];
            qheap[n] = qheap[(n - 1) / 2];
            qheap[(n - 1) / 2] = temp;
        }
        n = (n - 1) / 2;
    }
}

void heapifyDown(vector<int> & qheap, int n){
    
    while (true) {
        int smallIndex = 2 * n + 1;
        
        if (smallIndex + 1 < qheap.size()) {
            
            if (qheap[smallIndex] > qheap[smallIndex + 1]) {
                smallIndex += 1;
            }
            
            if (qheap[n] > qheap[smallIndex]) {
                swap(qheap[n], qheap[smallIndex]);
                n = smallIndex;
                continue;
            }
            break;
        }
        
        if (smallIndex < qheap.size()) {
            if (qheap[n] > qheap[smallIndex]) {
                swap(qheap[n], qheap[smallIndex]);
                n = smallIndex;
                continue;
            }
            break;
        }
        
        break;
    }
}

int findIndex(vector<int> &qheap, int val){
    int index = 0;
    
    for (int i = 0; i < qheap.size(); i++) {
        if (qheap[i] == val) {
            index = i;
            break;
        }
    }
    
    return index;
}


int main() {
    
    int t;
    cin >> t;
    vector<int> qheap;
    
    for (int i = 0; i < t; i++) {
        int qtype;
        cin >> qtype;
        
        if (qtype == 1) {
            int n;
            cin >> n;
            
            qheap.push_back(n);
            heapifyUp(qheap);
        }
        
        else if (qtype == 2) {
            int n;
            cin >> n;
            
            int index = findIndex(qheap, n);
            
            if (qheap.size() > 0) {
                qheap[index] = qheap.back();
                qheap.pop_back(); 
                heapifyDown(qheap, index);
            }
        }
        
        else if (qtype == 3) {
            if (qheap.size() > 0) {
                cout << qheap[0] << endl;
            }
        }
    } 
    
    return 0;
}