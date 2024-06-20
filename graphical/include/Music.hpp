#ifndef MUSIC_HPP
#define MUSIC_HPP

#include <SFML/Audio.hpp>

class Music {
private:
    sf::Music music;

public:
    Music();
    ~Music();

    void play();
    void pause();
    void stop();
};

#endif // MUSIC_HPP
