#include <algorithm>
#include <iostream>
#include <vector>
static int send_array_param[50];

class BMSParameters
{

  public:
    std::vector<int> getBatteryTempValuesInRange(int minTempVal, int maxTempVal);
    std::vector<int> getBatterySOCValuesInRange(int minSOCVal, int maxSOCVal);
    std::vector<int> generateRandomPrameters(int minVal, int maxVal);
    template <typename T>
    void sendParamValuesToConsole(T min, T max, std::string parameterName);
    bool sendParameterValuesToConsole(std::string parameterName, int minVal, int maxVal);
};
