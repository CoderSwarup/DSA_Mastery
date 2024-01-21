#include<iostream>
using namespace std;
#include <vector>


// Q ==> https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

void Missing(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] == 0){
            cout<< "Missing No is " << (i+1) << endl;
            break;
        }
    }
}

void Repeate(vector<int> &arr){
    int n = arr.size();
    for(int i=0;i<n;i++){
        if(arr[i] >= 2){
            cout<< "Repeating No is " << (i+1) << endl;
            break;
        }
    }
}
// using Extra Space 
// ==> TIme Coplexity is O(n)
// space Complexity = O(n)
void FindUsingExtraSpace(vector<int> &arr){
    int n = arr.size();
    vector<int> newarr(n,0);

    for(int i=0;i<n;i++){
        newarr[arr[i]-1]++;
    }

    Missing(newarr);
    Repeate(newarr);
}


// Optimize Solution Without using the extra space
void FindUsingWithoutExtraSpace(vector<int> &arr){
    
    int n = arr.size();

    // decrease Every value of array by -1
    for(int i=0;i<n;i++){
        arr[i]--;
    }

    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }

    // get Index And Store Occurence  
    // Now using the 2 Number Store in Signle Position Formula 
    // inside array the All values are 0 to n-1
    // so we take N 
    // for every index position value GETINDEX =  arr[i] % N = That give the Index 
    // and then that give index positon value add by N  ==> arr[GETINDEX] = arr[GETINDEX]+N;

    for(int i=0;i<n;i++){
        int getIndex = arr[i]%n;
        arr[getIndex] = arr[getIndex]+n;
    }

    // cout << endl;
    // for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    

    // Now Find Missing No
    for(int i=0;i<n;i++){
        int Number = arr[i] %n;
        int occurence = arr[i] /n;
        if(occurence == 0){
            cout << "Missing No is " <<  i+1 <<  endl;
            break;
        }
    }


    // Now Find Repeted  No
    for(int i=0;i<n;i++){
        int Number = arr[i] %n;
        int occurence = arr[i] /n;
        if(occurence == 2){
            cout << "Missing No is " <<  i+1 << endl;
            break;
        }
    }

}


int main(){

    vector<int> arr = {4,3,2,1,2,7,6};

    // FindUsingExtraSpace(arr);

    FindUsingWithoutExtraSpace(arr);


return 0;
}