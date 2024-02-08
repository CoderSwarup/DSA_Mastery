#include<iostream>
using namespace std;
#include <vector>
// ==> https://leetcode.com/problems/sorting-the-sentence/description/
// Input: s = "is2 sentence4 This1 a3"
// Output: "This is a sentence"



string SortSentence(string s){
    int n = s.size();
    vector<string>sortedSentences(9);

    string temp;
    int count = 0;

    for(int i=0;i<n;i++){
        if(s[i] == ' '){
            int Position = temp[temp.size()-1]-'1';
            temp.pop_back();
            sortedSentences[Position] = temp;
            temp.clear();
            count++;
        }else{
            temp += s[i];
        }
    }


    int pos = temp[temp.size()-1]-'1';
    temp.pop_back();
    sortedSentences[pos] = temp;
    temp.clear();

    for(int i=0;i<=count;i++){
        temp += sortedSentences[i];
        temp += ' ';
    }

    temp.pop_back();

    return temp;
}

int main(){

    string s = "is2 sentence4 This1 a3";
    cout << SortSentence(s);



return 0;
}