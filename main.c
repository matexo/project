#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "lifegame.h"
int main(int argc , char **argv)
	{
	int opt;
	char *input    =NULL;
	char *output   =NULL;
	int height     =100;
	int width      =100;
	int generation =10;
	int freq       =1 ;
	char *core_name=NULL;
	while( (opt = getopt(argc , argv , "i:o:n:m:g:f:r:")) != -1 )
		{
		switch(opt)
			{
			case 'i' :
				input=optarg;
				break;
			case 'o' :
				output=optarg;
				break;
			case 'n' :
				height=atoi(optarg);
				break;
			case 'm' :
				width=atoi(optarg);
				break;
			case 'g' :
				generation=atoi(optarg);
				break;
			case 'f' :
				freq=atoi(optarg);
				break;
			case 'r' :
				core_name=optarg;
				break;
			default:
				printf("BLEDNE PARAMETRY\n");
				exit( EXIT_FAILURE );
			}
		}

	if (optind < argc)
		{
		printf("BLEDNE PARAMETRY\n");
		exit( EXIT_FAILURE );
		}

	if(input==NULL)
		{
		printf("BRAK NAZWY PLIKU DO WCZYTANIA\n");
		exit( EXIT_FAILURE );
		}

	if(output==NULL)
		{
		printf("BRAK NAZWY PLIKU DO WYPISANIA\n");
		exit( EXIT_FAILURE );
		}

	if(core_name==NULL)
		{
		printf("BRAK NAZWY PLIKU DO ZAPISU OBRAZOW\n");
		exit( EXIT_FAILURE );
		}

	life(input , output , height , width , generation , freq , core_name);
	
	return 0;

	}
