# Game_engine
A powerfull game engine develop in C++

# Dependances:
    - g++ (compilateur présent sous linux utilisé dans le Makefile)
    - free-glut

# Lancement:
./GAME_ENGINE --command

--command:
--demo1:    Lance la démo n°1
--demo2:    Lance la démo n°2
--demo3:    Lance la démo n°3
--runTest:  Lance les tests unitaires
--help:     Affiche l'aide

# Compilation
make clean
make

#Explications:
Au lancement du programme la caméra est configurée pour montrer une vue 2D de la scene. Pour basculer en rendu 3D utiliser la molette de la souris
pour zoomer / dézoomer ou utiliser les touches de déplacement pour déplacer la caméra.

#Controles:
zoom / dezoom de la caméra:                 Utiliser la molette de la souris
Faire apparaitre une particule:             ESPACE (particule normal) ou R (particule random)
Monter la caméra:                           Z
Descendre la caméra:                        S
Deplacer la caméra vers la droite:          D
Deplacer la caméra vers la gauche:          Q
Clear la scene:                             C puis ESPACE