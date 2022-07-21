#include "Statistics.h"
#include "TestStatistics.h"

int main()
{
    BmsReceiverParameter bmsReceiverParameter = readBmsParametersFromConsole();
    MaximumBmsParameter maximumBmsParameter = getMaximumBmsParameter(bmsReceiverParameter);
    std::cout<<"Maximum Temperature:"<<maximumBmsParameter.maximumTemperature<<std::endl;
    std::cout<<"Maximum State Of Charge:"<<maximumBmsParameter.maximumStateOfCharge<<std::endl;
    MinimumBmsParameter minimumBmsParameter = getMinimumBmsParameter(bmsReceiverParameter);
    std::cout<<"Minimum Temperature:"<<minimumBmsParameter.minimumTemperature<<std::endl;
    std::cout<<"Minimum State Of Charge:"<<minimumBmsParameter.minimumStateOfCharge<<std::endl;
    BmsParameterSimpleMovingAverage bmsParameterSimpleMovingAverage = getSimpleMovingAverageOfBmsParameter(bmsReceiverParameter);
    std::cout<<"Simple Moving Average of last 5 values of Temperature:"<<bmsParameterSimpleMovingAverage.temperatureSimpleMovingAverage<<std::endl;
    std::cout<<"Simple Moving Average of last 5 values of State Of Charge:"<<bmsParameterSimpleMovingAverage.stateOfChargeSimpleMovingAverage<<std::endl;
    
    testBmsParameterStatistics();
    return 0;
}