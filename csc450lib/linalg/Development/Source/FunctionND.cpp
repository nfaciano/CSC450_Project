#include "FunctionND.h"

namespace csc450lib {
namespace linalg {

FunctionND::FunctionND(int n) : dim_(n) {
    if (n <= 0) {
        throw std::invalid_argument("Dimension must be positive");
    }
}

FunctionND::~FunctionND() = default;

bool FunctionND::isCorrectDimension(const std::vector<float>& x) const {
    return x.size() == static_cast<size_t>(dim_);
}


}  // namespace linalg
}  // namespace csc450lib
