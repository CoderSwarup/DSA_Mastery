#include<iostream>
using namespace std;
#include <cmath>
#include <vector>
void Factor(int n ){
    
    // TC O(sqrt(n))
    for(int i=1;i<=sqrt(n);i++){
        if (n%i==0){
            if(n/i == i){   // incase 36 => 6 * 6  ==> 36/6 = 6 =====> 6,6
                cout << i << " ";
            }else{
                cout << i <<" "<< n/i << " ";
            }

        }
    }



cout << "Sorted " << endl;
    // using Space Complexity 
    vector<int > multiplcationAns;
     for(int i=1;i<=sqrt(n);i++){
        if (n%i==0){
            if(n/i == i){   // incase 36 => 6 * 6  ==> 36/6 = 6 =====> 6,6
                cout << i << " ";
            }else{
                cout << i <<" " ;
                multiplcationAns.push_back(n/i);
            }

        }
    }

    for(int i=multiplcationAns.size()-1;i>=0;i--){
        cout << multiplcationAns[i] << " ";
    }


}
int main(){

    int n = 20;
    Factor(n);

return 0;
}