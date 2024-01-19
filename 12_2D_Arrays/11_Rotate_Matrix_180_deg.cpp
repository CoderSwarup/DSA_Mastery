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




// Optimal // but here is condition is n*m is same 
// Time Complexity O(n^2)
// Space Complexity O(1) 
void Rotate180Optimal(vector<vector<int>> &matrix){
    int n = matrix.size();

 
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
 
    
   for(int i=0;i<n;i++){
        int s =0;
        int e = n-1;
        while(s<e){
            swap(matrix[i][s],matrix[i][e]);
            s++;
            e--;
        }
    }
    

}



int main() {
    // vector<vector<int>> matrix = {{1, 2, 3,4}, { 5, 6,7,8}, {9,10,11,12},{13,14,15,16}};
    vector<vector<int>> matrix = {{1, 2, 3,4}, { 5, 6,7,8}, {9,10,11,12},{13,14,15,16}};




    
    Rotate180Optimal(matrix);
    printArray(matrix);
    return 0;
}
