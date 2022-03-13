#include "inc/defines.hpp"
#include "inc/askForName.hpp"
char name[50]{};
char* askForName(const std::string &pathString, const std::string &origPath) {
	while (true) {
		printf_s("What is your name? (Maximum of 50 characters)\r\n");
		fgets(name, 50, stdin);
		strtok(name, "\n");
		printf_s("So your name is \"%s\", correct?\r\n", name);
		char correct[4]{};
		fgets(correct, 4, stdin);
		for (uint_fast8_t i = 0; i >= strlen(correct); i++) {
			correct[i] = tolower(correct[i]);
		}
		if (logLevel == DEBUG) {
			printf_s("%sComparing correct[0] (first character of the response), which = \"%c\"\r\n", logLevel[DEBUG], correct[0]);
		}
		if (strcmp(&correct[0], "y")) {
			uint_fast8_t retValue = writeNameToFile(name, pathString, origPath);
			if (retValue == 1) {
				printf_s("A filesystem error occurred while trying to write the name to the disk, please report this to the developer.");
			}
			else if (retValue == 0) {
				break;
			}
		}
	}
	return name;
}
