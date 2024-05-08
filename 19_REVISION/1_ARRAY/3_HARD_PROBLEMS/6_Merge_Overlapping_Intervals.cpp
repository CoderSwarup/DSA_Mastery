#include<iostream>
using namespace std;
#include <bits/stdc++.h>
#include <algorithm>


// TC => O(N(LogN)) + O(2N)
//SC O(N)
vector<vector<int>> mergeOverlappingIntervalsBruteForce(vector<vector<int>> arr){

    sort(arr.begin() , arr.end());
    vector<vector<int>> ans;

    for(int i =0;i<arr.size() ;i++){

        int start = arr[i][0];
        int end = arr[i][1];


        // cout << start << " " << end <<"\n";

        if(!ans.empty() && end   <= ans.back()[1] ){
            continue;
        }


        for(int j=i+1;j<arr.size();j++){
            cout << arr[j][0] << "\n";
            if(arr[j][0] <= end){
                end = max(end,arr[j][1]);
            }else{
                break;
            }
        }

        ans.push_back({start,end});
    }

    return ans;
}


// TC =>  O(N*logN) + O(N),
// SC => O(N)
vector<vector<int>> mergeOverlappingIntervalsOptimal(vector<vector<int>> arr){

    sort(arr.begin() , arr.end());
    vector<vector<int>> ans;

    for(int i =0;i<arr.size() ;i++){

        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]);
        }else{
            ans.back()[1]=max(ans.back()[1],arr[i][1]);
        }

    }

    return ans;
}
int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    // vector<vector<int>> ans = mergeOverlappingIntervalsBruteForce(arr);
    vector<vector<int>> ans = mergeOverlappingIntervalsOptimal(arr);

    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}

