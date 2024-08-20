#include "Surface.h"
#include <string>

namespace csc450lib {
namespace calc {

// Constructor implementation (if not already defined)
Surface::Surface(float alpha, float xmin, float xmax)
    : Function1D(xmin, xmax), alpha(alpha) {
    // Initialization within the constructor list is sufficient.
}

// Concrete implementation of the pure virtual function 'func' from Function1D
// Update func to match the surface equation
float Surface::func(float x) const {
    return (sin(x)+2); // Ground equation
}
float Surface::dfunc(float x) const {
    return (cos(x));  // Derivative 
}



// Concrete implementation of 'getExpressionMMA'
std::shared_ptr<std::string> Surface::getExpressionMMA() const {
    return std::make_shared<std::string>("sin(x)"); // Return the equation as a string
}

// Concrete implementation of 'derivativeIsExact'
bool Surface::derivativeIsExact() const {
    // For a flat surface, the derivative is a constant (zero), so it's exact.
    return true;
}

} // namespace calc
} // namespace csc450lib
