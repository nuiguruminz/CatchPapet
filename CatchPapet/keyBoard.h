//#include <GL/glut.h>
#include <stdio.h>

#define MAXPOINTS 100      /* �L������_�̐��@�@ */
GLint point[MAXPOINTS][2]; /* ���W���L������z�� */
int pointnum = 0;          /* �L���������W�̐��@ */
int rubberband = 0;        /* ���o�[�o���h�̏��� */

//�O���[�o���ϐ��Q��
extern float angle0;
extern float angle1;
extern float angle2;
extern int flagT;

typedef enum{
	eMenu_Play,        //�v���C
	eMenu_Config,    //�ݒ�
	eMenu_Rank,		//�����L���O
	eMenu_Easy,
	eMenu_Normal,
	eMenu_Hard,

	eMenu_Num = 3,        //�{���ڂ̐�
} eMenu;
/*static */ int NowSelect = eMenu_Play;    //���݂̑I�����(�����͑I��)

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case ' ':
		switch (NowSelect){//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eMenu_Play://�Q�[���I�𒆂Ȃ�
			flagT = 0;
			// SceneMgr_ChangeScene(eScene_Game);//�V�[�����Q�[����ʂɕύX
			break;
		case eMenu_Config://�ݒ�I�𒆂Ȃ�
			flagT = 1;
			//SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		case eMenu_Rank://�����L���O�I�𒆂Ȃ�
			flagT = 2;
			//SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		}
		//glutIdleFunc(Select_Now);
		break;
	default:
		break;
	}
}
void specialkeydown(int key, int x, int y){
	switch (key){
	case GLUT_KEY_UP:
		NowSelect = (NowSelect + (eMenu_Num - 1)) % eMenu_Num;//�I����Ԃ���グ��
		//Select_Now();
		break;
	case GLUT_KEY_DOWN:
		NowSelect = (NowSelect + 1) % eMenu_Num;//�I����Ԃ��������
		//Select_Now();
		break;
	}
}