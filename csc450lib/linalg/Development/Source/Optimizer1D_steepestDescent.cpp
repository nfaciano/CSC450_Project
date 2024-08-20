#include "Optimizer1D_steepestDescent.h"
#include <cmath> // for std::abs

namespace csc450lib {
namespace linalg {

OptimizerRecord1D Optimizer1D_steepestDescent::minimize(float startX, float xMin, float xMax, float tol, int maxNumIters) const {
    float x = startX;
    float stepSize = 0.001; // Initial step size, might require adjustment
    OptimizerRecord1D record;

    for (int i = 0; i < maxNumIters; ++i) {
        // Numerical approximation of the derivative at x
        float grad = (func_->func(x + tol) - func_->func(x)) / tol;

        // Update x based on the gradient
        x -= stepSize * grad;

        // Clamp x within the bounds
        if (x < xMin) x = xMin;
        else if (x > xMax) x = xMax;

        // Check for convergence
        if (std::abs(grad) < tol) {
            record.optX = x;
            record.optVal = func_->func(x);
            record.numIters = i + 1;
            record.isSuccess = true;
            return record;
        }
    }

    // If the loop completes without convergence
    record.isSuccess = false;
    return record;
}

} // namespace linalg
} // namespace csc450lib
