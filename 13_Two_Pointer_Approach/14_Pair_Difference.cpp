#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void PrintArray(vector<int> &arr){
    int size = arr.size();

    for(int i=0;i<size;i++){
        cout << arr[i] << " ";
    }
}


void PairDiffUsingTwoPointer(vector<int> &arr,int target){

    int size = arr.size();
    int s = 0;
    int e = 1;
    vector<int> ans;


    while(s<size && e <size){
        int diff = arr[e] - arr[s];
        if(diff == target){
            ans.push_back(arr[s]);
            ans.push_back(arr[e]);
            break;
        }else if(diff < target){ // Here is diffrence is Low
            e++;
        }else{ // Here We Want Increase The Difference 
            s++;
        }

        // 
        if(s==e){
            e++;
        }
    }



   if(ans.size() != 2){
        cout << "NO Sum Found";
    }else{
        PrintArray(ans);
    }

}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5}; 
    
    PairDiffUsingTwoPointer(arr,6);

 

    
    return 0;
}
