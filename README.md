# 🎯 Jeu de Devinette en C

[![Langage](https://img.shields.io/badge/langage-C-blue)](https://www.iso-9899.info/) 
[![Licence](https://img.shields.io/badge/licence-MIT-green)](LICENSE)
[![Status](https://img.shields.io/badge/status-Actif-brightgreen)]()

---

## Description

Ce projet est un **jeu de devinette en C**, simple et interactif.  
Le joueur peut :

- Créer un compte avec pseudo et mot de passe
- Se connecter et jouer
- Deviner un nombre aléatoire
- Suivre son score et consulter le meilleur score
- Sauvegarder les scores dans un fichier `joueur.txt`

---

## Diagramme du flux du jeu

# jeux_devinette

---

## Installation et Compilation

1. Cloner ou télécharger le projet.
2. Compiler le code avec `gcc` :

```bash
gcc -o devinette jeu_devinette.c
./devinette

exemple d execution

===== Bienvenue dans votre jeu devmot ====
Entrer votre choix: 2
Entrer votre pseudo: emmanuel
Entrer votre password: 1234

====== BIENVENUE dans votre jeu de devinette mr emmanuel ====
1) Nouvelle partie
2) Sortir
Entrer votre choix: 1

Le nombre généré est: 42
Entrer votre valeur devinée: 42
Partie gagnée ! Score = 1



[ Menu Principal ]
1) Créer un compte
2) Se connecter
3) Liste des joueurs
4) Meilleur score
5) Quitter

[ Jeu ]
Nombre généré: 57
Entrer votre devinette: 57
Partie gagnée ! Score = 1

