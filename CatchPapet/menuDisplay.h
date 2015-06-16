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
extern RECT recDisplay;
extern MODEL* model;
#define OBJ_INTERVAL 230//�}�`�̊Ԋu

void menudisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, recDisplay.right, recDisplay.bottom);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(30.0, recDisplay.right / recDisplay.bottom, 0.1, 2000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//�v���C�{�^��
	glPushMatrix();
	glTranslatef(x0, recDisplay.top + OBJ_INTERVAL, 0.0f); //���s�ړ�
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(angle0, 1.0f, 0.0f, 0.0f);//��]
	glRotatef(angle0, 0.0f, 1.0f, 0.0f);//��]
	model->Draw();
	glPopMatrix();

	//�ݒ�{�^��
	glPushMatrix();
	glTranslatef(x1, recDisplay.top, 0.0f); //���s�ړ�
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(angle1, 1.0f, 0.0f, 0.0f);//��]
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);//��]
	model->Draw();
	glPopMatrix();

	//�����L���O�{�^��
	glPushMatrix();
	glTranslatef(x2, recDisplay.top - OBJ_INTERVAL, 0.0f); //���s�ړ�
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(angle2, 1.0f, 0.0f, 0.0f);//��]
	glRotatef(angle2, 0.0f, 1.0f, 0.0f);//��]
	model->Draw();
	glPopMatrix();

	//��Փx�C�[�W�[�{�^��
	glPushMatrix();
	glTranslatef(x3, recDisplay.top + OBJ_INTERVAL, 0.0f); //���s�ړ�
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(angle0, 1.0f, 0.0f, 0.0f);//��]
	glRotatef(angle0, 0.0f, 1.0f, 0.0f);//��]
	model->Draw();
	glPopMatrix();

	//��Փx�m�[�}���{�^��
	glPushMatrix();
	glTranslatef(x4, recDisplay.top, 0.0f); //���s�ړ�
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(angle1, 1.0f, 0.0f, 0.0f);//��]
	glRotatef(angle1, 0.0f, 1.0f, 0.0f);//��]
	model->Draw();
	glPopMatrix();

	//��Փx�n�[�h�{�^��
	glPushMatrix();
	glTranslatef(x5, recDisplay.top - OBJ_INTERVAL, 0.0f); //���s�ړ�
	gluLookAt(0.0, 0.0, 1500.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	//glRotatef(angle2, 1.0f, 0.0f, 0.0f);//��]
	glRotatef(angle2, 0.0f, 1.0f, 0.0f);//��]
	model->Draw();
	glPopMatrix();

	glutSwapBuffers();

}
