#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){

    int vertex , edges;
    cout << "enter the No of Vertex " ;
    cin >> vertex;
    cout << endl << "enter the No of Edges " ;
    cin >> edges;


    vector<int> AdjList[vertex];

    int u ,v;
     for(int i=0;i<edges;i++){
        cin >> u >> v ;
        AdjList[u].push_back(v);
        AdjList[v].push_back(u);
     }


      for(int i=0;i<vertex;i++){
        cout << i << " -> " ;
        for(int j=0;j<AdjList[i].size();j++){
            cout << AdjList[i][j] << " ";
        }
        cout << endl;
    }

return 0;
}

/**

OUTPUT

enter the No of Vertex 5

enter the No of Edges 6
0 1
1 2
0 2
1 3
3 4
2 4
0 -> 1 2
1 -> 0 2 3
2 -> 1 0 4
3 -> 1 4
4 -> 3 2
 */