/*
** ZAPPY PROJECT, 2024
** delivery
** File description:
** Camera
*/

#include "Camera.hpp"

/**
 * @brief Constructor for the Camera class.
*/
Camera::Camera() : camSpeed(10.0f), camZoom(1.1f) {}

/**
 * @brief Handles the movement of the camera.
 * @param view The view to move.
 * @param parallax The parallax to update.
*/
void Camera::handleMovement(sf::View& view, Parallax& parallax) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) {
        view.move(0, -camSpeed);
        parallax.update(0, -camSpeed * 0.1f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
        view.move(0, camSpeed);
        parallax.update(0, camSpeed * 0.1f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
        view.move(-camSpeed, 0);
        parallax.update(-camSpeed * 0.1f, 0);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
        view.move(camSpeed, 0);
        parallax.update(camSpeed * 0.1f, 0);
    }
}

/**
 * @brief Handles the zoom of the camera.
 * @param view The view to zoom.
 * @param event The event to handle.
*/
void Camera::handleZoom(sf::View& view, const sf::Event& event) {
    if (event.type == sf::Event::MouseWheelScrolled) {
        if (event.mouseWheelScroll.delta > 0) {
            view.zoom(1.0f / camZoom);
        } else if (event.mouseWheelScroll.delta < 0) {
            view.zoom(camZoom);
        }
    }
}
