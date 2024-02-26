#include "Ball.h"
#include "Surface.h"
#include <cmath>

namespace csc450lib {
namespace calc {

Ball::Ball(float x, float y, float vx, float vy)
    : position({x, y}), velocity({vx, vy}) {}

void Ball::update(float dt, const Surface &surface, float lambda) {
    // Update position based on current velocity
    position[0] += velocity[0] * dt;
    position[1] += velocity[1] * dt; // Update Y-coordinate without gravity effect

    // Check for collision with the surface
    if (position[1] <= surface.func(position[0])) {
        // Correct position to be on the surface
        position[1] = surface.func(position[0]);
        
        // Update velocity after bounce
        bounceOff(surface, lambda);
    } else {
        // Apply gravity effect
        velocity[1] -= 9.81 * dt; // Update velocity due to gravity
    }
}

void Ball::bounceOff(const Surface &surface, float lambda) {
    // Implementing bounce logic based on provided document
    updateVelocityAfterBounce(surface, lambda);
}

void Ball::updateVelocityAfterBounce(const Surface &surface, float lambda) {
    // Calculate the derivative at the point of bounce to get the slope
    float slope = surface.dfunc(position[0]);
    // Calculate the normal vector components
    float magnitude = sqrt(1 + slope * slope);
    float Nx = -slope / magnitude;
    float Ny = 1 / magnitude;

    // Calculate α using Eq. (4) from the document
    float alpha = -2 * lambda * (velocity[0] * Nx + velocity[1] * Ny);

    // Update outgoing velocity using Eq. (5)
    velocity[0] = lambda * velocity[0] + alpha * Nx;
    velocity[1] = lambda * velocity[1] + alpha * Ny;
}

} // namespace calc
} // namespace csc450lib
