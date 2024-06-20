#include "../include/Music.hpp"

Music::Music() {
    if (!music.openFromFile("assets/music.ogg")) {
        throw std::runtime_error("Failed to load music.ogg");
    }
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
