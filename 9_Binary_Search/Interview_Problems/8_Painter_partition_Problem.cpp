#include<iostream>
using namespace std;

// https://www.codingninjas.com/studio/problems/painter-s-partition-problem_1089557?leftPanelTabValue=PROBLEM
int isPossibleWay(int arr[], int n, int m, int mid) {
    int PainterCount = 1;
    int PaintTime = 0;

    for (int i = 0; i < n; i++) {
        if (PaintTime + arr[i] <= mid) {
            PaintTime += arr[i];
        } else {
            PainterCount++;

            if (PainterCount > m || arr[i] > mid) {
                return false;
            }
            PaintTime = arr[i];
        }
        if (PainterCount > m) {
            return false;
        }
    }

    return true;
}

int PaintMinTime(int arr[], int n, int m) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    int ans = -1;

    int s = 0;
    int e = sum;
    int mid = s + (e - s) / 2;

    while (s <= e) {
        if (isPossibleWay(arr, n, m, mid)) {
            ans = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }

    return ans;
}

int main() {
    int arr[2] = {48,90};
    cout << PaintMinTime(arr, 2, 2);
    // int arr[4] = {10, 20, 30, 40};
    // cout << PaintMinTime(arr, 4, 2);

    return 0;
}
