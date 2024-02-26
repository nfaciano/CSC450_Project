#ifndef SURFACE_H
#define SURFACE_H

#include "Function1D.h"
#include <string>

namespace csc450lib {
    namespace calc {

        /**
         * @brief Class representing a surface.
         */
        class Surface : public Function1D {
        private:
            float alpha; /**< Alpha parameter. */

        public:
            /**
             * @brief Constructor for Surface class.
             * @param alpha Alpha parameter.
             * @param xmin Minimum x-value.
             * @param xmax Maximum x-value.
             */
            Surface(float alpha, float xmin, float xmax);

            /**
             * @brief Calculates the function value at a given x-coordinate.
             * @param x Input x-coordinate.
             * @return Function value at x.
             */
            float func(float x) const override;

            /**
             * @brief Calculates the derivative of the function at a given x-coordinate.
             * @param x Input x-coordinate.
             * @return Derivative value at x.
             */
            float dfunc(float x) const;

            /**
             * @brief Gets the Mathematica expression for the function.
             * @return Pointer to the Mathematica expression.
             */
            std::shared_ptr<std::string> getExpressionMMA() const override;

            /**
             * @brief Indicates whether the derivative is exact.
             * @return True if the derivative is exact, false otherwise.
             */
            bool derivativeIsExact() const override;
        };

    } // namespace calc
} // namespace csc450lib

#endif // SURFACE_H
