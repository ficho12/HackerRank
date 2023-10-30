#include<bits/stdc++.h>

using namespace std;

//Define the structs Workshops and Available_Workshops.
struct Workshop {
    int start_time;
    int duration;
};

struct Available_Workshops {
    int n;
    Workshop* workshops;
};

//Implement the functions initialize and CalculateMaxWorkshops
Available_Workshops* initialize(int start_time[], int duration[], int n) {
    Available_Workshops* ptr = new Available_Workshops;
    ptr->n = n;
    ptr->workshops = new Workshop[n];
    for (int i = 0; i < n; i++) {
        ptr->workshops[i].start_time = start_time[i];
        ptr->workshops[i].duration = duration[i];
    }
    sort(ptr->workshops, ptr->workshops + n, [](const Workshop& a, const Workshop& b) {
        return a.start_time + a.duration < b.start_time + b.duration;
    });
    return ptr;
}

int CalculateMaxWorkshops(Available_Workshops* ptr) {
    int n = ptr->n;
    int max_workshops = 0;
    int current_end_time = 0;
    for (int i = 0; i < n; i++) {
        if (ptr->workshops[i].start_time >= current_end_time) {
            max_workshops++;
            current_end_time = ptr->workshops[i].start_time + ptr->workshops[i].duration;
        }
    }
    return max_workshops;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
