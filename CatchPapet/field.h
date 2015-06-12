//ÉvÉåÉCâÊñ 
//
#define WIDTH 640
#define HEIGHT 480
extern float x0;
extern float x1;
extern float x2;
extern float x3;
extern float x4;
extern float x5;

extern float angle0;
extern float angle1;
extern float angle2;
extern MODEL* model;

GLdouble vertex[][3] = {
		{ 0.0, 0.0, 0.0 },
		{ 1.0, 0.0, 0.0 },
		{ 1.0, 1.0, 0.0 },
		{ 0.0, 1.0, 0.0 },
		{ 0.0, 0.0, 1.0 },
		{ 1.0, 0.0, 1.0 },
		{ 1.0, 1.0, 1.0 },
		{ 0.0, 1.0, 1.0 }
};

int edge[][2] = {
		{ 0, 1 },
		{ 1, 2 },
		{ 2, 3 },
		{ 3, 0 },
		{ 4, 5 },
		{ 5, 6 },
		{ 6, 7 },
		{ 7, 4 },
		{ 0, 4 },
		{ 1, 5 },
		{ 2, 6 },
		{ 3, 7 }
};


void FieldDisplay(void)
{
	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	/* ê}å`ÇÃï`âÊ */
	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (i = 0; i < 12; ++i) {
		glVertex3dv(vertex[edge[i][0]]);
		glVertex3dv(vertex[edge[i][1]]);
	}
	glEnd();

	glFlush();
}
