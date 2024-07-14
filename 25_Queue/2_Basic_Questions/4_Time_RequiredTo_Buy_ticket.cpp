#include<iostream>
using namespace std;
#include <bits/stdc++.h>


//Time Take O(N2)
void takeTimeToBuyTicket(vector<int> arr ,int k){
        queue<int>q;

    for(int i=0;i<arr.size();i++){
        q.push(i);
    }

    int Timer =0;

    while(arr[k] != 0){
        arr[q.front()]--;

        if(arr[q.front()]){
            q.push(q.front());
        }
        q.pop();
        Timer++;
    }

    cout << "Time Required To index " << k << " to buy Ticket is "<< Timer <<endl; 
}

// TC 0(N)
void takeTimeToBuyTicketOptimal(vector<int> arr,int k){


    int Timer =0;


    for(int i=0;i<=k;i++){
        Timer += min(arr[k],arr[i]);
    }

    for(int i=k+1;i<arr.size();i++){
        Timer += min(arr[k]-1,arr[i]);
    }


    cout << "Time Required To index " << k << " to buy Ticket is "<< Timer <<endl; 
}


int main(){
    vector<int>arr={1,5,2,3,7};
    int k =2;

    // takeTimeToBuyTicket(arr,k);
    takeTimeToBuyTicketOptimal(arr,k);






return 0;
}