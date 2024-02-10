#include<iostream>
using namespace std;
#include <vector>


//https://leetcode.com/problems/sort-vowels-in-a-string/description/


// Input: s = "lEetcOde"
// Output: "lEOtcede"
// Explanation: 'E', 'O', and 'e' are the vowels in s; 'l', 't', 'c', and 'd' are all consonants. The vowels are sorted according to their ASCII values, and the consonants remain in the same places.


string sortVowels(string s) {

    // Take the Two vectors  for Store Lower Case Vowels and Uppercase Vowels
    vector<int> Uppercase(26,0);
    vector<int> Lowercase(26,0);

    // iterate the string s 
    for(int i=0;i<s.size();i++){
        // store Lowercase Vowels 
        if(s[i] =='a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] =='u'){
            Lowercase[s[i] - 'a']++;
            s[i] = '#';
        }
        if(s[i] =='A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] =='U'){
            Uppercase[s[i] - 'A']++;
            s[i] = '#';
        }
    }

    string SortedVowels;
    
    // Add UpperCase Vowels in the Sorted VBowels String 
    for(int i=0;i<26;i++){
        char c = 'A' +i;
        while(Uppercase[i]){
            SortedVowels += c;
            Uppercase[i]--;
        }
    }

    // Similarly For Lower Case 
    for(int i=0;i<26;i++){
        char c = 'a' +i;
        while(Lowercase[i]){
            SortedVowels += c;
            Lowercase[i]--;
        }
    }


    int SortedVowelsPosition = 0;
    int stringindex = 0;

    // for(int i=0;i<s.size();i++){
    //     if(s[i] == '#'){
    //         s[i] = SortedVowels[SortedVowelsPosition++];
    //     }
    // }

    while(SortedVowelsPosition<SortedVowels.size()){
        if(s[stringindex]=='#'){
            s[stringindex] = SortedVowels[SortedVowelsPosition++];
        }
        stringindex++;
    }

    return s;
}
 
int main(){

    string s = "lEetcOde";
    cout << sortVowels(s);


return 0;
}