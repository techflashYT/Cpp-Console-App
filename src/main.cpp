#include "inc/main.h"

int main(int argc, char **argv) {
    // Fool the compiler into thinking I'm using the variables until I find a use for them.
    (void)argc;
    (void)argv;
    #ifdef debugMode
        // TODO: Do debug mode things
    #endif
    return 0;
}
