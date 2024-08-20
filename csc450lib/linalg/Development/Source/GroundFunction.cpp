#include "GroundFunction.h"
#include <stdexcept>

namespace csc450lib {
namespace linalg {

GroundFunction::GroundFunction(std::function<float(const std::vector<float>&)> customFunc)
    : FunctionND(2), customGroundFunc(customFunc) {}

float GroundFunction::func(const std::vector<float>& x) const {
    if (x.size() != 2) {
        throw std::invalid_argument("Input vector must have a size of 2 for GroundFunction.");
    }
    return customGroundFunc(x);
}
std::vector<float> GroundFunction::grad(const std::vector<float>& x) const {
    if (x.size() != dim_) {
        throw std::invalid_argument("Input vector size does not match function dimensionality.");
    }

    float h = 1e-5; // Small step for numerical differentiation
    std::vector<float> gradient(x.size());

    for (size_t i = 0; i < x.size(); ++i) {
        // Create a copy of x and modify the ith element
        std::vector<float> x_plus_h = x;
        x_plus_h[i] += h;

        // Calculate the partial derivative with respect to x[i]
        gradient[i] = (customGroundFunc(x_plus_h) - customGroundFunc(x)) / h;
    }

    return gradient;
}
}  // namespace linalg
}  // namespace csc450lib
