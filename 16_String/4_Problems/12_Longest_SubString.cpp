#include<iostream>
using namespace std;
#include <vector>
//https://leetcode.com/problems/longest-substring-without-repeating-characters/

int LongetstSubstring(string s){
    int n = s.size();
    vector<bool>count(256,false);
    int first =0,second =0 , len =0;

    while(second<n){

        while(count[s[second]]){
            count[s[first]] = false;
            first++;
        }
        count[s[second]] = true;
        len = max(len,second - first+1);
        cout << len << " ";
        // cout << len << " ";
        second++;
    }
    cout << endl;
    return len;
}
int main(){

    string s = "abcabcbb";
    cout << LongetstSubstring(s);

return 0;
}