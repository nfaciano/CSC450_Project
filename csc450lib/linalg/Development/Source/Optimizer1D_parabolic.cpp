#include "Optimizer1D_parabolic.h"
#include <cmath>
#include <limits>
#include <iostream>

namespace csc450lib {
namespace linalg {

OptimizerRecord1D Optimizer1D_parabolic::minimize(float startX, float xMin, float xMax, float tol, int maxNumIters) const {
    OptimizerRecord1D record;
    float x1 = xMin, x2 = startX, x3 = xMax;
    float f1 = func_->func(x1), f2 = func_->func(x2), f3 = func_->func(x3);
    float xOpt = x2, fOpt = f2;
    float previousFOpt = std::numeric_limits<float>::max(); // Initialize with max float value

    for (record.numIters = 0; record.numIters < maxNumIters; ++record.numIters) {
        // Parabolic fit calculation
        float denominator = (x2 - x1) * (x2 - x3) * (x3 - x1);
        if (std::abs(denominator) < std::numeric_limits<float>::epsilon()) {
            std::cout << "Numerical instability detected. Adjusting points conservatively." << std::endl;
            // Adjust the search range conservatively to continue the search
            x1 = (x1 + x2) / 2;
            x3 = (x2 + x3) / 2;
            continue;
        }

        float A = (x3 * (f2 - f1) + x2 * (f1 - f3) + x1 * (f3 - f2)) / denominator;
        float B = (x3 * x3 * (f1 - f2) + x2 * x2 * (f3 - f1) + x1 * x1 * (f2 - f3)) / denominator;
        xOpt = -B / (2 * A);

        // Ensure xOpt is within bounds
        if (xOpt < xMin || xOpt > xMax) {
            xOpt = x1 + (x3 - x1) / 2; // Fallback to midpoint if xOpt is out of range
        }

        float fOptNew = func_->func(xOpt);
        if (fOptNew < fOpt) {
            // Update the bracket points based on the new optimum
            if (xOpt < x2) {
                x3 = x2; f3 = f2;
            } else {
                x1 = x2; f1 = f2;
            }
            x2 = xOpt; f2 = fOptNew;
            fOpt = fOptNew;
        } else {
            // Adjust the search range dynamically if no improvement
            x1 = (x1 + x2) / 2;
            x3 = (x2 + x3) / 2;
        }

        // Check for convergence
        if (std::abs(x3 - x1) < tol || std::abs(fOpt - previousFOpt) < tol) {
            record.optX = xOpt;
            record.optVal = fOpt;
            record.isSuccess = true;
            break;
        }
        previousFOpt = fOpt;
    }

    if (!record.isSuccess) {
        std::cout << "Failed to find minimum within tolerance after " << record.numIters << " iterations." << std::endl;
    }

    return record;
}

} // namespace linalg
} // namespace csc450lib
