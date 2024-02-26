#include "ExponentialDecayOscillation.h"
#include <cmath> // For std::exp and std::cos

namespace csc450lib {
namespace calc {

ExponentialDecayOscillation::ExponentialDecayOscillation() {}

float ExponentialDecayOscillation::func(float x) const {
    return std::exp(-x) * std::cos(x);
}

std::shared_ptr<std::string> ExponentialDecayOscillation::getExpressionMMA() const {
    return std::make_shared<std::string>("Exp[-x]*Cos[x]");
}

} // namespace calc
} // namespace csc450lib
