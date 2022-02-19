#include "inc/main.hpp"
#include "inc/defines.hpp"
int_fast32_t main(int_fast32_t argc, char **argv) {
	printf_s("Starting...\r\n");
	bool debugMode = false;
	if ((argc - 1) >= 1) {
		parseArgs(argc, argv, &debugMode);
	}
	if (debugMode) {
		printf_s("%s%i arguments passed!\r\n%sThe passed arguments are as follows:\r\n", dbgPrefix, argc - 1, dbgPrefix);
		for (int_fast8_t i = 1; i <= (argc - 1); i++) {
			printf_s("%sArgument %i: %s\r\n", dbgPrefix, i, argv[i]);
			// TODO: Add a function picker here.
		}
		printf_s("%sInitializing the data directory...\r\n", dbgPrefix);
	}
	std::string dataDir = initDataDir();
	if (debugMode) {
		printf_s("%sNameFile (%s) initialized!\r\n", dbgPrefix, dataDir.c_str());
	}

	std::string name = checkName(debugMode);
	printf_s("Welcome to the program, %s!\r\n", name.c_str());
	
	return 0;
}
