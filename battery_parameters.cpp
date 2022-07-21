#include<iostream>
#include<algorithm>
#include"battery_parameters.h"



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

void BMSParameters::sendTemperatureValuesToConsole(int minTempVal, int maxTempVal)
{
    int numberOfValues = 50;
    printf("The values for parameter: Temperature");
    std::cout << "------------------------------------------------------\n";
    for (int paramValue = 0; paramValue < numberOfValues; ++paramValue)
    {
        send_array_temp[paramValue] = getBatteryTempValuesInRange(minTempVal, maxTempVal)[paramValue];
        if (paramValue < numberOfValues - 1)
            std::cout << send_array_temp[paramValue] << ",";
        else
            std::cout << send_array_temp[paramValue];
    }
    std::cout << "\n";
}

void BMSParameters::sendSOCValuesToConsole(int minSOCVal, int maxSOCVal)
{
    int numberOfValues = 50;

    printf("The values for parameter: SOC");
    std::cout << "------------------------------------------------------\n";
    for (int paramValue = 0; paramValue < numberOfValues; ++paramValue)
    {
        send_array_soc[paramValue] = getBatterySOCValuesInRange(minSOCVal, maxSOCVal)[paramValue];
        if (paramValue < numberOfValues - 1)
            std::cout << send_array_soc[paramValue] << ",";
        else
            std::cout << send_array_soc[paramValue];
    }
    std::cout << "\n";
}

bool BMSParameters::sendParameterValuesToConsole( std::string parameterName, int minVal, int maxVal)
{
	if(parameterName == "Temperature")
	{
		sendTemperatureValuesToConsole(minVal,maxVal );
		return true;
	}
	if(parameterName == "SOC")
	{
		sendSOCValuesToConsole(minVal,maxVal );
		return true;
	}
	else
	{
		return false;
	}

}
