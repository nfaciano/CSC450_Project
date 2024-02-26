#ifndef BALLSIMULATION_H
#define BALLSIMULATION_H

#include <string>

namespace csc450lib {
    namespace calc {

        /**
         * @brief Class representing a ball simulation.
         */
        class BallSimulation {
        public:
            /**
             * @brief Constructor for BallSimulation class.
             * @param initialX Initial x-coordinate of the ball.
             * @param initialY Initial y-coordinate of the ball.
             * @param initialVx Initial velocity in the x-direction.
             * @param initialVy Initial velocity in the y-direction.
             * @param alpha Alpha parameter.
             * @param maxBounces Maximum number of bounces.
             * @param dt Time step.
             */
            BallSimulation(float initialX, float initialY, float initialVx, float initialVy, float alpha, int maxBounces, float dt);

            /**
             * @brief Runs the ball simulation.
             * @param outputFile Output file path.
             */
            void runSimulation(const std::string& outputFile);

        private:
            float initialX, initialY, initialVx, initialVy, alpha, dt; /**< Initial values and parameters. */
            int maxBounces; /**< Maximum number of bounces. */
        };

    } // namespace calc
} // namespace csc450lib

#endif // BALLSIMULATION_H
