#include<iostream>
using namespace std;
#include <vector>

// Match String Brute Force
// TC => O(n*m) ==> O(n-m) * O(m) => O(n-m2) => O(n*m)
// SC  => O(1)
int MatchStringBruteForce(string s1,string s2){
    int n = s1.size() , m= s2.size();

    for(int i=0;i<=n-m;i++){
        int first = i, second = 0;

        while(second<m){
            if(s1[first] != s2[second]){
                break;
            }else{
                first++;
                second++;
            }
           
        }

        if(second == m){
            return first-second;
        }
    }


    return -1;
}

// using KMP Algorithm 

void LPS(vector<int>&lps,string s){
    int n = s.size();
    int preffix = 0;
    int suffix = 1;

    while(suffix<n){
        if(s[preffix]==s[suffix])
        {  
            lps[suffix] = preffix+1;
            suffix++;
            preffix++;
        }else{
            if(preffix==0){
                lps[suffix] =0;
                suffix++;
            }else{
                preffix = lps[preffix-1];
            }
        }
    }

    // for(auto i: lps){
    //     cout << i << " ";
    // }
}


int MatchStrignKMP(string s1,string s2){
    int n = s1.size() , m=s2.size();
    vector<int>lps(m,0);

    int first =0;
    int second =0;

    LPS(lps,s2);

    while(first < n && second <m){

        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            if(second == 0){
                first++;
            }else{
                second = lps[second-1];
            }
        }


        if(second ==m){
            return  first-second;
        }
       
    } 
     

    return -1;
}


// simple solution 

int strStr(string haystack, string needle) {
        int x = needle.size();                                // Get the size of the needle
        for (int i = 0; i < haystack.size(); i++) {          // Iterate through the characters of the haystack
            if (needle == haystack.substr(i, x)) {          // Check if the substring of haystack starting at index i and of length x is equal to the needle
                return i;                                  // If true, return the current index i
            }
        }
        return -1;                                     // If no match is found, return -1
    }
    
int main(){

    string s1 = "sadbutsad";
    string s2 = "sad";

    cout << MatchStringBruteForce(s1,s2);
//    cout << MatchStrignKMP(s1,s2);


return 0;
}
