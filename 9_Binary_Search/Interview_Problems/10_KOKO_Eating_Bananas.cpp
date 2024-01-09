#include<iostream>
using namespace std;
#include <bits/stdc++.h>

   int minEatingSpeed(vector<int>& piles, int h) {
        int s =0 ,e =0 , mid , n = piles.size();
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += piles[i];
            if(piles[i]>=e){
                e = piles[i];
            }
           
        }

        s = sum /h;
        int ans = -1;
        // if The sum is less than hours then its return 0 
        if(s ==0){
            s = 1;
        }

        while(s<=e){
            mid = s + (e-s)/2;
            int total_time = 0;

            for(int i =0 ; i <n;i++){
                total_time += piles[i]/mid;
                if(piles[i]%mid != 0){
                    total_time++;
                }
            }


            if(total_time>h){
                s = mid +1;
            }else{
                
                ans = mid;
               e = mid -1;
            }
        }

        return ans;
    }
int main(){

    vector<int> piles = {30,11,23,4,20};
    int h =5;


    cout << minEatingSpeed(piles,h);

return 0;
}