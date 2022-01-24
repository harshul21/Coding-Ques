int climbing_stairs(int n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 1;
    }
    int left=climbing_stairs(n-1);
    int right=climbing_stairs(n-2);
    return left+right;
}
