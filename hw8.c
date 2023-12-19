#include <stdio.h>
#define size 1000
int walk_maze_function(int arr[][1000],int n,int i,int j){
    if(i<0 || j<0 ||i>=n ||j>=n)
        return 0;
    if(arr[i][j]==1)
        return 0;
    if(i==0 && j==0)
        return 1;//找到出口，要遍歷到出口至少需要一條路徑

    arr[i][j]=1;//把走過的格子變1，不然會重複計算

    int up = walk_maze_function(arr,n,i-1,j);//遞迴，若最後ij都0就是有路
    int left = walk_maze_function(arr,n,i,j-1);//沒路就會是0
    int right = walk_maze_function(arr,n,i,j+1);
    int down = walk_maze_function(arr,n,i+1,j);

    if(up || left || right || down)
        return 1;
    else
        return 0;
}
int main() {
    int n;
    int arr[size][size];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&arr[i][j]);
        }
    if(walk_maze_function(arr,n,n-1,n-1)==1)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
