// Function1D.cpp

#include "Function1D.h"

namespace csc450lib {
namespace calc {

Function1D::Function1D() 
    : lowerBound_(-std::numeric_limits<float>::max()),
      upperBound_(std::numeric_limits<float>::max()),
      domain_(nullptr) {}

Function1D::Function1D(float xmin, float xmax) 
    : lowerBound_(xmin), upperBound_(xmax), domain_(nullptr) {}

Function1D::Function1D(std::shared_ptr<DomainOfDefinition> d)
    : domain_(d) {
    // For a specific domain, lower and upper bounds might not be meaningful.
    lowerBound_ = 0;
    upperBound_ = 0;
}

bool Function1D::isDefinedAt(float x) const {
    // Check the domain if it's defined, otherwise use the lower and upper bounds.
    if (domain_) {
        return domain_->contains(x);
    } else {
        return x > lowerBound_ && x < upperBound_;
    }
}

float Function1D::getLowerBound() const {
    return lowerBound_;
}

float Function1D::getUpperBound() const {
    return upperBound_;
}

} // namespace calc
} // namespace csc450lib
