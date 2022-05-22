#include "Header.h"

int main(){
    SetConsoleOutputCP(437);//allowing terminal print ascii charicters
    Banner();
    char mine[_ROW_][_COL_];
    char matrix[_ROWS_][_COLS_];
    int opt = 0;
    while(1){
        scanf("%d", &opt);
        switch (opt)
        {
        case 1 :
            InitGame(mine,matrix);
            PlayGame(mine,matrix);
            break;        
        case 2 :
            printf("quit");
            break;
        }
    }
    return 0 ;
}