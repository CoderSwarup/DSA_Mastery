#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// breute Force 
int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
    // code here
    int Count_Max = 0;
    int count_index = -1;
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j =0; j<m;j++){
            if(arr[i][j] == 1){
                cnt++;
            }
        }
        
        if(cnt > Count_Max){
            Count_Max = cnt;
            count_index = i;
        }
    }
    
    return count_index;
}



// binary search 

 int lowerBound(vector<int> arr,int n){
    int low =0;
    int high = n-1;
    int ans = n;
    while(low <= high ){
        int mid = low + ((high-low)/2);
        if(arr[mid] >= 1){
            ans = mid;
            high = mid -1;
        }else{
            low = mid +1;
        }
    }
    
   return ans; 
}        
    
    
int rowWithMax1sBS(vector<vector<int> > arr, int n, int m) {
    // code here
    int Count_Max = 0;
    int count_index = -1;
    for(int i=0;i<n;i++){
        int cnt =m- lowerBound(arr[i],m);
        if(cnt>Count_Max){
            Count_Max = cnt;
            count_index = i;
        }
    
    }
    
   
    
    return count_index;
}
int main(){


    vector<vector<int>> arr =
           {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}};

    // cout << rowWithMax1s(arr, arr.size(), arr[0].size());
    cout << rowWithMax1sBS(arr, arr.size(), arr[0].size());



return 0;
}