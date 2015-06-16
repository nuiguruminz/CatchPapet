#pragma once
//#include <GL/glut.h>
//#include <stdio.h>
#include <mciapi.h>
#include "MenuSelect.h"

extern MCI_OPEN_PARMS mop; //���y�Đ��p

#define MAXPOINTS 100      /* �L������_�̐��@�@ */
#define ESCKEY 27
GLint point[MAXPOINTS][2]; /* ���W���L������z�� */
int pointnum = 0;          /* �L���������W�̐��@ */
int rubberband = 0;        /* ���o�[�o���h�̏��� */

//�O���[�o���ϐ��Q��
//extern float angle0;
//extern float angle1;
//extern float angle2;
extern int flagT;
extern int flagBack;
extern int flagSpace;

extern int NowSelect;    //���݂̑I�����(�����͑I��)
extern int NowScene; //���݂̃V�[���i�����̓��j���[��ʁj

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case ' ':
		switch (NowSelect){//���ݑI�𒆂̏�Ԃɂ���ď����𕪊�
		case eMenu_Play://�v���C�I�𒆂Ȃ�
			flagSpace = 1;
			NowScene = eScene_Select;
			//SceneMgr_ChangeScene(eScene_Select);//�V�[�����Q�[����ʂɕύX
			break;
		case eMenu_Config://�ݒ�I�𒆂Ȃ�
			flagT = 1;
			NowScene = eScene_Config;//�V�[����ݒ��ʂɕύX
			//SceneMgr_ChangeScene(eScene_Config);//�V�[����ݒ��ʂɕύX
			break;
		case eMenu_Rank://�����L���O�I�𒆂Ȃ�
			flagT = 2;
			NowScene = eScene_Rank;//�V�[���������L���O��ʂɕύX
			//SceneMgr_ChangeScene(eScene_Rank);//�V�[����ݒ��ʂɕύX
			break;
		}
		//glutIdleFunc(Select_Now);
	case 'p': //backspace�������ꂽ��
		switch (NowScene){
		case eScene_Menu:
			break;
		case eScene_Select:
			flagBack = 1; //back����
			NowScene = eScene_Menu;
			break;
		case eScene_Config:
			flagBack = 1; //back����
			NowScene = eScene_Menu;
			break;
		case eScene_Rank:
			flagBack = 1; //back����
			NowScene = eScene_Menu;
			break;
		}
		break;
	case ESCKEY:exit(0);
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