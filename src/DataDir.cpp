#include "inc/DataDir.hpp"
#include "inc/defines.hpp"
bool MAIN_DIR_GOOD = false;
bool CONFIG_DIR_GOOD = false;
struct stat b;
std::string origPath = "";
std::string pathString = "";
std::filesystem::path path;
std::error_code ec;

std::string initDataDir() {
	std::string username;
#ifdef _WIN32
	pathString = "C:\\Temp";
	if (stat(pathString.c_str(), &b) != 0) {
		system("mkdir C:\\Temp");
	}
	ofstream script("C:\\Temp\\script.bat");
	script << "@echo off\r\necho %username% > C:\\Temp\\username.txt";
	script.close();
	system("C:\\Temp\\script.bat");
	ifstream unamefile("C:\\Temp\\username.txt");
	if (unamefile.is_open()) {
		unamefile >> username;
	}
	unamefile.close();
	system("rmdir /Q /S C:\\Temp");
	pathString = "C:\\Users\\" + username + "\\Appdata\\Roaming\\Sanikdah Software";
	if (stat(pathString.c_str(), &b) != 0) {
		std::string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}

	pathString.append("\\TestingProgram");
	if (stat(pathString.c_str(), &b) != 0) {
		std::string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	origPath = pathString;
	pathString.append("\\CONFIG");
	if (stat(pathString.c_str(), &b) != 0) {
		std::string cmd = "mkdir \"" + pathString + "\"";
		system(cmd.c_str());
	}
	pathString = origPath;
#endif

	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		MAIN_DIR_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		printf_s("The data directory is a file!  Deleting it...\r\n");
#ifdef _WIN32
		std::string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		printf_s("Done!  Please restart the program!\r\n");
		system("pause");
		std::exit(0);
#else
		string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		cout << "Done!  Please restart the program!\r\nPress any key to continue...";
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		printf_s("An unknown error occurred reading the data directory, the error is:\r\n%s\r\nexiting...", ec.message());
		std::exit(1);
	}
	pathString = origPath + "\\CONFIG";
	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		CONFIG_DIR_GOOD = true;
	}
	if (is_regular_file(path, ec)) {
		printf_s("The config directory is a file!  Deleting it...\r\n");
#ifdef _WIN32
		std::string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		printf_s("Done!  Please restart the program!\r\n");
		system("pause");
		std::exit(0);
#else
		std::string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		printf_s("Done!  Please restart the program!\r\nPress any key to continue...");
		system("read -n1 key");
		std::exit(0);
#endif
	}
	if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
		printf_s("An unknown error occurred reading the config directory, the error is:\r\n%s\r\nexiting...", ec.message());
		std::exit(1);
	}

	if (MAIN_DIR_GOOD && CONFIG_DIR_GOOD) {
		if (!MAIN_DIR_GOOD) {
			return "ERROR: FAILED INIT MAIN DIR";
		}
		else if (MAIN_DIR_GOOD && CONFIG_DIR_GOOD) {
			pathString = origPath + "\\CONFIG\\NAME";
			return pathString;
		}
	}
	return "ERROR: GENERIC FAIL";
}


std::string checkName(bool debugMode) {
	if (debugMode) {
		printf_s("%sChecking for namefile...\r\n", dbgPrefix);
	}
	pathString = origPath + "\\CONFIG\\NAME";
	path = pathString; // Constructing the path from a string is possible.
	if (is_directory(path, ec)) {
		printf_s("A file in the config directory is a folder!  Deleting it...\r\n");
#ifdef _WIN32
		std::string cmd = "del \"" + pathString + "\"";
		system(cmd.c_str());
		printf_s("Done!  Please restart the program!\r\n");
		system("pause");
		std::exit(0);
#else
		std::string cmd = "rm \"" + pathString + "\"";
		system(cmd.c_str());
		printf_s("Done!  Please restart the program!\r\nPress any key to continue...");
		system("read -n1 key");
		std::exit(0);
#endif
	}
	else if (is_regular_file(path, ec)) {
		// It is a file, so read in the name.
		if (debugMode) {
			printf_s("%sNameFile already exists, loading it in.\r\n", dbgPrefix);
		}
		ifstream fileStream(path);
		std::string buffer;
		if (fileStream.is_open()) {
			if (debugMode) {
				printf_s("%sFileStream is open.\r\n", dbgPrefix);
			}
			fileStream >> buffer;
		}
		else {
			return "ERROR: ERROR OPENING NAMEFILE";
		}
		if (debugMode) {
			printf_s("%sDone reading, now closing the stream.\r\n", dbgPrefix);
		}
		fileStream.close();
		if (debugMode) {
			printf_s("%sFileStream read correctly, returning it's value.\r\n", dbgPrefix);
		}
		return buffer;
	}
	else {
		// Name doesn't exist yet, so we need to ask for it.
		if (debugMode) {
			printf_s("%sChecking for namefile...\r\n", dbgPrefix);
		}
		return askForName(pathString, origPath, debugMode);
	}
	// if (ec) { // Optional handling of possible errors. Usage of the same ec object works since fs functions are calling ec.clear() if no errors occur.
	//     printf_s("An unknown error occurred reading the config directory, the error is:\r\n%s\r\nexiting...", ec.message());
	//     std::exit(1);
	// }
	return "ERROR: GENRIC ERROR";
}
