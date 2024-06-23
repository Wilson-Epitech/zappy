/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Music
*/

#ifndef MUSIC_HPP_
#define MUSIC_HPP_

#include <SFML/Audio.hpp>

/**
 * @brief
 *
 */
class Music {
public:
    /**
     * @brief Construct a new Music object
     * 
     */
    Music();
    ~Music();

    /**
     * @brief Play the music
     * 
     */
    void play();

    /**
     * @brief Pause the music
     * 
     */
    void pause();

    /**
     * @brief Stop the music
     * 
     */
    void stop();
private:
    sf::Music music;
};

#endif /* !MUSIC_HPP_ */
