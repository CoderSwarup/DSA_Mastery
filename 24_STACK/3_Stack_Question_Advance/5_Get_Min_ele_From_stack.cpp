#include<iostream>
using namespace std;
#include <bits/stdc++.h>


class GetMinElem{
    public:
    
    stack<int> s;
    stack<int>minStack;
     /*returns min element from stack*/
    int getMin(){

           //Write your code here
           if(s.empty())
           return -1;

           return minStack.top();

    }

    /*returns poped element from stack*/
    int pop(){

           //Write your code here
           if(s.empty()){
               return -1;
           }else{
               int top = s.top();
               s.pop();
               minStack.pop();
               return top;
           }
    }

    /*push element x into the stack*/
    void push(int x){

           //Write your code here
           if(s.empty()){
               s.push(x);
               minStack.push(x);
           }else{
               s.push(x);
               minStack.push(min(x,minStack.top()));
           }
    }


};


// Without Using Extra MinElem  Stack

class GetMinElemWithoutExtraSpace{
    int minEle;
    stack<int> s;
  
    public:
    
       /*returns min element from stack*/
       int getMin(){
           
           //Write your code here
           if(s.empty())
           return -1;
           
           return s.top()%101;
           
       }
       
       /*returns poped element from stack*/
       int pop(){
           
           //Write your code here
           if(s.empty()){
               return -1;
           }else{
               int top = s.top()/101;
               s.pop();
               return top;
           }
       }
       
       /*push element x into the stack*/
       void push(int x){
           
           //Write your code here
           if(s.empty()){
               s.push(x*101+x);
             
           }else{
               s.push(x*101+min(s.top()%101,x));
               
           }
       }
};

int main(){
//    GetMinElem a;
   GetMinElemWithoutExtraSpace a;

   a.push(1);
   cout << a.pop() << endl;
   cout << a.getMin() << endl;



return 0;
}