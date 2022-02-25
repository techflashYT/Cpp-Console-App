#pragma once
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <filesystem>

using std::ofstream;
using std::ifstream;

char* askForName(std::string pathString, std::string origPath, bool debugMode);
