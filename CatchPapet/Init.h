extern MODEL* model;
#include <mciapi.h>
extern MCI_OPEN_PARMS mop;

void Init(){
	glewInit();
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	model = new MODEL("start3.obj");
	mop.lpstrDeviceType = "Sequencer"; //âπäyì«Ç›çûÇ›
	mop.lpstrElementName = "sample01.mid"; //âπäyì«Ç›çûÇ›
	glutSpecialFunc(specialkeydown);
	glutKeyboardFunc(keyboard);
}