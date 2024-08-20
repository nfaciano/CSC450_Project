#ifndef CSC450LIB_LINALG_FUNCTION1DFROMND_H
#define CSC450LIB_LINALG_FUNCTION1DFROMND_H

#include "FunctionND.h"
#include "Function1D.h"
#include <vector>

namespace csc450lib {
namespace linalg {

/**
 * @class Function1DfromND
 * @brief A class that represents a one-dimensional function derived from an N-dimensional function.
 */
class Function1DfromND : public calc::Function1D {
public:
    /**
     * @brief Construct a new Function1DfromND object
     * 
     * @param fn The N-dimensional function from which the 1D function is derived
     * @param x0 Origin in N-dimensional space
     * @param u_vect Direction vector for the U axis
     */
    Function1DfromND(const FunctionND& fn, const std::vector<float>& x0, const std::vector<float>& u_vect);

    /**
     * @brief Evaluate the function at a point u in one-dimensional space
     * 
     * @param u Point at which the function is to be evaluated
     * @return float The function value at point u
     */
    float func(float u) const override;

private:
    const FunctionND& fn_; // The N-dimensional function
    std::vector<float> x0_; // Origin in N-dimensional space
    std::vector<float> u_vect_; // Direction vector for the U axis
};

} // namespace linalg
} // namespace csc450lib

#endif // CSC450LIB_LINALG_FUNCTION1DFROMND_H
