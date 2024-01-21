#include<iostream>
using namespace std;
#include<vector>


int FindMajority(vector<int> &arr){

    // for(int i=0;i<arr.size();i++){
    //     ans ^=ans^arr[i];
    // }

    int candidate =0;
    int count = 0;

    for(int i=0;i<arr.size();i++){
        if(cout==0){
            candidate = arr[i];
            cout++ ;
        }else{
            
            if(candidate == arr[i]){
                count++;
            }else{
                count--;
            }
        }
    }

    int occurence = 0;
    for(int i=0;i<arr.size();i++){
        if(arr[i] == candidate){
            occurence++;
        }
    }   

    if(occurence > (arr.size()/2)){
        return candidate;
    }else{
        return -1;
    }
}

int main(){

    vector<int> arr = {3,3,7,39,1,2,3,3};
    cout << FindMajority(arr) ;

return 0;
}