#ifndef CSC450LIB_LINALG_OPTIMIZER1D_STEEPESTDESCENT_H
#define CSC450LIB_LINALG_OPTIMIZER1D_STEEPESTDESCENT_H

#include "Optimizer1D.h"

namespace csc450lib {
namespace linalg {

/**
 * @class Optimizer1D_steepestDescent
 * @brief A class that performs optimization using the steepest descent method.
 */
class Optimizer1D_steepestDescent : public Optimizer1D {
public:
    using Optimizer1D::Optimizer1D; // Inherit constructor

    /**
     * @brief Performs minimization using the steepest descent method.
     * 
     * @param startX Starting point of the search
     * @param xMin Minimum bound of the search interval
     * @param xMax Maximum bound of the search interval
     * @param tol Tolerance for the stopping criterion
     * @param maxNumIters Maximum number of iterations
     * @return OptimizerRecord1D A record of the optimization process
     */
    OptimizerRecord1D minimize(float startX, float xMin, float xMax, float tol, int maxNumIters) const override;
};

} // namespace linalg
} // namespace csc450lib

#endif // CSC450LIB_LINALG_OPTIMIZER1D_STEEPESTDESCENT_H
