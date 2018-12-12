# Game_engine
A powerfull game engine develop in C++

# Dependances:
    - g++ (compilateur présent sous linux utilisé dans le Makefile)
    - free-glut

# Lancement:
./GAME_ENGINE --command

--command:
--demo:      Lance la démo
--runTest:  Lance les tests unitaires
--help:     Affiche l'aide

# Compilation
make clean
make

# Controles:
zoom / dezoom de la caméra:                                              Utiliser la molette de la souris
Monter la caméra:                                                        Z
Descendre la caméra:                                                     S
Deplacer la caméra vers la droite:                                       D
Deplacer la caméra vers la gauche:                                       Q
Afficher / Ne plus Afficher les murs dans la scene                       X
Afficher/ Ne plus Afficher l'octree                                      W
Afficher/ Ne plus Afficher l'évolution de l'octree                       C
Afficher/ Ne plus Afficher la prise en compte des murs dans l'octree     V
Continuer / Stopper la simulation                                        B