#include<iostream>
using namespace std;
#include <algorithm>

string addStrings(string num1, string num2) {
    int n1 = num1.size() -1;
    int n2 = num2.size() -1;

    string ans;
    int carry = 0;
    while( n1 >= 0 && n2 >=0){
        int  sum = (num1[n1--]-'0') + (num2[n2--]-'0') + carry;
        carry = sum / 10;
        char c =   '0' + (sum%10);
        ans += c;
    }    


    while(n1>=0){
        int  sum = (num1[n1--]-'0')+carry;
        carry = sum / 10;
        char c = '0' + (sum%10);
        ans += c;
    }

    while(n2>=0){
        int  sum = (num2[n2--]-'0')+carry;
        carry = sum / 10;
        char c = '0' + (sum%10);
        ans += c;
    }

    if(carry){
        ans += '1';
    }

    // reverse the string 
    reverse(ans.begin(),ans.end());

    return ans;    
}

int main(){

    string n1 = "1000";
    string n2 = "114";

    cout << addStrings(n1,n2);




return 0;
}