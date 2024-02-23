#include<iostream>
using namespace std;

int main(){

    int n,m, k;
    cin >> n >> m >> k; 
    //
    int ***ptr = new int **[n];

    // create  a 2D Array 
    for(int i=0;i<n;i++){
        
        ptr[i] = new int *[m];
    }

    // create  a 1D Array 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                ptr[i][j] = new int[k];
            
        }
        
    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int c=0;c<k;c++){
                cin>> ptr[i][j][c];
            }
        }
        
    }


   // Print the 3D array to verify the values
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            for(int c=0; c<k; c++){
                cout << *(*(*(ptr+i)+j)+c)  << " "; //ptr[i][j][c]
            }
            cout << endl;
        }
        cout << endl;
    }  
    
    
    
      // Free the allocated memory
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            // release 1d array 
            delete [] ptr[i][j];
        }
        // release 2d array 
        delete [] ptr[i];
    }
    // release 3d array 
    delete [] ptr;


return 0;
}

// What is Wrong in this file ?

