


#include <iostream>
using namespace std;

  void hi();
  void hello();
  void sammy();

    int main(){

        hi();
    
    return 0;
}


 void hi(){
     cout << "this is hi function"<<endl;
     sammy();
     hello();
 }
  void hello(){
       cout << "this is hello fuction print using hi function  "<<endl;
  }

    void sammy(){
       cout << "this is sammy fuction print using hi function  "<<endl;
  }

