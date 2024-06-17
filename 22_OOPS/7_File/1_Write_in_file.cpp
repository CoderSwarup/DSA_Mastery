#include<iostream>
using namespace std;
#include <fstream>
int main(){

    // open file
    ofstream fout;
    fout.open("file.txt"); // if file not Exist then it Create 

    // write file 
    fout <<"Hello Bro \n NEW FILE IS ";

    fout.close();  // Release Resources

return 0;
}