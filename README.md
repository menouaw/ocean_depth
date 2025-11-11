# ocean_depth
jeu d'aventure en c

## but du jeu
Atteindre les abysses (plus bas niveau).

## déroulement
1. le joueur commence à la surface
2. tant qu'il n'est pas arrivé au fond, il choisit une salle à un niveau en-dessous (sans en connaître le contenu) 
3. la salle:
   - est vide: il descend dans la salle en-dessous sans combattre
   - est occupée par un monstre: il l'affronte; descend s'il gagne, meurt s'il perd
   - est occupée par un trésor: il en récupère le contenu puis descend
   - provoque un évènement spécial: à découvrir en jeu!