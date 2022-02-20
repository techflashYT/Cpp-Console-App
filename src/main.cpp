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
	std::string envValue = std::getenv("isThisTheRealTechflash");
	if (debugMode) {
		printf_s("%sname variable: %s\r\n%sValue of envValue == \"Yes, it\'s me: %s", dbgPrefix, name.c_str(), dbgPrefix, envValue == "Yes, it's me" ? "true" : "false");
	}
	if (name == "Techflash" && envValue != "Yes, it's me") {
		printf_s("Wow!  Nice job trying to impersonate me.\r\nYou won't get anything from this.\r\nYou'll scower the program trying to find out what good this has accomplished you,\r\nonly to find, that the answer is NONE.\r\n");
	}
	else {
		printf_s("Welcome to the program, %s!\r\n", name.c_str());
	}
	
	return 0;
}
