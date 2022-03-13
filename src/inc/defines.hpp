#pragma once


#define MAX_NAME_LEN     20
#define MAX_CHAR_ARR_LEN 85


#define TITLESTR "Placeholder Title"
#define GFX_API "OpenGL"

#include <iostream>
#ifdef ERROR
	#undef ERROR
#endif
#define DEBUG   0
#define WARNING 1
#define ERROR   2
#define FATAL   3
struct VarsList {
	char int1[MAX_NAME_LEN]{};
	int int1data;

	char int2[MAX_NAME_LEN]{};
	int int2data;

	char int3[MAX_NAME_LEN]{};
	int int3data;
	
	
	char string1[MAX_NAME_LEN]{};
	std::string string1data;

	char string2[MAX_NAME_LEN]{};
	std::string string2data;

	char string3[MAX_NAME_LEN]{};
	std::string string3data;
	
	
	char charArr1[MAX_NAME_LEN]{};
	char charArr1data[MAX_CHAR_ARR_LEN]{};

	char charArr2[MAX_NAME_LEN]{};
	char charArr2data[MAX_CHAR_ARR_LEN]{};

	char charArr3[MAX_NAME_LEN]{};
	char charArr3data[MAX_CHAR_ARR_LEN]{};


	char bool1[MAX_NAME_LEN]{};
	bool bool1data = false;

	char bool2[MAX_NAME_LEN]{};
	bool bool2data = false;

	char bool3[MAX_NAME_LEN]{};
	bool bool3data = false;
};
struct __logLevel {
	bool loggingLevel = 1; // Default of warning
	const char *strings[4] = {
		{"DEBUG: "},
		{"WARNING: "},
		{"ERROR: "},
		{"FATAL ERROR: "}
	};
	bool operator==(uint_fast8_t id) {
		return loggingLevel == id;
	}
	bool operator>=(uint_fast8_t id) {
		return loggingLevel >= id;
	}
	bool operator<=(uint_fast8_t id) {
		return loggingLevel <= id;
	}
	void operator=(uint_fast8_t id) {
		loggingLevel = id;
	}
	const char *operator[](uint_fast8_t id) {
		if (id <= 3) {
			return strings[id];
		}
		else {
			
			std::string err = "FATAL ERROR: Invalid ID " + std::to_string(id) +
			" for logLevel";
			
			throw std::invalid_argument(err.c_str());
		}
	}
} extern logLevel;
