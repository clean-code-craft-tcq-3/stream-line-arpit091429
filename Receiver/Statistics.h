#ifndef STATISTICS
#define STATISTICS

#include <bits/stdc++.h>
#include "ConsoleReader.h"

#define SMA_NUMBER_OF_ELEMETS 5

struct MaximumBmsParameter
{
    int maximumTemperature;
    int maximumStateOfCharge;
};

struct MinimumBmsParameter
{
    int minimumTemperature;
    int minimumStateOfCharge;
};

struct BmsParameterSimpleMovingAverage
{
    float temperatureSimpleMovingAverage;
    float stateOfChargeSimpleMovingAverage;
};

MaximumBmsParameter getMaximumBmsParameter(BmsReceiverParameter bmsReceiverParameter)
{
    MaximumBmsParameter maximumBmsParameter{0, 0};
    if(bmsReceiverParameter.temperatureValues.size() > 0)
    {
        maximumBmsParameter.maximumTemperature = *max_element(bmsReceiverParameter.temperatureValues.begin(), bmsReceiverParameter.temperatureValues.end());
    }
    if(bmsReceiverParameter.stateOfChargeValues.size() > 0)
    {
        maximumBmsParameter.maximumStateOfCharge = *max_element(bmsReceiverParameter.stateOfChargeValues.begin(), bmsReceiverParameter.stateOfChargeValues.end());
    }
    return maximumBmsParameter;
}

MinimumBmsParameter getMinimumBmsParameter(BmsReceiverParameter bmsReceiverParameter)
{
    MinimumBmsParameter minimumBmsParameter{0, 0};
    if(bmsReceiverParameter.temperatureValues.size() > 0)
    {
        minimumBmsParameter.minimumTemperature = *min_element(bmsReceiverParameter.temperatureValues.begin(), bmsReceiverParameter.temperatureValues.end());
    }
    if(bmsReceiverParameter.stateOfChargeValues.size() > 0)
    {
        minimumBmsParameter.minimumStateOfCharge = *min_element(bmsReceiverParameter.stateOfChargeValues.begin(), bmsReceiverParameter.stateOfChargeValues.end());
    }
    return minimumBmsParameter;
}

BmsParameterSimpleMovingAverage getSimpleMovingAverageOfBmsParameter(BmsReceiverParameter bmsReceiverParameter)
{
    BmsParameterSimpleMovingAverage bmsParameterSimpleMovingAverage{0, 0};
    if(bmsReceiverParameter.temperatureValues.size() >= SMA_NUMBER_OF_ELEMETS)
    {
        bmsParameterSimpleMovingAverage.temperatureSimpleMovingAverage = std::accumulate(bmsReceiverParameter.temperatureValues.end()-SMA_NUMBER_OF_ELEMETS, bmsReceiverParameter.temperatureValues.end(), 0.0) / SMA_NUMBER_OF_ELEMETS;
    }
    if(bmsReceiverParameter.stateOfChargeValues.size() >= SMA_NUMBER_OF_ELEMETS)
    {
        bmsParameterSimpleMovingAverage.stateOfChargeSimpleMovingAverage = std::accumulate(bmsReceiverParameter.stateOfChargeValues.end()-SMA_NUMBER_OF_ELEMETS, bmsReceiverParameter.stateOfChargeValues.end(), 0.0) / SMA_NUMBER_OF_ELEMETS;
    }
    return bmsParameterSimpleMovingAverage;
}

#endif