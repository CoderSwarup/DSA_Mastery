// Find First and Last Position of Element in Sorted Array
// => https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/



#include<iostream>
using namespace std;



int FirstOccurence(int arr[],int n,int key){
    int Findex = 0;
    int Lindex = n-1;
    int mid = Findex +(Lindex - Findex)/2;
    int ans = -1;
    while(Findex <=Lindex){
        if(arr[mid] == key){
            ans = mid;
            Lindex = mid - 1; 
        }

        if(arr[mid] < key){
            Findex = mid + 1;
        }

        if(arr[mid] > key){
            Lindex = mid-1;
        }
        mid = Findex +(Lindex - Findex)/2;
    }


    return ans;
}


int LastOccurence(int arr[],int n,int key){
    int Findex = 0;
    int Lindex = n-1;
    int mid = Findex +(Lindex - Findex)/2;
    int ans = -1;
    while(Findex <= Lindex){
        if(arr[mid] == key){
            ans = mid;
           Findex = mid +1;
        }

        if(arr[mid] < key){
            Findex = mid + 1;
        }

        if(arr[mid] > key){
            Lindex = mid-1;
        }
        mid = Findex +(Lindex - Findex)/2;
    }


    return ans;
}

int main(){

int oddarr[5] = {1,7,7,7,7};
int evenarr[6] = {5,7,7,8,9,9};

cout << "First Occurence 7 is " << FirstOccurence(oddarr,5,7) <<endl;
cout << "Last Occurence 7 is " << LastOccurence(oddarr,5,7) <<endl;

 cout << endl <<endl;
cout << "First Occurence 9 is " << FirstOccurence(evenarr,6,9) <<endl;
cout << "Last Occurence 9 is " << LastOccurence(evenarr,6,9) <<endl;

return 0;
}