#pragma once
#include <vector>
#include <string> 

static int send_array_temp[50];
static int send_array_soc[50];

class BMSParameters
{

public:

    std::vector<int> getBatteryTempValuesInRange(int minTempVal, int maxTempVal);
    std::vector<int> getBatterySOCValuesInRange(int minSOCVal, int maxSOCVal);
    std::vector<int> generateRandomPrameters(int minVal, int maxVal);
    void sendTemperatureValuesToConsole(int minTempVal, int maxTempVal);
    void sendSOCValuesToConsole(int minSOCVal, int maxSOCVal);
    bool sendParameterValuesToConsole(std::string parameterName, int minVal, int maxVal);
};
