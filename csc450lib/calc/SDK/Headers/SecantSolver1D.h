#ifndef SECANT_SOLVER_1D_H
#define SECANT_SOLVER_1D_H

#include "NonlinearSolver1D.h"
#include "Function1D.h"

namespace csc450lib {
    namespace calc {

        /**
         * @brief Class representing a Secant solver for 1D nonlinear equations.
         */
        class SecantSolver1D : public NonlinearSolver1D {
        public:
            /**
             * @brief Solves a 1D nonlinear equation using the Secant method.
             * @param f Pointer to the function for which to find a root.
             * @param x0 First initial guess for the root.
             * @param x1 Second initial guess for the root (should be different from x0).
             * @param n Maximum number of iterations.
             * @param tol Tolerance for the stopping criterion.
             * @return A NonlinearSolverRecord1D object containing the results of the method.
             */
            NonlinearSolverRecord1D solve(std::shared_ptr<Function1D> f, float x0, float x1, int n, float tol) const override;
        };

    } // namespace calc
} // namespace csc450lib

#endif // SECANT_SOLVER_1D_H
