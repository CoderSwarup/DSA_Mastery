#include<iostream>
using namespace std;
#include <map>
#include <limits.h>
#include <vector>
void Frequence(vector<int> &v) {
   

    int n = v.size();
    map<int, int> hash;

    int Lowest_Frequency_Value = INT_MAX;
    int Highest_Frequency_Value = INT_MAX;


    int highest_frequency= 0;
    int lowest_frequency = INT_MAX;

    for(int i = 0; i < n; i++) {
        hash[v[i]]++;
    }
    
    for(auto i:hash){
        // cout << i.first << " -> " << i.second <<endl;
        if(i.second > highest_frequency){
            if(i.second == highest_frequency){
                Highest_Frequency_Value = min(Highest_Frequency_Value, i.first);
            }else{
                Highest_Frequency_Value = i.first;
            }
            highest_frequency= i.second;
        }

        if(i.second < lowest_frequency){
            if(i.second == lowest_frequency){
                Lowest_Frequency_Value = min(Lowest_Frequency_Value,i.first);
            }else{
                Lowest_Frequency_Value = i.first;
            }
            lowest_frequency = i.second;
        }
    }




    vector<int> Result = {Highest_Frequency_Value,Lowest_Frequency_Value};

    for(auto i:Result){
        cout << i << " ";
    }

    // cout << highest << " " <<lowest << endl;
    // cout << highest_Value << " "  << lowest_Value;
}

int main(){

    // vector<int> arr = {1 ,2 ,3 ,1 ,1 ,4};
    vector<int> arr =  {11, 13, 3, 14, 17, 3, 7, 9, 1, 11, 9, 15, 5, 2, 2, 3};

    Frequence(arr);


return 0;
}

