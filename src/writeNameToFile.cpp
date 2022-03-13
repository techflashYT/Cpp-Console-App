#include "inc/defines.hpp"
#include "inc/writeNameToFile.hpp"
uint_fast8_t writeNameToFile(char name[50], std::string pathString, const std::string &origPath) {
	pathString = origPath + "\\CONFIG\\NAME";
	if (logLevel == DEBUG) {
		printf_s("%sOpening std::ofstream filestream using the path %s\r\n", logLevel[DEBUG], pathString.c_str());
	}
	std::ofstream fileStream(pathString);
	if (fileStream.is_open()) {
		std::string nameToWrite = name;
		nameToWrite = nameToWrite.substr(nameToWrite.find("\0") + 1);
		if (logLevel == DEBUG) {
			printf_s("%snameToWrite value: %s\r\n", logLevel[DEBUG], nameToWrite.c_str());
			printf_s("%sSuccessfully opened the fileStream, writing data \"%s\" to it with a maximum of 50 characters.\r\n", logLevel[DEBUG], nameToWrite.c_str());
		}
		fileStream.write(nameToWrite.c_str(), nameToWrite.size());
	}
	else {
		return 1;
	}
	if (logLevel == DEBUG) {
		printf_s("%sDone writing, now closing the stream.\r\n", logLevel[DEBUG]);
	}
	fileStream.close();
	if (fileStream.good()) {
		if (logLevel == DEBUG) {
			printf_s("%sFilestream wrote and closed correctly!  Returning 0 to show that it succeeded.\r\n", logLevel[DEBUG]);
		}
		return 0;
	}
	else {
		if (logLevel == DEBUG) {
			printf_s("%sFilestream failed to write or close!  Returning 1 to show that it failed.\r\n", logLevel[DEBUG]);
		}
		return 1;
	}
}
