#include<iostream>
using namespace std;
#include <vector>

int findMaxConsecutiveOnes(vector<int>& nums) {
        int count =0;
        int maxConsecutiveOnes = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                count =0;
            }else{
                count++;
                maxConsecutiveOnes = max(maxConsecutiveOnes,count);
            }
        }

        return maxConsecutiveOnes;
}

int main(){
    vector<int>arr = {1,0,1,1,0,0};
    cout << findMaxConsecutiveOnes(arr);


return 0;
}