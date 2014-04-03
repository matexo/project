#include <stdio.h>	//printf
#include <stdlib.h>	//malloc realloc
#include "population.h"


population_t pop_alloc()
	{
	population_t pop=malloc(sizeof *pop);
	pop->c=malloc(2*sizeof *pop->c);
	if(pop->c==NULL)
		{
		printf("BRAK PAMIECI NA ALOKACJE TABLICY DYNAMICZNEJ\n");
		exit(EXIT_FAILURE);
		}
	pop->size=0;
	pop->max_size=2;
	return pop;
	}

void pop_realloc( population_t pop) 
	{
	pop->c=realloc(pop->c , pop->max_size * 2 * sizeof *pop->c);
	if(pop->c==NULL)
		{
		printf("BRAK PAMIECI NA ALOKACJE TABLICY DYNAMICZNEJ\n");
		exit(EXIT_FAILURE);
		}
	pop->max_size*=2;
	}

void pop_clear(population_t pop) 
	{
	pop->size=0;
	}

void pop_swap( population_t pop1 , population_t pop2) 
	{
	population_t tmp=pop1;
	pop1=pop2;
	pop2=tmp;
	}

void pop_write(population_t pop)
	{
	int i;
	for(i=0;i<pop->size;i++)
		printf("%d %d\n", pop->c[i].x , pop->c[i].y);
	printf("\n");
	}

void pop_add(population_t pop , int a , int b)
	{
	if(pop->size==pop->max_size)
		pop_realloc(pop);

	pop->c[pop->size].x=a;
	pop->c[pop->size].y=b;
	pop->size++;
	}

void pop_free(population_t pop)	
	{
	free(pop->c);
	free(pop);
	}

