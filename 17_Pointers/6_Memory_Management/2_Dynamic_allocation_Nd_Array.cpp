#include<iostream>
using namespace std;

int main(){

    //Creat a @D Array using Pointer (Dynamic Mmory Location)

    int n ,m; // rows and colums 
    cout << "Enter a Rows And Colums : " ;
    cin >> n >> m;

    // Create a 1d array 
    int **ptr = new int*[n];


    ///create a 2D array 
    for(int i=0;i<n;i++){
        ptr[i] = new int[m];
    }

    //take the Value Inside Array 
    cout << endl <<"Enter a Value inside Array " << (n*m)<< endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> ptr[i][j];
        }
    }

    cout <<  endl << "Print All vlaues Of the Array " << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << *(*(ptr+i)+j) << " "; // also use ptr[i][j]
        }
        cout << endl;
    }


    //Release the heap memory 

    cout << endl << "Release The 1D Array Memory ptr delete[] [n]" << endl;
    for(int i=0;i<n;i++){
        delete[] ptr[i];
    }

    cout << endl << "Release The 2D Array Memory delete[] ptr" << endl;
    delete[] ptr;

return 0;
}