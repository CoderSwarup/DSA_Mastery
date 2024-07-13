#include<iostream>
using namespace std;
#include <queue>


void showq(queue<int> Q)
{
    queue<int> q = Q;
    while (!q.empty()) {
        cout << '\t' << q.front();
        q.pop();
    }
    cout << '\n';
}

int main(){

    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
 
    cout << "The queue Q is : ";
    showq(Q);
 
    cout << "\nQ.size() : " << Q.size();
    cout << "\nQ.front() : " << Q.front();
    cout << "\nQ.back() : " << Q.back();
 
    cout << "\nQ.pop() : ";
    Q.pop();
    showq(Q);




return 0;
}