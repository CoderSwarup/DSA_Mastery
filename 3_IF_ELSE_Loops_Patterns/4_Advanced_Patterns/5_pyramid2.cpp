#include<iostream>
using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=0;i<=n;i++){
        int space = n-i;
        for(int j =space;j>0;j--){
            cout << " ";
        }

        for(int j=0;j<i;j++){
            cout<<"*";
        }
        cout<<endl;
    }

    cout<<"triangle"<<endl;
    for(int i=0;i<=n;i++){
        int space = n-i;
        for(int j =space;j>0;j--){
            cout << " ";
        }

        for(int j=0;j<i;j++){
            cout<<" *";
        }

      
        cout<<endl;
    }


    cout<<"triangle 2"<<endl;

    for(int i=0;i<=n;i++){
        int space = n-i;
        for(int j =space;j>0;j--){
            cout << " ";
        }

        for(int j=0;j<i;j++){
            cout<<"*";
        }
          for(int j=0;j<=i;j++){
            cout<<"*";
        }
        cout<<endl;
    }


    cout<<"Reverse Pyramid"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            cout<<" ";
        }


        for(int j=n-i+1;j>=1;j--){
            cout<<"*";
        }
     
        cout<<endl;
    }

cout<<"No triangle"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=n-i;j>0;j--){
            cout<<" ";
        }

        for(int j=0;j<=i-1;j++){
            cout<<j+1;
        }

        for(int j=1;j<=i-1;j++){
            cout<<j;
        }

        cout<< endl;
    }




return 0;
}