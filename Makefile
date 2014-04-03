LIFE: main.o inout.o lifegame.o matrix.o neighbors.o population.o rules.o image.o
	$(CC) -o LIFE  main.o inout.o lifegame.o matrix.o neighbors.o population.o rules.o image.o `allegro-config --libs`



.PHONY: clean
clean:
	-rm *.o LIFE

.PHONY: cleanimg
cleanimg:
	-rm images/*.bmp
