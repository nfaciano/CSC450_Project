#include "DomainOfDefinition.h"

namespace csc450lib {
namespace calc {

DomainOfDefinition::DomainOfDefinition(float lower, BoundType lowerType, float upper, BoundType upperType) {
    addInterval(lower, lowerType, upper, upperType);
}

void DomainOfDefinition::addInterval(float lower, BoundType lowerType, float upper, BoundType upperType) {
    intervals_.push_back({{lower, lowerType}, {upper, upperType}});
}

void DomainOfDefinition::addPoint(float point) {
    points_.insert(point);
}

bool DomainOfDefinition::contains(float x) const {
    for (const auto& interval : intervals_) {
        bool lowerOk = (interval.first.second == BoundType::Inclusive) ? (x >= interval.first.first) : (x > interval.first.first);
        bool upperOk = (interval.second.second == BoundType::Inclusive) ? (x <= interval.second.first) : (x < interval.second.first);
        if (lowerOk && upperOk) {
            return true;
        }
    }

    if (points_.find(x) != points_.end()) {
        return true;
    }

    return false;
}

} // namespace calc
} // namespace csc450lib
