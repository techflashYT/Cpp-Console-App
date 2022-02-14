#pragma once
#include <iostream>
#include <cstdint>
#include <fstream>
#include <filesystem>

void parseArgs(int argc, char** argv, bool* debugMode);
std::string initDataDir();
std::string checkName(bool debugMode);
