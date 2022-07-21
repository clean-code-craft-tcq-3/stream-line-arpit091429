#ifndef CONSOLEREADER
#define CONSOLEREADER

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#define TEMPERATURE_STRING "Temperature"
#define STATEOFCHARGE_STRING "SOC"

struct BmsReceiverParameter
{
    std::vector<int> temperatureValues;
    std::vector<int> stateOfChargeValues;
};

std::vector<int> getBmsParameterValues()
{
    std::string line, value;
    std::vector<int> parameterValues;
    getline(std::cin, line);
    std::stringstream values(line);
    while(getline(values, value, ','))
    {
        parameterValues.push_back(std::stoi(value));
    }
    return parameterValues;
}

void validateBmsParameter(std::string line, BmsReceiverParameter &bmsReceiverParameter)
{
    std::string value;
    if(line.find(TEMPERATURE_STRING) != std::string::npos)
    {
        bmsReceiverParameter.temperatureValues = getBmsParameterValues();
    }
    else if(line.find(STATEOFCHARGE_STRING) != std::string::npos)
    {
        bmsReceiverParameter.stateOfChargeValues = getBmsParameterValues();
    }
}

BmsReceiverParameter readBmsParametersFromConsole()
{
    std::string line;
    BmsReceiverParameter bmsReceiverParameter;
    while(getline(std::cin, line))
    {
        validateBmsParameter(line, bmsReceiverParameter);
    }
    return bmsReceiverParameter;
}

#endif