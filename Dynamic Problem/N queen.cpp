bool isSafe(int row,int col,vector<string> board,int n){
    int row1=row;
    int col1=col;
    while(row>=0 and col>=0){
        if(board[row][col]=='Q'){
            return false;
        }
        row--;
        col--;
    }

    row=row1;
    col=col1;

    while(col1>=0){
        if(board[row1][col1]=='Q'){
            return false;
        }
        col1--;
    }

    row1=row;
    col1=col;

    while(row1<n and col1>=0){
        if(board[row1][col1]=='Q'){
            return false;
        }
        row1++;
        col1--;
    }
    return true;

}
void solve(int col,vector<string> board,vector<vector<string>> ans,int n){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(isSafe(row,col,board,n)){
            board[row][col]='Q';
            solve(col+1,board,ans,n);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,board,ans,n);
    return ans;
}
