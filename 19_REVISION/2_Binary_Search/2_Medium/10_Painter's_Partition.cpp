#include<iostream>
using namespace std;
#include <bits/stdc++.h>


int isPossibleWay(vector<int> &boards, int n, int m, int mid) {
    int PainterCount = 1;
    int PaintTime = 0;

    for (int i = 0; i < n; i++) {
        if (PaintTime + boards[i] <= mid) {
            PaintTime += boards[i];
        } else {
            PainterCount++;

            if (PainterCount > m || boards[i] > mid) {
                return false;
            }
            PaintTime = boards[i];
        }
        if (PainterCount > m) {
            return false;
        }
    }

    return true;
}



int findLargestMinDistance(vector<int> &boards, int k)
{
    int sum = 0;

    for (int i = 0; i < boards.size(); i++) {
        sum += boards[i];
    }

    int ans = -1;

    int s = 0;
    int e = sum;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (isPossibleWay(boards, boards.size(), k, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main(){


    vector<int> arr = {5,10,30,20,15};
    int k = 3;
    cout << findLargestMinDistance(arr, k) << endl;
return 0;
}