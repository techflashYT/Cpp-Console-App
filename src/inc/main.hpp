#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>

void parseArgs(int_fast32_t argc, char** argv, bool* debugMode, bool* achievementTestArg);
std::string initDataDir();
void checkName(char (*)[50], bool debugMode);

#include "achievements.hpp"
