#include<iostream>
using namespace std;

int RomanCharValue(char c){
    if(c == 'I'){
        return 1;
    }else if(c == 'V'){
        return 5;
    }else if(c == 'X'){
        return 10;
    }else if(c == 'L'){
        return 50;
    }else if(c == 'C'){
        return 100;
    }else if(c == 'D'){
        return 500;
    }else{
        return 1000;
    }
}


int RomanToInterger(string s){
    int sum =0;
    for(int i=0;i<s.size() -1;i++){
        if(RomanCharValue(s[i])  < RomanCharValue(s[i+1])){
            sum -= RomanCharValue(s[i]);
        }else{
           sum += RomanCharValue(s[i]);
        }
    }

    sum += RomanCharValue(s[s.size()-1]);

    return sum;
}

int main(){

    string s;
    cin >> s;


    cout << RomanToInterger(s);    



return 0;
}