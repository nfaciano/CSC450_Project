// SecantSolver1D.cpp

#include "SecantSolver1D.h"
#include "CSC450Exception.h"

namespace csc450lib {
    namespace calc {

        NonlinearSolverRecord1D SecantSolver1D::solve(std::shared_ptr<Function1D> f, float x0, float x1, int n, float tol) const {
            float f0 = f->func(x0);
            float f1 = f->func(x1);
            float x2, f2;
            int iter = 1; // Starting with 1 since we already have f(x0) and f(x1)

            while (fabs(f1) > tol && iter < n) {
                if (fabs(f1 - f0) < tol) {
                    FAIL_CONDITION(true, ErrorCode::FUNCTION_DIFFERENCE_TOO_SMALL, "Difference between f(x1) and f(x0) too small, stopping.");

                }
                x2 = x1 - f1 * (x1 - x0) / (f1 - f0);
                f2 = f->func(x2);

                x0 = x1;
                f0 = f1;
                x1 = x2;
                f1 = f2;

                iter++;
            }

            return NonlinearSolverRecord1D(x1, f1, iter, fabs(f1) <= tol);
        }

    } // namespace calc
} // namespace csc450lib
