extern float x0;
extern float x1;
extern float x2;
extern float x3;
extern float x4;
extern float x5;
extern int flagT;
//#include "keyBoard.h"

void menuidle(void)
{
	if (flagT == 0 && NowSelect == eMenu_Play){ //Play�{�^���I�𒆂�space��������Ă�����
		//�{�^�������ֈړ�
		x0 -= 3.0;
		x1 -= 3.0;
		x2 -= 3.0;
		if (x3 > (WIDTH / 2 - 300)){
			x3 -= 3.0;
			x4 -= 3.0;
			x5 -= 3.0;
		}
		else {
			NowSelect = eMenu_Easy;
			flagT = 3;
		}
	}
	switch (NowSelect){//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenu_Play://�Q�[���I�𒆂Ȃ�
		angle0 += 0.1f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Config://�ݒ�I�𒆂Ȃ�
		angle0 = 0.0f;
		angle1 += 0.1f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Rank://�����L���O�I�𒆂Ȃ�
		angle0 = 0.0f;
		angle1 = 0.0f;
		angle2 += 0.1f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Easy:
		angle0 += 0.1f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
	case eMenu_Normal:
		angle0 = 0.0f;
		angle1 += 0.1f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
	case eMenu_Hard:
		angle0 = 0.0f;
		angle1 = 0.0f;
		angle2 += 0.1f;
		Sleep(1);
		glutPostRedisplay();

	}
	Sleep(1);
	glutPostRedisplay();
}