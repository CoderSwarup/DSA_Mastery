#include<iostream>
using namespace std;
#include <bits/stdc++.h>



int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq;

        for(int i=0;i<stones.size();i++)
        pq.push(stones[i]);


        while(pq.size() >1){
            int s1 =pq.top();
            pq.pop();
            int s2 =pq.top();
            pq.pop();

            int weight = s1-s2;

            if(weight){
                pq.push(weight);
            }
        }


        return pq.empty() ? 0 : pq.top();
    }

int main(){

    // vector<int> arr ={2,7,4,1,8,1};
    vector<int> arr ={2,2};

    cout << lastStoneWeight(arr);

return 0;
}