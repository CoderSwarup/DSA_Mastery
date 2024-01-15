#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>


void printArray(vector<int>arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}


// two pointer approch which is first index is from arr1length -1 and second index is an the arr2 [0] index
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
    int leftindex = m-1;
    int rightindex = 0;


    while(leftindex >= 0 && rightindex < n){
        if(nums1[leftindex] > nums2[rightindex]){
            swap(nums1[leftindex] , nums2[rightindex]);
        leftindex--;
        rightindex++;

        }else{
            break;
        }
    }
    sort(nums1.begin(),nums1.end());
    // printArray(nums1);
     sort(nums2.begin(),nums2.end());
    // printArray(nums2);
}


// Opmtimal solution usin gap method 
void SwapGreater(vector<int>& arr1, vector<int>& arr2, int index1 , int index2){
    if(arr1[index1] > arr2[index2]){
        swap(arr1[index1] , arr2[index2]);
    }
    
}



void mergegapMethdod(vector<int>& nums1, int n, vector<int>& nums2, int m){
    int len = n+m;
    int gap = (len/2) + (len%2);


    while(gap>0){
        int left = 0;
        int right = left  + gap;


        while(right < len){

            // arr1 and arr2 
            if (left<n && right>=n){
                SwapGreater(nums1,nums2,left,right-n);// right - len of left array
           
            } else if(left>=n){
                // arr 2 and arr 2
                SwapGreater(nums2,nums2,left - n ,right-n);  
            }else{
                // arr1 and arr1
                 SwapGreater(nums1,nums1,left,right);
            }

            left++;
            right++;
   
        }
             if(gap == 1) return;
        gap = (gap/2) + (gap%2);
    }
}




int main(){

vector<int> nums1 = {1,3,35};

// nums1.insert(nums1.begin() +1,54);

vector<int> nums2 = {0,2,4,17};

// merge(nums1,nums1.size(),nums2,nums2.size());

mergegapMethdod(nums1,nums1.size(),nums2,nums2.size());

printArray(nums1);
printArray(nums2);


return 0;
}