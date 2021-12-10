main.out: main.o generateur.o mouvements_controller.o mouvements_helper.o generateur.o
	gcc mouvements_controller.o mouvements_helper.o generateur.o main.o -o main.out
mouvements_controller.o: mouvements_helper.o mouvements_controller.h mouvements_controller.c
	gcc -c mouvements_controller.c
mouvements_helper.o: mouvements_helper.c mouvements_helper.h
	gcc -c mouvements_helper.c
generateur.o: generateur.c generateur.h
	gcc -c generateur.c
main.o: main.c
	gcc -c main.c 