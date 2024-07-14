#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){

    queue<int> Q ;
    Q.push(1);
    Q.push(2);
    Q.push(3);
    Q.push(4);
    Q.push(5);


    int n = Q.size();


    while(n--){
        cout<< Q.front() << " ";
        Q.push(Q.front());
        Q.pop();
    }


    cout << endl << "Size " << Q.size() << endl;

return 0;
}