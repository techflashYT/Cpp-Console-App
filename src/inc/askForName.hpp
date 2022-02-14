#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstdint>
#include <cstdio>
#include <cstring>

uint8_t writeNameToFile(char name[50], std::string pathString, std::string origPath, bool debugMode);
