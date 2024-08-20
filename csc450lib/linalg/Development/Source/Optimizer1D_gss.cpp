#include "Optimizer1D_gss.h"
#include <cmath>

namespace csc450lib {
namespace linalg {

OptimizerRecord1D Optimizer1D_gss::minimize(float startX, float xMin, float xMax, float tol, int maxNumIters) const {
    OptimizerRecord1D record;
    const float invPhi = (std::sqrt(5.0f) - 1) / 2; // 1/phi
    const float invPhi2 = (3 - std::sqrt(5.0f)) / 2; // 1/phi^2

    // Establish the bounds of the search
    float a = xMin, b = xMax;
    float h = b - a;
    if (h <= tol) {
        record.optX = a;
        record.optVal = func_->func(a);
        record.isSuccess = true;
        record.numIters = 0;
        return record;
    }

    // Required steps to achieve tolerance
    int n = std::ceil(std::log(tol/h)/std::log(invPhi));

    float c = a + invPhi2 * h;
    float d = a + invPhi * h;
    float fc = func_->func(c);
    float fd = func_->func(d);

    for (int k = 0; k < maxNumIters; k++) {
        if (fc < fd) {
            b = d;
            d = c;
            c = a + invPhi2 * (b - a);
            fd = fc;
            fc = func_->func(c);
        } else {
            a = c;
            c = d;
            d = a + invPhi * (b - a);
            fc = fd;
            fd = func_->func(d);
        }
        if ((b - a) < tol * invPhi) break;
    }

    record.optX = (b + a) / 2;
    record.optVal = func_->func(record.optX);
    record.isSuccess = true;
    record.numIters = n;

    return record;
}

} // namespace linalg
} // namespace csc450lib
