#include<iostream>
using namespace std;
#include <vector>

int LongestPalindrome(string s){
    int n = s.size();

    // if(n==1){
    //     return 1;
    // }
    vector<int> lower(26,0);
    vector<int> upper(26,0);

    int count =0;
    int OddCount = 0;


    // Seperate The Aplhabet Counts
    for(int i=0;i<n;i++){
        if(s[i] >= 'a'){
            lower[s[i]-'a']++;
        }else{
            upper[s[i]-'A']++;
        }
    }

    // Now Count The Longest Palindrome String
    for(int i=0;i<26;i++){
        //check if the Lower ith Means (lowercase Count )
        if(lower[i]%2 ==0){
            count += lower[i];
        }else{
            count += lower[i] -1;
            OddCount = 1;
        }

        // Similarly Check For the Uppercase 
        if(upper[i]%2==0){
            count += upper[i];
        }else{
            count += upper[i] -1;
            OddCount = 1;
        }
    }


    // if the Odd Count Value  Add
    count += OddCount;

    // for(auto i:lower){
    //     cout << i << endl;
    // }
    return count;



}
int main(){

    string s = "aAAbbA";
    cout<<  LongestPalindrome(s);




return 0;
}