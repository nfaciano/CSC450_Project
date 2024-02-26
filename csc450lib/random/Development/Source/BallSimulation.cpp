#include "BallSimulation.h"
#include "Ball.h"
#include "Surface.h"
#include <iostream>
#include <fstream>

namespace csc450lib {
    namespace calc {
        BallSimulation::BallSimulation(float initialX, float initialY, float initialVx, float initialVy, float alpha, int maxBounces, float dt)
            : initialX(initialX), initialY(initialY), initialVx(initialVx), initialVy(initialVy), alpha(alpha), maxBounces(maxBounces), dt(dt) {}

        void BallSimulation::runSimulation(const std::string& outputFile) {
            // Create the sinusoidal surface and the ball with initial conditions
            Surface surface(alpha, initialX, initialY);
            Ball ball(initialX, initialY, initialVx, initialVy);

            // Prepare file for output
            std::ofstream file(outputFile);

            // Check if file is open
            if (!file.is_open()) {
                std::cerr << "Error opening file for writing.\n";
                return;
            }

            // Write the initial conditions to the file
            file << "Initial conditions:\n";
            file << "Position: (" << initialX << ", " << initialY << ")\n";
            file << "Velocity: (" << initialVx << ", " << initialVy << ")\n\n";

            // Write the header for the bounce data
            file << "Bounce data:\n";

            // Simulation loop
            for (int bounceCount = 0; bounceCount <= maxBounces; ++bounceCount) {
                // Store initial data for the segment
                float startX = ball.position[0];
                float startY = ball.position[1];
                float startVx = ball.velocity[0];
                float startVy = ball.velocity[1];

                // Run the simulation until the ball bounces
                while (true) {
                    ball.update(dt, surface, alpha);

                    // Check if the ball has bounced
                    if (ball.position[1] <= surface.func(ball.position[0])) {
                        // Log the bounce to the file
                        file << "Bounce #" << bounceCount + 1 << ":\n";
                        file << "Start Position: (" << startX << ", " << startY << ")\n";
                        file << "End Position: (" << ball.position[0] << ", " << ball.position[1] << ")\n";
                        file << "Start Velocity: (" << startVx << ", " << startVy << ")\n";
                        file << "End Velocity: (" << ball.velocity[0] << ", " << ball.velocity[1] << ")\n\n";
                        break; // Break out of the loop to process the next segment
                    }
                }
            }

            // Close the file
            file.close();
        }
    }
}
