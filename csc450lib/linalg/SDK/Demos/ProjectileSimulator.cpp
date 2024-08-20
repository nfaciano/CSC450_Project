#include <iostream>
#include <vector>
#include <cmath>
#include <functional>
#include <fstream>
#include "GroundFunction.h"

const float g = 9.81f;  // Acceleration due to gravity (m/s^2)

using namespace csc450lib::linalg;

class ProjectileSimulator {
    std::vector<float> initialPosition;
    std::vector<float> initialVelocity;
    GroundFunction& groundFunction;
    std::ofstream outFile;

public:
    ProjectileSimulator(const std::vector<float>& initialPos, const std::vector<float>& initialVel, GroundFunction& groundFunc)
        : initialPosition(initialPos), initialVelocity(initialVel), groundFunction(groundFunc), outFile("trajectory.csv") {
        outFile << "Time,X,Y,Z\n";  // Header for CSV file
    }


    ~ProjectileSimulator() {
        if (outFile.is_open()) {
            outFile.close();
        }
    }

    std::vector<float> shellPosition(float t) const {
        return {
            initialPosition[0] + initialVelocity[0] * t,
            initialPosition[1] + initialVelocity[1] * t,
            initialPosition[2] + initialVelocity[2] * t - 0.5f * g * t * t
        };
    }

    float findImpactTime() {
        float t = 0.0f;
        float deltaTime = 0.01f;
        float tolerance = 0.1f;  // Adjusted for more realistic ground contact
        std::vector<float> position;
        float groundElevation;

        do {
            position = shellPosition(t);
            groundElevation = groundFunction.func({position[0], position[1]});
            outFile << t << "," << position[0] << "," << position[1] << "," << position[2] << "\n";

            if (position[2] <= groundElevation + tolerance) {
                return t;  // Impact time found
            }

            t += deltaTime;
        } while (position[2] > groundElevation);

        return -1;  // Return -1 if no impact found within reasonable time
    }
};

int main() {
    // Example usage of the ProjectileSimulator
    std::vector<float> initialPosition = {0.0f, 0.0f, 1.0f};  // Initial position above ground
    float magnitude = 100.0f;  // Initial speed in m/s
    float theta = 3.1415926f / 4;  // 45 degrees
    float phi = 3.1415926f / 6;  // 30 degrees
    std::vector<float> initialVelocity = {
        magnitude * std::cos(theta) * std::cos(phi),
        magnitude * std::sin(theta) * std::cos(phi),
        magnitude * std::sin(phi)
    };

    // Define the ground function
    auto groundFunc = [](const std::vector<float>& x) -> float {
        // Example ground function
        return 0.05f * x[0] + 0.1f * x[1];  // Simple sloped terrain
    };
    GroundFunction groundFunction(groundFunc);

    ProjectileSimulator simulator(initialPosition, initialVelocity, groundFunction);
    float impactTime = simulator.findImpactTime();

    if (impactTime >= 0) {
        std::vector<float> impactPosition = simulator.shellPosition(impactTime);
        std::cout << "Impact time: " << impactTime << " seconds" << std::endl;
        std::cout << "Impact position: X=" << impactPosition[0]
                  << " Y=" << impactPosition[1] << " Z=" << impactPosition[2] << std::endl;
    } else {
        std::cerr << "No impact detected within the expected time frame." << std::endl;
    }

    return 0;
}
