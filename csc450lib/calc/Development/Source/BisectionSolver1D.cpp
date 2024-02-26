#include "BisectionSolver1D.h"
#include "CSC450Exception.h"
#include <iostream>
namespace csc450lib {
    namespace calc {

        NonlinearSolverRecord1D BisectionSolver1D::solve(std::shared_ptr<Function1D> f, float a, float b, int n, float tol) const {
            float fa = f->func(a);
            float fb = f->func(b);
            
            // Replace standard exception with CSC450Exception
FAIL_CONDITION(fa * fb >= 0, ErrorCode::FUNCTION_NOT_DEFINED_AT_EVALUATION_POINT, "f(a) and f(b) must have opposite signs");
            float c, fc;
            int iter = 0;
            do {
                c = (a + b) / 2;
                fc = f->func(c);

                if (fa * fc < 0) {
                    b = c;
                    fb = fc;
                } else {
                    a = c;
                    fa = fc;
                }

                iter++;
            } while (fabs(fc) > tol && iter < n);

            return NonlinearSolverRecord1D(c, fc, iter, fabs(fc) <= tol);
        }

    } // namespace calc
} // namespace csc450lib
