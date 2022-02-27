#include "inc/main.hpp"
#include "inc/defines.hpp"
/*
	This is the main function, it returns 0 unless something goes wrong.
	This is where execution begins.

	PARAMS:
	int argc:  The number of arguments passed to the program, including the program path.
	char argv[ ][ ]  (char **argv): The arguments passed to the program, stored as strings in an array of char arrays.

	RETURNS: int (0 for success, non-zero value for failure.)
*/
int_fast32_t main(int_fast32_t argc, char **argv) {
	printf_s("Starting...\r\n");
	bool debugMode = false;
	bool achievementTestArg = false;
	if ((argc - 1) >= 1) {
		parseArgs(argc, argv, &debugMode, &achievementTestArg);
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

	char name[50]{};
	checkName(&name, debugMode);
	std::string envValue = "";
	if (debugMode) {
		printf_s("%sname variable: %s\r\n", dbgPrefix, name);
	}
	if (std::getenv("isThisTheRealTechflash") != NULL) {
		envValue = std::getenv("isThisTheRealTechflash");
	}
	else {
		envValue = "Doesn\'t exist";
	}
	if (debugMode) {
		printf_s("%sValue of envValue == \"Yes, it\'s me\": %s, value of envValue itself: %s\r\n", dbgPrefix, envValue == "Yes, it's me" ? "true" : "false", envValue.c_str());
	}
	if (strcmp(name, "Techflash") == 0 && envValue != "Yes, it's me") {
		printf_s("Wow.  Nice job trying to impersonate me.\r\nYou won't get anything from this.\r\nYou'll scower the program trying to find out what good this has accomplished you,\r\nonly to find, that the answer is NONE.\r\n");
	}
	else {
		printf_s("Welcome to the program, %s!\r\n", name);
	}
	if (achievementTestArg) {
		achievements.earn(0, debugMode);
		return 0;
	}
}
