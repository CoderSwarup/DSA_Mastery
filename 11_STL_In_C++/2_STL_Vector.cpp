#include<iostream>
using namespace std;
#include <vector>
int main(){

    vector <int> arr;

    vector <int> arr2(5,1); // size of the vector is 5 and all value are 1 by default 1
    cout << endl;
    for(auto i:arr2){
        cout << i<< endl;
    }

    vector <int> arr3(5); 
    cout << endl;
    for(auto j:arr3){
        cout << j<< endl;
    }


    cout << endl;

    cout << "size " <<  arr.size() << " " << arr2.size() <<endl;

    cout << "Capacity " << arr.capacity() << " " << arr2.capacity() << endl; 

    // insert value
    arr.push_back(33);
    arr2.push_back(2);

    cout << "size " <<  arr.size() << " " << arr2.size() <<endl;

    cout << "Capacity " << arr.capacity() << " " << arr2.capacity() << endl; 

 arr.push_back(1);
  arr.push_back(2);

    cout <<endl << "size " <<  arr.size()  <<endl;
    // capacity increase in double

    cout << "Capacity " << arr.capacity()  << endl; 


    // clear vector 

    arr.clear();
    cout << endl;
    cout << "Size after clearing " << arr.size() << endl ;
    // resize vector
    // arr.resize(4);
    // cout << "Size after resizing " << arr.size() << endl ;

    //capacity
    cout << "Capacity after clearing " << arr.capacity()  << endl;


    arr3.insert(1,3);




     vector<int> g1;
 
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);
 
    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of cbegin and cend: ";
    for (auto i = g1.cbegin(); i != g1.cend(); ++i)
        cout << *i << " ";
 
    cout << "\nOutput of rbegin and rend: ";
    for (auto ir = g1.rbegin(); ir != g1.rend(); ++ir)
        cout << *ir << " ";
 
    cout << "\nOutput of crbegin and crend : ";
    for (auto ir = g1.crbegin(); ir != g1.crend(); ++ir)
        cout << *ir << " ";


         cout << endl;
      vector<int> g2;
 
    for (int i = 1; i <= 10; i++)
        g2.push_back(i * 10);
 
    cout << "\nReference operator [g] : g2[2] = " << g2[2];
 
    cout << "\nat : g2.at(4) = " << g2.at(4);
 
    cout << "\nfront() : g2.front() = " << g2.front();
 
    cout << "\nback() : g2.back() = " << g2.back();
 
    // pointer to the first element
    int* pos = g2.data();
 
    cout << "\nThe first element is " << *pos;




return 0;
}