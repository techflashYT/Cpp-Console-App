#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>

uint_fast8_t writeNameToFile(char name[50], std::string pathString, std::string origPath, bool debugMode);
