#include "inc/CMD_Args.h"

void parseArgs(int argc, char** argv, bool* debugMode) {
    // Check if argument is --debug-mode
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--debug-mode") == 0) {
            *debugMode = true;
        }
        else {

        }
    }
}
