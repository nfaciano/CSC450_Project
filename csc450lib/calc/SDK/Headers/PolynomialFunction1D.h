#ifndef POLYNOMIALFUNCTION1D_H
#define POLYNOMIALFUNCTION1D_H

#include "Function1D.h"
#include <vector>
#include <memory>
#include <string>

namespace csc450lib {
namespace calc {

/**
 * @class PolynomialFunction1D
 * @brief Represents a one-dimensional polynomial function.
 * 
 * This class extends Function1D to implement polynomial functions. It supports evaluation
 * of the polynomial at a given point using both a traditional method and Horner's method.
 * It also provides a method to get a Mathematica-compatible expression of the polynomial.
 */
class PolynomialFunction1D : public Function1D {
public:
    /**
     * Constructor from a vector of coefficients.
     * @param a The coefficients of the polynomial, from highest to lowest degree.
     */
    PolynomialFunction1D(const std::vector<float>& a);

    /**
     * Constructor from an array of coefficients.
     * @param a The coefficients array.
     * @param n The number of coefficients in the array.
     */
    PolynomialFunction1D(const float* a, unsigned int n);

    /**
     * Evaluates the polynomial at a given point x using a modified traditional method.
     * @param x The point at which to evaluate the polynomial.
     * @return The value of the polynomial at x.
     */
    float func(float x) const override;

    /**
     * Evaluates the polynomial at a given point x using Horner's method.
     * @param x The point at which to evaluate the polynomial.
     * @return The value of the polynomial at x.
     */
    float funcHorner(float x) const;

    /**
     * Gets a Mathematica-compatible expression of the polynomial.
     * @return A string containing the Mathematica-compatible expression.
     */
    std::shared_ptr<std::string> getExpressionMMA() const override;
    /**
     * Indicates that this polynomial function can compute its derivative exactly.
     * @return Always true for polynomial functions.
     */

    // Override the dfunc method to provide an exact derivative value at x
    float dfunc(float x) const override;

    // Implementation indicating this class provides an exact derivative
    bool derivativeIsExact() const override;

    PolynomialFunction1D derivative() const;

    float numericalDerivative(float x) const;


private:
    std::vector<float> coefficients; ///< The coefficients of the polynomial.
};


} // namespace calc
} // namespace csc450lib

#endif // POLYNOMIALFUNCTION1D_H
