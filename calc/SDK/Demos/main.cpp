#include "ExponentialDecayOscillation.h"
#include "SineWaveVaryingAmplitude.h"
#include "PolynomialFunction1D.h"
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    // Define the range and step size for x values
    float xStart = 0.0f, xEnd = 10.0f, xStep = 0.1f;

    csc450lib::calc::ExponentialDecayOscillation expDecayFunc;
    csc450lib::calc::SineWaveVaryingAmplitude sineWaveFunc;
    std::vector<float> polyCoefficients = {1.0f, -2.0f, 1.0f}; // 1.0 + (-2.0)*x + 1.0*x^2
    csc450lib::calc::PolynomialFunction1D polyFunc(polyCoefficients);

    // Open output files
    std::ofstream expDecayFile("expDecayResults.txt");
    std::ofstream sineWaveFile("sineWaveResults.txt");
    std::ofstream polyFuncFile("polyFuncResults.txt");

    // Check if files are open
    if (!expDecayFile.is_open() || !sineWaveFile.is_open() || !polyFuncFile.is_open()) {
        std::cerr << "Error opening output files." << std::endl;
        return 1;
    }

    // Loop over the range of x values and write the results
for (float x = xStart; x <= xEnd + xStep * 0.5f; x += xStep) {
        expDecayFile << x << "\t" << expDecayFunc.func(x) << std::endl;
        sineWaveFile << x << "\t" << sineWaveFunc.func(x) << std::endl;
        polyFuncFile << x << "\t" << polyFunc.func(x) << std::endl;
    }

    // Close the files
    expDecayFile.close();
    sineWaveFile.close();
    polyFuncFile.close();

    std::cout << "Output files generated successfully." << std::endl;
    return 0;
}
