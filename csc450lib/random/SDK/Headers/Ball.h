#ifndef BALL_H
#define BALL_H

#include "Surface.h"
#include <array>

namespace csc450lib {
    namespace calc {

        /**
         * @brief Class representing a ball.
         */
        class Ball {
        public:
            /**
             * @brief Constructor for Ball class.
             * @param x Initial x-coordinate.
             * @param y Initial y-coordinate.
             * @param vx Initial velocity in the x-direction.
             * @param vy Initial velocity in the y-direction.
             */
            Ball(float x, float y, float vx, float vy);

            /**
             * @brief Updates the position of the ball.
             * @param dt Time step.
             * @param surface Surface object.
             * @param lambda Lambda parameter.
             */
            void update(float dt, const Surface &surface, float lambda);

            /**
             * @brief Bounces the ball off the surface.
             * @param surface Surface object.
             * @param lambda Lambda parameter.
             */
            void bounceOff(const Surface &surface, float lambda);

            std::array<float, 2> position; /**< Position of the ball. */
            std::array<float, 2> velocity; /**< Velocity of the ball. */

        private:
            /**
             * @brief Updates the velocity of the ball after a bounce.
             * @param surface Surface object.
             * @param lambda Lambda parameter.
             */
            void updateVelocityAfterBounce(const Surface &surface, float lambda);
        };

    } // namespace calc
} // namespace csc450lib

#endif // BALL_H
