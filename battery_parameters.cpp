#include "battery_parameters.h"
#include <string>

#define TOTAL_COUNT 50

std::vector<int> BMSParameters::generateRandomPrameters(int minVal, int maxVal)
{
    static std::vector<int> generatedParameters;
    generatedParameters.push_back(rand() % (maxVal - minVal + 1) + minVal);
    return generatedParameters;
}

std::vector<int> BMSParameters::getBatteryTempValuesInRange(int minTempVal, int maxTempVal)
{
    return generateRandomPrameters(minTempVal, maxTempVal);
}

std::vector<int> BMSParameters::getBatterySOCValuesInRange(int minSOCVal, int maxSOCVal)
{
    return generateRandomPrameters(minSOCVal, maxSOCVal);
}

template <typename T>
void BMSParameters::sendParamValuesToConsole(T min, T max, std::string parameterName)
{

    std::cout << "The values for parameter:";
    std::cout << parameterName;
    std::cout << "------------------------------------------------------\n";
    for (int paramValue = 0; paramValue < TOTAL_COUNT; ++paramValue)
    {
        send_array_param[paramValue] = getBatterySOCValuesInRange(min, max)[paramValue];
        if (paramValue < TOTAL_COUNT - 1)
            std::cout << send_array_param[paramValue] << ",";
        else
            std::cout << send_array_param[paramValue];
    }
    std::cout << "\n";
}

bool BMSParameters::sendParameterValuesToConsole(std::string parameterName, int minVal, int maxVal)
{
    sendParamValuesToConsole(minVal, maxVal, parameterName);
    return true;
}
