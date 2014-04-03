#include "image.h"
#include <stdio.h>
void make_image(population_t pop , int n , int m , char name[])
	{
	int i;
	allegro_init();
	set_color_depth( 16 );
	BITMAP *image = create_bitmap( 8*n, 8*m );
	PALETTE pal;
	
		if( image )
			{
    			clear_to_color( image , makecol( 255 , 255 , 255 ) );
			for(i=0;i<pop->size;i++)
				{
				rectfill( image , pop->c[i].x*8 , pop->c[i].y*8 , pop->c[i].x*8+8 , pop->c[i].y*8+8, makecol( 0 , 0 , 0 ) );
				}
			save_bitmap( name , image , pal );
    			destroy_bitmap( image );
			}
	allegro_exit();
	}
