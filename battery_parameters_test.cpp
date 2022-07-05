#define CATCH_CONFIG_MAIN
#include "battery_parameters.h"
#include "test/catch.hpp"

TEST_CASE(" Parameter values")
{

    int         minTempVal         = 0;
    int         maxTempVal         = 45;
    int         minSOCVal          = 20;
    int         maxSOCVal          = 80;
    std::string parameterName1     = "Temperature";
    std::string parameterName2     = "SOC";
    std::string wrongParameterName = "Charging Rate";

    BMSParameters obj_BMSParameters;

    REQUIRE(obj_BMSParameters.sendParameterValuesToConsole(parameterName1, minTempVal, maxTempVal) == true);
    REQUIRE(obj_BMSParameters.sendParameterValuesToConsole(parameterName2, minSOCVal, maxSOCVal) == true);
    REQUIRE(obj_BMSParameters.sendParameterValuesToConsole(wrongParameterName, minTempVal, maxTempVal) == false);
    getchar();
}
