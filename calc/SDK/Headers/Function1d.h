// Function1D.h

#ifndef CSC450LIB_CALC_FUNCTION1D_H
#define CSC450LIB_CALC_FUNCTION1D_H

#include "DomainOfDefinition.h"  // Include the header for DomainOfDefinition
#include <memory>
#include <string>

namespace csc450lib {
namespace calc {

class Function1D {
public:
    // Default constructor for a function defined over the entire float range.
    Function1D();

    // Constructor for a function defined over a specific float range.
    Function1D(float xmin, float xmax);

    // Constructor for a function defined over a particular domain.
    Function1D(std::shared_ptr<DomainOfDefinition> d);

    // Pure virtual function to evaluate the function at x.
    virtual float func(float x) const = 0;

    // Pure virtual function to get the function's Mathematica-compatible expression.
    virtual std::shared_ptr<std::string> getExpressionMMA() const = 0;

    // Check if x is within the function's domain.
    bool isDefinedAt(float x) const;

    // Get the lower bound of the function's domain (only valid for simple intervals).
    float getLowerBound() const;

    // Get the upper bound of the function's domain (only valid for simple intervals).
    float getUpperBound() const;

private:
    float lowerBound_;
    float upperBound_;
    std::shared_ptr<DomainOfDefinition> domain_;
};

} // namespace calc
} // namespace csc450lib

#endif // CSC450LIB_CALC_FUNCTION1D_H
