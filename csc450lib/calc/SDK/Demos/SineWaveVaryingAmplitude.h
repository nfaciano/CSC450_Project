#ifndef SINEWAVEVARYINGAMPLITUDE_H
#define SINEWAVEVARYINGAMPLITUDE_H

#include "Function1D.h"

namespace csc450lib {
namespace calc {

class SineWaveVaryingAmplitude : public Function1D {
public:
    SineWaveVaryingAmplitude();
    float func(float x) const override;
    std::shared_ptr<std::string> getExpressionMMA() const override;
};

} // namespace calc
} // namespace csc450lib

#endif // SINEWAVEVARYINGAMPLITUDE_H
