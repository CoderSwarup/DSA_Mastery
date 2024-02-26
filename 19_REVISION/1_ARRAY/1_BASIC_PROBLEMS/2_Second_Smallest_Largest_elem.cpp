#include<iostream>
using namespace std;
#include <vector>
#include <limits.h>
vector<int> getSecondOrderElements(int n, vector<int> arr) {
    // Write your code here.
    vector<int> ans;
    if(n == 0 || n ==1){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }

    int FIRST_SMALLEST = INT_MAX;
    int FIRST_LARGEST = INT_MIN;

    // find first Largest and Smallest
    for(int i=0;i<n;i++){
        if(arr[i] > FIRST_LARGEST ){
            FIRST_LARGEST = arr[i];
        }
        if(arr[i] < FIRST_SMALLEST){
            FIRST_SMALLEST = arr[i];
        }
    }


    int SECOND_SMALLEST = INT_MAX;
    int SECONG_LARGEST = INT_MIN;

    for(int i=0;i<n;i++){
        if(arr[i] != FIRST_LARGEST && arr[i] > SECONG_LARGEST ){
            SECONG_LARGEST = arr[i];
        }
        if(arr[i] != FIRST_SMALLEST && arr[i] < SECOND_SMALLEST){
            SECOND_SMALLEST = arr[i];
        }
    }

    ans.push_back(SECONG_LARGEST);
    ans.push_back(SECOND_SMALLEST);

    return ans;

}

int main(){

    vector<int> arr = {1, 2, 3, 4, 5};
    vector<int> ans = getSecondOrderElements(arr.size(),arr);

    cout << "Largest : "  << ans[0] << endl; 
    cout << "Smallest : "  << ans[1] << endl; 

return 0;
}