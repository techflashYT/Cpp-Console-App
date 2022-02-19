#include "inc/writeNameToFile.hpp"
#include "inc/defines.hpp"
uint8_t writeNameToFile(char name[50], std::string pathString, std::string origPath, bool debugMode) {
    pathString = origPath + "\\CONFIG\\NAME";
    if (debugMode) {
        printf_s("%sOpening std::ofstream filestream using the path %s\r\n", dbgPrefix, pathString.c_str());
    }
    std::ofstream fileStream(pathString);
    if (fileStream.is_open()) {
        std::string nameToWrite = name;
        nameToWrite.substr(nameToWrite.find("\0") + 1);
        if (debugMode) {
            printf_s("%snameToWrite value: %s\r\n", dbgPrefix, nameToWrite.c_str());
            printf_s("%sSuccessfully opened the fileStream, writing data \"%s\" to it with a maximum of 50 characters.\r\n", dbgPrefix, nameToWrite.c_str());
        }
        fileStream.write(nameToWrite.c_str(), nameToWrite.size());
    }
    else {
        return 1;
    }
    if (debugMode) {
        printf_s("%sDone writing, now closing the stream.\r\n", dbgPrefix);
    }
    fileStream.close();
    if (fileStream.good()) {
        if (debugMode) {
            printf_s("%sFilestream wrote and closed correctly!  Returning 0 to show that it succeeded.\r\n", dbgPrefix);
        }
        return 0;
    }
    else {
        if (debugMode) {
            printf_s("%sFilestream failed to write or close!  Returning 1 to show that it failed.\r\n", dbgPrefix);
        }
        return 1;
    }
}
