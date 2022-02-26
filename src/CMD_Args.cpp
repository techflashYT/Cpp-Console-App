#include "inc/CMD_Args.hpp"

/*
	This is the parseArgs function.
	It gets called by main( ) if any arguments are passed to the program.

	PARAMS:
	int argc: The number of arguments passed to the program.
	char argv[ ][ ] (char **argv): The arguments passed to the program, as an array of char arrays (an array of strings)
	bool *debugMode: A pointer to the debugMode bool, this is so that it can be modified from within this function, as it checks for the --debug-mode flag.

	RETURNS: void (nothing)
*/
void parseArgs(int_fast32_t argc, char** argv, bool* debugMode) {
	VarsList varsList {
			"argc",
			argc,
			"none",
			0,
			"none",
			0,
			"argv[0]",
			argv[0],
			"argv[1]",
			argv[1],
			"none",
			"none",
			"none",
			false,
			"none",
			false,
			"none",
			false
	};
	if (argv[2] != NULL) {
		varsList.string3 = "argv[2]";
		varsList.string3data = argv[2];
	}
	bool alreadyShownMsg = false;
	for (uint_fast8_t i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--debug-mode") == 0) {
			*debugMode = true;
		}
		else if (strcmp(argv[i], "--crash-handler") == 0) {
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

