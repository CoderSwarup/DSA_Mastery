#include<iostream>
using namespace std;
#include <vector>

 vector<int> merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i =0;
        int j =0;
        vector<int> thirdArray;
        while(i<m && j<n){
            // cout << i << j << endl;
            if(nums1[i] < nums2[j]){
                thirdArray.push_back(nums1[i]);
                i++;
            }else{
                 thirdArray.push_back(nums2[j]);
                 j++;
            }
        }

        while(i<m){
            
            thirdArray.push_back(nums1[i]);
              i++;
        }

         while(j<n){
            thirdArray.push_back(nums2[j]);
              j++;
        }


        return thirdArray;
}

int main(){

vector<int> nums1 = {1,3,35};

vector<int> nums2 = {0,2,4,17,78};


vector<int> arr = merge(nums1,nums1.size(),nums2,nums2.size());




for(int i=0; i < arr.size();i++){
    cout << arr[i]<< " ";
}


return 0;
}