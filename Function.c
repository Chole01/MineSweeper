#include "Header.h"


void Banner(){
    printf(" ----------------------\n");
    printf("|      -1- start       |\n");
    printf(" ----------------------\n");
    printf("|      -2- quit        |\n");
    printf(" ----------------------\n");
}

void Mine_Zone(int row, int col, char arry_matrix[_ROW_][_COL_]){
    int num_col;
    int num_row;
    for(num_row=0; num_row<row; num_row++){
        for(num_col=0;num_col<col;num_col++){
            printf(" ---");
        }
        printf("\n");
        for(num_col=0;num_col<col;num_col++){
            printf("| %c ", arry_matrix[num_row][num_col]);
        }
        printf("|");
        printf("\n");
        if(num_row==row-1){
            for(num_col=0;num_col<col;num_col++){
                printf(" ---");
            }
        }       
    }
}

void Matrix_Zone(int row, int col, char arry_matrix[_ROWS_][_COLS_]){
    int num_col;
    int num_row;
    for(num_row=0; num_row<row-1; num_row++){
        for(num_col=0;num_col<col-1;num_col++){
            printf(" ---");
        }
        printf("\n");
        for(num_col=0;num_col<col-1;num_col++){
            printf("| %c ", arry_matrix[num_row][num_col]);
        }
        printf("|");
        printf("\n");
        if(num_row==row-2){
            for(num_col=0;num_col<col-1;num_col++){
                printf(" ---");
            }
        }       
    }    
}

void InitMatrix(char arry[_ROWS_][_COLS_], char c){
    int num_col;
    int num_row;
    for(num_col=0;num_col<_COLS_;num_col++){
        for(num_row=0;num_row<_ROWS_;num_row++){
            arry[num_row][num_col]= c;
        }
    }
}

void SetMine(char arry[_ROW_][_COL_]){
    int count_mine=0;
    srand((unsigned int)time(NULL)); 
    while(count_mine<NUM_MINE){
        int x =rand()%_ROW_;
        int y =rand()%_COL_;
        if(arry[x][y]!=MINE){
            arry[x][y]=MINE;
            count_mine++;
        }
    }
}

void InitMine(char arry[_ROW_][_COL_], char c){
    int num_col;
    int num_row;
    for(num_col=0;num_col<_COL_;num_col++){
        for(num_row=0;num_row<_ROW_;num_row++){
            arry[num_row][num_col]= c;
        }
    }
}

void InitGame(char arry_mine[_ROW_][_COL_],char arry_matrix[_ROWS_][_COLS_]){
    InitMine(arry_mine,SPACE);
    SetMine(arry_mine);
    InitMatrix(arry_matrix, DIAMOND);
}

int Num_Mine(int x, int y, char arry_mine[_ROW_][_COL_], char arry_matrix[_ROWS_][_COLS_]){
    int num_mine,m,n;
    num_mine=0;
    for(m=x-1;m<=x+1;m++){
        for(n=y-1;n<=y+1;n++){
            if (arry_mine[m][n]==MINE){
                num_mine++;
            }
        }
    }
    if (num_mine==0){
        arry_matrix[x][y]=SPACE;
    }
    else{
        arry_matrix[x][y]=num_mine+48;//ascii 48-->0
    }
}

void Spread(int x, int y, char arry_mine[_ROW_][_COL_], char arry_matrix[_ROWS_][_COLS_]){
    int temp_x,temp_y;
    for(temp_x=x-1;temp_x<=x+1;temp_x++){
        for(temp_y=y-1;temp_y<=y+1;temp_y++){
            if(arry_matrix[temp_x][temp_y]!=DIAMOND){
                continue;
            }
            else{
                Num_Mine(temp_x,temp_y,arry_mine,arry_matrix);
                if(arry_matrix[temp_x][temp_y]==SPACE){
                    Spread(temp_x,temp_y,arry_mine,arry_matrix);
                }
            }
        }
    }
}

void GameOver(char arry_mine[_ROW_][_COL_], char arry_matrix[_ROWS_][_COLS_]){
    int x,y=0;
    for(x=0;x<=_ROW_;x++){
        for(y=0;y<=_COL_;y++){
            if(arry_mine[x][y]==MINE){
                arry_matrix[x][y]=MINE;
            }
        }
    }
}

void PlayGame(char arry_mine[_ROW_][_COL_],char arry_matrix[_ROWS_][_COLS_]){
    Matrix_Zone(_ROWS_,_COLS_,arry_matrix);
    printf("\n");
    int x,y;
    while(1){
        scanf("%d %d", &x, &y);
        if(arry_mine[x][y]==MINE){
            //Mine_Zone(_ROW_,_COL_,arry_mine);
            printf("\n");
            printf("boom! game over!\n");
            GameOver(arry_mine,arry_matrix);
            Banner();
            break;
        }
        else{
            Num_Mine(x,y,arry_mine,arry_matrix);
            if(arry_matrix[x][y]==SPACE){
                Spread(x,y,arry_mine,arry_matrix); 

            }
        }
        Matrix_Zone(_ROWS_,_COLS_,arry_matrix);
        printf("\n");   
    }
    Matrix_Zone(_ROWS_,_COLS_,arry_matrix);
    printf("\n");
}



