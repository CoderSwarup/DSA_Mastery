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


bool BinarySearch(vector<int> &arr,int target,int s, int e){
       int size = arr.size();
    //    cout << target;

       while(s<=e){
            int mid = s + (e-s)/2;
            if(target == arr[mid]){
                return true;
            }else if(target > arr[mid]){
                s= mid+1;
            }
            else{
                e = mid -1;
            }

       }


       return false;
}


// Time Complexity = O(N * log(N))
void TwoSumUsingBinary(vector<int> &arr,int target){
    int size = arr.size();
      vector<int> ans;


    for(int i=0;i<size -1;i++){
        int x = target - arr[i];
        int s = i+1;
        int e = size-1;

        bool isAns = BinarySearch(arr,x,s,e);
        if(isAns){
            ans.push_back(arr[i]) ;
            ans.push_back(x) ;
            break;
        }


    }


    if(ans.size() != 2){
        cout << "NO Sum Found";
    }else{
        PrintArray(ans);
    }
}


void TwoSumUsingTwoPointer(vector<int> &arr,int target){

    int size = arr.size();
    int s = 0;
    int e = size -1;
    vector<int> ans;


    while(s<=e){
        int sum = arr[s] + arr[e];
        if(sum == target){
            ans.push_back(arr[s]);
            ans.push_back(arr[e]);
            break;
        }else if(sum > target){
            e--;
        }else{
            s++;
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

    // PrintArray(arr);

    // TwoSumUsingBinary(arr,81);
    TwoSumUsingTwoPointer(arr,81);

 

    
    return 0;
}
