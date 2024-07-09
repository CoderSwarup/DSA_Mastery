#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <climits>

using namespace std;

// TC O(N)
// SC O(3n)

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    // Next Smallest Right
    vector<int> NSR(n); 
    // Next Smallest Left
    vector<int> NSL(n, -1); 

    // Stack to store indices
    stack<int> s;

    // Find Next Smallest Right for each bar
    for (int i = 0; i < n; i++) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            NSR[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }
    // Assign NSR for remaining bars in the stack
    while (!s.empty()) {
        NSR[s.top()] = n;
        s.pop();
    }

    // Find Next Smallest Left for each bar
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && heights[s.top()] > heights[i]) {
            NSL[s.top()] = i;
            s.pop();
        }
        s.push(i);
    }

    // Calculate the largest rectangle area
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, heights[i] * (NSR[i] - NSL[i] - 1));
    }

    return ans;
}


//mETHOD2   
// tc O(N)

// sc (n)
int largestRectangleAreaM2(vector<int>& heights) {
    int n = heights.size(); 
    //stack
    stack<int> s;
    int ans = INT_MIN;
    int index;
    for(int i=0;i<n;i++){
        while(!s.empty() && heights[s.top()] > heights[i]){
            index = s.top();
            s.pop();
            if(!s.empty()){
                ans = max(ans,heights[index] * (i - s.top() -1));
            }else{
                ans = max(ans,heights[index] * i);
            }
        }
        s.push(i);
    }
     while(!s.empty()){
            index = s.top();
            s.pop();
            if(!s.empty()){
                ans = max(ans,heights[index] * ( n - s.top()-1));
            }else{
                ans = max(ans,heights[index] * n);
            }
        }
    return ans;
    
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    // cout << "The area of the largest rectangle is: " << largestRectangleArea(heights) << endl;
    cout << "The area of the largest rectangle is: " << largestRectangleAreaM2(heights) << endl;
    return 0;
}
