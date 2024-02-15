#include<iostream>
using namespace std;
#include <vector>

// Brute Force
// TC O(n2)
// SC O(n)
int LogestPSBruteForce(string s){
    int len =0;
    int n = s.size();
    vector<string> suffix(n-1);
    vector<string>preffix(n-1);

    // find Prefix
    for(int i=0; i<n-1;i++){
        string ss;
        for(int j=0;j<=i;j++){
            ss+=s[j];
        }
        preffix[i] =ss;
    }

    // find Prefix
    for(int i=n-1; i>0;i--){
        string ss;
        for(int j=i;j<n;j++){
            ss+=s[j];
        }
        suffix[(n-1)-i] =ss;
    }

    for(int i=0;i<preffix.size();i++){
        //   cout << preffix[i] << " " << suffix[i] << " -> " <<  (preffix[i]==suffix[i]) << "\n";
        if(preffix[i] == suffix[i]){
           len = preffix[i].size();
        }
    }



    return len;
}

// 
// using Two Pointer Approach
// Thiu is not Possible for the All Test cases 
int LogestPSTwoPointer(string s){
    int len =0;
    int n = s.size();
    vector<int>lps(n,0);
    int preffix =0 ,suffix =1;

    while(suffix<n){
        if(s[preffix] == s[suffix]){
            lps[suffix]= preffix+1;
            preffix++;
            suffix++;
        }else{
            if(preffix == 0){
                lps[suffix++] =0;
            }else{
                preffix = lps[preffix-1];
            }
        }
    }
    return lps[n-1];
}


int main(){
    // string s="ABCDEABCD";
    // string s="AACAA"; 
    string s="AAAAAD"; 
    // string s ="aaaa";

    // cout << LogestPSBruteForce(s);
    cout << LogestPSTwoPointer(s);

return 0;
}