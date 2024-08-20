#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){


    int vertex ,edges;
    cout << "enter the No of Vertex " ;
    cin >> vertex;
    cout << endl << "enter the No of Edges " ;
    cin >> edges;


    // vector<vector<bool> > AdjMat(vertex,vector<bool>(vertex,0)); // unDir and UnWeight
    vector<vector<int> > AdjMat(vertex,vector<int>(vertex,0)); // unDire and Weight


    int u ,v , weight;

    for(int i=0;i<edges;i++){
        cin >> u >> v >> weight;
        
        AdjMat[u][v] = weight;
        AdjMat[v][u] = weight;
    }

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout << AdjMat[i][j] << " ";
        }
        cout << endl;
    }



return 0;
}

/*

 undirected and unweighted
enter the No of Vertex 5 

enter the No of Edges 6
0 1
0 2
1 2
1 3
2 4
3 4
0 1 1 0 0
1 0 1 1 0
1 1 0 0 1
0 1 0 0 1
0 0 1 1 0
*/