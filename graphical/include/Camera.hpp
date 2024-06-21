/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Camera
*/

#ifndef CAMERA_HPP_
#define CAMERA_HPP_

#include <SFML/Graphics.hpp>
#include "Parallax.hpp"

class Camera {
public:
    Camera();

    void handleMovement(sf::View& view, Parallax& parallax);
    void handleZoom(sf::View& view, const sf::Event& event);

private:
    float camSpeed;
    float camZoom;
};

#endif /* !CAMERA_HPP_ */
