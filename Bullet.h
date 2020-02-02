#define GL_SILENCE_DEPRECATION
#ifndef BULLET_H
#define BULLET_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>

using namespace std;
class Bullet{
private:
	float Bx1;
	float Bx2;
	float By1;
	float By2;
	float bR;
	float bG;
	float bB;
	float pointx;
	float pointy;
	float B_r;
	float Bx;
	float By;
public:
	Bullet();
	~Bullet();
	void B_setallx(float x1,float x2);
	void B_setally(float y1, float y2);
	void B_Py();
	void B_My();
	void P_DrawBullet();	//プレイヤーのバレットのドロー
	void E_DrawBullet();	//エネミーのbバレットのドロー
	float B_getrx();
	float B_getry();
	float getpointx();
	float getpointy();
	float B_getr();
	float B_getBx();		//x座標の中心
	float B_getBy();		//y座標の中心

};
#endif