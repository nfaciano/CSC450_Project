#ifndef NONLINEARSOLVER1D_H
#define NONLINEARSOLVER1D_H

#include <memory>
#include "Function1D.h"

namespace csc450lib {
    namespace calc {

        /**
         * @brief Structure representing the record of a 1D nonlinear solver.
         */
        struct NonlinearSolverRecord1D {
            float xStar; /**< The estimated root. */
            float valStar; /**< The function value at the estimated root. */
            int numIter; /**< The number of iterations performed. */
            bool isSuccess; /**< Flag indicating if the solver succeeded. */

            /**
             * @brief Constructor for NonlinearSolverRecord1D.
             * @param xStar The estimated root.
             * @param valStar The function value at the estimated root.
             * @param n The number of iterations performed.
             * @param isSuccess Flag indicating if the solver succeeded.
             */
            NonlinearSolverRecord1D(float xStar, float valStar, int n, bool isSuccess)
                : xStar(xStar), valStar(valStar), numIter(n), isSuccess(isSuccess) {}
        };

        /**
         * @brief Abstract class for 1D nonlinear solvers.
         */
        class NonlinearSolver1D {
        public:
            /**
             * @brief Solves a 1D nonlinear equation.
             * @param f Pointer to the function for which to find a root.
             * @param a Lower bound of the interval.
             * @param b Upper bound of the interval.
             * @param n Maximum number of iterations.
             * @param tol Tolerance for stopping criterion.
             * @return A NonlinearSolverRecord1D object containing the results of the method.
             */
            virtual NonlinearSolverRecord1D solve(std::shared_ptr<Function1D> f, float a, float b, int n, float tol) const = 0;
        };

    } // namespace calc
} // namespace csc450lib

#endif // NONLINEARSOLVER1D_H
