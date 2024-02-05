#include "Function1D.h"
#include "DomainOfDefinition.h"
#include <iostream>
#include <cassert>
#include <limits>
#include <cmath>
#include <memory>

// Example function that inherits from Function1D for testing
class TestFunction : public csc450lib::calc::Function1D {
public:
    TestFunction() : Function1D() {}
    TestFunction(float xmin, float xmax) : Function1D(xmin, xmax) {}
    TestFunction(std::shared_ptr<csc450lib::calc::DomainOfDefinition> d) : Function1D(d) {}

    virtual float func(float x) const override {
        return x * x; // Simple square function for testing
    }

    virtual std::shared_ptr<std::string> getExpressionMMA() const override {
        return std::make_shared<std::string>("x^2");
    }
};


bool areFloatsEqual(float a, float b, float epsilon = 0.0001) {
    return std::abs(a - b) < epsilon;
}

void testDomainContains() {
    std::cout << "Testing DomainOfDefinition::contains..." << std::endl;

    csc450lib::calc::DomainOfDefinition domain(0, csc450lib::calc::DomainOfDefinition::BoundType::Inclusive, 1, csc450lib::calc::DomainOfDefinition::BoundType::Exclusive);
    assert(domain.contains(0.5) && "0.5 should be within the domain");
    assert(!domain.contains(1.5) && "1.5 should not be within the domain");
    
    // Test boundary cases
    assert(domain.contains(0) && "0 should be included in the domain");
    assert(!domain.contains(1) && "1 should be excluded from the domain");
    
    std::cout << "Passed DomainOfDefinition::contains tests." << std::endl;
}

void testFunctionDefinition() {
    std::cout << "Testing Function1D::isDefinedAt..." << std::endl;

    auto domainPtr = std::make_shared<csc450lib::calc::DomainOfDefinition>(0, csc450lib::calc::DomainOfDefinition::BoundType::Inclusive, 1, csc450lib::calc::DomainOfDefinition::BoundType::Exclusive);
    TestFunction funcWithDomain(domainPtr);
    
    assert(funcWithDomain.isDefinedAt(0.5) && "Function should be defined at 0.5");
    assert(!funcWithDomain.isDefinedAt(1.5) && "Function should not be defined at 1.5");
    
    std::cout << "Passed Function1D::isDefinedAt tests." << std::endl;
}

void testFunctionEvaluation() {
    std::cout << "Testing TestFunction::func..." << std::endl;

    TestFunction funcWithBounds(-10, 10);
    assert(areFloatsEqual(funcWithBounds.func(2), 4) && "Function at x=2 should evaluate to 4");
    assert(areFloatsEqual(funcWithBounds.func(-3), 9) && "Function at x=-3 should evaluate to 9");

    std::cout << "Passed TestFunction::func tests." << std::endl;
}
void testMultipleIntervalsAndPoints() {
    std::cout << "Testing multiple intervals and single points..." << std::endl;

    csc450lib::calc::DomainOfDefinition multiDomain;
    multiDomain.addInterval(-10, csc450lib::calc::DomainOfDefinition::BoundType::Inclusive, -5, csc450lib::calc::DomainOfDefinition::BoundType::Exclusive);
    multiDomain.addInterval(5, csc450lib::calc::DomainOfDefinition::BoundType::Inclusive, 10, csc450lib::calc::DomainOfDefinition::BoundType::Inclusive);
    multiDomain.addPoint(0);

    // Test multiple intervals
    assert(multiDomain.contains(-7.5) && "Point within the first interval should be contained");
    assert(multiDomain.contains(7.5) && "Point within the second interval should be contained");
    assert(multiDomain.contains(0) && "Single point added should be contained");
    assert(!multiDomain.contains(11) && "Point outside any interval should not be contained");
    assert(!multiDomain.contains(-10.1) && "Point outside any interval should not be contained");
    
    // Test boundaries
    assert(multiDomain.contains(-10) && "Inclusive boundary of first interval should be contained");
    assert(!multiDomain.contains(-5) && "Exclusive boundary of first interval should not be contained");
    assert(multiDomain.contains(10) && "Inclusive boundary of second interval should be contained");
    
    std::cout << "Passed tests for multiple intervals and single points." << std::endl;
}

void testBoundsMethods() {
    std::cout << "Testing Function1D bounds methods..." << std::endl;

    TestFunction funcWithBounds(-10, 10);
    assert(areFloatsEqual(funcWithBounds.getLowerBound(), -10) && "Lower bound should be -10");
    assert(areFloatsEqual(funcWithBounds.getUpperBound(), 10) && "Upper bound should be 10");

    // Test with domain
    auto domainPtr = std::make_shared<csc450lib::calc::DomainOfDefinition>(0, csc450lib::calc::DomainOfDefinition::BoundType::Inclusive, 1, csc450lib::calc::DomainOfDefinition::BoundType::Exclusive);
    TestFunction funcWithDomain(domainPtr);
    assert(areFloatsEqual(funcWithDomain.getLowerBound(), 0) && "Lower bound should be 0 for domain");
    assert(areFloatsEqual(funcWithDomain.getUpperBound(), 0) && "Upper bound should be 0 for domain");

    std::cout << "Passed Function1D bounds methods tests." << std::endl;
}

int main() {
    try {
        testDomainContains();
        testFunctionDefinition();
        testFunctionEvaluation();
        testMultipleIntervalsAndPoints();
        testBoundsMethods();
        // More tests can be added here
        std::cout << "All tests passed successfully." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Test failed with exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}