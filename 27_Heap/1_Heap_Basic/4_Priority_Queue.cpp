#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){

    cout << "Priority Queue " << endl << endl;
    cout << "Max Heap Priority Queue " << endl;
    priority_queue<int> p; // max heap

    p.push(10);
    p.push(20);
    p.push(2);
    p.push(21);
    p.push(1);

    cout << p.top() << endl;
    p.pop();
    cout << p.top() << endl;

    cout << "Print all Elem of Max Heap Priority Queue "<< endl;
    while(!p.empty()){
        cout << p.top() << " ";
        p.pop();
    }

    cout << endl << endl;

      cout << "Min Heap Priority Queue " << endl;

    priority_queue<int ,vector<int> ,greater<int> > mp;
    mp.push(22);
    mp.push(1);
    mp.push(11);
    mp.push(2);
    mp.push(0);

    cout << "Print all Elem of Min Heao Priority Queue "<< endl;
    while(!mp.empty()){
        cout << mp.top() << " ";
        mp.pop();
    }


return 0;
}