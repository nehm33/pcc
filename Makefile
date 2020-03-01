CFLAGS=-Wall -Wextra -g -I include -c -O2
LDFLAGS= -lm
DIRSDL=/users/prog1a/C/librairie/2011
CFLAGSPHELMA= -g  -I/usr/local/include -I/usr/local/include/SDL -I/usr/include/SDL
LDFLAGSPHELMA= -L/usr/local/lib -lSDL -lSDL_ttf -lSDL_image -lm



EXE=test_sommet test_liste test_graphe test_affich_liste_fermee test_tas test_liste_sommet test_hachage reseau_americain reseau_americain1 reseau_parisien reseau_parisien1 test test_graphique_graphe main

all : $(EXE)

test_sommet : test_sommet.o Sommet.o Liste.o Arc.o
	gcc -o $@ $^ $(LDFLAGS)

test_liste : test_liste.o Liste.o Arc.o
	gcc -o $@ $^ $(LDFLAGS)

test_graphe : test_graphe.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

test_affich_liste_fermee : test_affich_liste_fermee.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

test_tas : test_tas.o Tas.o Graphe.o Sommet.o Liste.o Arc.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

test_liste_sommet : test_liste_sommet.o Sommet.o Liste.o Arc.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

test_hachage : test_hachage.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

reseau_americain : reseau_americain.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

reseau_americain1 : reseau_americain1.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

reseau_parisien : reseau_parisien.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

reseau_parisien1 : reseau_parisien1.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o
	gcc -o $@ $^ $(LDFLAGS)

test: Draw.o test.o
	gcc -o $@ $^ $(LDFLAGSPHELMA)

test_graphique_graphe: test_graphique_graphe.o Draw.o affichage_graph.o divers_graph.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o divers_graph.o
	gcc -o $@ $^ $(LDFLAGSPHELMA)

main: main.o Draw.o affichage_graph.o divers_graph.o reseau.o Graphe.o Sommet.o Liste.o Arc.o Tas.o divers.o Liste_sommet.o divers_graph.o
	gcc -o $@ $^ $(LDFLAGSPHELMA)

%.o: %.c
	gcc -g -c $(CFLAGSPHELMA) $^

clean:
		rm -f *.o $(EXE)
