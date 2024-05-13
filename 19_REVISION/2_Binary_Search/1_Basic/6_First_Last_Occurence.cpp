#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// BruteForce 
// TC O(N)
vector<int> FirstLastOccurenceBrutForce(vector<int> arr,int k , int n){

    int first = -1;
    int last = -1;

    for(int i=0;i<arr.size();i++){
        if(arr[i] == k){
            if(first == -1) first = i;
            last = i;
        }
    }

    return {first ,last};
}


// Binary search
// TC O(logN)

int lowerBound(vector<int> arr,int k , int n){
    int ans = n;
    int s = 0;
    int e = arr.size() -1;

    while(s<=e){
        int mid = s+ ((e-s)/2);
        if(arr[mid] >= k){
            ans = mid;
            e = mid-1;
        }else{
            s= mid+1;

        }

    }

    return ans;
}


int upperbound(vector<int> arr,int k , int n){
    int ans = n;
    int s = 0;
    int e = arr.size() -1;

    while(s<=e){
        int mid = s+ ((e-s)/2);
        if(arr[mid] > k){
            ans = mid;
            e = mid-1;
        }else{
            s= mid+1;

        }

    }

    return ans;
}
vector<int> FirstLastOccurenceBinarySearch(vector<int> arr,int k , int n){

    int lb = lowerBound(arr,k,n);
    
    if(lb == n || arr[lb] != k) return {-1 ,-1};

    int up = upperbound(arr,k,n);
    return {lb,up-1};
   
}


// Simpae Binary 
// First Occurence 
int Foccurence(vector<int> arr,int k , int n){
    int ans = -1;
    int s =0;
    int l = arr.size()-1;
    while(s<=l){
        int mid = s + ((l-s)/2);
        if(arr[mid] == k){
            ans = mid;
            l = mid-1;
        }else if(arr[mid] > k){
            l = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans ;

}


int Loccurence(vector<int> arr,int k , int n){
    int ans = -1;
    int s =0;
    int l = arr.size()-1;
    while(s<=l){
        int mid = s + ((l-s)/2);
        if(arr[mid] == k){
            ans = mid;
            s= mid+1;
        }else if(arr[mid] > k){
            l = mid-1;
        }else{
            s = mid+1;
        }
    }
    return ans ;

}


int main(){

  int n = 7;
  int key = 13;

  vector < int > v = {3,4,13,13,13,20,40};
//   vector<int> ans = FirstLastOccurenceBrutForce(v, key, n);
  vector<int> ans = FirstLastOccurenceBinarySearch(v, key, n);
   
  cout << ans[0] << " " << ans[1] << "\n";


  cout << "Simple Binary  First Occurence " << Foccurence(v, key, n) << "\n";
  cout << "Simple Binary  Last Occurence " << Loccurence(v, key, n);
  

return 0;
}