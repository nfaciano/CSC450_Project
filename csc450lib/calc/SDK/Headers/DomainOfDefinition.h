#ifndef CSC450LIB_CALC_DOMAINOFDEFINITION_H
#define CSC450LIB_CALC_DOMAINOFDEFINITION_H

#include <vector>
#include <utility>
#include <set>

namespace csc450lib {
namespace calc {
/**
 * @class DomainOfDefinition
 * @brief Represents the domain of definition for a function, including intervals and points.
 * 
 * This class is used to define the domain over which a function is defined. It supports adding
 * both intervals and discrete points to the domain. An interval can be either inclusive or exclusive.
 */
class DomainOfDefinition {
public:
    /**
     * Represents the type of boundary for an interval (inclusive or exclusive).
     */
    enum class BoundType { Inclusive, Exclusive };

    /**
     * Default constructor. Initializes an empty domain.
     */
    DomainOfDefinition();

    /**
     * Constructor for creating a domain with a single interval.
     * @param lower The lower bound of the interval.
     * @param lowerType The type of the lower bound (inclusive or exclusive).
     * @param upper The upper bound of the interval.
     * @param upperType The type of the upper bound (inclusive or exclusive).
     */
    DomainOfDefinition(float lower, BoundType lowerType, float upper, BoundType upperType);

    /**
     * Adds an interval to the domain.
     * @param lower The lower bound of the interval.
     * @param lowerType The type of the lower bound (inclusive or exclusive).
     * @param upper The upper bound of the interval.
     * @param upperType The type of the upper bound (inclusive or exclusive).
     */
    void addInterval(float lower, BoundType lowerType, float upper, BoundType upperType);

    /**
     * Adds a single point to the domain.
     * @param point The point to add to the domain.
     */
    void addPoint(float point);

    /**
     * Checks if a value is within the domain.
     * @param x The value to check.
     * @return True if x is within the domain, false otherwise.
     */
    bool contains(float x) const;

private:
    // Stores intervals as pairs of pairs, each with a float and BoundType
    std::vector<std::pair<std::pair<float, BoundType>, std::pair<float, BoundType>>> intervals_;
    // Stores discrete points
    std::set<float> points_;
};


} // namespace calc
} // namespace csc450lib

#endif // CSC450LIB_CALC_DOMAINOFDEFINITION_H
