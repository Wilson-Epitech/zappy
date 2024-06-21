/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

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

#endif /* !MUSIC_HPP_ */
