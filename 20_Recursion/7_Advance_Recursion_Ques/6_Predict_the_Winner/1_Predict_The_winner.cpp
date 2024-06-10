#include<iostream>
using namespace std;
#include <bits/stdc++.h>

// TC O(n2)
//SC O(n)
int winner(vector<bool> &person,int person_left,int index, int k,int n){
    if(person_left==1){
        // for(int i=0;i<person.size();i++){
        //     if(person[i] ==0) return i;
        // }
        return index;
    }

    int kill = (k-1)%person_left;

    while(kill--){
        index = (index+1)%n;
        while(person[index] ==1){
            index = (index+1)%n;
        }
    }
    person[index] = 1;
    
    //Next alive Person 
   while(person[index] ==1){
        index = (index+1)%n;
            
    }

   return winner(person,person_left-1,index,k,n);

}


// optimal 
//Time Complexxity  O(n)
//spacke complexity = O(n)

int winnerOptimal(int n,int k){
    if(n==1) return 0;


    return (winnerOptimal(n-1,k)+k)%n;
}
int main(){

    int n = 4;
    int k =2;
    vector<bool> person(n,0);
    int person_left = n;
    int index = 0;

//    cout <<  winner(person,person_left,index,k,n)+1;
    cout << winnerOptimal(n,k)+1;
return 0;
}