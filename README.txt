
Pour compiler le programme, il suffit de taper la commande make dans la console.

Pour supprimer les ex�cutables et les fichiers .o, il faut juste taper la commande make clean.

La partie non graphique est constitu� de 4 ex�cutables:
reseau_americain
reseau_americain1
reseau_parisien
reseau_parisien1
Les ex�cutables dont leur nom se termine par 1 ne permettent de faire qu'une utilisation tandis que les autres en permettent de multiples.

Pour l'ex�cutable reseau_americain, il faut �crire en param�tre le nom du fichier.
Pour l'ex�cutable reseau_americain1, il faut �crire en param�tre le nom du fichier et les num�ros des sommets de d�part et d'arriv�e.
Les ex�cutables reseau_parisien et reseau_parisien1 n'ont pas besoin de param�tres.
Exemples:
./reseau_americain /users/prog1a/C/librairie/projetS22019/grapheFloride.csv
./reseau_americain1 /users/prog1a/C/librairie/projetS22019/grapheFloride.csv 0 200000
./reseau_parisien1
./reseau_parisien

Pour la version graphique, il n'y a qu'un seul ex�cutable: main.
Exemple:
./main
