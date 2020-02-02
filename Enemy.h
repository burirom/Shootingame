#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
using namespace std;

class Enemy{
private:
	float eR;
	float eG;
	float eB;
	float ex1;		//左
	float ex2;		//右
	float ey1;		//上
	float ey2;		//下
	float E_rx;		//中心のx座標
	float E_ry;		//中心のy座標
	float E_r;		//半径
	int E_life;		//ライフ
public:
	Enemy();
	~Enemy();
	void setall(float x1,float x2,float y1,float y2,float R,float G,float B);
	void DrawEnemy(float Ex);
	float E_getrx();	//ゲット　中心のx座標
	float E_getry();	//ゲット　中心のy座標
	void E_die();		//エネミーのライフを減らす処理
	int getE_life();	//ゲット　エネミーのライフ
	float E_getr();		//ゲット　半径
	float E_getx1();	//ゲット  x1
	float E_getx2();	//ゲット  x2
	float E_gety1();	//ゲット  y1
	float E_gety2();	//ゲット  y2
	void E_setlife();	//セット life
	// int diecount();		//死亡の加算

};