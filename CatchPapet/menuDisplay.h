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
#define OBJ_INTERVAL 230//図形の間隔
#define WIDTH 640
#define HEIGHT 480
#define CENTER 0　//後で修正

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

	//if (NowScene == 0){ //シーンがメニューなら
		//プレイボタン
		glPushMatrix();
		glTranslatef(x0, (HEIGHT/2), 0.0f); //平行移動
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle0, 1.0f, 0.0f, 0.0f);//縦回転
		glRotatef(angle0, 0.0f, 1.0f, 0.0f);//横回転
		model->Draw();
		glPopMatrix();

		//設定ボタン
		glPushMatrix();
		glTranslatef(x1, (HEIGHT / 2) - OBJ_INTERVAL, 0.0f); //平行移動
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle1, 1.0f, 0.0f, 0.0f);//回転
		glRotatef(angle1, 0.0f, 1.0f, 0.0f);//回転
		model->Draw();
		glPopMatrix();

		//ランキングボタン
		glPushMatrix();
		glTranslatef(x2, (HEIGHT/2) - OBJ_INTERVAL*2, 0.0f); //平行移動
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle2, 1.0f, 0.0f, 0.0f);//回転
		glRotatef(angle2, 0.0f, 1.0f, 0.0f);//回転
		model->Draw();
		glPopMatrix();

		//難易度イージーボタン
		glPushMatrix();
		glTranslatef(x3, (HEIGHT / 2), 0.0f); //平行移動
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle0, 1.0f, 0.0f, 0.0f);//縦回転
		glRotatef(angle0, 0.0f, 1.0f, 0.0f);//横回転
		model->Draw();
		glPopMatrix();

		//難易度ノーマルボタン
		glPushMatrix();
		glTranslatef(x4, (HEIGHT / 2) - OBJ_INTERVAL, 0.0f); //平行移動
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle1, 1.0f, 0.0f, 0.0f);//回転
		glRotatef(angle1, 0.0f, 1.0f, 0.0f);//回転
		model->Draw();
		glPopMatrix();

		//難易度ハードボタン
		glPushMatrix();
		glTranslatef(x5, (HEIGHT / 2) - OBJ_INTERVAL*2, 0.0f); //平行移動
		gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
		//glRotatef(angle2, 1.0f, 0.0f, 0.0f);//回転
		glRotatef(angle2, 0.0f, 1.0f, 0.0f);//回転
		model->Draw();
		glPopMatrix();

	//}

	glutSwapBuffers();

}
