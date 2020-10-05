#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <time.h>

GLfloat theta_Upper = 0;
GLfloat theta_Lower = 0;
GLfloat Max = 45;
GLfloat Min = -45;
GLfloat Pose = 0;


//머리
void Draw_Head() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.8, 0.7);

	double rad = 0.3;

	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		double angle = i * 3.141592 / 180;
		double x = rad * cos(angle);
		double y = 0.8 + rad * sin(angle);
		glVertex2f(x, y);
	}
	glEnd();
	glFinish();
}

//몸
void Draw_Body() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFinish();
}

//상단 오른팔
void Draw_UpperArm_R() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(0.7, 0.3, 0.0);
	glVertex3f(0.7, 0.0, 0.0);
	glEnd();
	glFinish();
}

//하단 오른팔
void Draw_LowerArm_R() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(0.7, 0.3, 0.0);
	glVertex3f(0.7, 0.0, 0.0);
	glEnd();
}

//손
void Draw_Hand_R() {
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.9, 0.0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.3f, 0.0f);
	glVertex3f(0.3f, 0.2f, 0.0f);
	glVertex3f(0.2f, 0.0f, 0.0f);
	glEnd();
	glFinish();
}

//상단 왼팔
void Draw_UpperArm_L() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(-0.7, 0.3, 0.0);
	glVertex3f(-0.7, 0.0, 0.0);
	glEnd();
	glFinish();
}

//하단 왼팔
void Draw_LowerArm_L() {
	glBegin(GL_POLYGON);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.3, 0.0);
	glVertex3f(-0.7, 0.3, 0.0);
	glVertex3f(-0.7, 0.0, 0.0);
	glEnd();
}

//왼손
void Draw_Hand_L() {
	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.9, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.2, 0.0);
	glVertex3f(-0.2, 0.3, 0.0);
	glVertex3f(-0.3, 0.2, 0.0);
	glVertex3f(-0.2, 0.0, 0.0);
	glEnd();
	glFinish();
}

//오른쪽 어깨의 움직임
void GoToShoulderCoordinates_R() {
	glTranslatef(0.5, 0.5, 0.0);
	glRotatef(theta_Upper, 0.0, 0.0, 1.0);
}

//오른쪽 팔꿈치의 움직임
void GoToElbowCoordinates_R() {
	glTranslatef(0.7, 0.0, 0.0);
	glRotatef(theta_Upper, 0.0, 0.0, 1.0);
	glRotatef(theta_Lower, 0.0, 0.0, 1.0);//
}

//오른손의 움직임
void GoToWristCoordinates_R() {
	glTranslatef(0.7, 0.1, 0.0);
	glRotatef(theta_Upper, 0.0, 0.0, 1.0);
	glRotatef(theta_Lower, 0.0, 0.0, 1.0);//
}

//왼쪽 어깨의 움직임
void GoToShoulderCoordinates_L() {
	glTranslatef(-0.5, 0.5, 0.0);
	glRotatef(-1 * theta_Upper, 0.0, 0.0, 1.0);
}

//왼쪽 팔꿈치 움직임
void GoToElbowCoordinates_L() {
	glTranslatef(-0.7, 0.0, 0.0);
	glRotatef(-1 * theta_Upper, 0.0, 0.0, 1.0);
	glRotatef(-1 * theta_Lower, 0.0, 0.0, 1.0);//
}

//왼쪽손의 움직임
void GoToWristCoordinates_L() {
	glTranslatef(-0.7, 0.1, 0.0);
	glRotatef(-1 * theta_Upper, 0.0, 0.0, 1.0);
	glRotatef(-1 * theta_Lower, 0.0, 0.0, 1.0);//
}

//오른팔의 위치를 조절 및 그리기
void drawArm_R() {

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glPushMatrix();
	GoToShoulderCoordinates_R();
	Draw_UpperArm_R();
	glPushMatrix();
	GoToElbowCoordinates_R();
	Draw_LowerArm_R();
	glPushMatrix();
	GoToWristCoordinates_R();
	Draw_Hand_R();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
}

//왼팔의 위치를 조절 및 그리기
void drawArm_L() {

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glPushMatrix();
	GoToShoulderCoordinates_L();
	Draw_UpperArm_L();
	glPushMatrix();
	GoToElbowCoordinates_L();
	Draw_LowerArm_L();
	glPushMatrix();
	GoToWristCoordinates_L();
	Draw_Hand_L();
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();


}

void Movement() {
	if (Pose == 1 && theta_Upper <= Max) {
		theta_Upper++;
	}
	else if (Pose == 2 && theta_Upper >= Min) {
		theta_Upper--;
	}
	else if (Pose == 3 && theta_Lower <= Max) {
		theta_Lower++;
	}
	else if (Pose == 4 && theta_Lower >= Min) {
		theta_Lower--;
	}
}

void MyDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	Draw_Head();
	Draw_Body();
	drawArm_R();
	drawArm_L();
	Movement();
	glEnd();
	glutSwapBuffers();
}

void MyTimer(int Value)
{
	glutPostRedisplay();
	glutTimerFunc(30, MyTimer, 1);
}

void MyKeyboard(unsigned char KeyPressed, int X, int Y) {

	switch (KeyPressed) {
	case 'Q':
	case 'q':
		Pose = 1;
		break;
	case 'A':
	case 'a':
		Pose = 2;
		break;
	case 'P':
	case 'p':
		Pose = 3;
		break;
	case 'L':
	case 'l':
		Pose = 4;
		break;
	}
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(1000, 800);   //윈도우 크기
	glutInitWindowPosition(100, 0);
	glutCreateWindow("OpenGL Drawing Example");
	glClearColor(1.0, 1.0, 1.0, 1.0);   //배경색 설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 1.0, -1.0);
	glutDisplayFunc(MyDisplay); //디스플레이 이벤트 핸들러 등록
	glutKeyboardFunc(MyKeyboard); //키보드 인터럽트 핸들러 등록
	glutTimerFunc(40, MyTimer, 1); //타이머 인터럽트
	glutMainLoop(); //해당과정을 loop
	return 0;
}