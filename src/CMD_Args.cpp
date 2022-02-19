#include "inc/CMD_Args.hpp"

void parseArgs(int_fast32_t argc, char** argv, bool* debugMode) {
	// Check if argument is --debug-mode
	for (uint_fast8_t i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--debug-mode") == 0) {
			*debugMode = true;
		}
		else {
			printf_s("Invalid argument!\r\n");
			// showUsage();
			std::exit(1);
		}
	}
}
