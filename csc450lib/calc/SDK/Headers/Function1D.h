// Function1D.h

#ifndef CSC450LIB_CALC_FUNCTION1D_H
#define CSC450LIB_CALC_FUNCTION1D_H

#include "DomainOfDefinition.h"  // Include the header for DomainOfDefinition
#include <memory>
#include <string>

namespace csc450lib {
namespace calc {

/**
 * @class Function1D
 * @brief Abstract base class for a one-dimensional mathematical function.
 * 
 * This class provides a common interface for functions of a single variable. It supports
 * evaluation of the function at a point, checking if a point is within the function's domain,
 * and obtaining the function's domain bounds. It is designed to be extended by more specific
 * function types.
 */
class Function1D {
public:
    // Constructors and virtual destructor for polymorphic use
    Function1D();
    Function1D(float xmin, float xmax);
    Function1D(std::shared_ptr<DomainOfDefinition> d);

    /**
     * Pure virtual function to evaluate the function at a given value of x.
     * @param x The input value.
     * @return The function value at x.
     */
    virtual float func(float x) const = 0;

    /**
     * Pure virtual function to get the function's Mathematica-compatible expression.
     * @return A string containing the Mathematica-compatible expression.
     */
    virtual std::shared_ptr<std::string> getExpressionMMA() const = 0;

    /**
     * Checks if the function is defined at a given value of x.
     * @param x The value to check.
     * @return True if the function is defined at x, false otherwise.
     */
    bool isDefinedAt(float x) const;

    /**
     * Gets the lower bound of the function's domain.
     * @return The lower bound of the domain.
     */
    float getLowerBound() const;

    /**
     * Gets the upper bound of the function's domain.
     * @return The upper bound of the domain.
     */
    float getUpperBound() const;
    /**
     * Computes the numerical approximation of the first derivative at a given point x.
     * @param x The point at which to approximate the derivative.
     * @return The approximate derivative at x.
     */
    virtual float dfunc(float x) const;

    /**
     * Pure virtual function to check if the derivative calculation is exact.
     * @return True if the derivative is calculated exactly, false otherwise.
     */
    virtual bool derivativeIsExact() const = 0;



private:
    float lowerBound_; ///< The lower bound of the domain for simple intervals.
    float upperBound_; ///< The upper bound of the domain for simple intervals.
    std::shared_ptr<DomainOfDefinition> domain_; ///< The domain of definition object.
};


} // namespace calc
} // namespace csc450lib

#endif // CSC450LIB_CALC_FUNCTION1D_H
