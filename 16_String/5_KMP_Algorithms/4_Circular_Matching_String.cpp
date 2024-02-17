#include<iostream>
using namespace std;
#include <vector>



void FindLPS(string s,vector<int> lps){
    int n= s.size();
    int first =0;
    int second = 1;

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


}

bool circularMatching(string s1 ,string s2){
    s1+= s1;
    int n = s1.size();

    int m = s2.size();
    vector<int>lps(m,0);

    FindLPS(s2,lps);

    int first =0;
    int second =0;



    while(first < n && second <m){
        if(s1[first] == s2[second]){
            first++;
            second++;
        }else{
            if(second == 0){
                first++;
            }else{
                second = lps[second-1];
            }
        }

        if(second==m) {
            //  cout << first -second ;
            return true;
        }
    }

   

    return false;
}

int main(){

    string s1 ="cdeabrroab";
    string s2 = "abcde";

    cout << circularMatching(s1,s2);

return 0;
}