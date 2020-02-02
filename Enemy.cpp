#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include "Enemy.h"
using namespace std;
Enemy::Enemy(){
	E_life = 1;		//エネミーのライフを初期化
}
Enemy::~Enemy(){

}
void Enemy::setall(float x1,float x2,float y1,float y2,float R,float G,float B){
	eR = R;
	eG = G;
	eB = B;
	ex1 = x1;
	ex2 = x2;
	ey1 = y1;
	ey2 = y2;
	E_rx = (x1 + x2)/2;			//中心のx座標
	E_ry = (y1 + y2)/2;			//中心のy座標
	E_r = (x2-x1)/2;			//エネミーの半径
	
}
void Enemy::DrawEnemy(float Ex){ 			//エネミー
	glColor3d(eR,eG,eB);
		glBegin(GL_QUADS);
		glVertex2d(ex1+Ex, ey1);
		glVertex2d(ex2+Ex, ey1);
		glVertex2d(ex2+Ex, ey2);
		glVertex2d(ex1+Ex, ey2);

	glEnd();
}
float Enemy:: E_getrx(){		//中心のx座標のゲット
	return E_rx;
}
float Enemy:: E_getry(){		//中心のy座標のゲット
	return E_ry;
}
void Enemy::E_die(){			//エネミーのライフを減らす
	E_life--;
}
int Enemy::getE_life(){			//エネミーのライフをゲット
	return E_life;
}
float Enemy::E_getr(){			//エネミーの半径
	return E_r;
}
float Enemy::E_getx1(){			//ex1をゲット
	return ex1;
}
float Enemy::E_getx2(){			//ex2をゲット
	return ex2;
}
float Enemy::E_gety1(){			//ey1をゲット
	return ey1;
}
float Enemy::E_gety2(){			//ey2をゲット
	return ey2;
}
// int Enemy::diecount(){			//死亡の加算
// 	return 1;
// }

void Enemy::E_setlife(){
	E_life = 1;
}