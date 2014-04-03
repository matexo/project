#include "matrix.h"
#include "neighbors.h"
#include "population.h"

int is_alive(int a , int b , int **board , int n , int m)
	{
	int life_nei=life_neighbor(a,b,board,n,m);
	if(board[a][b]==2 && life_nei==3) return 1;
	else if(board[a][b]==1 && (life_nei==2 || life_nei==3)) return 1;
	else return 0;
	}
