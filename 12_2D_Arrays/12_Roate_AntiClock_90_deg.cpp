#include<iostream>
#include<vector>

using namespace std;

void printArray(vector<vector<int>> matrix){
    int n = matrix.size();
    int m = matrix[0].size();


     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << matrix[i][j] << " ";

        }

        cout << endl;

    }

}





// Transpose ==> Reverse Column 
void Rotate(vector<vector<int>> &matrix){
    int n = matrix.size();

    // transpose 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
           swap(matrix[i][j],matrix[j][i]);
        }
    }

    // revese column
    for(int i=0;i<n;i++){
        int s =0;
        int e = n-1;
        while(s<e){
            swap(matrix[s][i],matrix[e][i]);
            s++;
            e--;
        }
    }

}


// Reverse row ==> Transpose
void Rotate2(vector<vector<int>> &matrix){
    int n = matrix.size();


   // revese column
    for(int i=0;i<n;i++){
        int s =0;
        int e = n-1;
        while(s<e){
            swap(matrix[i][s],matrix[i][e]);
            s++;
            e--;
        }
    }
    // transpose 
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
           swap(matrix[i][j],matrix[j][i]);
        }
    }

 

}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3,4}, { 5, 6,7,8}, {9,10,11,12},{13,14,15,16}};

   vector<vector<int>> matrix2 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};


    
    printArray(matrix2);
    // Rotate(matrix2); 
    Rotate2(matrix2); 
    printArray(matrix2);
    return 0;
}
