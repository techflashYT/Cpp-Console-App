#pragma once
#include <iostream>
#include <cstdint>
#include <cstring>

void parseArgs(int argc, char** argv, bool* debugMode);
std::string initDataDir();
void checkName(char (*)[50], bool debugMode);
