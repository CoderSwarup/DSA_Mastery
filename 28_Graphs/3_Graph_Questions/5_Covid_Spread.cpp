#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int row[4] = {-1, 1, 0, 0};
int col[4] = {0, 0, -1, 1};

bool valid(int i, int j, int r, int c) {
    return (i >= 0 && i < r && j >= 0 && j < c);
}

int helpaterp(vector<vector<int>> hospital) {
    int r = hospital.size();
    if (r == 0) return -1;  // Edge case: Empty hospital
    int c = hospital[0].size();

    // Queue for BFS
    queue<pair<int, int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hospital[i][j] == 2) {
                q.push(make_pair(i, j));
            }
        }
    }

    int Timer = 0;

    // BFS loop
    while (!q.empty()) {
        int curr_patient = q.size();
        bool found = false;  // To check if any new infections happened

        while (curr_patient--) {
            int i = q.front().first;
            int j = q.front().second;

            q.pop();

            for (int k = 0; k < 4; k++) {
                int ni = i + row[k];
                int nj = j + col[k];
                
                if (valid(ni, nj, r, c) && hospital[ni][nj] == 1) {
                    hospital[ni][nj] = 2;
                    q.push(make_pair(ni, nj));
                    found = true;
                }
            }
        }

        if (found) {
            Timer++;
        }
    }

    // Check if any fresh patients left
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (hospital[i][j] == 1) {
                return -1;
            }
        }
    }

    return Timer;
}

int main(){

    int r = 3, c = 5;
    vector<vector<int>> hospital = {
        {2, 1, 0, 2, 1},
        {1, 0, 1, 2, 1},
        {1, 0, 0, 2, 1}
    };

    int result = helpaterp(hospital);

    if (result == -1) {
        cout << "All patients cannot be infected." << endl;
    } else {
        cout << "Minimum time required to infect all patients: " << result << endl;
    }

return 0;
}