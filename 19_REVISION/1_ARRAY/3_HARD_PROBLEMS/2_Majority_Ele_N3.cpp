#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// brute force
// TC O(N2)
// SC O(1) beacuase their every time n/3 ele present that means it can only store the 2 ele

vector<int> majorityElement(vector<int> v) {
    int n = v.size();
    vector<int> ans;

    for(int i =0;i<n;i++){
        if(ans.empty() || ans[0] != v[i]){
            int c=0;
            for(int j =0;j<n;j++){

                if(v[i] == v[j]){
                    c++;
                }
            }
            if(c > (n/3)){
                ans.push_back(v[i]);
            }

            if(ans.size() == 2){
                break;
            }
        }
    }


    return ans;
}


//better 
// using hashing 

// TC O(N*log(N)) =>  map
// TC O(N*(1)) =>  unordered_map  ||  O(N*Log(N))
// SC )(N)
vector<int> majorityElementBetter(vector<int> v) {
    unordered_map<int,int> hashValue;
    int n = v.size();
    vector<int>ans;
    int minEleReq = (n/3)+1;

    for(int i=0;i<n;i++){
        hashValue[v[i]]++;
        if(minEleReq == hashValue[v[i]]){
            ans.push_back(v[i]);
        }
        if(ans.size() == 2){
            break;
        }
    }
    //also
    // for(auto i:hashValue){
       
    //     if(i.second > n/3  ){
    //             ans.push_back(i.first);
    //     }

    //     if(ans.size() == 2){
    //          break;
    //     }

    // }

  
    sort(ans.begin(),ans.end());
    return ans;

}


// Optimal  // Voting candidate element

bool isGreater(vector<int> v,int k){
    int n = v.size();
    int c = 0;
    for(int i=0;i<n;i++){
        if(v[i] == k){
            c++;
        }
    }


    return  (c > (n / 3)) ? true : false;
}

vector<int> majorityElementOptimal(vector<int> v) {

    int n = v.size();

    // ele 1 
    int ele1=INT_MIN;
    int ctn1 =0;
    // ele 2
    int ele2=INT_MIN;
    int ctn2 =0;

    for(int i=0;i<n;i++){
        if(ctn1 == 0 && v[i] != ele2){
            ele1 = v[i];
            ctn1++;
        }else if(ctn2 == 0 && v[i] != ele1){
            ele2 = v[i];
            ctn2++;
        }else if(ele1 == v[i]){
            ctn1++;
        }else if(ele2 == v[i]){
            ctn2++;
        }else{
            ctn1--;
            ctn2--;
        }
    }

    vector<int> ans;
    // check the elements are n/i
    if(isGreater(v,ele1)){
        ans.push_back(ele1);
    }
    
    if(isGreater(v,ele2)){
        ans.push_back(ele2);
    }
    

    sort(ans.begin(),ans.end());

    return ans;

}
int main(){
   vector<int> arr = {11, 33, 33, 11, 33, 11};
    // vector<int> ans = majorityElement(arr);
    // vector<int> ans = majorityElementBetter(arr);
    vector<int> ans = majorityElementOptimal(arr);

    for (auto it : ans)
        cout << it << " ";


return 0;
}