#include "inc/defines.hpp"
#include "inc/display.hpp"
uint_fast32_t fps = 60;
uint_fast32_t screenW = 0;
uint_fast32_t screenH = 0;
uint_fast32_t windowW = 0;
uint_fast32_t windowH = 0;

void setUpDisplayVars(uint_fast32_t desktopRight, uint_fast32_t desktopBottom) {
	screenW = desktopRight;
	screenH = desktopBottom;
	windowW = glutGet(GLUT_WINDOW_WIDTH);
	windowH = glutGet(GLUT_WINDOW_HEIGHT);

}


// TODO: Factor in the display resolution somehow.
void display() {
	fps++;
	glutSetWindowTitle(((std::string)((std::string)TITLESTR + "  |  " + GFX_API + "  |  " + "FPS: " + std::to_string(fps))).c_str());
	if (logLevel == DEBUG) {
		fprintf_s(stdout, "%sscreenW: %i\r\n%sscreenH: %i\r\n%swindowW: \
%i\r\n%swindowH: %i\r\n", logLevel[DEBUG], screenW,
						  logLevel[DEBUG], screenH,
						  logLevel[DEBUG], windowW,
						  logLevel[DEBUG], windowH);
	}
	if (logLevel <= WARNING && (screenW < 640 || screenH < 480)) {
		fprintf_s(stderr, "%sScreen resolution (%ix%i) is under 1024x768, \
some things might not look right.", logLevel[WARNING], screenW, screenH);
	}
	glClearColor(0.3f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
		glColor3f(1.0f, 0.0f, 0.0f); // Red
		glVertex2f(-0.5f, -0.5f);    // x, y
		glVertex2f( 0.5f, -0.5f);
		glVertex2f( 0.5f,  0.5f);
		glVertex2f(-0.5f,  0.5f);
	glEnd();
	
	glFlush();
	return;
}
