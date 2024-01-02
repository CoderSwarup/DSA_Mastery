#include<iostream>
using namespace std;

void updatearray(int arr[] , int n){
    cout << "Inside Print array Function "<< endl;
    arr[0] = 999;
     for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }

       cout<< endl << "going back to  main Function "<< endl;

}
int main(){

    int arr[3] = {1,2,3};

    updatearray(arr,3);

   cout << "Inside Main Function "<< endl; 

   // update the array value becasue the we pass the array address not array value 
    for(int i=0;i<3;i++){
        cout << arr[i] << " ";
    }



return 0;
}