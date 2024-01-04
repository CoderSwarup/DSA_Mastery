
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

int oddFindex =FirstOccurence(oddarr,5,7);
int oddLindex= LastOccurence(oddarr,5,7);
int Occurence = (oddLindex - oddFindex ) +1;

cout<<"Number of Occurece of 7 is " << Occurence << endl;

 cout << endl <<endl;
int evenFI = FirstOccurence(evenarr,6,9);
int evenLI =LastOccurence(evenarr,6,9);
int Occurence2 = (evenLI - evenFI ) +1;

cout<<"Number of Occurece of 9 is " << Occurence2 << endl;
return 0;
}