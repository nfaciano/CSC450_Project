#include "NewtonRaphsonSolver1D.h"
#include "CSC450Exception.h"
#include <cmath> // Make sure to include cmath for fabs

namespace csc450lib {
    namespace calc {

        NonlinearSolverRecord1D NewtonRaphsonSolver1D::solve(std::shared_ptr<Function1D> f, float a, float b, int n, float tol) const {
            float x = a; // Use 'a' as the initial guess 'x0'
            float fx = f->func(x);
            float dfx;
            int iter = 0;
            while (fabs(fx) > tol && iter < n) {
                dfx = f->dfunc(x);
                if (fabs(dfx) < tol) {
                    throw CSC450Exception(ErrorCode::DERIVATIVE_TOO_SMALL, "Derivative too small, stopping.");
                }
                x -= fx / dfx;
                fx = f->func(x);
                iter++;
            }
            return NonlinearSolverRecord1D(x, fx, iter, fabs(fx) <= tol);
        }

    } // namespace calc
} // namespace csc450lib
