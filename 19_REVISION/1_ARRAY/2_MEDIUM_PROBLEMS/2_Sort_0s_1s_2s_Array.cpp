#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// brute frce 
// O(Nlogn)

void sortArray(vector<int>& arr)
{
    // Write your code here
    int size = arr.size();
    for(int i=0;i < size;i++){
            int min_idx = i;

            for(int j=i+1;j<size;j++){
                if(arr[min_idx] > arr[j]){
                    // int temp = arr[min_idx];
                    // arr[min_idx] = arr[j];
                    // arr[j] = temp;
                    
                    swap(arr[min_idx],arr[j]);
                }
            }

    }
}


// Better O(N)
void sortArrayBetter(vector<int>& arr)
{
    // Write your code here
    int n = arr.size();
    int c1 =0 , c0 = 0 , c2=0;

    for(int i=0;i < n;i++){
        if(arr[i] == 0) c0++;
        if(arr[i] == 1) c1++;
        if(arr[i] == 2) c2++;

    }

    for(int i=0;i < c0;i++){
        arr[i] = 0;
    }

     for(int i=c0;i < c1+c0;i++){
        arr[i] = 1;
    }
     for(int i=c1+c0;i < n;i++){
        arr[i] = 2;
    }

}


// OPTIMAL Dutch National flag algorithm. 
// TC O(N)

void sortArrayOptimal(vector<int>& arr)
{
    int low = 0;
    int mid = 0;
    int high = arr.size() -1;

    while(mid <= high){

        // con1 mid == 0
        if(arr[mid] ==0 ){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }else if(arr[mid] == 1){
        // con2 mid == 1;
            mid++;
        }else{
        // con 3 mid == 2
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}


int main(){
   vector<int> ans = { 2, 2, 2, 2, 0, 0, 1, 0};
    // sortArray(ans);
    // sortArrayBetter(ans);
    sortArrayOptimal(ans);
   for(auto i :ans){
        cout << i << " ";
    }
return 0;
}