#pragma once
#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <filesystem>

using std::ofstream;
using std::ifstream;

char* askForName(const std::string &pathString, const std::string &origPath);
