#include "inc/CMD_Args.hpp"

void parseArgs(int_fast32_t argc, char** argv, bool* debugMode) {
	VarsList varsList;
	// Check if argument is --debug-mode
	bool alreadyShownMsg = false;
	for (uint_fast8_t i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--debug-mode") == 0) {
			*debugMode = true;
		}
		if (strcmp(argv[i], "--crash-handler")== 0) {
			crashDump(varsList, "a", __func__, *debugMode);
		}
		else if (strcmp(argv[i], "2>CON") == 0) {
			if (!alreadyShownMsg) {
				printf_s("Thanks for using a debugger to help test the program!\r\n");
			}
			alreadyShownMsg = true;
		}
		else if (strcmp(argv[i], "1>CON") == 0) {
			if (!alreadyShownMsg) {
				printf_s("Thanks for using a debugger to help test the program!\r\n");
			}
			alreadyShownMsg = true;
		}
		else if (strcmp(argv[i], "<CON") == 0) {
			if (!alreadyShownMsg) {
				printf_s("Thanks for using a debugger to help test the program!\r\n");
			}
			alreadyShownMsg = true;
		}
		else {
			printf_s("Invalid argument: \"%s\"!\r\n", argv[i]);
			// showUsage();
			std::exit(1);
		}
	}
}

