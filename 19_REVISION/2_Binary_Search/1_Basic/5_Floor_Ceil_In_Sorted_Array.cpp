#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int findFloor(vector<int> arr , int x){
    int n = arr.size() ;
    int ans = -1;

    int low = 0;
    int high = n -1;

    while(low <= high){
        int mid = low + ((high -low) /2);
        if(arr[mid] <= x){
            ans = arr[mid];
            low = mid +1;
        }else{
            high = mid-1;
        }
    }

    return ans;
}

int findCeil(vector<int> arr , int x){
    int n = arr.size() ;
    int ans = -1;

    int low = 0;
    int high = n -1;

    while(low <= high){
        int mid = low + ((high -low) /2);
        if(arr[mid] >= x){
            ans = arr[mid];
           high = mid -1;
        }else{
            low = mid +1;
        }
    }

    return ans;
}

vector<int> floorCeil(vector<int> arr , int x){

    int floor = findFloor( arr ,  x);
    int ceil = findCeil(arr ,  x);

    return {floor ,ceil};
}

int main(){

    vector<int > arr ={3, 4, 4, 7, 8, 10};
    int  x= 5;
    vector<int > ans = floorCeil(arr,x);

    cout << ans[0] << " " <<ans[1];


return 0;
}