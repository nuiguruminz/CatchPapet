#include <mciapi.h>

extern MCI_OPEN_PARMS mop; //���y�Đ��p

//#define WIDTH 640
//#define HEIGHT 240
#define CENTER 0
#define MOVE 5.0
//extern int flagBack;
//extern float x0;
//extern float x1;
//extern float x2;
//extern float x3;
//extern float x4;
//extern float x5;
//extern int flagT;
//extern RECT recDisplay;
//extern int NowScene;

void menuidle(void)
{

	if (flagSpace == 1 && NowSelect == eMenu_Play){
		//�{�^�������ֈړ�
		x0 -= MOVE;
		x1 -= MOVE;
		x2 -= MOVE;
		if (x3 >= CENTER){
			x3 -= MOVE;
			x4 -= MOVE;
			x5 -= MOVE;
		}
		else {
			flagSpace = 0; //space������ĂȂ���Ԃɖ߂�
			//NowSelect = eMenu_Easy;
			NowScene = eScene_Select;
			//flagT = 3;
		}
	}
	else if (flagBack) //�o�b�N�{�^���������ꂽ��
	{
		//�{�^�����E�ֈړ�
		x3 += MOVE;
		x4 += MOVE;
		x5 += MOVE;
		if (x0 <= CENTER){
			x0 += MOVE;
			x1 += MOVE;
			x2 += MOVE;
		}
		else {
			flagBack = 0;
		}
	
	}

	//else if (flagT == 1 && NowSelect == eMenu_Config){ //Config�{�^���I�𒆂�space��������Ă�����

	//}
	//else if (flagT == 1 && NowSelect == eMenu_Rank){ //Rank�{�^���I�𒆂�space��������Ă�����

	//}
	//else if (flagT == 4){

	//}
	////�I�[�v��
	////mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)&mop);
	switch (NowSelect){//���݂̑I����Ԃɏ]���ď����𕪊�
	case eMenu_Play://�Q�[���I�𒆂Ȃ�
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0); //���y�Đ� //�������ςȂ� //���y�I���ƂȂ������̂̓������݂��Ȃ� //���y��������H
		angle0 += 0.3f;
		angle1 = 0.0f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Config://�ݒ�I�𒆂Ȃ�
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
		angle0 = 0.0f;
		angle1 += 0.3f;
		angle2 = 0.0f;
		Sleep(1);
		glutPostRedisplay();
		break;
	case eMenu_Rank://�����L���O�I�𒆂Ȃ�
		//mciSendCommand(mop.wDeviceID, MCI_PLAY, 0, 0);
		angle0 = 0.0f;
		angle1 = 0.0f;
		angle2 += 0.3f;
		Sleep(1);
		glutPostRedisplay();
		break;
		/*
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
		*/
	}
	Sleep(1);
	glutPostRedisplay();
}