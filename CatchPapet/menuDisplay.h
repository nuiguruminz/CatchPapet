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

void menudisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, WIDTH, HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30.0, WIDTH / HEIGHT, 0.1, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//プレイボタン
	glPushMatrix();
	glTranslatef(x0, HEIGHT / 2, 0.0f); //平行移動
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle0, 1.0f, 0.0f, 0.0f);//回転
	glRotatef(angle0, 0.0f, 1.0f, 0.0f);//回転
	model->Draw();
	glPopMatrix();

	//設定ボタン
	glPushMatrix();
	glTranslatef(x1, HEIGHT / 2 - 240, 0.0f); //平行移動
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle1, 1.0f, 0.0f, 0.0f);//回転
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);//回転
	model->Draw();
	glPopMatrix();

	//ランキングボタン
	glPushMatrix();
	glTranslatef(x2, HEIGHT / 2 - 480, 0.0f); //平行移動
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle2, 1.0f, 0.0f, 0.0f);//回転
	glRotatef(angle2, 0.0f, 1.0f, 0.0f);//回転
	model->Draw();
	glPopMatrix();

	//難易度イージーボタン
	glPushMatrix();
	glTranslatef(x3, HEIGHT / 2, 0.0f); //平行移動
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle0, 1.0f, 0.0f, 0.0f);//回転
	glRotatef(angle0, 0.0f, 1.0f, 0.0f);//回転
	model->Draw();
	glPopMatrix();

	//難易度ノーマルボタン
	glPushMatrix();
	glTranslatef(x4, HEIGHT / 2 - 240, 0.0f); //平行移動
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle1, 1.0f, 0.0f, 0.0f);//回転
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);//回転
	model->Draw();
	glPopMatrix();

	//難易度ハードボタン
	glPushMatrix();
	glTranslatef(x5, HEIGHT / 2 - 480, 0.0f); //平行移動
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glRotatef(angle2, 1.0f, 0.0f, 0.0f);//回転
	glRotatef(angle2, 0.0f, 1.0f, 0.0f);//回転
	model->Draw();
	glPopMatrix();

	glutSwapBuffers();

}
