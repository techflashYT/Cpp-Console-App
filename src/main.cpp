#include "inc/main.hpp"
__logLevel logLevel;
#include "inc/defines.hpp"
extern uint_fast32_t fps;
int_fast32_t main(int_fast32_t argc, char** argv) {
	bool achievementTestArg = false;
	checkArgs(argc, argv, &achievementTestArg);
	if (logLevel == DEBUG) {
		printf_s("%sInitialized GLUT.\r\n", logLevel[DEBUG]);
	}
	std::string dataDir = initDataDir();
	if (logLevel == DEBUG) {
		printf_s("%sNameFile (%s) initialized!\r\n", logLevel[DEBUG], dataDir.c_str());
	}

	char name[50]{};
	checkName(&name);
	std::string envValue = "";
	if (logLevel == DEBUG) {
		fprintf_s(stdout, "%sname variable: %s\r\n", logLevel[DEBUG], name);
	}
	if (std::getenv("isThisTheRealTechflash") != NULL) {
		envValue = std::getenv("isThisTheRealTechflash");
	}
	else {
		envValue = "Doesn\'t exist";
	}
	if (logLevel == DEBUG) {
		fprintf_s(stdout, "%sValue of envValue == \"Yes, it\'s me\": %s, value of envValue itself: %s\r\n", logLevel[DEBUG], envValue == "Yes, it's me" ? "true" : "false", envValue.c_str());
	}
	if (strcmp(name, "Techflash") == 0 && envValue != "Yes, it's me") {
		printf_s("Wow.  Nice job trying to impersonate me.\r\n\
You won't get anything from this.\r\n\
You'll scower the program trying to find out what good this has accomplished you,\r\n\
only to find, that the answer is NONE.\r\n");
	}
	else {
		fprintf_s(stdout, "Welcome to the program, %s!\r\n", name);
	}
	if (achievementTestArg) {
		achievements.earn(0);
		return 0;
	}
	
	// Get the current resolution
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow(); // Get a handle to the desktop window
	GetWindowRect(hDesktop, &desktop); // Get the size of screen to the variable desktop
	
	glutInit(&argc, argv);
	glutInitWindowSize(640, 640);
	std::string title = (std::string)TITLESTR + "  |  " + GFX_API + "  |  " + "FPS: " + std::to_string(fps);
	glutCreateWindow(title.c_str());
	// This is wasteful, I know, but it's the only easy way to make it work,
	// as the `glutDisplayFunc` function only allows you to pass in a single
	// function as an argument, and not any additional arguments to be passed
	// to it.
	setUpDisplayVars(desktop.right, desktop.bottom);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
