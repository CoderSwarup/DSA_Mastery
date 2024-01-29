#include<iostream>
using namespace std;
#include <vector>
#include <algorithm>




void FourSumTwoPointer(vector<int> arr,int target){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    bool isAns = false;

    for(int i =0;i< n-3;i++){
        for(int j=i+1;j<n-2;j++){
            int newTarget = target - (arr[i] + arr[j]);

            int s = j+1;
            int e = n-1;

            while(s<e){
                int Sum =  arr[s]+arr[e];
                if(Sum == newTarget){
                    cout<<""<<arr[i]<<" "<<arr[j]<<" "<<arr[s]<<" "<<arr[e]<<" are the answer pair."<<endl;
                    isAns = true;
                    break;
                }else if(Sum > newTarget){
                    e--;
                }else{
                    s++;
                }
            }
        }
    }


      if(!isAns){
        cout << "Target is Not Present";
    }
}
int main(){

    vector<int> arr = {1,4,45,6,10,8};
    FourSumTwoPointer(arr,56);



return 0;
}