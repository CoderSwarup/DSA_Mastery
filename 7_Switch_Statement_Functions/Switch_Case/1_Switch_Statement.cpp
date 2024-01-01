#include<iostream>
using namespace std;

int main(){

    char ch = 'b';

    auto num = 0;

    // switch(ch){
    //     case 'a':
    //             cout<<"Case a " <<endl;
    //             break;

    //     // Nested switch 
    //     case 'b':
    //             cout<<"Case b " <<endl;
    //             switch(num){
    //                 case 1:
    //                       cout << "Num value is 1"<<endl;
    //                       break;
    //                 default: 
    //                         cout << "Num not Match"<<endl;
    //             }
    //             break;
    //     default : cout << "Default";
    // }

    while(true){
         cout<<"i 1" << endl;
        switch(num){
            case 0:
                cout << "Enter the number is 0" << endl;
                break;

            default: exit(1);
        }
        cout<<"i";
    }

return 0;
}