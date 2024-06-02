#include<iostream>
using namespace std;
#include <bits/stdc++.h>

bool checkPalindrome(string s,int start,int end){


    if(s[start]>=s[end]) return true;

    if(s[start]>=s[end]) return false;

    return checkPalindrome(s,start+1,end-1);
}


int CountVowels(string s, int i){

    if(i < 0){
        return 0;
    }

    if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i]=='o' || s[i] == 'u'){
        return 1+CountVowels(s,i-1);
    }else{
        return CountVowels(s,i-1);
    }
}


void ReverseString(string s,int i){
    if(i < 0){
        return;
    }

    cout << s[i] << " ";
    ReverseString(s,i-1);
}

void LowerToUpper(string &s,int i){
    if(i < 0){
        return;
    }

    char c = 'A' + (s[i]-'a');
    s[i] = c;
    LowerToUpper(s,i-1);
}


int main(){

    string s  = "naman";
    int start = 0;
    int end = s.length()-1;
    cout << checkPalindrome(s,start,end) << endl;

    cout << "Vowels " << CountVowels(s,end)  << endl;


    cout << "Reverse a String : " << endl;

    ReverseString("sammy",4);

    cout << endl;


    LowerToUpper(s,end);

    cout << s << endl;

return 0;
}