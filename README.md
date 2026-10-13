<div align="center">

# Zappy

**Un jeu en réseau où des IA s'affrontent sur une planète torique.**

<img alt="C" src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white"/> <img alt="C++" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/> <img alt="SFML" src="https://img.shields.io/badge/SFML-8CC445?style=for-the-badge&logo=sfml&logoColor=white"/> <img alt="Boost.Asio" src="https://img.shields.io/badge/Boost.Asio-4B4B4B?style=for-the-badge"/> <img alt="GitHub Actions" src="https://img.shields.io/badge/GitHub%20Actions-2088FF?style=for-the-badge&logo=githubactions&logoColor=white"/>

<sub>Projet à 6 · 2024</sub>

</div>

## Le projet en quelques mots

Le plus gros projet de l'année, à six. Trois programmes qui se parlent par TCP : un **serveur** en C qui fait tourner le monde, une **interface graphique** en C++ pour le regarder, et des **IA** qui jouent toutes seules. Les équipes ramassent des ressources sur une carte torique et réalisent des rituels pour monter de niveau.

## Ce que ça fait

- **Serveur (C)** : carte torique, ressources qui réapparaissent, gestion du temps, plusieurs équipes et plusieurs clients en même temps
- **Protocole texte** avec deux types de clients : les IA (joueurs) et les interfaces graphiques (spectateurs)
- **Interface graphique (C++ / SFML)** : caméra déplaçable, fond en parallaxe, tuiles, ressources et personnages animés, panneau d'infos
- **IA (C++)** : client autonome qui se connecte au serveur dans une équipe
- Doc technique générée avec Doxygen, CI GitHub Actions

## Lancer le projet

```bash
make
./zappy_server -p 4242 -x 15 -y 10 -n red blue -c 6 -f 60
./zappy_ai -p 4242 -n red -h 127.0.0.1
sleep infinity | ./zappy_gui -p 4242 -h 127.0.0.1
```

La documentation technique complète est dans [DOCUMENTATION.md](DOCUMENTATION.md).

## L'équipe

<a href="https://github.com/Wilson-Epitech/zappy/graphs/contributors"><img src="https://contrib.rocks/image?repo=Wilson-Epitech/zappy" alt="Contributeurs"/></a>

Jules Beauvais, Mathis Martinez, Aleksa Panic, Wilson Bordichon, Aziz Ennaifer, Alexandru Mosneagu

**Ma partition :** J'ai travaillé sur l'**interface graphique** (client réseau, boucle principale, caméra, ressources graphiques), sur le **parsing des arguments du serveur** et quelques commandes (`plv`, `tna`), sur la documentation du serveur, et j'ai harmonisé les Makefiles des trois binaires et le script de coding style de la CI.
