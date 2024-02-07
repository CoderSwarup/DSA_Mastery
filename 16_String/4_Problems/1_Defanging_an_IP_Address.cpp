#include<iostream>
using namespace std;

// Input: address = "1.1.1.1"
// Output: "1[.]1[.]1[.]1"

// https://leetcode.com/problems/defanging-an-ip-address/description/
string defangIPaddr(string address) {
        string ans;

        for(int i=0;i<address.size();i++){
            if(address[i] == '.'){
            ans += "[.]";
            }else{
                ans += address[i];
            }
        }

        return ans;
    }

int main(){

    string s = "11.1.2.1";

   cout << defangIPaddr(s);


return 0;
}