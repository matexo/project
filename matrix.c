#include <stdio.h>   //printf
#include <stdlib.h>  //malloc

#include "matrix.h"

mat_t mat_alloc( int a , int b)
	{
	mat_t mat=malloc(sizeof *mat);
	int i;
	mat->n=a;
	mat->m=b;
	mat->board=(int**)malloc( mat->n * sizeof(int*));
	if(mat->board==NULL)
		{
		printf("BRAK PAMIECI NA ALOKACJE PLANSZY\n");
		exit ( EXIT_FAILURE);
		}
	for(i=0;i<mat->n;i++)
		{
		mat->board[i]=(int*)calloc(mat->m , sizeof(int));
		if(mat->board==NULL)
			{
			printf("BRAK PAMIECI NA ALOKACJE PLANSZY\n");
			exit ( EXIT_FAILURE);
			}		
		}
	return mat;	
	}

void mat_write( mat_t mat)	
	{
	int i,j;
	for(i=0;i<mat->n;i++)
		{
		for(j=0;j<mat->m;j++)
			{
			if(mat->board[i][j]==1) printf("#");
			else if(mat->board[i][j]==2)  printf("?");
			else printf(".");
			}
		printf("\n");
		}
	}

void mat_swap( mat_t mat1 , mat_t mat2)
	{
	mat_t tmp=mat1;
	mat1=mat2;
	mat2=tmp;
	}

void mat_free(mat_t mat)
	{
	int i;
	for(i=0;i<mat->n;i++)
		free(mat->board[i]);
	free(mat->board);
	free(mat);
	}

