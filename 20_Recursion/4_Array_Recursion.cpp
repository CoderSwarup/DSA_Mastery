#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void printArrayUsingRecursion(vector<int> arr , int i){
    if(i==0){
        cout << arr[i] << endl;
        return;
    }


    printArrayUsingRecursion(arr,i-1);
    cout << arr[i] << endl;
    // printArrayUsingRecursion(arr,i-1); // for Reverse
}

void printArrayUsingRecursionM2(vector<int> arr , int i){
    int n = arr.size();
    if(i==n){
        return;
    }


    // printArrayUsingRecursionM2(arr,i+1);// for Reverse
    cout << arr[i] << endl;
    printArrayUsingRecursionM2(arr,i+1);
}


int ArraySum(vector<int> arr , int i){

    // if(i==-1){
    //     return 0;
    // }


    // return arr[i]+ArraySum(arr,i-1); 

    if(i==arr.size()){
        return 0;
    }

    return arr[i]+ArraySum(arr,i+1);
}



void ArraySumWithArgs(vector<int> arr , int i,int sum){

    if(i==-1){
        cout << sum;
        return ;
    }

   

    sum += arr[i];
    ArraySumWithArgs(arr,i-1,sum);
}


int MinEle(vector<int> arr , int i){

    if(i==arr.size()-1){
        return arr[i];
    }

    return min(arr[i],MinEle(arr,i+1));
}


// Binary Search

bool BSSearchEle(vector<int> arr,int s, int e, int x){
    if(s>e){
        return false;
    }

    int mid = s + ((e-s)/2);
    if(arr[mid] == x){
        return true;
    }else if(arr[mid] < x){
        return BSSearchEle(arr,mid+1,e,x);
    }else{
        return BSSearchEle(arr,s,mid-1,s);
    }
}
int main(){

    vector<int> arr = {2,3,5,6};
    printArrayUsingRecursion(arr,arr.size()-1) ;

    cout <<  endl;

    printArrayUsingRecursionM2(arr,0);


    // 
    cout << endl << "Array Sum " << endl;
    // cout << ArraySum(arr,arr.size()-1) << endl;
    cout << ArraySum(arr,0) << endl;

    cout << endl << "Array Sum in Passing Argument" << endl;
    ArraySumWithArgs(arr,arr.size()-1,0);


    cout << endl << "Minimum Element In Array : " << endl;
    cout << MinEle(arr,0) << endl;


    
     cout << endl << "Find Element In Array Using Binary Search : " << endl;
     cout << BSSearchEle(arr,0,arr.size()-1,3);
return 0;
}