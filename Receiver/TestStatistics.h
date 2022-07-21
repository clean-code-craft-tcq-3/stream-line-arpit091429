#ifndef TESTSTATISTICS
#define TESTSTATISTICS

#include <assert.h>
#include "ConsoleReaderStub.h"

void testMaximumForEmptyValues(BmsReceiverParameter bmsReceiverParameter)
{
    MaximumBmsParameter maximumBmsParameter = getMaximumBmsParameter(bmsReceiverParameter);
    assert(maximumBmsParameter.maximumTemperature == 0);
    assert(maximumBmsParameter.maximumStateOfCharge == 0);
}

void testMinimumForEmptyValues(BmsReceiverParameter bmsReceiverParameter)
{
    MinimumBmsParameter minimumBmsParameter = getMinimumBmsParameter(bmsReceiverParameter);
    assert(minimumBmsParameter.minimumTemperature == 0);
    assert(minimumBmsParameter.minimumStateOfCharge == 0);
}

void testSmaForEmptyValues(BmsReceiverParameter bmsReceiverParameter)
{
    BmsParameterSimpleMovingAverage bmsParameterSimpleMovingAverage = getSimpleMovingAverageOfBmsParameter(bmsReceiverParameter);
    assert(bmsParameterSimpleMovingAverage.temperatureSimpleMovingAverage == 0);
    assert(bmsParameterSimpleMovingAverage.stateOfChargeSimpleMovingAverage == 0);
}

void testForEmptyValues()
{
    BmsReceiverParameter bmsReceiverParameter = readBmsParametersFromConsoleStub1();
    testMaximumForEmptyValues(bmsReceiverParameter);
    testMinimumForEmptyValues(bmsReceiverParameter);
    testSmaForEmptyValues(bmsReceiverParameter);
}

void testMaximumForDifferentNumberOfValues(BmsReceiverParameter bmsReceiverParameter)
{
    MaximumBmsParameter maximumBmsParameter = getMaximumBmsParameter(bmsReceiverParameter);
    assert(maximumBmsParameter.maximumTemperature == 83);
    assert(maximumBmsParameter.maximumStateOfCharge == 99);
}

void testMinimumForDifferentNumberOfValues(BmsReceiverParameter bmsReceiverParameter)
{
    MinimumBmsParameter minimumBmsParameter = getMinimumBmsParameter(bmsReceiverParameter);
    assert(minimumBmsParameter.minimumTemperature == -5);
    assert(minimumBmsParameter.minimumStateOfCharge == 3);
}

void testSmaForDifferentNumberOfValues(BmsReceiverParameter bmsReceiverParameter)
{
    BmsParameterSimpleMovingAverage bmsParameterSimpleMovingAverage = getSimpleMovingAverageOfBmsParameter(bmsReceiverParameter);
    assert(bmsParameterSimpleMovingAverage.temperatureSimpleMovingAverage == (float)36.8);
    assert(bmsParameterSimpleMovingAverage.stateOfChargeSimpleMovingAverage == (float)56.6);
}

void testForDifferentNumberOfValues()
{
    BmsReceiverParameter bmsReceiverParameter = readBmsParametersFromConsoleStub2();
    testMaximumForDifferentNumberOfValues(bmsReceiverParameter);
    testMinimumForDifferentNumberOfValues(bmsReceiverParameter);
    testSmaForDifferentNumberOfValues(bmsReceiverParameter);
}

void testMaximumForEqualNumberOfValues(BmsReceiverParameter bmsReceiverParameter)
{
    MaximumBmsParameter maximumBmsParameter = getMaximumBmsParameter(bmsReceiverParameter);
    assert(maximumBmsParameter.maximumTemperature == 59);
    assert(maximumBmsParameter.maximumStateOfCharge == 97);
}

void testMinimumForEqualNumberOfValues(BmsReceiverParameter bmsReceiverParameter)
{
    MinimumBmsParameter minimumBmsParameter = getMinimumBmsParameter(bmsReceiverParameter);
    assert(minimumBmsParameter.minimumTemperature == -1);
    assert(minimumBmsParameter.minimumStateOfCharge == 2);
}

void testSmaForEqualNumberOfValues(BmsReceiverParameter bmsReceiverParameter)
{
    BmsParameterSimpleMovingAverage bmsParameterSimpleMovingAverage = getSimpleMovingAverageOfBmsParameter(bmsReceiverParameter);
    assert(bmsParameterSimpleMovingAverage.temperatureSimpleMovingAverage == (float)30.6);
    assert(bmsParameterSimpleMovingAverage.stateOfChargeSimpleMovingAverage == (float)45.2);
}

void testForEqualNumberOfValues()
{
    BmsReceiverParameter bmsReceiverParameter = readBmsParametersFromConsoleStub3();
    testMaximumForEqualNumberOfValues(bmsReceiverParameter);
    testMinimumForEqualNumberOfValues(bmsReceiverParameter);
    testSmaForEqualNumberOfValues(bmsReceiverParameter);
}

void testBmsParameterStatistics()
{
    testForEmptyValues();
    testForDifferentNumberOfValues();
    testForEqualNumberOfValues();
}

#endif