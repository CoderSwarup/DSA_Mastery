#include<iostream>
using namespace std;
#include <bits/stdc++.h>


bool possible(vector<int>& bloomDay, int m, int k, int day) {
    int bDays = 0;
    int count = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
        if (day >= bloomDay[i]) {
            count++;
        } else {
            bDays += (count / k);
            count = 0;
        }
    }
    bDays += (count / k);
    if (bDays >= m) {
        return true;
    }
    return false;
}

// bruteForce 
//TC O(MAXI-MINI) * O(N)
int minDays(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if((m*k) > n) return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++) {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    for (int i = mini; i <= maxi; i++) {
        if (possible(bloomDay, m, k, i))
            return i;
    }
    return -1;
}

int main(){



return 0;
}