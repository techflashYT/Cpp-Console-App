#pragma once
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <sstream>
#include <filesystem>

using std::ofstream;
using std::ifstream;

std::string askForName(std::string pathString, std::string origPath, bool debugMode);
