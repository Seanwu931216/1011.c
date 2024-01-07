#include <stdio.h>
#define BOARD_SIZE 8
int main() {
    int found, posX, posY, sltDisk, sltColor;
    int i, j, k;
    found=0;
    int reversi[BOARD_SIZE][BOARD_SIZE] = {
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,2,1,0,0,0},
        {0,0,0,1,2,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0}
    };
    scanf("%d%d%d", &posX, &posY, &sltColor);
    sltDisk=reversi[posX][posY];
    printf("%d",sltDisk);
    switch (sltDisk) {
    case 0:
        printf("There is no disk at (%d, %d).\n ", posX, posY);
        if (sltColor==1)
            printf("black ");
        else
            printf("white ");
        //方向向量
        for (i=-1; i<=1; ++i)
            for (j=-1; j<=1; ++j) {
                if (i==0 && j==0)
                    continue;
                //k代表步數
                for (k=1; k<=2; ++k) {
                    if (posX+i*k<0 || posX+i*k>=BOARD_SIZE ||
                        posY+j*k<0 || posY+j*k>=BOARD_SIZE ||
                        reversi[posX+i*k][posY+j*k]==0) 
                            break;
                    if (reversi[posX+i*k][posY+j*k]==sltColor) {
                        if (k!=1)
                            found=1;
                        break;
                    }
                }
                if (found)
                    break;
            }
        if (found)
            printf("disk can be placed here.");
        else
            printf("disk can't be placed here.");
        break;
    case 1:
        printf("The disk at (%d, %d) is black.\nNo new disk can be placed here.", posX, posY);
        break;
    case 2:
        printf("The disk at (%d, %d) is white.\nNo new disk can be placed here.", posX, posY);
        break;
    }
}
