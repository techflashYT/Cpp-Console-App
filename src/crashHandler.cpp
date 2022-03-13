#include "inc/defines.hpp"
#include "inc/crashHandler.hpp"

void crashDump(VarsList varsList, const char* reason, const char* caller) {
	fprintf_s(stderr,
" \
Something went wrong, please report this error along with the following crash dump to the developer.\r\n\
============BEGIN CRASH DUMP============\r\n\
Suspected cause: %s\r\n \
\r\n\
\r\n\
Function that caused the crash: %s()\r\n\
===========BEGIN VARIABLE DUMP==========\r\n", reason, caller);
if (strcmp(varsList.int1, "none") != 0) {
	fprintf_s(stderr, "type: int           name: %s   value: %i \r\n", varsList.int1, varsList.int1data);
}
if (strcmp(varsList.int2, "none") != 0) {
	fprintf_s(stderr, "type: int           name: %s   value: %i \r\n", varsList.int2, varsList.int2data);
}
if (strcmp(varsList.int3, "none") != 0) {
	fprintf_s(stderr, "type: int           name: %s   value: %i \r\n", varsList.int3, varsList.int3data);
}
if (strcmp(varsList.string1, "none") != 0 || varsList.string1data != "none") {
	fprintf_s(stderr, "type: std::string   name: %s   value: %s \r\n", varsList.string1, varsList.string1data.c_str());
}
if (strcmp(varsList.string2, "none") != 0 || varsList.string2data != "none") {
	fprintf_s(stderr, "type: std::string   name: %s   value: %s \r\n", varsList.string2, varsList.string2data.c_str());
}
if (strcmp(varsList.string3, "none") != 0 || varsList.string3data != "none") {
	fprintf_s(stderr, "type: std::string   name: %s   value: %s \r\n", varsList.string3, varsList.string3data.c_str());
}
if (strcmp(varsList.charArr1, "none") != 0 || strcmp(varsList.charArr1data, "none") != 0) {
	fprintf_s(stderr, "type: char[]        name: %s   value: %s \r\n", varsList.charArr1, varsList.charArr1data);
}
if (strcmp(varsList.charArr2, "none") != 0 || strcmp(varsList.charArr2data, "none") != 0) {
	fprintf_s(stderr, "type: char[]        name: %s   value: %s \r\n", varsList.charArr2, varsList.charArr2data);
}
if (strcmp(varsList.charArr3, "none") != 0 || strcmp(varsList.charArr3data, "none") != 0) {
	fprintf_s(stderr, "type: char[]        name: %s   value: %s \r\n", varsList.charArr3, varsList.charArr3data);
}
if (strcmp(varsList.bool1, "none") != 0) {
	fprintf_s(stderr, "type: bool	       name: %s   value: %s \r\n", varsList.bool1, varsList.bool1data ? "true" : "false");
}
if (strcmp(varsList.bool2, "none") != 0) {
	fprintf_s(stderr, "type: bool	       name: %s   value: %s \r\n", varsList.bool2, varsList.bool2data ? "true" : "false");
}
if (strcmp(varsList.bool3, "none") != 0) {
	fprintf_s(stderr, "type: bool	       name: %s   value: %s \r\n", varsList.bool3, varsList.bool3data ? "true" : "false");
}
fprintf_s(stderr,
"Debug Mode State: %s\r\n \
=============END CRASH DUMP=============\r\n", logLevel == DEBUG ? "ENABLED" : "DISABLED"); 	// Convert 0 or 1 of bool to a string of "true" or "false"
	abort();
}
