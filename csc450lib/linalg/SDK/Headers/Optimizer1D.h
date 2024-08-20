#ifndef CSC450LIB_LINALG_OPTIMIZER1D_H
#define CSC450LIB_LINALG_OPTIMIZER1D_H

#include "Function1D.h"
#include "OptimizerRecord1D.h"
#include <memory>

namespace csc450lib {
namespace linalg {

/**
 * @class Optimizer1D
 * @brief Abstract class representing an optimizer for one-dimensional functions.
 */
class Optimizer1D {
public:
    /**
     * @brief Construct a new Optimizer1D object
     * 
     * @param f Function to be optimized, wrapped in a shared pointer
     */
    explicit Optimizer1D(std::shared_ptr<calc::Function1D> f);

    /**
     * @brief Virtual destructor for polymorphic deletion
     */
    virtual ~Optimizer1D() = default;

    // Prevent copy and move operations
    Optimizer1D(const Optimizer1D&) = delete;
    Optimizer1D(Optimizer1D&&) = delete;
    Optimizer1D& operator=(const Optimizer1D&) = delete;
    Optimizer1D& operator=(Optimizer1D&&) = delete;

    /**
     * @brief Set the function object to be optimized
     * 
     * @param f Function to be optimized, wrapped in a shared pointer
     */
    void setFunction(std::shared_ptr<calc::Function1D> f);

    /**
     * @brief Get the function object being optimized
     * 
     * @return std::shared_ptr<const calc::Function1D> The function being optimized
     */
    std::shared_ptr<const calc::Function1D> getFunction() const;

    /**
     * @brief Perform optimization and return the optimization record
     * 
     * @param startX Initial search point
     * @param xMin Minimum x value for search
     * @param xMax Maximum x value for search
     * @param tol Tolerance for optimization
     * @param maxNumIters Maximum number of iterations
     * @return OptimizerRecord1D The record of the optimization process
     */
    virtual OptimizerRecord1D minimize(float startX, float xMin, float xMax,
                                       float tol, int maxNumIters) const = 0;

protected:
    std::shared_ptr<calc::Function1D> func_;  // Function to be optimized
};

} // namespace linalg
} // namespace csc450lib

#endif // CSC450LIB_LINALG_OPTIMIZER1D_H
