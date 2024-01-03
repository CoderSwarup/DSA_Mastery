#include<iostream>
using namespace std;


int BinarySearch(int arr[],int size, int target){
    int startindex = 0;

    int lastindex = size -1;

    // int Midindex = (startindex+lastindex)/2;
     // Here is the One Mistake that if the start and End Index Values Are 2^31 -1 2,147,483,647
     // if we Add here The both 2,147,483,647 +2,147,483,647 
     // Return Answer is 4294967294 
     // Its Exceed The Integer Range

     // Insted Of that we use 
     int Midindex = startindex + ((lastindex - startindex)/2);
     // In this case the Answer return is 
    //  2,147,483,647 + ((2,147,483,647-2,147,483,647)) = 2147483647 
    // This Not Exceed The Int Range 

    // Loop excecute untl the start end less than lastindex
    while(startindex <= lastindex){

        // arr of midindex is equal to target then return index
        if(arr[Midindex]==target){
            return Midindex;
        }

        // check if the arr of midindex is Less than target then increase startindex = midindex +1
        if(arr[Midindex] < target){
            startindex = Midindex + 1;
        }else{
            // else update last index to midindex -1 
            lastindex = Midindex -1;
        }
 

        Midindex = (startindex+lastindex)/2;
    }


    return -1;

}

int main(){

    int arr[5] = {2,5,7,16,21};
    int arr2[6] = {33,44,55,66,77,88};


    cout << BinarySearch(arr,5,2) << endl;
    cout << BinarySearch(arr2,6,1) << endl;
return 0;
}