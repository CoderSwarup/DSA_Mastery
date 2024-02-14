#include<iostream>
using namespace std;
#include <vector>

// => https://www.geeksforgeeks.org/problems/smallest-distant-window3132/1?page=1&difficulty
// Input : "AABBBCBBAC"
// Output : 3
// Explanation : Sub-string -> "BAC"


int smallestSubStringWithDistinctCharacter(string str){
 
    int n = str.size();

    // Declare The Count Charter Value 
    vector<int> count(256,0);

    int diff =0; // Unique charater Value
    int first =0 , second =0; // Two Pointers
    int len = str.size(); // Initial Minimum Length 
    cout << len << " ";

    // Count The Unique Charater Length  == diff
    while(first<n){
        if(count[str[first]]==0)
        diff++;

         count[str[first++]]++;   
    }

    // Set Again Count all Valuye 0;
    for(int i=0;i<256;i++){
        count[i]=0;
    }
    first  =0;

    // Main Program 
    while(second<n){

        // Until the Diff is zero
        while(diff && second<n){
            if(count[str[second]] == 0){
                diff--;
            }

            count[str[second++]]++;
        }

        len = min(len , second-first);
        cout << len << " ";

        // Until the diff == 1
        while(diff !=  1){
            len = min(len , second-first);
            cout << len << " ";
            count[str[first]]--;
            if(count[str[first]] == 0){
                diff++;
            }
            first++;

        }
    }

    cout << endl;


    return len;
}

int main(){

    string s ="AABBBCBBAC";
    cout << smallestSubStringWithDistinctCharacter(s);



return 0;
}