#include "Camera.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Math.hpp"

Camera::Camera(Vector2f p_pos)
:pos(p_pos)
{
}

void Camera::updateCamera(Vector2f p_pos){
    offset = (p_pos - pos) * velocity;
}

