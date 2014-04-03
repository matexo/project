#include <stdio.h> 	//fprintf fscanf
#include <stdlib.h> 	// FILE
#include "population.h"

void read_file(char name_r[] , population_t pop)
	{
	FILE *in=fopen(name_r,"r");
	int a,b;
	if(in==NULL)
		{
		printf("NIE MOZNA OTWORZYC PLIKU\n");
		exit(EXIT_FAILURE);
		}
	while(fscanf(in , "%d %d" , &a , &b)==2)
		{
		pop_add(pop , a , b);
		}
	fclose(in);
	}

void write_file(char name_w[] , population_t pop)
	{
	char buf[256];
	sprintf(buf , "out/%s", name_w);
	FILE *out=fopen(buf,"w");
	int i;
	if(out==NULL)
		{
		printf("NIE MOZNA STWORZYC PLIKU\n");
		exit(EXIT_FAILURE);
		}
	for(i=0;i<pop->size;i++)
		{
		fprintf(out , "%d %d\n" , pop->c[i].x , pop->c[i].y);
		}
	fclose(out);
	}
