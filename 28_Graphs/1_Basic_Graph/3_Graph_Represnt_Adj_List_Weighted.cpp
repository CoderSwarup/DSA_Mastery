#include<iostream>
using namespace std;
#include <bits/stdc++.h>

int main(){

    int vertex , edges;
    cout << "enter the No of Vertex " ;
    cin >> vertex;
    cout << endl << "enter the No of Edges " ;
    cin >> edges;


    vector<pair<int,int> > AdjList[vertex];

    int u ,v ,w;
     for(int i=0;i<edges;i++){
        cin >> u >> v >> w ;
        AdjList[u].push_back(make_pair(v,w));
        AdjList[v].push_back(make_pair(u,w));
     }


      for(int i=0;i<vertex;i++){
        cout << i << " -> " ;
        for(int j=0;j<AdjList[i].size();j++){
            cout << AdjList[i][j].first << " " << AdjList[i][j].second << " "; 
        }
        cout << endl;
    }

return 0;
}

/**

OUTPUT
enter the No of Vertex 5

enter the No of Edges 6
0 1 10
0 2 5
1 2 9
1 3 8
3 4 11
2 4 5
0 -> 1 10 2 5
1 -> 0 10 2 9 3 8
2 -> 0 5 1 9 4 5
3 -> 1 8 4 11
4 -> 3 11 2 5

 */