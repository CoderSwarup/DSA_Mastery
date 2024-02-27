#include<iostream>
using namespace std;

#include<vector>

//  Brute force approach 
// TC O(n)
// SC O(n)

vector<int> moveZeros(int n, vector<int>& a) {
    // Write your code here.
    vector<int> ans(n);
    int j =0;

    // for non zeros 
    for(int i=0;i<n;i++){
        if(a[i] != 0){
            ans[j] = a[i];
            j++;
        }
    }
    // zeros 
    for(int i=0;i<n;i++){
        if(a[i] == 0){
            ans[j] = a[i];
            j++;
        }
    }
    

    return ans;
}


// optimal 
// SC O(1)
// TC O(n)
vector<int> moveZerosOptimal(int n, vector<int>& a) {

    // find the first 0 value index position 
    int j = -1;
    for(int i=0;i<n;i++){
        if(a[i] == 0){
            j= i;
            break;
        }
    }

    if(j == -1) return a;

    // now main swapping from j+1 to n
    for(int i=j+1;i<n;i++){
        if(a[i] != 0){
            swap(a[j],a[i]);
            j++;
        }
    }
    return a;
}

int main(){
  vector<int> arr = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
//   vector<int>ans = moveZeros(arr.size(),arr);
  vector<int>ans = moveZerosOptimal(arr.size(),arr);

  for (int i = 0; i <  ans.size(); i++)
   {
    cout << ans[i] << " ";
    }

return 0;
}