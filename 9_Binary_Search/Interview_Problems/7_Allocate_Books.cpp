#include<iostream>
using namespace std;
#include <vector>

int isPossibleWay(vector<int> arr, int n, int m,int mid){

    int StudentCount = 1;
    int pagesum = 0;

    for(int i = 0;i<n;i++){
        if (pagesum+ arr[i] <= mid) {
            pagesum += arr[i];
        }else{
            StudentCount++;

            if(StudentCount > m || arr[i] > mid){
                return false;
            }

            pagesum = arr[i];
        }

        if(StudentCount > m) {
            return false;
        }

    }

    return true;
}
int allocateBooks(vector<int> arr, int n, int m){

    int s = 0;
    int sum = 0;

    for(int i=0;i<n;i++){
        sum += arr[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s+ (e-s)/2;

    while(s<=e){
        if(isPossibleWay(arr,n,m,mid)){
            ans = mid;
            e = mid -1;
        }else{
            s = mid +1;
        }
        mid = s+ (e-s)/2;

    }

    return ans;

}
int main(){
    vector<int> arr = {12, 34, 67, 90};
    int n = arr.size();
    int m = 2;
    int bookAllocate = allocateBooks( arr, n,  m);
    cout << "Number of books that can be allocated is: "<<bookAllocate<< endl;
return 0;
}