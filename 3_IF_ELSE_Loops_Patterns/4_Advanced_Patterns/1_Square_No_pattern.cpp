#include<iostream>
using namespace std;

int main(){
    int n ;
    cin>>n;

    cout << endl << endl;

    /*
    1 1 1 1 1
    2 2 2 2 2
    3 3 3 3 3
    4 4 4 4 4
    5 5 5 5 5
    */

    cout<< "Simple \n";
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout << endl << endl;

    /*
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    5 4 3 2 1
    */
    cout <<"Reverse no pattern";
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<n-j+1<<" ";
        }
        cout<<endl;
    }

    cout << endl << endl;

    
    /*
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    1 2 3 4 5
    */


    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            cout<<j<<" ";
        }
        cout<<endl;
    }

return 0;
}