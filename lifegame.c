#include "lifegame.h"

void life(char namein[] , char nameout[] , int hei , int wit , int n , int f , char core[])
	{
	int i,j;
	int image_counter=1;
	char buf[256];

	mat_t mat=mat_alloc(hei,wit);
	mat_t mat_tmp=mat_alloc(hei , wit);

	population_t pop=pop_alloc();
	population_t pop_dead=pop_alloc();
	population_t pop_tmp=pop_alloc();

	population_t ptmp;
	mat_t mtmp;

	read_file(namein , pop);		// wczytanie z pliku komorek do populacji

	for(i=0;i<pop->size;i++)		// uzupelnienie planszy
		{
		if(is_edge( pop->c[i].x , pop->c[i].y , mat->n , mat->m))
			{
			printf("\nPLANSZA JEST ZA MALA NA TE DANE\nPOWIEKSZ PLANSZE ZWIEKSZAJAC -n I -m W PARAMATRACH\n");
			exit ( EXIT_FAILURE);	
			}
		mat->board[pop->c[i].x][pop->c[i].y]=1;
		}

	for(i=0;i<n;i++)
		{
		if(i%f==0)
			{
			sprintf(buf , "images/%s%d.bmp" , core , image_counter);
			make_image(pop , mat->n , mat->m , buf);
			image_counter++;
			}	

		for(j=0;j<pop->size;j++)
			dead_neighbor(pop->c[j].x , pop->c[j].y , pop_dead , mat->board , mat->n , mat->m );

		for(j=0;j<pop_dead->size;j++)
			{
			if(is_alive(pop_dead->c[j].x , pop_dead->c[j].y , mat->board , mat->n , mat->m))
				{
				mat_tmp->board[pop_dead->c[j].x][pop_dead->c[j].y]=1;
				pop_add(pop_tmp , pop_dead->c[j].x , pop_dead->c[j].y);
				}
			mat->board[pop_dead->c[j].x][pop_dead->c[j].y]=0;
			}
		pop_clear(pop_dead);

		for(j=0;j<pop->size;j++)
			{
			if(is_alive(pop->c[j].x , pop->c[j].y , mat->board , mat->n , mat->m))
				{
				mat_tmp->board[pop->c[j].x][pop->c[j].y]=1;
				pop_add(pop_tmp , pop->c[j].x , pop->c[j].y);
				}
			}
		for(j=0;j<pop->size;j++)
			mat->board[pop->c[j].x][pop->c[j].y]=0;
		pop_clear(pop);

		ptmp=pop;//zamienic na funkcje?
		pop=pop_tmp;
		pop_tmp=ptmp;
		mtmp=mat;
		mat=mat_tmp;
		mat_tmp=mtmp;
		}

	write_file( nameout , pop ); 

	pop_free(pop);
	pop_free(pop_tmp);
	pop_free(pop_dead);
	mat_free(mat);
	mat_free(mat_tmp);
	
	}
