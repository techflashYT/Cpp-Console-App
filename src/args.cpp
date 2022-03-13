#include "inc/args.hpp"

/*
	This is the checkArgs function.
	It gets called by main( ) if any arguments are passed to the program.

	PARAMS:
	int argc: The number of arguments passed to the program.
	char argv[ ][ ] (char **argv): The arguments passed to the program, as an array of char arrays (an array of strings)
	bool *debugMode: A pointer to the debugMode bool, this is so that it can be modified from within this function, as it checks for the --debug-mode flag.

	RETURNS: void (nothing)
*/
void checkArgs(int_fast32_t argc, char** argv, bool* achievementTestArg) {
	VarsList varsList {
			"argc",    // int1
			argc,      // int1data
			"none",    // int2
			0,		   // int2data
			"none",	   // int3
			0,		   // int3data
			"none",    // string1
			"none",	   // string1data
			"none",    // string2
			"none",    // string2data
			"none",    // string3
			"none",    // string3data
			"none",    // charArr1
			"none",   // charArr1data
			"none",   // charArr2
			"none",   // charArr2data
			"none",   // charArr3
			"none",   // charArr3data
			"none",   // bool1
			false,     // bool1data
			"none",   // bool2
			false,     // bool2data
			"none",   // bool3
			false      // bool3data
	};
	strcpy(varsList.charArr1, "argv[0]");
	strcpy(varsList.charArr1data, argv[0]);
	if (argv[1] != NULL) {
		strcpy(varsList.charArr2, "argv[1]");
		strcpy(varsList.charArr2data, argv[1]);
	}
	if ((argc - 1) >= 3) {
		if (argv[2] != NULL) {
			strcpy(varsList.charArr3, "argv[2]");
			strcpy(varsList.charArr3data, argv[2]);
		}
	}
	bool alreadyShownMsg = false;
	for (uint_fast8_t i = 1; i < argc; i++) {
		if (strcmp(argv[i], "--debug-mode") == 0) {
			logLevel = DEBUG;
		}
		else if (strcmp(argv[i], "--crash-handler") == 0) {
			crashDump(varsList, "The user manually initiated the crash dump.", __func__);
		}
		else if (strcmp(argv[i], "--test-achievements") == 0) {
			*achievementTestArg = true;
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

