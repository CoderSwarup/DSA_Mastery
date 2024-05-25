#include<iostream>
using namespace std;
#include <bits/stdc++.h>


//Brute Force
double findSmallestMaxDist(vector<int> &stations, int k) {
    // Code here
    int n = stations.size();
    vector<int> HowMany(n-1,0);
    
    for(int newStation = 1;newStation <= k ;newStation++){
         double maxSection =-1;
        int maxIndex = -1;
        
        for(int i =0;i<n-1;i++){
            double diff = stations[i+1] - stations[i];
            double Sectionlen = diff / (double)(HowMany[i]+1);
            if(Sectionlen > maxSection){
                maxSection = Sectionlen;
                maxIndex = i;
            }
        }
        HowMany[maxIndex]++;
        
    }
    
    
     double Ans = -1;
    for(int i =0;i<n-1;i++){
           double diff = stations[i+1] - stations[i];
           double Sectiondiff = diff / (double)(HowMany[i]+1);
          Ans = max(Ans,Sectiondiff);
    }
    
    
    return Ans;
}


// Better
// Time Complexity: O(n logn + k logn),  n = size of the given array, k = no. of gas stations to be placed.

// Space Complexity: O(n-1)+O(n-1)
// Reason: The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue.
 double findSmallestMaxDistBetter(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        priority_queue<pair<double , int>> pq;
        
        // insert the distance in the pq
        for(int i=0;i<n-1;i++){
            double diff = stations[i+1] - stations[i];
            pq.push({diff ,i});
        }
        
        vector<int> howMany(n-1,0);
        
        
        for(int gas=1;gas <= k;gas++){
            auto maxindex = pq.top().second;
            pq.pop();
            howMany[maxindex]++;
            
            
            double diff = stations[maxindex+1] - stations[maxindex];
            double newDiff = diff / (double)(howMany[maxindex]+1);
            
            pq.push({newDiff,maxindex});
            
            
        }
        
        
        return pq.top().first;
}


// binaru search

//Time Complexity: O(n*log(Len)) + O(n)
int numberOfGasStationsRequired(vector<int> &stations, double dist){
      int ctn =0;
      
      for(int i=0;i<stations.size()-1;i++){
          int d = (stations[i+1] - stations[i]);
          int numberOfStationsPlace = d / dist;
          if(d == numberOfStationsPlace){
              numberOfStationsPlace--;
          }
          ctn += numberOfStationsPlace;
      }
      
      return ctn;
      
      
  }
    double findSmallestMaxDistBinarySearch(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
      
        
        double low =0;
        double  high = 0;
        
        for(int i=0;i<n;i++){
             high = max(high, (double)(stations[i + 1] - stations[i]));
        }
        
        double diff = 1e-6 ;
        while(high -low > diff){
            double mid = low + ((high-low)/2.0);
            int cnt = numberOfGasStationsRequired(stations,mid);
            if(cnt > k){
                low = mid;
            }else{
                high = mid;
            }
        }
        
        
        return high;
        
    }
int main(){

    vector<int> stations = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // cout << findSmallestMaxDist(stations,9);
    // cout << findSmallestMaxDistBetter(stations,9);
    cout << findSmallestMaxDistBinarySearch(stations,9);

return 0;
}