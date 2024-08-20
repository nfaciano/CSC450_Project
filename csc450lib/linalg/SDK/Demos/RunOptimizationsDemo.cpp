#include "Optimizer1D_parabolic.h"
#include "Optimizer1D_gss.h"
#include "Optimizer1D_steepestDescent.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <string>

// A simple quadratic function for testing
class QuadraticFunction : public csc450lib::calc::Function1D {
public:
    float func(float x) const override {
        return (x - 2.0f) * (x - 2.0f) + 1.0f;
    }

    std::shared_ptr<std::string> getExpressionMMA() const override {
        return std::make_shared<std::string>("(x-2)^2 + 1");
    }

    bool derivativeIsExact() const override {
        return true;
    }
};

class OptimizerDemo {
private:
    std::shared_ptr<csc450lib::calc::Function1D> function;
    csc450lib::linalg::Optimizer1D_parabolic parabolicOptimizer;
    csc450lib::linalg::Optimizer1D_gss gssOptimizer;
    csc450lib::linalg::Optimizer1D_steepestDescent steepestDescentOptimizer;
    std::ofstream file;

public:
    OptimizerDemo(std::shared_ptr<csc450lib::calc::Function1D> func)
        : function(func),
          parabolicOptimizer(func),
          gssOptimizer(func),
          steepestDescentOptimizer(func),
          file("optimization_results.txt") {}

    ~OptimizerDemo() {
        if (file.is_open()) {
            file.close();
        }
    }

    void runOptimizations(float startX, float xMin, float xMax, float tol, int maxNumIters) {
        file << "Optimizer,OptX,OptVal,NumIters,Success\n";

        runAndExport(gssOptimizer, "GSS", startX, xMin, xMax, tol, maxNumIters);
        runAndExport(parabolicOptimizer, "Parabolic", startX, xMin, xMax, tol, maxNumIters);
        runAndExport(steepestDescentOptimizer, "Steepest Descent", startX, xMin, xMax, tol, maxNumIters);
    }

private:
    void runAndExport(csc450lib::linalg::Optimizer1D& optimizer, const std::string& name, float startX, float xMin, float xMax, float tol, int maxNumIters) {
        auto result = optimizer.minimize(startX, xMin, xMax, tol, maxNumIters);
        file << name << "," << result.optX << "," << result.optVal << "," << result.numIters << "," << (result.isSuccess ? "Yes" : "No") << "\n";
    }
};

int main() {
    auto quadFunc = std::make_shared<QuadraticFunction>();
    OptimizerDemo demo(quadFunc);

    float startX = 0.f; // Initial guess
    float xMin = -5.0f; // Minimum x value
    float xMax = 5.0f; // Maximum x value
    float tol = 0.001f; // Tolerance for convergence
    int maxNumIters = 100000; // Maximum number of iterations

    demo.runOptimizations(startX, xMin, xMax, tol, maxNumIters);

    return 0;
}
