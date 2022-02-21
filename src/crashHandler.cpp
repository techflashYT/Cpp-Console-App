#include "inc/crashHandler.hpp"
#include "inc/defines.hpp"

void crashDump(VarsList varsList, std::string reason, std::string caller, bool debugMode) {
	// Convert 0 or 1 of bool to a string of "true" or "false"


	printf_s(" \
Something went wrong, please report this error along with the following crash dump to the developer.\r\n\
============BEGIN CRASH DUMP============\r\n\
Suspected cause: %s\r\n \
\r\n\
\r\n\
Function that caused the crash: %s()\r\n\
===========BEGIN VARIABLE DUMP==========\r\n", reason.c_str(), caller.c_str());
if (varsList.int1 != "none") {
	printf_s("type: int           name: %s   value: %i \r\n", varsList.int1.c_str(), varsList.int1data);
}
if (varsList.int2 != "none") {
	printf_s("type: int           name: %s   value: %i \r\n", varsList.int2.c_str(), varsList.int2data);
}
if (varsList.int3 != "none") {
	printf_s("type: int           name: %s   value: %i \r\n", varsList.int3.c_str(), varsList.int3data);
}
if (varsList.string1 != "none" || varsList.string1data != "none") {
	printf_s("type: std::string   name: %s   value: %s \r\n", varsList.string1.c_str(), varsList.string1data.c_str());
}
if (varsList.string2 != "none" || varsList.string2data != "none") {
	printf_s("type: std::string   name: %s   value: %s \r\n", varsList.string2.c_str(), varsList.string2data.c_str());
}
if (varsList.string3 != "none" || varsList.string3data != "none") {
	printf_s("type: std::string   name: %s   value: %s \r\n", varsList.string3.c_str(), varsList.string3data.c_str());
}
if (varsList.bool1 != "none") {
	printf_s("type: bool	      name: %s   value: %s \r\n", varsList.bool1.c_str(), varsList.bool1data ? "true" : "false");
}
if (varsList.bool2 != "none") {
	printf_s("type: bool	      name: %s   value: %s \r\n", varsList.bool2.c_str(), varsList.bool2data ? "true" : "false");
}
if (varsList.bool3 != "none") {
	printf_s("type: bool	      name: %s   value: %s \r\n", varsList.bool3.c_str(), varsList.bool3data ? "true" : "false");
}
printf_s("Debug Mode State: %s\r\n\
=============END CRASH DUMP=============\r\n", debugMode ? "ENABLED" : "DISABLED");
	abort();
}
