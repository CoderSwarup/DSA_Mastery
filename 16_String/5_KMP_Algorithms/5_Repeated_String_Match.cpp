#include<iostream>
using namespace std;
#include <vector>

    void findLPS(string txt, vector<int> &lps) {
        int n = txt.size();
        int preffix = 0;
        int suffix = 1;

        while (suffix < n) {
            if (txt[preffix] == txt[suffix]) {
                lps[suffix] = preffix + 1;
                preffix++;
                suffix++;
            }else{
                if(preffix ==0){
                    suffix++;
                }else{
                    preffix = lps[preffix-1];
                }
            }
        }
    }

    bool isSubstring(string pattern, string txt) {
        int n = pattern.size();
        int m = txt.size();
        vector<int> lps(m, 0);

        findLPS(txt, lps);

        int first = 0;
        int second = 0;

  

        while (first < n ) {
            if (pattern[first] == txt[second]) {
                first++;
                second++;
            } else {
                if (second == 0) {
                    first++;
                } else {
                    second = lps[second - 1];
                }
            }

            if (second == m) {
                return true;
            }
        }


        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int repeate = 1;

        if(a == b){
            return 1;
        }

        while (temp.size() < b.size()) {
            temp += a;
            repeate++;
        }

        // find the String Is Match Or Not
        if(isSubstring(temp,b))
        return repeate;

        // if not then Check again
        if(isSubstring(temp+a,b)){
            repeate++;
            return repeate;
        }
        

        // else return 1
        return -1;
    }

int main(){
    string s1  ="aaac";
    string s2 = "aac";


    cout << repeatedStringMatch(s1,s2);




return 0;
}