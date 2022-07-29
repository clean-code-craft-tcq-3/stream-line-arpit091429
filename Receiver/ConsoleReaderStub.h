#ifndef CONSOLEREADERSTUB
#define CONSOLEREADERSTUB

BmsReceiverParameter readBmsParametersFromConsoleStub1()
{
    BmsReceiverParameter bmsReceiverParameter;
    bmsReceiverParameter.temperatureValues = {};
    bmsReceiverParameter.stateOfChargeValues = {};
    return bmsReceiverParameter;
}

BmsReceiverParameter readBmsParametersFromConsoleStub2()
{
    BmsReceiverParameter bmsReceiverParameter;
    bmsReceiverParameter.temperatureValues = {10, -5, 44, 56, 6, 83};
    bmsReceiverParameter.stateOfChargeValues = {50, 64, 15, 89, 3, 99, 65, 78, 38};
    return bmsReceiverParameter;
}

BmsReceiverParameter readBmsParametersFromConsoleStub3()
{
    BmsReceiverParameter bmsReceiverParameter;
    bmsReceiverParameter.temperatureValues = {45, 0, -1, 46, 25, 59, 16, 7};
    bmsReceiverParameter.stateOfChargeValues = {74, 26, 20, 80, 10, 97, 37, 2};
    return bmsReceiverParameter;
}

#endif