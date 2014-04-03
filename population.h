#ifndef POPULATION_H
#define POPULATION_H

// struktura na pojedyncza komorke
typedef struct 
	{
	int x;
	int y;
	} cell_t;

// struktura na tablice dynamiczna
typedef struct 
	{
	cell_t *c;
	int size;
	int max_size;
	} *population_t;


// inicjacja struktury na tablice dynamiczna przechowujaca populacje
population_t pop_alloc();					//TOTEST
	

// funkcja powiekszajaca miejsce na populacje (zwieksza tablice o 2 razy)
void pop_realloc( population_t pop); 					//TOTEST
	

// czysci tablice ( nie zmienia jej rozmiaru )
void pop_clear(population_t pop);					//TESTED
	

// zamienia dwie populacje ze soba
void pop_swap( population_t pop1 , population_t pop2); 			//TOTEST
	

// wypisuje populacje (komorki zywe)
void pop_write(population_t pop);					//TESTED
	

// dodaje komorke do populacji
void pop_add(population_t pop , int a , int b);				//TESTED
	

// zwalnia zarezerwowana pamiec na tablice dynamiczna
void pop_free(population_t pop);					//TOTEST

#endif
