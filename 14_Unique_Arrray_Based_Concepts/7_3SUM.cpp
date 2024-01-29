#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>
//brute Force Approach
// TC O(n3)

void ThreeSUM(vector<int> arr,int target){
    int n = arr.size();
    bool isAns = false;
    for(int i =0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            for(int k= j+1;k<n;k++){
                if(arr[i]+arr[j]+arr[k] == target){
                    cout <<"Triplet is : "<<arr[i]<<" "<<arr[j]<<" "<<arr[k];
                    isAns = true;
                    return ;
                }
            }
        }
    }

    if(!isAns){
        cout << "Target is Not Present";
    }
}




//Using the Binary Search Approach 
// TC O(n^2 log(n))

bool BinarySearch(vector<int> arr,int s,int e,int target){
    while (s <= e) {

        int mid = s+(e-s)/2;
        if(arr[mid] == target){
            return true;
        }else if(target > arr[mid] ){
            s=mid+1;
        }else{
            e=mid-1;
        }
    }

    return false;
}



void ThreeSumBinarySearch(vector<int> arr,int target){
    int n = arr.size();

    bool isAns = false;
    for(int i =0;i<n-2;i++){
        for(int j = i+1;j<n-1;j++){
            int newTarget = target - (arr[i] + arr[j]);
            int start = j+1;
            int end = n-1;

            if(BinarySearch(arr,start,end,newTarget)){
                cout <<"Triplet is Using Binary Search : "<<arr[i]<<" "<<arr[j]<<" "<<newTarget;
                isAns = true;
                break;
            }

        }
    }


    if(!isAns){
        cout << "Target is Not Present";
    }
}



// Using Two Pointer 
// TC  O(log(n)) + O(n^2)  == O(n^2)
void ThreeSumTwoPointer(vector<int> arr,int target){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    bool isAns = false;
    for(int i =0;i<n-2;i++){
        int s = i+1;
        int e = n-1;
        int newTarget = target - arr[i];

        while(s<=e){
            int Sum = arr[s] + arr[e];
            if(Sum == newTarget){
                cout <<"Triplet is Using Binary Search : "<<arr[i]<<" "<<arr[s]<<" "<<arr[e];
                isAns = true;
                break;
            }else if(Sum > newTarget){
                e--;
            }else{
                s++;
            }
        }
    }



      if(!isAns){
        cout << "Target is Not Present";
    }
}
int main(){

    vector<int> arr = {1,4,45,6,10,8};
    ThreeSUM(arr,15); // TC O(n3)
    cout <<endl;
    ThreeSumBinarySearch(arr,20); // TC O(n^2 log(n))
    cout <<endl;
    ThreeSumTwoPointer(arr,15);// TC  O(log(n)) + O(n^2)  == O(n^2)


return 0;
}