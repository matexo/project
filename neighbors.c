#include "population.h"

int is_edge(int a , int b , int n , int m)
	{
	if(a<0 || b<0 || a>=n || b>=m)
		return 1;
	else return 0;
	}

int life_neighbor(int a , int b , int **board , int n , int m)		
	{
	int neighbor=0;
	int i,j;
	for(i=a-1 ; i<a+2 ; i++)
		for(j=b-1 ; j<b+2 ; j++)
			{
			if(i==a && j==b) continue;
			if(is_edge(i , j , n , m)==0 && board[i][j]==1)
				neighbor++;
			}
	return neighbor;
	}


void dead_neighbor(int a , int b , population_t pop , int **board , int n , int m)
	{
	int i,j;
	for(i=a-1 ; i<a+2 ; i++)
		for(j=b-1 ; j<b+2 ; j++)
			{
			if(i==a && j==b) continue;
			if(is_edge(i , j , n , m)==0 && board[i][j]==0)
				{
				pop_add(pop , i , j);
				board[i][j]=2;
				}
			}
	}
