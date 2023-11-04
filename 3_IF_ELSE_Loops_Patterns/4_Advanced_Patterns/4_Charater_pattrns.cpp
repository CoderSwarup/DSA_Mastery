#include<iostream>
using namespace std;

int main(){
    int n = 3;

    // char a= 'A';
    //   for(int i=1;i<=n;i++){

    //     for(int j =1;j<=n;j++){
    //         cout<<a<<" ";
    //     }
    //     a++;
    //     cout<<endl;
    // }

    // cout << endl << endl;

    for(int i=1;i<=n;i++){
    char a= 'A'+i-1;
        for(int j =1;j<=n;j++){
            cout<<a<<" ";
            // a++;
        }
        cout<<endl;
    }

    cout << endl << endl;

    for(int i=1;i<=n;i++){
        // char a= 'A'+i-1;
        for(int j =1;j<=n;j++){
        char a= 'A'+j-1;
            cout<<a<<" ";
        }
        cout<<endl;
    }

    cout << endl << endl;

    for(int i=1;i<=n;i++){
        for(int j =1;j<=n;j++){
        char a= 'A'+i+j-2;
            cout<<a<<" ";
        }
        cout<<endl;
    }

    cout << endl << endl;


    char a= 'A';
    for(int i=1;i<=4;i++){
        for(int j =1;j<=i;j++){
            // cout<<a++<<" ";
            // cout<<char(a+i+j-2)<<" ";
            // cout<<char(a+n-i+1)<<" ";
            cout<<char(a+n-i+j)<<" ";
        }
        cout<<endl;
    }

    cout << endl << endl;

return 0;
}