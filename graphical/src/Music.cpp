/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Music
*/

#include "Music.hpp"

Music::Music() {
    if (!music.openFromFile("graphical/assets/music.ogg")) {
        return;
    }
    music.openFromFile("graphical/assets/music.ogg");
    music.setLoop(true);
    music.setVolume(10);
}

Music::~Music() {

}

void Music::play() {
    music.play();
}

void Music::pause() {
    music.pause();
}

void Music::stop() {
    music.stop();
}
