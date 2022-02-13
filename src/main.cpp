#include "inc/main.hpp"
#include "inc/defines.hpp"

int main(int argc, char **argv) {
    bool debugMode = false;
    if ((argc - 1) >= 1) {
        parseArgs(argc, argv, &debugMode);
    }
    if (debugMode) {
        printf_s("%s%i arguments passed!\r\n%sThe passed arguments are as follows:\r\n", dbgPrefix, argc - 1, dbgPrefix);
        for (int i = 1; i <= (argc - 1); i++) {
            printf_s("%sArgument %i: %s\r\n", dbgPrefix, i, argv[i]);
        }
    }
    printf_s("Welcome to the program!\r\n");
    return 0;
}
