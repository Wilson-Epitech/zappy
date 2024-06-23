/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Music
*/

#include "Music.hpp"

/**
 * @brief Constructor for the Music class.
*/
Music::Music() {
    if (!music.openFromFile("graphical/assets/music.ogg")) {
        return;
    }
    music.openFromFile("graphical/assets/music.ogg");
    music.setLoop(true);
    music.setVolume(10);
}
/**
 * @brief Destructor for the Music class.
*/
Music::~Music() {

}

/**
 * @brief Plays the music.
*/
void Music::play() {
    music.play();
}

/**
 * @brief Pauses the music.
*/
void Music::pause() {
    music.pause();
}

/**
 * @brief Stops the music.
*/
void Music::stop() {
    music.stop();
}
