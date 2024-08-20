#ifndef FUNCTIONND_H
#define FUNCTIONND_H

#include <vector>
#include <stdexcept>

namespace csc450lib {
namespace linalg {

/**
 * @class FunctionND
 * @brief Abstract class for N-dimensional functions.
 */
class FunctionND {
public:
    /**
     * @brief Construct a new FunctionND object
     * 
     * @param n Dimension of the function's input set
     */
    explicit FunctionND(int n);

    /**
     * @brief Destroy the FunctionND object
     */
    virtual ~FunctionND();

    // Preventing copy and assignment
    FunctionND(const FunctionND&) = delete;
    FunctionND& operator=(const FunctionND&) = delete;

    /**
     * @brief Calculate the function value at a given point in N-dimensional space
     * 
     * @param x Point in N-dimensional space
     * @return float Function value at point x
     */
    virtual float func(const std::vector<float>& x) const = 0;

    /**
     * @brief Calculate the gradient of the function at a given point in N-dimensional space
     * 
     * @param x Point in N-dimensional space
     * @return std::vector<float> Gradient of the function at point x
     */
    virtual std::vector<float> grad(const std::vector<float>& x) const = 0;

protected:
    int dim_;  // Dimension of the function's input set

private:
    bool isCorrectDimension(const std::vector<float>& x) const;
};

}  // namespace linalg
}  // namespace csc450lib

#endif // FUNCTIONND_H
