#ifndef MATRIX_H
#define MATRIX_H

//struktura macierzy - planszy 
typedef struct  
	{
	int **board;
	int n;
	int m;
	} *mat_t;

// inicjalizacja macierzy
mat_t mat_alloc(int a , int b);

// wypisanie planszy
void mat_write( mat_t mat);	

// zamiana dwoch plansz ze soba
void mat_swap( mat_t mat1 , mat_t mat2);

// zwolnienie pamieci dla planszy
void mat_free(mat_t mat);


#endif

