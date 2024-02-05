#ifndef CSC450LIB_CALC_DOMAINOFDEFINITION_H
#define CSC450LIB_CALC_DOMAINOFDEFINITION_H

#include <vector>
#include <utility>
#include <set>

namespace csc450lib {
namespace calc {

class DomainOfDefinition {
public:
    enum class BoundType { Inclusive, Exclusive };
    DomainOfDefinition() = default;


    // Constructor for a single interval
    DomainOfDefinition(float lower, BoundType lowerType, float upper, BoundType upperType);

    // Add an interval to the domain
    void addInterval(float lower, BoundType lowerType, float upper, BoundType upperType);

    // Add a single point to the domain
    void addPoint(float point);

    // Check if a value is within the domain
    bool contains(float x) const;

private:
    std::vector<std::pair<std::pair<float, BoundType>, std::pair<float, BoundType>>> intervals_;
    std::set<float> points_;
};

} // namespace calc
} // namespace csc450lib

#endif // CSC450LIB_CALC_DOMAINOFDEFINITION_H
