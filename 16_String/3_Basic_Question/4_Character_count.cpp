#include<iostream>
using namespace std;
#include <vector>
#include <limits.h>

char getMaxOccuringChar(string str)
    {
        // Your code 
        vector<int>count(26,0);
        
        int max_occure = INT_MIN;
        int index =0;
        
        for(int i =0;i<str.size() ;i++ ){
            count[str[i] - 97 ]++;
            max_occure = max(max_occure,count[str[i] - 97]);
        }



        for(int i=0;i<26;i++){
            // cout << (count[index] > count[i] ) << " " << count[index] << " " << count[i] << endl;
            if(count[index] < count[i] ){
                index = i;
            }
        }



        char ans = 'a' + index;
        return ans;
    }

int main(){

    string s ="testsample";
    cout << getMaxOccuringChar(s);

return 0;
}