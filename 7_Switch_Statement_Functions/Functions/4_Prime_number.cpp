#include<iostream>
using namespace std;


void IsPrime(int n){
    for(int i = 2;i < n;i++){
        if(n%i == 0){
            cout << "Note a Prime Number";
            return;
        }
    }

    cout << "Prime Number";
}
int main(){
    try{
        int n;
        cout << "Eneter a Ineger Number" << endl;
        cin >> n;

        IsPrime(n);

    }catch(int er){
        cout << "Not a Integer" << er;
    }


return 0;
}