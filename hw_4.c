#include <stdio.h>
#define board_size  8

int main() {
    int i, j,value,k;
    int chessy[8][8];
    
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            scanf("%d", &(chessy[i][j]));//i雖然是x座標，但決定的是哪一列，而j則是決定哪一行
        }
    }
    int x ,y;
    scanf("%d %d",&x,&y);
    value = chessy[x][y];
    if(value != 0){
        for ( i = -1; i <= 1; i++){//1,0,-1代表方向向量
            for(j = -1;j<= 1 ;j++){
                if( i==0 && j==0)continue;//待在自己原本的的位置上，故不考慮，繼續for迴圈
                for(k=1;k<board_size;k++){
                    if(x+i*k<0 ||x+i*k>(board_size-1)||//i、j從0~7，需考慮大於7小於0的可能
                       y+j*k<0 ||y+j*k>(board_size-1)||
                       chessy[x+i*k][y+j*k]==value)break;//從原本位置開始找，找到跟自己同色則breeak
                    if(chessy[x+i*k][y+j*k]==0){
                        if(k!=1){
                            printf("%d,%d\n",x+i*k,y+j*k);
                        }
                    }
                }
            }
        }
    }
        return 0;
}
