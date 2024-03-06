#include<iostream>
using namespace std;
#include <bits/stdc++.h>


// There’s an array ‘A’ of size ‘N’ with an equal number of positive and negative elements. Without altering the relative order of positive and negative elements, you must return an array of alternately positive and negative values.

// Note: Start the array with positive elements.


// here the Psositive and negative are eualles

// Brute force 1
vector<int> RearrangeElementBruteForce(vector<int>arr){
    vector<int> Pos;
    vector<int> neg;

    //
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            Pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }

    int c1=0;
    int c2 =0;


    for(int i=0;i<arr.size();i++){
        if(i%2 == 0){
            arr[i]=Pos[c1];
            c1++;
        }else{
            arr[i] = neg[c2];
            c2++;
        }
    }


    // also use Following 
    for(int i=0;i<arr.size()/2;i++){
      
      arr[2*i] = Pos[i];
      arr[2*i+1] = neg[i];
    }
  

    return arr;

}


//Optimal 
// TC O(N)
// SC O(N)

vector<int> RearrangeElementOptimal(vector<int>arr){
    vector<int> ans(arr.size());
    int posIndex =0;
    int negativeIndex = 1;
    //
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            ans[posIndex] = arr[i];
            posIndex+=2;
        }else{
            ans[negativeIndex] = arr[i];
            negativeIndex+=2;
        }
    }



    return ans;

}



// Variety 2

// positive and negative not equals 


vector<int> RearrangeElementVariety2(vector<int>arr){
    vector<int> pos;
    vector<int>neg;

    // f
    for(int i=0;i<arr.size();i++){
        if(arr[i]>0){
            pos.push_back(arr[i]);
        }else{
            neg.push_back(arr[i]);
        }
    }

    // Main code
    int posindex =0 ;
    int negindex =0;
    int index = 0;

    while(posindex < pos.size() && negindex < neg.size() ){
        
        if(index%2 ==0){
            arr[index] = pos[posindex];
            posindex++;
        }else{
            arr[index] = neg[negindex];
            negindex++;
        }
        index++;

    }

    // if the positive Remains
    while(posindex < pos.size()){
        arr[index++] = pos[posindex++];
    }

        // if the negative Remains
    while(negindex < neg.size()){
        arr[index++] = neg[negindex++];
    }


    // also we use if pos.size > neg.size() on this condition 


    return arr;
}

int main(){
     vector<int> A {1,2,-4,-5};
    //  vector<int> ans = RearrangeElementBruteForce(A);
     vector<int> ans = RearrangeElementOptimal(A);

     for(auto i:ans){
        cout << i << " ";
     }


     cout << endl << "variety 2" << endl;
    vector<int> arr = {1,2,-4,-5,3,4};

    vector<int> ans2 = RearrangeElementVariety2(arr);

    for(auto i:ans2){
        cout << i << " ";
     }


return 0;
}