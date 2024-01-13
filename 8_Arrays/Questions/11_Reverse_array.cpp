#include <iostream>
using namespace std;

void printarray(int arr[],int n){

    for(int i =0;i<n;i++){
        cout << arr[i] <<" ";

    }

    cout << endl;

}
// Method 1 
void reverse(int arr[],int n){
    for(int i = 0;i <n;i++){
        if(i>=n-i){
            break;
        }

        swap(arr[i],arr[n-i-1]);
       
    }
}
// Mehtod 2 ;
void reverseArray(int arr[] , int m)
{

  int s = 0;
  int e = m-1;

  while(s<e){
      swap(arr[s],arr[e]);
      s++;
      e--;
  }
    
}
int main() {
    int N;

    cin>>N;

    int arr[N];

    for(int i=0;i<N;i++){

        cin>>arr[i];

    }

    // reverse(arr,N);
    reverseArray(arr,N);

    printarray(arr,N);

    return 0;
}