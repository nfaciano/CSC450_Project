#include "Function1DfromND.h"
#include <cmath>
#include <stdexcept>
#include <numeric>
namespace csc450lib {
namespace linalg {

Function1DfromND::Function1DfromND(const FunctionND& fn, const std::vector<float>& x0, const std::vector<float>& u_vect)
    : fn_(fn), x0_(x0), u_vect_(u_vect) {
    if (x0.size() != u_vect.size()) {
        throw std::invalid_argument("Dimension mismatch between origin and direction vector.");
    }
    // Normalize the direction vector to ensure it's a unit vector
    float magnitude = std::sqrt(std::inner_product(u_vect.begin(), u_vect.end(), u_vect.begin(), 0.0f));
    for (auto& component : u_vect_) {
        component /= magnitude;
    }
}

float Function1DfromND::func(float u) const {
    std::vector<float> x(x0_.size());
    for (size_t i = 0; i < x.size(); ++i) {
        x[i] = x0_[i] + u * u_vect_[i];
    }
    return fn_.func(x);
}

} // namespace linalg
} // namespace csc450lib
