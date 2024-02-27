#include<iostream>
using namespace std;
#include <set>
#include <vector>

//Brute Force 
//Time Compleixty : O( (m+n)log(m+n) ) 
// SC O(N+M)
vector < int > sortedArray(vector < int > a, vector < int > b) {
    // Write your code here
    set<int> Unique;
    vector<int> ans;

    // find arr 1 unique log(n)
    for(int i=0;i<a.size();i++){
        Unique.insert(a[i]);
    }

     // find arr 2 unique log(m)
    for(int i=0;i<b.size();i++){
        Unique.insert(b[i]);
    }

    for(auto i :Unique){
        ans.push_back(i);
    }

    return ans;
}


// optimal 
// TC )(M+N)
// SC O(m+N)
vector < int > sortedArrayOptimal(vector < int > a, vector < int > b) {
    // Write your code here
    vector<int> Union;
    int index1 = 0 , index2 =0;

    while(index1 < a.size() && index2 <b.size())
    {
        if(a[index1] < b[index2]){
            if( Union.size() == 0 || Union.back() != a[index1]){
                Union.push_back(a[index1]);

            }
            index1++;
        }else{
            if(Union.size() == 0 || Union.back() != b[index2]){
                Union.push_back(b[index2]);
            }
            index2++;
        }
    }

    while(index1 < a.size() )
    {
            if(Union.size() == 0 || Union.back() != a[index1]){
                Union.push_back(a[index1]);
            }
            index1++;
    }

    while(index2 < b.size() )
    {
            if( Union.size() == 0 || Union.back() != b[index2]){
                Union.push_back(b[index2]);
            }
            index2++;
    
    }


    
    return Union;
}


int main(){
    vector<int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    vector<int> b= {2, 3, 4, 4, 5, 11, 12};

    // vector < int > Union = sortedArray(a,b);
    vector < int > Union = sortedArrayOptimal(a,b);
    cout << "Union of arr1 and arr2 is  " << endl;
    for (auto val: Union)
    cout << val << " ";


return 0;
}