//Sudoku Puzzle Solver using C
#include<stdio.h>

int row(int [9][9],int , int , int);
int column(int [9][9],int, int , int);
int square(int [9][9] ,int , int , int);
int solve(int [9][9], int , int);
void print(int [9][9]);

int main(){
    int sudoku[9][9]={{5,3,0,0,7,0,0,0,0},
		      {6,0,0,1,9,5,0,0,0},
		      {0,9,8,0,0,0,0,6,0},
                      {8,0,0,0,6,0,0,0,3},
                      {4,0,0,8,0,3,0,0,1},
                      {7,0,0,0,2,0,0,0,6},
                      {0,6,0,0,0,0,2,8,0},
                      {0,0,0,4,1,9,0,0,5},
                      {0,0,0,0,8,0,0,7,9}};
    printf("\tThe Sudoku Solver\n");
    /*printf("Enter the input of Sudoku: \n");
    for(int i=0;i<9;i++){
        printf("Enter the input of Row %d: ",i+1);
        for(int j=0;j<9;j++){
            scanf("%d",&sudoku[i][j]);
        }
    }
    printf("\n");*/
    if(solve(sudoku,0,0))
    	print(sudoku);
}

void print(int sudoku[9][9]){
    printf("\nSolved Sudoku:\n");
    for (int i = 0; i < 9; i++){
       for (int j = 0; j < 9; j++){
            printf("%d ",sudoku[i][j]);
       }
        printf("\n");
    }
}


int solve(int sudoku[9][9],int x, int y){
    int num=1;
    int x1=0,y1=0;
    if(sudoku[x][y]!=0){
        if(x==8&&y==8){
            return 1;
        }
        if(x<8){
            x++;
        }
        else{
		if(y<8){
               		x=0;
               		y++;
		}
        }
        if(solve(sudoku,x,y)){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(sudoku[x][y]==0){
        while(num<10){
            if(!square(sudoku,x,y,num) && !row(sudoku,x,y,num) && !column(sudoku,x,y,num)){
            	sudoku[x][y]=num;
            	if(x==8&&y==8){
                	return 1;
            	}
            	if(x<8){
                	    x1=x+1;
            	}
            	else{
			if(y<8){
                            x1=0;
                            y1=y+1;
			}
            	}
            	if(solve(sudoku,x1,y1)){
                    	return 1;
            	}
	    }
	    num++;
        }
    	sudoku[x][y]=0;
    	return 0;
    }
}


int row(int sudoku[9][9],int x, int y, int num){
     for(int i=0;i<9;i++){
        if(sudoku[i][y] == num)
        return 1;
    }
    return 0;
}

int column(int sudoku[9][9],int x, int y, int num){
    for(int i=0;i<9;i++){
        if(sudoku[x][i] == num)
        return 1;
    }
    return 0;
}

int square(int sudoku[9][9],int x, int y, int num){
     if(x < 3){
        x=0;
    }
    else if(x < 6){
        x=3;
    }
    else{
        x=6;
    }
    if(y < 3){
        y=0;
    }
    else if(y < 6){
        y=3;
    }
    else{
        y=6;
    }
    for(int i=x;i<x+3;i++){
        for(int j=y;j<y+3;j++){
            if(sudoku[i][j]==num)
            return 1;
        }
    }
    return 0;
}
