#include<iostream>
using namespace std;
#include <vector>
#include <limits.h>


// TC O(n)
// SC O(n)

void TappingWater(vector<int> BuldingHeight){
    int n = BuldingHeight.size();
    int Ans = 0;
    vector<int> LeftMax(n);
    vector<int> RightMax(n);

    LeftMax[0] = 0;
    RightMax[n-1] = 0;

    // find LeftMax 
    for(int i =0;i<n;i++){
        LeftMax[i+1] = max(LeftMax[i],BuldingHeight[i]);
    }

    // also
    // for(int i =1;i<n;i++){
    //     LeftMax[i] = max(LeftMax[i-1],BuldingHeight[i-1]);
    // }


    // Finding Right Max Element
     for(int i =n-1;i>=0;i--){
        RightMax[i-1] = max(BuldingHeight[i],RightMax[i]);
    }


    for(int currentheight=0;currentheight<n;currentheight++){
        int minHeight = min(LeftMax[currentheight],RightMax[currentheight]);
        // cout << minHeight << " " << BuldingHeight[currentheight] << " " << (minHeight-BuldingHeight[BuldingHeight]) << endl;

        // Here is if the minheight is Lessthan currnt Height Then Its Not Possible to store The Answer
        if(minHeight>BuldingHeight[currentheight]){
            Ans +=  minHeight - BuldingHeight[currentheight];
        }
    }   


    cout << Ans;

}

// TC O(n)
// SC O(1)
void TappingWaterWithoutSpace(vector<int> BuldingHeight){
    int n = BuldingHeight.size();
    int Ans = 0;
    int MaxHeight = 0;
    int MaxHeightIndex = 0;

    // 
    int LeftMaxHeight  = BuldingHeight[0] , RightMaxHeight = BuldingHeight[n-1];

    // Find Max Heigth Bulding 
    for(int i =0;i<n;i++){
        if(BuldingHeight[i]>MaxHeight){
            MaxHeight = BuldingHeight[i];
            MaxHeightIndex = i;
        }
    }

   // Find The Ans Until the MaxHeightIndex


//    for(int i = 0;i<MaxHeightIndex;i++){
//     int minHeight = min(LeftMaxHeight,BuldingHeight[MaxHeightIndex]);
//     LeftMaxHeight = max(LeftMaxHeight,BuldingHeight[i]);

//     if(minHeight > BuldingHeight[i]){
//         Ans += minHeight - BuldingHeight[i];
//     }
//    }
   for(int i = 0;i<MaxHeightIndex;i++){
    if(LeftMaxHeight > BuldingHeight[i]){
        Ans += LeftMaxHeight - BuldingHeight[i];
    }else{
            LeftMaxHeight = BuldingHeight[i];
    }
   }


   // Find The  Answer From MaxHeighIndx To End Of Array


//    for(int i=n-1;i>MaxHeightIndex;i--){
//     int minHeight = min(RightMaxHeight,BuldingHeight[MaxHeightIndex]);
//     RightMaxHeight = max(RightMaxHeight,BuldingHeight[i]);


//     if(minHeight > BuldingHeight[i]){
//         Ans += minHeight - BuldingHeight[i];
//     }
//    }


for(int i=n-1;i>MaxHeightIndex;i--){

    if(RightMaxHeight > BuldingHeight[i]){
        cout << "Ans";
        Ans += RightMaxHeight - BuldingHeight[i];
    }else{
            RightMaxHeight = BuldingHeight[i];
    }
   }


   cout << Ans;
}


// Tapping Water using the Two Pointer 
void  TappingWaterTwoPointer(vector<int> height){
        int leftMax = INT_MIN;
        int rightMax = INT_MIN;
        int water = 0;
        int left = 0;
        int right = height.size()-1;

        while(left < right)
        {
            leftMax = max(leftMax,height[left]);
            rightMax = max(rightMax,height[right]);
            if(leftMax < rightMax)
                water += leftMax - height[left++];
            else
                water += rightMax - height[right--];
        }

        cout << water;
}


int main(){

    vector<int> BuldingHeight = {4,2,0,5,2,6,2,7};
    // vector<int> BuldingHeight = {0,1,0,2,1,0,1,3,2,1,2,1};
    // TappingWater(BuldingHeight);
    // TappingWaterWithoutSpace(BuldingHeight);
    TappingWaterTwoPointer(BuldingHeight);


return 0;
}