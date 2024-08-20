#ifndef CSC450LIB_LINALG_OPTIMIZERRECORD1D_H
#define CSC450LIB_LINALG_OPTIMIZERRECORD1D_H

namespace csc450lib {
namespace linalg {

/**
 * @class OptimizerRecord1D
 * @brief A record of the optimization process in one-dimensional optimization.
 */
class OptimizerRecord1D {
public:
    float optX;      ///< Optimized x value
    float optVal;    ///< Optimized function value
    int numIters;    ///< Number of iterations performed
    bool isSuccess;  ///< Success flag for the optimization process

    /**
     * @brief Construct a new Optimizer Record 1D object with default values
     */
    OptimizerRecord1D()
        : optX(0), optVal(0), numIters(0), isSuccess(false) {}
};

} // namespace linalg
} // namespace csc450lib

#endif // CSC450LIB_LINALG_OPTIMIZERRECORD1D_H
