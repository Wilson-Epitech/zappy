
---

# ZAPPY: A Tribute to Zaphod Beeblebrox

ZAPPY est un jeu en réseau où plusieurs équipes s'affrontent sur une carte à tuiles contenant des ressources. L'objectif est d'atteindre le niveau d'élévation maximum avec au moins 6 joueurs de la même équipe.

## Préliminaires

- **Noms des binaires**: `zappy_server`, `zappy_gui`, `zappy_ai`
- **Langages utilisés**: 
  - Serveur: C
  - Interface graphique: C++
  - IA: Libre choix

## Compilation

Le Makefile doit contenir des règles pour compiler les binaires nommés ci-dessus (`zappy_server`, `zappy_gui`, `zappy_ai`).

## Usage

### Serveur

```sh
./zappy_server -p port -x width -y height -n name1 name2 ... -c clientsNb -f freq
```

- **Options**:
  - `-p`: Numéro de port
  - `-x`: Largeur du monde
  - `-y`: Hauteur du monde
  - `-n`: Noms des équipes
  - `-c`: Nombre de clients autorisés par équipe
  - `-f`: Inverse de l'unité de temps pour l'exécution des actions

### Interface Graphique

```sh
./zappy_gui -p port -h machine
```

- **Options**:
  - `-p`: Numéro de port
  - `-h`: Nom d'hôte de la machine (serveur)

### Client IA

```sh
./zappy_ai -p port -n name -h machine
```

- **Options**:
  - `-p`: Numéro de port
  - `-n`: Nom de l'équipe
  - `-h`: Nom de la machine (localhost par défaut)

## Description du Jeu

### Géographie

- Le jeu se déroule sur un monde plat sans reliefs.
- Les bords de la carte sont connectés (sortir par la droite revient par la gauche, et vice-versa).

### Ressources

Le monde contient des ressources alimentaires et des pierres précieuses réparties selon des densités spécifiques:

| Ressource | Densité |
| --------- | ------- |
| Nourriture | 0.5     |
| Linemate  | 0.3     |
| Deraumere | 0.15    |
| Sibur     | 0.1     |
| Mendiane  | 0.1     |
| Phiras    | 0.08    |
| Thystame  | 0.05    |

### Activités des Joueurs

Les joueurs doivent se nourrir et collecter des pierres pour s'élever dans la hiérarchie. L'élévation nécessite de réunir des joueurs et des pierres sur la même case et de lancer un rituel.

### Commandes des Joueurs

Les joueurs peuvent exécuter les actions suivantes:

- **Se déplacer**: `Forward`
- **Tourner à droite**: `Right`
- **Tourner à gauche**: `Left`
- **Regarder autour**: `Look`
- **Inventaire**: `Inventory`
- **Diffuser un message**: `Broadcast text`
- **Nombre de connexions disponibles**: `Connect_nbr`
- **Pondre un joueur**: `Fork`
- **Éjecter les autres joueurs**: `Eject`
- **Prendre un objet**: `Take object`
- **Déposer un objet**: `Set object`
- **Commencer une incantation**: `Incantation`

## Interface Graphique

- L'interface graphique doit permettre une visualisation du monde en 2D au minimum.
- Utilisation recommandée de la bibliothèque SFML pour la réalisation graphique.

## Communication Client/Serveur

La communication se fait via des sockets TCP. Le client envoie ses requêtes sans attendre leur exécution immédiate. Le serveur envoie des confirmations d'exécution.

## Protocole

Les détails du protocole de communication entre le client IA et le serveur sont définis dans la documentation.

---