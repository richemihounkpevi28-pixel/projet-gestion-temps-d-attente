# SmartQueue C++

**SmartQueue** est une application en console développée en C++ pour répartir automatiquement les clients entre plusieurs guichets en fonction de leur charge de travail.

## Objectif du projet

L'objectif est d'améliorer la gestion des files d'attente en équilibrant la charge des guichets afin de réduire le temps nécessaire au traitement de tous les clients.

## Fonctionnalités actuelles

- Configuration du nombre de guichets.
- Enregistrement des clients avec un numéro de ticket, un nom et une durée de service.
- Répartition automatique vers le guichet le moins chargé.
- Calcul de la durée moyenne, minimale et maximale des services.
- Affichage des clients affectés à chaque guichet.
- Calcul de la charge totale de chaque guichet.
- Estimation du temps de finition global.
- Vérification de certaines limites de saisie.

## Technologies utilisées

- **Langage :** C++
- **Bibliothèques :** `<iostream>`, `<string>`, `<vector>`
- **Environnement de développement :** Code::Blocks

## Principe de fonctionnement

Pour chaque client, le programme recherche le guichet ayant la charge totale la plus faible, lui affecte le client et met à jour sa charge.

Le temps de finition global correspond à la charge maximale parmi les guichets après la répartition.

## Exemple

Pour trois guichets et quatre clients :

| Client | Durée de service |
|---|---:|
| Paul | 10 minutes |
| Amina | 5 minutes |
| Jean | 8 minutes |
| Sara | 12 minutes |

La répartition automatique donne :

| Guichet | Clients | Charge totale |
|---|---|---:|
| 1 | Paul | 10 minutes |
| 2 | Amina, Sara | 17 minutes |
| 3 | Jean | 8 minutes |

Le temps de finition global estimé est de **17 minutes**.

## Installation et exécution

1. Installer [Code::Blocks](https://www.codeblocks.org/).
2. Créer un projet C++ de type *Console application*.
3. Placer le code source dans `main.cpp`.
4. Compiler et exécuter avec la touche `F9`.

Le programme utilise un compilateur compatible avec le standard C++ utilisé par les fonctionnalités présentées.

## Limites actuelles

Cette version réalise une répartition prévisionnelle à partir des durées de service saisies. Elle ne simule pas encore le passage réel du temps, les appels de clients, les priorités ou la sauvegarde des données.

## Améliorations envisagées

- Gestion des clients prioritaires.
- Simulation du service et appel du prochain client.
- Calcul des temps d'attente estimés.
- Historique des clients servis.
- Sauvegarde et chargement des données.
- Statistiques avancées sur les performances des guichets.

## Auteur

Projet personnel réalisé dans le cadre de l'apprentissage du C++ et des algorithmes de gestion de files d'attente.
