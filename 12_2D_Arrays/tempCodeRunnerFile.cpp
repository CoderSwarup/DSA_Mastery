     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){

            // cout<< matrix[i][j] << " ";
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i]=temp;
        }
    }