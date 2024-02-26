
#include <iostream>
#include <fstream>
#include <vector>
#include "BallSimulation.h"
#include "BisectionSolver1D.h"
#include "SecantSolver1D.h"
#include "Function1D.h"
#include "NewtonRaphsonSolver1D.h" // Include the header file for NewtonRaphsonSolver1D

namespace csc450lib {
namespace calc {

class MyFunction : public Function1D {
public:
    float func(float x) const override {
        return x * x * x + 4;
    }

    float dfunc(float x) const override {
        // Derivative of x^3 + 4 is 3x^2
        return 3 * x * x;
    }
    
// Concrete implementation of 'getExpressionMMA'
std::shared_ptr<std::string> getExpressionMMA() const {
    return std::make_shared<std::string>("x^3 + 4"); // Return the equation as a string
}

// Concrete implementation of 'derivativeIsExact'
bool derivativeIsExact() const {
    // For a flat surface, the derivative is a constant (zero), so it's exact.
    return true;
}
};

} // namespace calc
} // namespace csc450lib

int main() {
    // Ball simulation
    std::cout << "Running ball simulation...\n";
    csc450lib::calc::BallSimulation simulation(0, 3, 5, 10, 0.9, 4, 0.01);
    simulation.runSimulation("ball_trajectory.txt");

    // Bisection solver test
    std::cout << "\nTesting Bisection Solver 1D...\n";
    csc450lib::calc::BisectionSolver1D bisectionSolver;
    csc450lib::calc::MyFunction myFunction; // Create an instance of MyFunction
    auto bisectionResult = bisectionSolver.solve(std::make_shared<csc450lib::calc::MyFunction>(myFunction), -10, 10, 100, 0.0001);
    std::cout << "Bisection root: " << bisectionResult.xStar << ", Function value at root: " << bisectionResult.valStar << std::endl;

    // Secant solver test
    std::cout << "\nTesting Secant Solver 1D...\n";
    csc450lib::calc::SecantSolver1D secantSolver;
    auto secantResult = secantSolver.solve(std::make_shared<csc450lib::calc::MyFunction>(myFunction), -5, 5, 100, 0.0001);
    std::cout << "Secant root: " << secantResult.xStar << ", Function value at root: " << secantResult.valStar << std::endl;

    // Newton-Raphson solver test
    std::cout << "\nTesting Newton-Raphson Solver 1D...\n";
    csc450lib::calc::NewtonRaphsonSolver1D newtonRaphsonSolver;
    auto newtonRaphsonResult = newtonRaphsonSolver.solve(std::make_shared<csc450lib::calc::MyFunction>(myFunction), -10, 10, 100, 0.0001);
    std::cout << "Newton-Raphson root: " << newtonRaphsonResult.xStar << ", Function value at root: " << newtonRaphsonResult.valStar << std::endl;

    return 0;
}