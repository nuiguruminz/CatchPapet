#include <mciapi.h>

extern MCI_OPEN_PARMS mop; //���y�Đ��p

extern float x0;
extern float x1;
extern float x2;
extern float x3;
extern float x4;
extern float x5;
extern int flagT;
extern RECT recDisplay;
#define WCENTER recDisplay.right/2.0

void menuidle(void)
{
	if (flagT == 0 && NowSelect == eMenu_Play){ //Play�{�^���I�𒆂�space��������Ă�����
		//�{�^�������ֈړ�
		x0 -= 5.0;
		x1 -= 5.0;
		x2 -= 5.0;
		if (x3 >= WCENTER){
			x3 -= 5.0;
			x4 -= 5.0;
			x5 -= 5.0;
		}
		else {
			NowSelect = eMenu_Easy;
			flagT = 0;
		}
	}
	else if (flagT == 1 && NowSelect == eMenu_Config){ //Config�{�^���I�𒆂�space��������Ă�����

	}
	else if (flagT == 1 && NowSelect == eMenu_Rank){ //Rank�{�^���I�𒆂�space��������Ă�����

	}
	else if (flagT == 4){

	}
	//�I�[�v��
	//mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
	switch (NowSelect){//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenu_Play://�Q�[���I�𒆂Ȃ�
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0); //���y�Đ� //�������ςȂ� //���y�I���ƂȂ������̂̓������݂��Ȃ� //���y��������H
		angle0 += 0.1f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Config://�ݒ�I�𒆂Ȃ�
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
		angle0 = 0.0f;
		angle1 += 0.1f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Rank://�����L���O�I�𒆂Ȃ�
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
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