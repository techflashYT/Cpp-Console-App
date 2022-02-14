#include "inc/askForName.hpp"
#include "inc/defines.hpp"
char name[50]{};
std::string askForName(std::string pathString, std::string origPath, bool debugMode) {
	while (true) {
		printf_s("What is your name? (Maximum of 50 characters)\r\n");
		fgets(name, 50, stdin);
		strtok(name, "\n");
		printf_s("So your name is \"%s\", correct?\r\n", name);
		char correct[4]{};
		fgets(correct, 4, stdin);
		std::string a = correct;
		for (int i = 0; i >= (int)a.length(); i++) {
			correct[i] = tolower(correct[i]);
		}
		if (debugMode) {
			printf_s("%sComparing correct[0] (first character of the response), which = \"%c\"\r\n", dbgPrefix, correct[0]);
		}
		if (strcmp(&correct[0], "y")) {
			uint8_t retValue = writeNameToFile(name, pathString, origPath, debugMode);
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
