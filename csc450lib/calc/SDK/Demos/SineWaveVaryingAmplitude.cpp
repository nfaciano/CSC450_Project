#include "SineWaveVaryingAmplitude.h"
#include <cmath> // For std::sin

namespace csc450lib {
namespace calc {

SineWaveVaryingAmplitude::SineWaveVaryingAmplitude() {}

float SineWaveVaryingAmplitude::func(float x) const {
    return std::sin(x) * x;
}

std::shared_ptr<std::string> SineWaveVaryingAmplitude::getExpressionMMA() const {
    return std::make_shared<std::string>("Sin[x]*x");
}

} // namespace calc
} // namespace csc450lib
