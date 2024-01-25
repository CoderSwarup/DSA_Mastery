#include<iostream>
using namespace std;



void PrintArray(int arr[],int size){

    for(int i=0;i < 6;i++){
        cout << arr[i] << " ";
    }
}
void segregate(int arr[],int size){
    int s =0;
    int e = size -1;

    while(s<e){
        if(arr[s] ==0){
            s++;
        }else{
            if(arr[e] ==0){
                swap(arr[s],arr[e]);
                s++;
                e--;
            }else{
                e--;
            }
        }
    }
}
int main(){

    int arr[6] = {1,0,1,0,0,1};
    int size = sizeof(arr) / sizeof(int);
    cout << "Given array is: ";
    PrintArray(arr,size);
    cout<< endl;
    segregate(arr,size);
    PrintArray(arr,size);




return 0;
}