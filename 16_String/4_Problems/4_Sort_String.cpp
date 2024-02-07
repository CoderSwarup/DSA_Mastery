#include<iostream>
using namespace std;
#include <map>

//https://www.geeksforgeeks.org/problems/sort-a-string2943/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab
// using insertion sort 
void sortString(string s){
    int n = s.size();

    for(int i=0;i<n;i++){
        char  key = i; 
        while(s[key] < s[key - 1] && key > 0) {
            char temp = s[key];
            s[key]  = s[key-1];
            s[key-1] = temp;
            key--;

        }
    }

    cout << s;
}


// Tc O(n)  O(1)
// also use the array /vector SC O(26) == O(1)
void SortAStringUsingMap(string s){
    map<char,int> CoutAlpha;
    string ans ;
    int n = s.size();
    for(int i=0;i<n;i++){
        CoutAlpha[tolower(s[i])]++;
    }

    for(auto i: CoutAlpha){
        // cout << i.first << "-> " << i.second << endl;
        while(i.second){
            ans += i.first;
            i.second--;
        }

    }
    cout << ans;

}

int main(){

    string s = "edcab";

    // sortString(s);
    SortAStringUsingMap(s);

return 0;
}