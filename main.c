#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "lifegame.h"

char *info=
"\n"
"********************** LIFE ********************************\n"
"Opis parametrow wywolania:\n"
"-i (nazwa pliku wejsciowego)\n"
"-o (nazwa pliku wyjsciowego)\n"
"-n (szerokosc planszy)\n"
"-m (wysokosc planszy)\n"
"-g (ilosc generacji)\n"
"-f (czestotliwosc wytwarzania obrazow)\n"
"-r (rdzen nazwy obrazow)\n"
"Do poprawnego wytwarzania obrazow potrzebny jest folder images.\n"
"Do poprawnego wytwarzania plikow wyjsciowych potrzebny jest folder out\n"
"Przykladowe testy znajduja sie w folderze tests.\n"
"Plik wejsciowy powinien byc w formacie:\n"
"x y (gdzie x i y to wspolrzedne komorek zywych)\n"
"\n"
"Przykladowe komenda uzycia:\n"
"./LIFE -i tests/glider_gun -o glider_gun -n 80 -m 80 -g 200 -f 20 -r glider\n"
"*************************************************************\n";


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
				printf("%s\n\n",info);
				printf("BLEDNE PARAMETRY\n");
				exit( EXIT_FAILURE );
			}
		}

	if (optind < argc)
		{
		printf("%s\n\n",info);
		printf("BLEDNE PARAMETRY\n");
		exit( EXIT_FAILURE );
		}

	if(input==NULL)
		{
		printf("%s\n\n",info);
		printf("BRAK NAZWY PLIKU DO WCZYTANIA\n");
		exit( EXIT_FAILURE );
		}

	if(output==NULL)
		{
		printf("%s\n\n",info);
		printf("BRAK NAZWY PLIKU DO WYPISANIA\n");
		exit( EXIT_FAILURE );
		}

	if(core_name==NULL)
		{
		printf("%s\n\n",info);
		printf("BRAK NAZWY PLIKU DO ZAPISU OBRAZOW\n");
		exit( EXIT_FAILURE );
		}

	life(input , output , height , width , generation , freq , core_name);
	
	return 0;

	}
