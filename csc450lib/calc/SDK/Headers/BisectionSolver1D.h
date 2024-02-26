#ifndef BISECTION_SOLVER_1D_H
#define BISECTION_SOLVER_1D_H

#include "NonlinearSolver1D.h"

namespace csc450lib {
    namespace calc {

        /**
         * @brief Class representing a bisection solver for 1D nonlinear equations.
         */
        class BisectionSolver1D : public NonlinearSolver1D {
        public:
            /**
             * @brief Solves a 1D nonlinear equation using the bisection method.
             * @param f Pointer to the function for which to find a root.
             * @param a Lower bound of the interval.
             * @param b Upper bound of the interval.
             * @param n Maximum number of iterations.
             * @param tol Tolerance for stopping criterion.
             * @return A NonlinearSolverRecord1D object containing the results of the method.
             */
            NonlinearSolverRecord1D solve(std::shared_ptr<Function1D> f, float a, float b, int n, float tol) const override;
        };

    } // namespace calc
} // namespace csc450lib

#endif // BISECTION_SOLVER_1D_H
