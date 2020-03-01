
Pour compiler le programme, il suffit de taper la commande make dans la console.

Pour supprimer les exécutables et les fichiers .o, il faut juste taper la commande make clean.

La partie non graphique est constitué de 4 exécutables:
reseau_americain
reseau_americain1
reseau_parisien
reseau_parisien1
Les exécutables dont leur nom se termine par 1 ne permettent de faire qu'une utilisation tandis que les autres en permettent de multiples.

Pour l'exécutable reseau_americain, il faut écrire en paramètre le nom du fichier.
Pour l'exécutable reseau_americain1, il faut écrire en paramètre le nom du fichier et les numéros des sommets de départ et d'arrivée.
Les exécutables reseau_parisien et reseau_parisien1 n'ont pas besoin de paramètres.
Exemples:
./reseau_americain /users/prog1a/C/librairie/projetS22019/grapheFloride.csv
./reseau_americain1 /users/prog1a/C/librairie/projetS22019/grapheFloride.csv 0 200000
./reseau_parisien1
./reseau_parisien

Pour la version graphique, il n'y a qu'un seul exécutable: main.
Exemple:
./main
