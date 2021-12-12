OFILES = main.o mouvements_controller.o mouvements_helper.o generateur.o graphisme_victoire.o graphisme_accueil.o
main.out: $(OFILES)
	gcc ${OFILES} -o main.out -lgraph
mouvements_controller.o: mouvements_helper.o mouvements_controller.h mouvements_controller.c
	gcc -ansi -c mouvements_controller.c
mouvements_helper.o: mouvements_helper.c mouvements_helper.h
	gcc -ansi -c mouvements_helper.c
generateur.o: generateur.c generateur.h
	gcc -ansi -c generateur.c
main.o: main.c
	gcc -ansi -c main.c 
graphisme_victoire.o: graphisme_victoire.c graphisme_victoire.h
	gcc -ansi -c graphisme_victoire.c
graphisme_accueil.o: graphisme_accueil.c graphisme_accueil.h
	gcc -ansi -c graphisme_accueil.c 
clean:
	rm *.o *.out
.PHONY: clean