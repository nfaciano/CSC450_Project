#ifndef GROUNDFUNCTION_H
#define GROUNDFUNCTION_H

#include "FunctionND.h"
#include <vector>
#include <functional>

namespace csc450lib {
namespace linalg {

/**
 * @class GroundFunction
 * @brief A class for representing ground functions, derived from FunctionND.
 */
class GroundFunction : public FunctionND {
public:
    /**
     * @brief Construct a new Ground Function object using a custom function
     * 
     * @param customFunc The custom function to use for this ground function
     */
    GroundFunction(std::function<float(const std::vector<float>&)> customFunc);

    // Disabling copy and assignment
    GroundFunction(const GroundFunction&) = delete;
    GroundFunction& operator=(const GroundFunction&) = delete;

    // Enabling move semantics
    GroundFunction(GroundFunction&&) noexcept = default;
    GroundFunction& operator=(GroundFunction&&) noexcept = default;

    /**
     * @brief Evaluate the ground function at a given point in N-dimensional space
     * 
     * @param x Point in N-dimensional space
     * @return float Function value at point x
     */
    virtual float func(const std::vector<float>& x) const override;

    /**
     * @brief Calculate the gradient of the ground function at a given point
     * 
     * @param x Point in N-dimensional space
     * @return std::vector<float> Gradient at point x
     */
    std::vector<float> grad(const std::vector<float>& x) const override;

private:
    std::function<float(const std::vector<float>&)> customGroundFunc;
};

}  // namespace linalg
}  // namespace csc450lib

#endif // GROUNDFUNCTION_H
