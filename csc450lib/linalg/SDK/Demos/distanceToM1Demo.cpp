#include <cmath>
#include <iostream>
#include <vector>
#include <limits>
#include <memory>
#include "Function1D.h"
#include "Optimizer1D_steepestDescent.h"
#include <fstream>
#include <iomanip>
namespace csc450lib {
namespace calc {

class SpecificFunction : public Function1D {
    float a;
    std::pair<float, float> m1;

public:
    SpecificFunction(float a, std::pair<float, float> m1) : a(a), m1(m1) {}

    float func(float x) const override {
        return (7 * std::exp(a * x - 5) - 1) / (std::exp(a * x - 5) + 1) + (3 / 10.0f) * x * std::sin((5 / 4.0f) * x + 3);
    }

    std::shared_ptr<std::string> getExpressionMMA() const override {
        return std::make_shared<std::string>("Mathematica expression for SpecificFunction");
    }

    bool derivativeIsExact() const override {
        return false; // Assuming we don't have an exact method for the derivative
    }

    float distanceToM1(float x, int normType) const {
        float y = func(x);
        float dx = x - m1.first;
        float dy = y - m1.second;

        switch (normType) {
            case 1:  // Manhattan (L1) norm
                return std::abs(dx) + std::abs(dy);
            case 2:  // Euclidean (L2) norm
                return std::sqrt(dx * dx + dy * dy);
            case std::numeric_limits<int>::max():  // Chebyshev (Linf) norm
                return std::max(std::abs(dx), std::abs(dy));
            default:
                throw std::invalid_argument("Invalid norm type");
        }
    }
};

class DistanceFunction : public Function1D {
    std::shared_ptr<SpecificFunction> specificFunction;
    int normType;

public:
    DistanceFunction(std::shared_ptr<SpecificFunction> func, int norm) : specificFunction(func), normType(norm) {}

    float func(float x) const override {
        return specificFunction->distanceToM1(x, normType);
    }

    std::shared_ptr<std::string> getExpressionMMA() const override {
        return std::make_shared<std::string>("Mathematica expression for DistanceFunction");
    }

    bool derivativeIsExact() const override {
        return false;
    }

};
}  // namespace calc
}  // namespace csc450lib
void optimizeDistance(std::shared_ptr<csc450lib::calc::Function1D> function, int normType, const std::string& filename) {
    std::ofstream outFile;
    outFile.open(filename, std::ios::app);  // Open in append mode to add data for each norm

    csc450lib::linalg::Optimizer1D_steepestDescent optimizer(function);
    auto result = optimizer.minimize(1.0f, -10.0f, 10.0f, 1e-2, 100000);

    if (result.isSuccess) {
        std::cout << "Optimization successful for norm " << normType << std::endl;
        outFile << normType << "," << result.optX << "," << result.optVal << std::endl;
    } else {
        std::cout << "Optimization failed for norm " << normType << std::endl;
        outFile << normType << ",," << std::endl;  // Indicate failure with empty values
    }

    outFile.close();
}
int main() {
    using namespace csc450lib::calc;

    std::string filename = "optimization_results.csv";
    std::ofstream outFile(filename);
    outFile << "NormType,OptimalX,OptimalDistance\n";  // Write the CSV header
    outFile.close();

    float a = 3.0f;  // Parameter for the function
    std::pair<float, float> m1 = {5, -5};  // Data point m1

    auto specificFunction = std::make_shared<SpecificFunction>(a, m1);
    std::vector<int> norms = {1, 2, std::numeric_limits<int>::max()};  // L1, L2, Linf

    for (int normType : norms) {
        auto distanceFunction = std::make_shared<DistanceFunction>(specificFunction, normType);
        optimizeDistance(distanceFunction, normType, filename);
    }

    return 0;
}