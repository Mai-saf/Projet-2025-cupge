Ce projet simule le système dynamique de Lorenz. Les résultats sont sauvegardés dans un fichier texte et peuvent être visualisés en utilisant Gniplot.
Les fonctionnalités principales du code sont: la simulation des trajectoires qui sont basés sur les équations de Lorenz, et les paramètres configurables par l'utilisateur
tel que les coefficients (sigma, rho et beta), les conditions initiales (x, y, z) et le pas de temps et durée total.

Le fichier inclut un fichier Makefile pour simplifier la complilation et l'execution


Depuis la racine du projet dans un codespace, entrée la commade:  

     make

Cela va permettre de générer un executable dans le répertoire   

     bin/


Lancez le programme en executant:

     ./bin/main


Le programme vous demandera par la suite de rentrer les paramètres suivant: les coefficients, les conditions initiales x, y et z, le pas de temps et la durée totale et le nom du fichier de sortie

Ensuite, il faudra visualiser les trajectoires sur Gnuplot. Pour le lancer, tapez sur le terminal:    

     gnuplot

Il faut maintenant afficher la trajectoire en 3D. Pour cela tappez sur le terminal les commade suivante:

     set parametric
     set xlabel "X"
     set ylabel "Y"
     set zlabel "Z"
     splot "trajectoire.txt" using with 2:3:4 with lines title "Trajectoire"


Il s'agit maintenant de rajouter les couleurs en fonction du temps pour les courbes. Utilisez les commande suivante:

     set palette defined (0 "blue", 1 "green", 2 "yellow", 3 "red")
     splot "trajectoire.txt" using 2:3:4:1 with lines palette title "Trajectoire"


Enfin, sauvegardez le graphique en format PNG, en configurant le terminal de sortie:

     set terminal png size 800,600
     set output "trajectoire.png"

Terminez:
    
     set output


L'image sera sauvegardée sous le nom de trajectoire.png dans le répertoire courant.







