#include<iostream>
using namespace std;

void RotateClockWise(string &s){
    int n = s.size()-1;
    char chr = s[n] , chr2 = s[n-1];
    for(int i=n-1;i>=0;i--){
        s[i+2] = s[i];
    }

    s[1] =  chr;
    s[0] = chr2;
}

void RotateAntiClockWise(string &s){
    int n = s.size()-1;
    char chr = s[0] , chr2 = s[1];

    for(int i=2;i<=n;i++){
        s[i-2] = s[i];
    }

    s[n-1] = chr;
    s[n] = chr2;

}


// Optimal
// TC O(1) 
 bool isClockwise(string &str1, string &str2){
        int n = str1.size();
        for(int i=0; i<n; ++i){
            if(str1[i]!=str2[(i+2)%n]) return false;
        }
        
        return true;
}
    
bool isRotated(string str1, string str2)
{
        return isClockwise(str1, str2) || isClockwise(str2, str1);
}

int main(){

    string str1 = "amazon";
    string str2 = "azonam";

    if(str1 == str2){
        cout << "False";
    }
    string clockwise = str1;

    RotateClockWise(clockwise);

    if(clockwise == str2){
        cout << "Clock wise";
    }

    string antiClock = "amazon";
    RotateAntiClockWise(antiClock);


    if(antiClock == str2){
        cout << "Anti clock Wise";
    }


    // Approach Two 
    
    // cout << isRotated(str1,str2);

return 0;
}