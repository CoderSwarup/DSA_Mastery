
    for(int k=0;k<4;k++){
        if(isValid(i+row[k],j+col[k],n)&&matrix[i+row[k]][j+col[k]]&&!isVisited[i+row[k]][j+col[k]]){

            path.push_back(dir[k]);
            RatInMaze(matrix,i+row[k],j+col[k],n,ans,path,isVisited);
            path.pop_back();
        
         }
    }