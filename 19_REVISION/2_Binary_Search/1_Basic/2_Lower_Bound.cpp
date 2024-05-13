
#include <bits/stdc++.h>
using namespace std;

// TC O(N)
int lowerBound(vector<int> arr, int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] >= x) {
            // lower bound found:
            return i;
        }
    }
    return n;
}


// TC O(log n)

int lowerBoundBS(vector<int> arr, int n, int x){
    int ans = x;

    int start = 0;
    int end = n-1;
    while (start <= end) {
        int mid = start + ((end-start)/2);
        if(arr[mid] >= x){
            ans = mid;
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}



int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    // int ind = lowerBound(arr, n, x);
    int ind = lowerBoundBS(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";
    ind = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    cout << "The lower bound is the index using cp algo: " << ind << "\n";
    return 0;
}


