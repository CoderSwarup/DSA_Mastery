#include<iostream>
using namespace std;
#include <vector>
//+++++++++++++++++++++++
// => https://www.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1?page=1&difficulty
// ++++++++++++++++++++

// using BruteForce 
// TC => O(N^2)
// SC => O(N)

bool isPalindromeString(string s,int end){
    int n = s.size();
    int start = 0;

    while(start<end){
        if(s[start] != s[end]){
            return false;
        }else{
            start++;
            end--;
        }
    }

    return true;
}

string PalindromeString(string s){
    int n = s.size();
    string palindromeCharters;
    int end = n-1;

    for(int i=0;i<n;i++){
        if(isPalindromeString(s,end)){
            break;
            // return palindromeCharters;
        }
        palindromeCharters += s[end];
        end--;
    }

    // cout << palindromeCharters;

    return (palindromeCharters+s);

}

/// +++++++++++++++++++++++++++++++++


// Using the KMP Algorithm
int FindLPS(string s){
    int n= s.size();
    int first =0;
    int second = 1;
    vector<int>lps(n,0);

    while(second <n){
        if(s[first] == s[second]){
            lps[second] = first+1;
            first++;
            second++;
        }else{
            if(first ==0){
                lps[second] =0;
                second++;
            }else{
                first = lps[first-1];
            }
        }
    }


    return lps[n-1];
}

int minChar(string str){
    string reverse = str;
    int start =0;
    int end = reverse.size() -1;

    while(start<end){
        swap(reverse[start],reverse[end]);
        start++;
        end--;
    }

    str += "$";
    str += reverse;

   int LPSlength = FindLPS(str);
   int ans = reverse.size() - LPSlength;

    return ans;
}



int main(){

    string s = "aaaotcaakr";

    // Brute Force Approach
    // cout << PalindromeString(s);
    // cout << isPalindromeString(s);

    //Using KMP Method
    cout << minChar(s);


return 0;
}