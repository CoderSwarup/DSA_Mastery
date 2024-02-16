#include<iostream>
using namespace std;
#include<vector>
void LPS(vector<int>&lps,string s){
    int n = s.size();
    int preffix = 0;
    int suffix = 1;

    while(suffix<n){
        if(s[preffix]==s[suffix])
        {  
            lps[suffix] = preffix+1;
            suffix++;
            preffix++;
        }else{
            if(preffix==0){
                lps[suffix] =0;
                suffix++;
            }else{
                preffix = lps[preffix-1];
            }
        }
    }


}


vector <int> searchPattern(string s1,string s2){
    int n = s1.size() , m=s2.size();
    vector<int>lps(m,0);
    vector<int>ocuurStartLength;

    int first =0;
    int second =0;

    LPS(lps,s2);

    while(first < n && second <m){

        if(s1[first] == s2[second]){
            first++;
            second++;
        }
        else{
            if(second == 0){
                first++;
            }else{
                second = lps[second-1];
            }
        }


        if(second ==m){
            ocuurStartLength.push_back(first - second+1);
            second =0;
        }
       
    } 
     
    cout << ocuurStartLength.size() <<endl;

    if(ocuurStartLength.size() == 0){
        ocuurStartLength.push_back(-1);
    }
    
    cout << ocuurStartLength.size() <<endl;
     
    return ocuurStartLength;

}

int main(){

    string s1 = "geeksforgeeks";
    string s2 = "geek";

   vector<int> MAP = searchPattern(s1,s2);
   for(auto i:MAP){
    cout << i << " ";
   }

return 0;
}