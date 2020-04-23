`make installSDL` pour la lib

Tu peux creer une map via l'editeur (tout se compile avec le makefile principal), si son usage est pas clair c'est un feedback interessant

Tu peux link une map en argument de l'executable doom-nukem, ca ajoutera une option dans le menu

Commandes du menu :
	- WASD : bouger le curseur
	- Enter : valider la selection

Commandes dans le jeu :
	- WASD : deplacements
	- Clic gauche : tir/coup
	- Clic droit : changer d'arme
	- Shift : sprint
	- +/- (numpad) augmenter/baisser la sensibilite de la souris
	- M (en qwerty) : retour au menu
	- E : ouvre une porte verrouillee (necessite une clef)

On peut ramasser les objets en marchant dessus. Ils ne seront pas ramasses si tu es deja au max de la ressource en question.
Pour finir chacun des niveaux de base, il faut tuer tous les ennemis.
Les ennemis flottants ne meurent que si on les touche avec le BFG (l'arme massive qui necessite des cells pour tirer). Le niveau 2 est base autour de ca, il faut trouver les cells pour ensuite tuer les 3 ennemis de ce type.
Le reste devrait etre intuitif !

Enjoy =)
