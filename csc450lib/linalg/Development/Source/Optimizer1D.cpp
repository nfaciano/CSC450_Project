#include "Optimizer1D.h"

namespace csc450lib {
namespace linalg {

Optimizer1D::Optimizer1D(std::shared_ptr<calc::Function1D> f) : func_(std::move(f)) {}

void Optimizer1D::setFunction(std::shared_ptr<calc::Function1D> f) {
    func_ = std::move(f);
}

std::shared_ptr<const calc::Function1D> Optimizer1D::getFunction() const {
    return func_;
}

} // namespace linalg
} // namespace csc450lib
