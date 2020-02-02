Mygame05:Mygame06.o Enemy.o Player.o Bullet.o
	g++ -o Mygame06 Mygame06.o Enemy.o Player.o Bullet.o -mmacosx-version-min=10.9 -framework OpenGL -framework GLUT
Mygame06.o:Mygame06.cpp
	g++ -c Mygame06.cpp -mmacosx-version-min=10.9 -framework OpenGL -framework GLUT
Enemy.o:Enemy.cpp
	g++ -c Enemy.cpp -mmacosx-version-min=10.9 -framework OpenGL -framework GLUT
Player.o:Player.cpp
	g++ -c Player.cpp -mmacosx-version-min=10.9 -framework OpenGL -framework GLUT
Bullet.o:Bullet.cpp
	g++ -c Bullet.cpp -mmacosx-version-min=10.9 -framework OpenGL -framework GLUT
clean:
	rm -f *.o Enemy Mygame06 Player