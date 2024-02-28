#include<iostream>
using namespace std;
#include <vector>
int singleNumber(vector<int>& nums) {
        int xor1 =0;
        for(int i=0;i<nums.size();i++){
            xor1 ^= nums[i];
        }

        return xor1;
    }
int main(){
    vector<int> arr = {1,2,1,3,4,4,3};
    cout << singleNumber(arr);

return 0;
}