#pragma once
#include <cstdint>
#include <iostream>
#include <future>
#include <vector>
#include "achievements.hpp"
extern "C" {
	#include "GL/glut.h"
	#include <windows.h>
}
template<typename ...Args>
void log(std::string format, Args&&... args);
void checkArgs(int_fast32_t argc, char** argv, bool* achievementTestArg);
std::string initDataDir();
void checkName(char (*nameRef)[50]);
void display();
void setUpDisplayVars(uint_fast32_t desktopRight, uint_fast32_t desktopBottom);


std::vector<std::future<void>> futures;
