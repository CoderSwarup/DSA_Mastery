#include<iostream>
using namespace std;
#include<deque>
int main(){

    deque <int>a;

    for(int i=1;i<=5;i++)
    a.push_back(i);

    cout<<"The deque is : ";
    for(auto &x: a)
    cout << x << " ";
    cout << endl;


     deque <int>b;

     b.push_back(2);
     b.push_front(1);
 b.push_back(21);
     b.push_front(11);

     // 

     b.pop_back();
     b.pop_front();
     for(auto y :b){
        cout << y << endl;
     }

      b.push_back(21);
     b.push_front(11);

     cout << "at " << b.at(0) << endl;

    // front back

    cout << "front " << b.front() << endl;
    cout << "back " << b.back() << endl;

    cout << "size  " << b.size() << endl;

    cout << " is Empty " <<  b.empty() << endl;

    b.erase(b.begin(),b.end()-1);
    cout << "after erase size  " << b.size() << endl;

return 0;
}