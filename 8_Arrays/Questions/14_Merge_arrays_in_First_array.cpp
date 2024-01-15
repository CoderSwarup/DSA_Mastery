#include<iostream>
using namespace std;
#include <vector>


//https://leetcode.com/problems/merge-sorted-array/description/


// int merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
//         int i =0;
//         int j =0;
//         while(i<m && j<n){
      
//    if(nums1[i] == 0){
//             i++;
//          }
//          if(nums2[j]== 0){
//             j++;
//          }

//          if(nums1[i]< nums2[j]){
//             nums1.insert(nums1.begin() +i,nums1[i]);
//             i++;
//          }
//          else{
//             nums1.insert(nums1.begin() +j,nums2[j]); 
//             j++;
//          }
//         }



//          while(i<m){
//             nums1.push_back(nums1[i]);
//               i++;
//         }

//          while(j<n){
//             nums1.push_back(nums2[j]);
//               j++;
//         }
  


// }


int main(){
vector<int> nums1 = {1,3,35};

// nums1.insert(nums1.begin() +1,54);

vector<int> nums2 = {0,2,4,17};

merge(nums1,nums1.size(),nums2,nums2.size());



for(int i=0; i < nums1.size();i++){
    cout << nums1[i]<< " ";
}


return 0;
}