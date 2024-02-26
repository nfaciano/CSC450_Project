#ifndef NEWTON_RAPHSON_SOLVER_1D_H
#define NEWTON_RAPHSON_SOLVER_1D_H

#include "NonlinearSolver1D.h"
#include "Function1D.h" // Include this if Function1D is defined in a separate header

namespace csc450lib {
    namespace calc {
        /*!
         * \class NewtonRaphsonSolver1D
         * \brief Implements the Newton-Raphson method for finding roots of a nonlinear equation.
         */
        class NewtonRaphsonSolver1D : public NonlinearSolver1D {
        public:
            /*!
             * \brief Solve the nonlinear equation using the Newton-Raphson method.
             * \param f The function for which to find a root.
             * \param a Unused parameter in this method, included for interface compatibility.
             * \param b Unused parameter in this method, included for interface compatibility.
             * \param n The maximum number of iterations.
             * \param tol The tolerance for stopping criteria.
             * \return A NonlinearSolverRecord1D containing the solution information.
             */
            NonlinearSolverRecord1D solve(std::shared_ptr<Function1D> f, float a, float b, int n, float tol) const override;
        };
    } // namespace calc
} // namespace csc450lib

#endif // NEWTON_RAPHSON_SOLVER_1D_H
