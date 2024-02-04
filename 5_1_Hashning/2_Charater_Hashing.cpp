#include<iostream>
using namespace std;

int main(){

    string str;
    cin >> str;
    

    // Only Lower case 
    // int Hash[26] = {0};
    // PrePerocessing 
    // for(int i=0;i<str.size();i++){
    //     Hash[(int)str[i] - (int)'a']++;
    // }
    // int q ;
    // cin >> q;
    // while(q--){
    //     char x;
    //     cin >> x;
    //     cout << x << "Appears : " << Hash[(int)x - (int)'a'] << endl; 
    // }


    // For All   
    int Hash[256] = {0};
    for(int i=0;i<str.size();i++){
        Hash[(int)str[i]]++;
    }
    int q ;
    cin >> q;
    while(q--){
        char x;
        cin >> x;
        cout << x << "Appears : " << Hash[(int)x] << endl; 
    }
return 0;
}