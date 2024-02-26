#ifndef EXPONENTIALDECAYOSCILLATION_H
#define EXPONENTIALDECAYOSCILLATION_H

#include "Function1D.h"

namespace csc450lib {
namespace calc {

class ExponentialDecayOscillation : public Function1D {
public:
    ExponentialDecayOscillation();
    float func(float x) const override;
    std::shared_ptr<std::string> getExpressionMMA() const override;
};

} // namespace calc
} // namespace csc450lib

#endif // EXPONENTIALDECAYOSCILLATION_H
