#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){
    string A = "ababdc";

    string ans = "";
    vector<int> repeadted(26,0);
    queue<char>Q;
    for(int i=0;i<A.size();i++){
        if(repeadted[A[i] -'a'] >=1){
            repeadted[A[i] -'a']++;

            while(!Q.empty() && repeadted[Q.front() -'a'] >1){
                Q.pop();
            }

            if(Q.empty()){
                ans += '#';
            }else{
                ans += Q.front();
            }
        }else{
            repeadted[A[i] -'a']++;
            Q.push(A[i]);

            while(!Q.empty() && repeadted[Q.front() -'a'] >1){
                Q.pop();
            }

            ans += Q.front();
        }
    }


    cout << "ANS IS " << ans;

return 0;
}