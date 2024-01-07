#include <stdio.h>
#define BOARD_SIZE 8

int find_chess(int arr[BOARD_SIZE][BOARD_SIZE],int x,int y,int Disk){
    int i,j,k;
    int found;
    switch (Disk) {
    case 0:
        //方向向量
        for (i=-1; i<=1; ++i)
            for (j=-1; j<=1; ++j) {
                if (i==0 && j==0)
                    continue;
                //k代表步數
                int temp,value;
                for (k=1; k<=BOARD_SIZE; ++k) {
                    if (x+i*k<0 || x+i*k>=BOARD_SIZE ||
                        y+j*k<0 || y+j*k>=BOARD_SIZE ||
                        arr[x+i*k][y+j*k]==0) 
                            break;
                    value = arr[x+i*k][y+j*k];
                    temp = arr[x+i*(k+1)][y+j*(k+1)];
                    if (k!=1 && found!=temp){
                        return 1;
                    }
                }
                return 0;
            }
        if (!found)
            return 0;
        break;
    case 1:
        return 0;
        break;
    case 2:
        return 0;
        break;
    }
}
void print_steps(int arr[BOARD_SIZE][BOARD_SIZE],int x,int y ,int Color){
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++){
            //k代表步數
            int temp = 0,value = 0;
            for (int k=1; k<=BOARD_SIZE; ++k) {
                if (x+i*k<0 || x+i*k>=BOARD_SIZE ||
                    y+j*k<0 || y+j*k>=BOARD_SIZE ||
                    arr[x+i*k][y+j*k]==Color) 
                    break;
                if(k == 1 && arr[x+i*k][y+j*k] == 0)
                    break;
                value = arr[x+i*k][y+j*k];
                temp = arr[x+i*(k-1)][y+j*(k-1)];
                if (value == 0 && temp != Color && temp != 0) {
                        printf("(%d,%d)",x+i*k,y+j*k);
                }
            }
        }
}

int main() {
    int  posX, posY,sltDisk;
    int reversi[BOARD_SIZE][BOARD_SIZE] = {
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,1,1,1,0,0},
                     {0,0,0,2,1,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0},
                     {0,0,0,0,0,0,0,0}
                };
    scanf("%d%d", &posX, &posY);
    sltDisk=reversi[posX][posY];
    printf("%d",find_chess(reversi[BOARD_SIZE][BOARD_SIZE],posX,posY,sltDisk));
    
    printf("\n白子可下位置:\n");
    for(int i=0;i<BOARD_SIZE;i++)
        for(int j=0;j<BOARD_SIZE;j++){
            if(reversi[i][j] == 1){
                print_steps(reversi,i,j,reversi[i][j]);
            }
    }
   printf("\n黑子可下位置:\n");
   for(int i=0;i<BOARD_SIZE;i++)
        for(int j=0;j<BOARD_SIZE;j++){
            if(reversi[i][j] == 2){
                print_steps(reversi,i,j,reversi[i][j]);
            }
        }
}
