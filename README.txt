Proposition de solution pour l'exercice C++ MFC.

Rappel de l'énnoncé:

Ecrire en C++ avec MFC une application sans CLR pour faire la somme de 2 nombres. Celle-ci sera composé de :
•	2 zones d’édition pour les nombres à additionner.
•	1 zone statique pour afficher le résultat.
•	1 Bouton pour effacer les zones d’édition et la zone statique.
•	1 point de menu supplémentaire « Tools » avec un sous menu « calculer » qui effectue la somme et l’affiche dans la zone statique.
•	1 point de menu contextuel avec « calculer » qui fait la même chose que le point précédent.
•	1 fichier de log avec une trace de tous les calculs effectués.


Pour résoudre cet exercice, Visual Studio 2017 a été utilisé avec le module MFC.

Au moment de la création du projet, une question s'est posée: Application avec Frame et menu ou simple dialogue ?
L'ennoncé parle de rajouter un point de menu supplémentaire, ce qui tend vers la solution avec frame, 
mais il parle aussi d'utiliser de simple éléménts de dialogue qui doivent être dans une boîte de dialogue.
Il est possible de créer une application avec frame qui permet d'ouvrir une boîte de dialogue via une entrée de menu,
mais ceci n'est pas dans le scénario de l'énnoncé.
En temps réel, je retournerais vers les personnes demanderesses, mais dans le cadre de cet exercice, j'ai pris la liberté 
de partir vers la solution simple boîte de dialogue, sans menu. Par conséquent l'ajout d'un point supplémentaire 
"Tools" n'a pas été réalisé. Tous les autres points sont réalisés.
À noter également que, dans le cadre de ce petit exercice, aucun effort n'a été réalisé sur le look de la boîte de dialogue
qui devrait être adapté en fonction des standards de la société. Aucun effort n'a été réalisé également pour localiser le 
fichier de log qui est juste créé dans le répertoire courant.

Pour être plus précis:
Ce que j'ai fait:
- utiliser l'assistant de création de projet de Visual Studio
- le design de la boîte de dialogue
- la rédaction du code des événements pour gérer le menu contextuel, réaliser le calcul et le journaliser, pour vider les zones de l'écran.
- mettre le tout dans github

Ce que je n'ai pas fait: tout le reste qui a été fait par Visual Studio.
