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

/**
 * @brief Camera class for handling movement and zoom
 * functionality in a 2D view.
 *
 * The Camera class provides methods to handle movement
 * and zoom interactions for a 2D view, typically used
 * in a game or graphical application. It also integrates
 * parallax scrolling to create a depth effect.
 */
class Camera {
public:
    /**
     * @brief Constructs a new Camera object with
     * default speed and zoom values.
     *
     * The constructor initializes the camera's
     * movement speed and zoom level.
     */
    Camera();
    ~Camera() = default;
    /**
     * @brief Handles the movement of the camera
     * view.
     *
     * This method adjusts the position of the
     * camera view based on user input.
     *
     * @param view The view object to be manipulated.
     * @param parallax The parallax object to be updated
     * alongside the camera view.
     */
    void handleMovement(sf::View& view, Parallax& parallax);

    /**
     * @brief Handles the zoom functionality
     * of the camera view.
     *
     * This method adjusts the zoom level of
     * the camera view based on user input
     * events, such as mouse wheel scroll.
     *
     * @param view The view object to be manipulated.
     * @param event The event object containing the
     * zoom input (e.g., mouse wheel).
     */
    void handleZoom(sf::View& view, const sf::Event& event);

private:
    float camSpeed;
    float camZoom;
};

#endif /* !CAMERA_HPP_ */
