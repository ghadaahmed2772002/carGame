#include<Windows.h> 
#include<GL\glut.h>

float x = 0, y = 0;
float xc1 = 0, yc1 = 15.5, dx1 = .7;
float xc2 = 5, yc2 = 6.8, dx2 = .8;
float xc3 = 10, yc3 = -2.5, dx3 = 1;
float xc4 = -15, yc4 = -11.2, dx4 = .9;
float width, height;
void draw();
void reshape(int, int);
void timer(int);
void backGround();
int main(int argc, char** argv) {
	// glut init
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	// create window
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);
	glutInitWindowSize(width, height);
	//glutInitWindowPosition(10,10);
	glutCreateWindow("Fatma");
	//glutFullScreen();
	glutDisplayFunc(draw);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	backGround();
	glutMainLoop();
}
void draw_road_lines()
{
	//-------------------road-------------------//
	glLineWidth(9);
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-60, 21);
	glVertex2f(-40, 21);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-40, 21);
	glVertex2f(-20, 21);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-20, 21);
	glVertex2f(0, 21);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, 21);
	glVertex2f(20, 21);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(20, 21);
	glVertex2f(40, 21);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, 21);
	glVertex2f(60, 21);
	glEnd();
	//internal lines
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 60, y + 16.5);
	glVertex2f(x - 55, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 50, y + 16.5);
	glVertex2f(x - 45, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 40, y + 16.5);
	glVertex2f(x - 35, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 30, y + 16.5);
	glVertex2f(x - 25, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 20, y + 16.5);
	glVertex2f(x - 15, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 10, y + 16.5);
	glVertex2f(x - 5, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 0, y + 16.5);
	glVertex2f(x + 5, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 10, y + 16.5);
	glVertex2f(x + 15, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 20, y + 16.5);
	glVertex2f(x + 25, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 30, y + 16.5);
	glVertex2f(x + 35, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 40, y + 16.5);
	glVertex2f(x + 45, y + 16.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 50, y + 16.5);
	glVertex2f(x + 55, y + 16.5);
	glEnd();

	//--------------------------//
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-60, 12);
	glVertex2f(-40, 12);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-40, 12);
	glVertex2f(-20, 12);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-20, 12);
	glVertex2f(0, 12);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, 12);
	glVertex2f(20, 12);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(20, 12);
	glVertex2f(40, 12);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, 12);
	glVertex2f(60, 12);
	glEnd();
	//internal lines
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 60, y + 7.5);
	glVertex2f(x - 55, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 50, y + 7.5);
	glVertex2f(x - 45, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 40, y + 7.5);
	glVertex2f(x - 35, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 30, y + 7.5);
	glVertex2f(x - 25, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 20, y + 7.5);
	glVertex2f(x - 15, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 10, y + 7.5);
	glVertex2f(x - 5, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 0, y + 7.5);
	glVertex2f(x + 5, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 10, y + 7.5);
	glVertex2f(x + 15, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 20, y + 7.5);
	glVertex2f(x + 25, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 30, y + 7.5);
	glVertex2f(x + 35, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 40, y + 7.5);
	glVertex2f(x + 45, y + 7.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 50, y + 7.5);
	glVertex2f(x + 55, y + 7.5);
	glEnd();

	//-------------------------//
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-60, 3);
	glVertex2f(-40, 3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-40, 3);
	glVertex2f(-20, 3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-20, 3);
	glVertex2f(0, 3);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, 3);
	glVertex2f(20, 3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(20, 3);
	glVertex2f(40, 3);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, 3);
	glVertex2f(60, 3);
	glEnd();
	//internal lines
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 60, y - 1.5);
	glVertex2f(x - 55, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 50, y - 1.5);
	glVertex2f(x - 45, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 40, y - 1.5);
	glVertex2f(x - 35, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 30, y - 1.5);
	glVertex2f(x - 25, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 20, y - 1.5);
	glVertex2f(x - 15, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 10, y - 1.5);
	glVertex2f(x - 5, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 0, y - 1.5);
	glVertex2f(x + 5, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 10, y - 1.5);
	glVertex2f(x + 15, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 20, y - 1.5);
	glVertex2f(x + 25, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 30, y - 1.5);
	glVertex2f(x + 35, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 40, y - 1.5);
	glVertex2f(x + 45, y - 1.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 50, y - 1.5);
	glVertex2f(x + 55, y - 1.5);
	glEnd();

	//-------------------------//
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-60, -6);
	glVertex2f(-40, -6);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-40, -6);
	glVertex2f(-20, -6);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-20, -6);
	glVertex2f(0, -6);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, -6);
	glVertex2f(20, -6);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(20, -6);
	glVertex2f(40, -6);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, -6);
	glVertex2f(60, -6);
	glEnd();
	//internal lines
	glLineWidth(7);
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 60, y - 10.5);
	glVertex2f(x - 55, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 50, y - 10.5);
	glVertex2f(x - 45, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 40, y - 10.5);
	glVertex2f(x - 35, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 30, y - 10.5);
	glVertex2f(x - 25, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 20, y - 10.5);
	glVertex2f(x - 15, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x - 10, y - 10.5);
	glVertex2f(x - 5, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 0, y - 10.5);
	glVertex2f(x + 5, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 10, y - 10.5);
	glVertex2f(x + 15, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 20, y - 10.5);
	glVertex2f(x + 25, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 30, y - 10.5);
	glVertex2f(x + 35, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 40, y - 10.5);
	glVertex2f(x + 45, y - 10.5);
	glEnd();
	glBegin(GL_LINES);
	glColor4f(1, 1, 1, 0);
	glVertex2f(x + 50, y - 10.5);
	glVertex2f(x + 55, y - 10.5);
	glEnd();

	//---------------------------//
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-60, -15);
	glVertex2f(-40, -15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(-40, -15);
	glVertex2f(-20, -15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(-20, -15);
	glVertex2f(0, -15);
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(0, -15);
	glVertex2f(20, -15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1, .6, 0);
	glVertex2f(20, -15);
	glVertex2f(40, -15);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(0, 0, 0);
	glVertex2f(40, -15);
	glVertex2f(60, -15);
	glEnd();

}
void draw_green_roed()
{
	glBegin(GL_POLYGON);
	glColor3f(0, .7, 0);
	glVertex2f(60, 21);
	glVertex2f(-60, 21);
	glVertex2f(-60, 30);
	glVertex2f(60, 30);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0, .7, 0);
	glVertex2f(60, -15);
	glVertex2f(-60, -15);
	glVertex2f(-60, -30);
	glVertex2f(60, -30);
	glEnd();
}
void draw_car1()
{
	//??? ???????
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 1);
	glVertex2f(xc1 + 0, yc1 + 2);
	glVertex2f(xc1 + 0, yc1 + 0);
	glVertex2f(xc1 + 1, yc1 - 1);
	glVertex2f(xc1 + 6, yc1 - 1);
	glVertex2f(xc1 + 7, yc1 + 0);
	glVertex2f(xc1 + 7, yc1 + 2);
	glVertex2f(xc1 + 6, yc1 + 3);
	glVertex2f(xc1 + 1, yc1 + 3);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc1 + 1.5, yc1 - 1);
	glVertex2f(xc1 + 1.5, yc1 - 1.5);
	glVertex2f(xc1 + 2.5, yc1 - 1.5);
	glVertex2f(xc1 + 2.5, yc1 - 1);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc1 + 4.5, yc1 - 1);
	glVertex2f(xc1 + 4.5, yc1 - 1.5);
	glVertex2f(xc1 + 5.5, yc1 - 1.5);
	glVertex2f(xc1 + 5.5, yc1 - 1);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc1 + 1.5, yc1 + 3);
	glVertex2f(xc1 + 1.5, yc1 + 3.5);
	glVertex2f(xc1 + 2.5, yc1 + 3.5);
	glVertex2f(xc1 + 2.5, yc1 + 3);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc1 + 4.5, yc1 + 3);
	glVertex2f(xc1 + 4.5, yc1 + 3.5);
	glVertex2f(xc1 + 5.5, yc1 + 3.5);
	glVertex2f(xc1 + 5.5, yc1 + 3);
	glEnd();
	//???????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc1 + 6.75, yc1 + 0);
	glVertex2f(xc1 + 7, yc1 + 0);
	glVertex2f(xc1 + 7, yc1 + 2);
	glVertex2f(xc1 + 6.75, yc1 + 2);
	glEnd();
	//????????
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);
	glVertex2f(xc1 + .5, yc1 + .25);
	glVertex2f(xc1 + .5, yc1 + 1.75);
	glEnd();
	//?????? ???? ????
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc1 + 1.5, yc1 - .75);
	glVertex2f(xc1 + 2.75, yc1 - .75);
	glVertex2f(xc1 + 2.75, yc1 + 2.75);
	glVertex2f(xc1 + 1.5, yc1 + 2.75);
	glEnd();
	//?????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc1 + 4.5, yc1 - .75);
	glVertex2f(xc1 + 5.75, yc1 - .75);
	glVertex2f(xc1 + 5.75, yc1 + 2.75);
	glVertex2f(xc1 + 4.5, yc1 + 2.75);
	glEnd();
}
void draw_car2()
{
	//??? ???????
	glBegin(GL_POLYGON);
	glColor3f(.2, .9, 0);
	glVertex2f(xc2 + 0, yc2 + 2);
	glVertex2f(xc2 + 0, yc2 + 0);
	glVertex2f(xc2 + 1, yc2 - 1);
	glVertex2f(xc2 + 6, yc2 - 1);
	glVertex2f(xc2 + 7, yc2 + 0);
	glVertex2f(xc2 + 7, yc2 + 2);
	glVertex2f(xc2 + 6, yc2 + 3);
	glVertex2f(xc2 + 1, yc2 + 3);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc2 + 1.5, yc2 - 1);
	glVertex2f(xc2 + 1.5, yc2 - 1.5);
	glVertex2f(xc2 + 2.5, yc2 - 1.5);
	glVertex2f(xc2 + 2.5, yc2 - 1);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc2 + 4.5, yc2 - 1);
	glVertex2f(xc2 + 4.5, yc2 - 1.5);
	glVertex2f(xc2 + 5.5, yc2 - 1.5);
	glVertex2f(xc2 + 5.5, yc2 - 1);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc2 + 1.5, yc2 + 3);
	glVertex2f(xc2 + 1.5, yc2 + 3.5);
	glVertex2f(xc2 + 2.5, yc2 + 3.5);
	glVertex2f(xc2 + 2.5, yc2 + 3);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc2 + 4.5, yc2 + 3);
	glVertex2f(xc2 + 4.5, yc2 + 3.5);
	glVertex2f(xc2 + 5.5, yc2 + 3.5);
	glVertex2f(xc2 + 5.5, yc2 + 3);
	glEnd();
	//???????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc2 + .25, yc2 + 0);
	glVertex2f(xc2 + 0, yc2 + 0);
	glVertex2f(xc2 + 0, yc2 + 2);
	glVertex2f(xc2 + .25, yc2 + 2);
	glEnd();
	//????????
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);
	glVertex2f(xc2 + 6.5, yc2 + .25);
	glVertex2f(xc2 + 6.5, yc2 + 1.75);
	glEnd();
	//?????? ???? ????
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc2 + 1.5, yc2 - .75);
	glVertex2f(xc2 + 2.75, yc2 - .75);
	glVertex2f(xc2 + 2.75, yc2 + 2.75);
	glVertex2f(xc2 + 1.5, yc2 + 2.75);
	glEnd();
	//?????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc2 + 4.5, yc2 - .75);
	glVertex2f(xc2 + 5.75, yc2 - .75);
	glVertex2f(xc2 + 5.75, yc2 + 2.75);
	glVertex2f(xc2 + 4.5, yc2 + 2.75);
	glEnd();
}
void draw_car3()
{
	//??? ???????
	glBegin(GL_POLYGON);
	glColor3f(.8, 0, 0);
	glVertex2f(xc3 + 0, yc3 + 2);
	glVertex2f(xc3 + 0, yc3 + 0);
	glVertex2f(xc3 + 1, yc3 - 1);
	glVertex2f(xc3 + 6, yc3 - 1);
	glVertex2f(xc3 + 7, yc3 + 0);
	glVertex2f(xc3 + 7, yc3 + 2);
	glVertex2f(xc3 + 6, yc3 + 3);
	glVertex2f(xc3 + 1, yc3 + 3);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc3 + 1.5, yc3 - 1);
	glVertex2f(xc3 + 1.5, yc3 - 1.5);
	glVertex2f(xc3 + 2.5, yc3 - 1.5);
	glVertex2f(xc3 + 2.5, yc3 - 1);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc3 + 4.5, yc3 - 1);
	glVertex2f(xc3 + 4.5, yc3 - 1.5);
	glVertex2f(xc3 + 5.5, yc3 - 1.5);
	glVertex2f(xc3 + 5.5, yc3 - 1);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc3 + 1.5, yc3 + 3);
	glVertex2f(xc3 + 1.5, yc3 + 3.5);
	glVertex2f(xc3 + 2.5, yc3 + 3.5);
	glVertex2f(xc3 + 2.5, yc3 + 3);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc3 + 4.5, yc3 + 3);
	glVertex2f(xc3 + 4.5, yc3 + 3.5);
	glVertex2f(xc3 + 5.5, yc3 + 3.5);
	glVertex2f(xc3 + 5.5, yc3 + 3);
	glEnd();
	//???????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc3 + 6.75, yc3 + 0);
	glVertex2f(xc3 + 7, yc3 + 0);
	glVertex2f(xc3 + 7, yc3 + 2);
	glVertex2f(xc3 + 6.75, yc3 + 2);
	glEnd();
	//????????
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);
	glVertex2f(xc3 + .5, yc3 + .25);
	glVertex2f(xc3 + .5, yc3 + 1.75);
	glEnd();
	//?????? ???? ????
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc3 + 1.5, yc3 - .75);
	glVertex2f(xc3 + 2.75, yc3 - .75);
	glVertex2f(xc3 + 2.75, yc3 + 2.75);
	glVertex2f(xc3 + 1.5, yc3 + 2.75);
	glEnd();
	//?????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc3 + 4.5, yc3 - .75);
	glVertex2f(xc3 + 5.75, yc3 - .75);
	glVertex2f(xc3 + 5.75, yc3 + 2.75);
	glVertex2f(xc3 + 4.5, yc3 + 2.75);
	glEnd();
}
void draw_car4()
{
	//??? ???????
	glBegin(GL_POLYGON);
	glColor3f(.2, 1, .9);
	glVertex2f(xc4 + 0, yc4 + 2);
	glVertex2f(xc4 + 0, yc4 + 0);
	glVertex2f(xc4 + 1, yc4 - 1);
	glVertex2f(xc4 + 6, yc4 - 1);
	glVertex2f(xc4 + 7, yc4 + 0);
	glVertex2f(xc4 + 7, yc4 + 2);
	glVertex2f(xc4 + 6, yc4 + 3);
	glVertex2f(xc4 + 1, yc4 + 3);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc4 + 1.5, yc4 - 1);
	glVertex2f(xc4 + 1.5, yc4 - 1.5);
	glVertex2f(xc4 + 2.5, yc4 - 1.5);
	glVertex2f(xc4 + 2.5, yc4 - 1);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc4 + 4.5, yc4 - 1);
	glVertex2f(xc4 + 4.5, yc4 - 1.5);
	glVertex2f(xc4 + 5.5, yc4 - 1.5);
	glVertex2f(xc4 + 5.5, yc4 - 1);
	glEnd();
	//?????? ???? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc4 + 1.5, yc4 + 3);
	glVertex2f(xc4 + 1.5, yc4 + 3.5);
	glVertex2f(xc4 + 2.5, yc4 + 3.5);
	glVertex2f(xc4 + 2.5, yc4 + 3);
	glEnd();
	//?????? ???? ??? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc4 + 4.5, yc4 + 3);
	glVertex2f(xc4 + 4.5, yc4 + 3.5);
	glVertex2f(xc4 + 5.5, yc4 + 3.5);
	glVertex2f(xc4 + 5.5, yc4 + 3);
	glEnd();
	//???????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 0);
	glVertex2f(xc4 + .25, yc4 + 0);
	glVertex2f(xc4 + 0, yc4 + 0);
	glVertex2f(xc4 + 0, yc4 + 2);
	glVertex2f(xc4 + .25, yc4 + 2);
	glEnd();
	//????????
	glEnable(GL_POINT_SMOOTH);
	glPointSize(5);
	glBegin(GL_POINTS);
	glColor3f(1, 1, 0);
	glVertex2f(xc4 + 6.5, yc4 + .25);
	glVertex2f(xc4 + 6.5, yc4 + 1.75);
	glEnd();
	//?????? ???? ????
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc4 + 1.5, yc4 - .75);
	glVertex2f(xc4 + 2.75, yc4 - .75);
	glVertex2f(xc4 + 2.75, yc4 + 2.75);
	glVertex2f(xc4 + 1.5, yc4 + 2.75);
	glEnd();
	//?????? ???? ???
	glBegin(GL_POLYGON);
	glColor3f(0, 0, 1);
	glVertex2f(xc4 + 4.5, yc4 - .75);
	glVertex2f(xc4 + 5.75, yc4 - .75);
	glVertex2f(xc4 + 5.75, yc4 + 2.75);
	glVertex2f(xc4 + 4.5, yc4 + 2.75);
	glEnd();
}
void draw() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//-------------------linas road-------------------//
	draw_road_lines();
	//-------------------green road-----------------//
	draw_green_roed();
	//-------------------car-------------------//
	draw_car1();
	draw_car2();
	draw_car3();
	draw_car4();
	glFlush();
}
void reshape(int w, int h) {
	float ratio;
	if (h == 0)
		h = 1;
	ratio = (float)w / h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (w >= h)
		gluOrtho2D(-30 * ratio, 30 * ratio, -30, 30);
	else
		gluOrtho2D(-30, 30, -30 / ratio, 30 / ratio);
	glMatrixMode(GL_MODELVIEW);
}
void backGround() {
	// color [0,1]
	glClearColor(0.5, 0.5, 0.5, 0);
}
void timer(int v) {
	// repaint
	glutPostRedisplay();
	glutTimerFunc(1000 / 25, timer, 0);
	xc3 -= dx3;
	xc1 -= dx1;
	xc2 += dx2;
	xc4 += dx4;
	if (xc1 < -60)
		xc1 = 60;
	if (xc3 < -60)
		xc3 = 60;
	if (xc2 > 60)
		xc2 = -60;
	if (xc4 > 60)
		xc4 = -60;
}