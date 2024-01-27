#include<iostream>
using namespace std;
#include <vector>

void PrintSubArray(vector<int> array){
    int n = array.size();

    // By we want to loop iterate From the 1 to n-1 
    for(int size = 1 ;size <= n;size++){
        
        // this loop want to run from  < n- size  + 1 || <=  n- size
        for(int i =0;i<=n-size;i++){

            
            //here we print that every subarray 
            // so we want to start the loop from  i 
            // end the loop with i+size
            for(int j =i; j<i+size;j++)
            cout << array[j] << " ";

            cout << endl;
        }
       
    }
}



int main(){

    vector<int> arr = {6,4,5};
    PrintSubArray(arr);

return 0;
}