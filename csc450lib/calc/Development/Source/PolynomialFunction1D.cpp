#include "PolynomialFunction1D.h"
#include <sstream>

namespace csc450lib {
namespace calc {

PolynomialFunction1D::PolynomialFunction1D(const std::vector<float>& a) : coefficients(a) {}

PolynomialFunction1D::PolynomialFunction1D(const float* a, unsigned int n) : coefficients(a, a + n) {}

float PolynomialFunction1D::func(float x) const {
    float result = 0.0;
    float xPower = 1.0; // Start with x^0
    for (size_t i = 0; i < coefficients.size(); ++i) {
        result += coefficients[i] * xPower;
        xPower *= x; // Calculate the next power of x for the next iteration
    }
    return result;
}

float PolynomialFunction1D::funcHorner(float x) const {
    float result = coefficients.back();
    for (int i = coefficients.size() - 2; i >= 0; --i) {
        result = result * x + coefficients[i];
    }
    return result;
}


float PolynomialFunction1D::dfunc(float x) const {
        // First, get the derivative polynomial
        PolynomialFunction1D derivativePoly = this->derivative();

        // Now, evaluate this derivative polynomial at the given point x
        return derivativePoly.func(x);
    }


    // Method to explicitly use the base class's dfunc for numerical approximation
    float PolynomialFunction1D::numericalDerivative(float x) const {
        return Function1D::dfunc(x);
    }



// Method to compute the derivative polynomial
    PolynomialFunction1D PolynomialFunction1D::derivative() const {
        if (coefficients.size() <= 1) {
            // Derivative of a constant is 0
            return PolynomialFunction1D(std::vector<float>{0});
        }
        std::vector<float> derivativeCoefficients(coefficients.size() - 1);
        for (size_t i = 1; i < coefficients.size(); ++i) {
            derivativeCoefficients[i - 1] = coefficients[i] * i;
        }
        return PolynomialFunction1D(derivativeCoefficients);
    }
std::shared_ptr<std::string> PolynomialFunction1D::getExpressionMMA() const {
    std::stringstream ss;
    ss << coefficients[0];
    for (size_t i = 1; i < coefficients.size(); ++i) {
        ss << " + " << coefficients[i] << "*x^" << i;
    }
    return std::make_shared<std::string>(ss.str());
}



bool PolynomialFunction1D::derivativeIsExact() const {
    return true; // Polynomials have exact derivatives
}
} // namespace calc
} // namespace csc450lib
