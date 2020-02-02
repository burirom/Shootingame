#define GL_SILENCE_DEPRECATION
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <GLUT/glut.h>
#include <vector>
#include <cmath>
#include "Bullet.h"
using namespace std;

Bullet::Bullet(){
	
	bR = 0.0;
	bB = 0.0;
	bG = 0.0;
	Bx1 = -0.05;
	Bx2 = 0.05;
	By1 = -0.4;
	By2 = -0.5;
	pointx = 0;
	pointy = 0;
	B_r = 0.01;   //半径
	Bx = 0;
	By = 0;
	
	
}

Bullet::~Bullet(){
	
}

void Bullet::B_setallx(float x1,float x2){
	Bx1 = x1;
	Bx2 = x2;
	Bx = (x2+x1)/2;
}
void Bullet::B_setally(float y1,float y2){
	By1 = y1;
	By2 = y2;
}
void Bullet::P_DrawBullet(){
	const float pi = 3.141592;
	glBegin(GL_TRIANGLE_FAN);	
 	glColor4f(1.0, 1.0, 1.0, 1.0);	
 	By = (By2+By1)/2;			//Byをセット

 	for(float i = 0; i < 360; i += 1){
 		pointx = B_r * sin(i * pi / 180)+Bx;
 		pointy =B_r * cos(i * pi / 180)+By;
 	glVertex2f(pointx,pointy);
 	}
 	glEnd();
}

void Bullet::E_DrawBullet(){
	const float pi = 3.141592;	
	glBegin(GL_TRIANGLE_FAN);	
 	glColor4f(1.0, 1.0, 0.0, 1.0);	
 	By = (By2+By1)/2;			//Byをセット
 	for(float i = 0; i < 360; i += 1){
 		pointx = B_r * sin(i * pi / 180)+Bx;
 		pointy =B_r * cos(i * pi / 180)+By;
 	glVertex2f(pointx,pointy);
 	}
 	glEnd();
}
float Bullet::B_getrx(){
	return (Bx1 + Bx2)/2;
}

float Bullet::B_getry(){
	return (By1 + By2)/2;
}

void Bullet::B_Py(){
	
	By1+=0.02;
	By2+=0.02;
}
void Bullet::B_My(){
	
	By1-=0.02;
	By2-=0.02;
}
float Bullet::getpointx(){
	return pointx;
}
float Bullet::getpointy(){
	return pointy;
}
float Bullet::B_getr(){
	return B_r;
}
float Bullet::B_getBx(){
	return Bx;
}
float Bullet::B_getBy(){
	return By;
}
