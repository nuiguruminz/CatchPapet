extern float x0;
extern float x1;
extern float x2;
extern float x3;
extern float x4;
extern float x5;

extern float angle0;
extern float angle1;
extern float angle2;
//extern RECT recDisplay;
extern MODEL* model;
#define OBJ_INTERVAL 230//}Œ`‚ÌŠÔŠu
#define WIDTH 640
#define HEIGHT 480
#define CENTER 0@//Œã‚ÅC³

extern int NowScene;

void menudisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30.0, WIDTH / HEIGHT, 0.1, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//if (NowScene == 0){ //ƒV[ƒ“‚ªƒƒjƒ…[‚È‚ç
		//ƒvƒŒƒCƒ{ƒ^ƒ“
		glPushMatrix();
		glTranslatef(x0, (HEIGHT/2), 0.0f); //•½sˆÚ“®
		glScalef(0.2f, 0.2f, 0.2f); //Šg‘åk¬
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle0, 1.0f, 0.0f, 0.0f);//c‰ñ“]
		glRotatef(angle0, 0.0f, 1.0f, 0.0f);//‰¡‰ñ“]
		model->Draw();
		glPopMatrix();

		//Ý’èƒ{ƒ^ƒ“
		glPushMatrix();
		glTranslatef(x1, (HEIGHT / 2) - OBJ_INTERVAL, 0.0f); //•½sˆÚ“®
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle1, 1.0f, 0.0f, 0.0f);//‰ñ“]
		glRotatef(angle1, 0.0f, 1.0f, 0.0f);//‰ñ“]
		model->Draw();
		glPopMatrix();

		//ƒ‰ƒ“ƒLƒ“ƒOƒ{ƒ^ƒ“
		glPushMatrix();
		glTranslatef(x2, (HEIGHT/2) - OBJ_INTERVAL*2, 0.0f); //•½sˆÚ“®
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle2, 1.0f, 0.0f, 0.0f);//‰ñ“]
		glRotatef(angle2, 0.0f, 1.0f, 0.0f);//‰ñ“]
		model->Draw();
		glPopMatrix();

		//“ïˆÕ“xƒC[ƒW[ƒ{ƒ^ƒ“
		glPushMatrix();
		glTranslatef(x3, (HEIGHT / 2), 0.0f); //•½sˆÚ“®
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle0, 1.0f, 0.0f, 0.0f);//c‰ñ“]
		glRotatef(angle0, 0.0f, 1.0f, 0.0f);//‰¡‰ñ“]
		model->Draw();
		glPopMatrix();

		//“ïˆÕ“xƒm[ƒ}ƒ‹ƒ{ƒ^ƒ“
		glPushMatrix();
		glTranslatef(x4, (HEIGHT / 2) - OBJ_INTERVAL, 0.0f); //•½sˆÚ“®
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle1, 1.0f, 0.0f, 0.0f);//‰ñ“]
		glRotatef(angle1, 0.0f, 1.0f, 0.0f);//‰ñ“]
		model->Draw();
		glPopMatrix();

		//“ïˆÕ“xƒn[ƒhƒ{ƒ^ƒ“
		glPushMatrix();
		glTranslatef(x5, (HEIGHT / 2) - OBJ_INTERVAL*2, 0.0f); //•½sˆÚ“®
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle2, 1.0f, 0.0f, 0.0f);//‰ñ“]
		glRotatef(angle2, 0.0f, 1.0f, 0.0f);//‰ñ“]
		model->Draw();
		glPopMatrix();

	//}

	glutSwapBuffers();

}
