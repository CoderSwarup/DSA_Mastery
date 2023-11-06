#include<iostream>
using namespace std;

int main(){

    /* 
    * * *
    * * *
    * * *
    */
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<" * ";
        }
        cout<<endl;

    }


    /*
    1 1 1
    2 2 2
    3 3 3
    */

     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<i+1<<" ";
        }
        cout<<endl;

    }

return 0;
}