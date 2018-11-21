#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

float angle = 0.0f;
float lx=0.0f,lz=-1.0f;
float lxx=1.0f,lzz=0.0f;
float x=0.0f, z=95.0f;
float deltaAngle = 0.0f;
float deltaMove = 0;
float deltaMoveX = 0;
int xOrigin = -1;
int h,w;

void changeSize(int ww, int hh) {

	h = hh;
	w = ww;
	if (h == 0)
		h = 1;
	float ratio =  w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void restorePerspectiveProjection() {

	glMatrixMode(GL_PROJECTION);

	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
}

void setOrthographicProjection() {

	glMatrixMode(GL_PROJECTION);

	glPushMatrix();

	glLoadIdentity();

	gluOrtho2D(0, w, h, 0);

	glMatrixMode(GL_MODELVIEW);
}

void computePosZ(float deltaMove) {

	x += deltaMove * lx * 0.1f;
	z += deltaMove * lz * 0.1f;
}

void computePosX(float deltaMoveX) {

    x += deltaMoveX * lxx * 0.1f;
	z += deltaMoveX * lzz * 0.1f;
}
void renderScene(void) {

	if (deltaMove)
		computePosZ(deltaMove);

    if (deltaMoveX)
		computePosX(deltaMoveX);


	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
    gluLookAt(	x, 1.0f, z,x+lx, 1.0f,  z+lz,0.0f, 1.0f,  0.0f);

// ground
    glColor3f(0.50f, 0.50f, 0.50f);
	glBegin(GL_QUADS);
		glVertex3f(-200.0f, 0.0f, -60.0f);
		glVertex3f(-200.0f, 0.0f,  60.0f);
		glVertex3f( 100.0f, 0.0f,  60.0f);
		glVertex3f( 100.0f, 0.0f, -60.0f);
	glEnd();
//field

    glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex3f(-200.0f, 0.0f, 100.0f);
		glVertex3f(100.0f, 0.0f,  100.0f);
		glVertex3f(100.0f, 0.0f,  60.0f);
		glVertex3f(-200.0f, 0.0f, 60.0f);
	glEnd();
//Main Building
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(0.0f ,10.0f, 20.0f);
        glutSolidSphere(15.75f,20,20);
    glPopMatrix();

//end Main Building
//annex1
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glTranslatef(-60.0f ,5.0f, 50.0f);
        glScalef(8.0,1.0,1.0);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glTranslatef(-10.0f ,8.0f, 50.0f);
        glScalef(20.0,3.0,8.0);
        glutSolidCube(1);
    glPopMatrix();

    glPushMatrix();
        glColor3f(1.0f, 0.0f, 0.0f);
        glTranslatef(40.0f ,5.0f, 50.0f);
        glScalef(8.0,1.0,1.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex1
//annex 2

    glPushMatrix();
        glColor3f(0.0f, 1.0f, 0.0f);
        glTranslatef(-100.0f ,5.0f, 30.0f);
        glScalef(8.0,3.0,1.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex2
//between 2&3

    glPushMatrix();
        glColor3f(0.0f, 0.0f, 1.0f);
        glTranslatef(-61.0f ,5.0f, 20.0f);
        glScalef(0.60,1.0,1.0);
        glutSolidCube(10);
    glPopMatrix();


    glPushMatrix();
        glColor3f(0.0f, 0.0f, 1.0f);
        glTranslatef(-61.0f ,5.0f, 0.0f);
        glScalef(0.60,1.0,1.0);
        glutSolidCube(10);
    glPopMatrix();

    glPushMatrix();
        glColor3f(0.0f, 0.0f, 1.0f);
        glTranslatef(-60.0f ,15.0f, 10.0f);
        glScalef(1.0,1.0,3.0);
        glutSolidCube(10);
    glPopMatrix();
//end between 2&3
//annex 3
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f);
        glTranslatef(-100.0f ,5.0f, -10.0f);
        glScalef(8.0,3.0,1.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex 3
//annex 7
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 1.0f);
        glTranslatef(-145.0f ,5.0f, 10.0f);
        glScalef(1.0,8.0,5.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex 7

//annex 4
    glPushMatrix();
        glColor3f(0.0f, 1.0f, 1.0f);
        glTranslatef(-55.0f ,5.0f, -40.0f);
        glScalef(2.0,3.0,5.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex 4

//annex 5
    glPushMatrix();
        glColor3f(1.0f, 1.0f, 0.0f);
        glTranslatef(-30.0f ,5.0f, -40.0f);
        glScalef(2.0,3.0,5.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex 5

//annex 6
    glPushMatrix();
        glColor3f(1.0f, 0.0f, 1.0f);
        glTranslatef(0.0f ,5.0f, -40.0f);
        glScalef(2.0,5.0,5.0);
        glutSolidCube(10);
    glPopMatrix();
//end annex 6
	setOrthographicProjection();

	glPushMatrix();
	glLoadIdentity();
	glPopMatrix();

	restorePerspectiveProjection();

	glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int xx, int yy) {

	switch (key) {
		case 27:exit(0);break;
	}
}

void pressKey(int key, int xx, int yy) {

	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0.5f; break;
		case GLUT_KEY_DOWN : deltaMove = -0.5f; break;
		case GLUT_KEY_LEFT : deltaMoveX -= 0.5; break;
		case GLUT_KEY_RIGHT : deltaMoveX += 0.5; break;

	}
}

void releaseKey(int key, int x, int y) {

	switch (key) {
		case GLUT_KEY_UP : deltaMove = 0;break;
		case GLUT_KEY_DOWN : deltaMove = 0;break;
		case GLUT_KEY_LEFT : deltaMoveX = 0;break;
		case GLUT_KEY_RIGHT : deltaMoveX = 0;break;
	}
}

void mouseMove(int x, int y) {
	if (xOrigin >= 0) {
		deltaAngle = (x - xOrigin) * 0.001f;
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}

void mouseButton(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) {

		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {
			xOrigin = x;
		}
	}
}

int main(int argc, char **argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(800,600);
	glutCreateWindow("AIUB 3D");
    glClearColor(0.40f, 0.40f, 1.0f,0.0);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	glutIgnoreKeyRepeat(1);
	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(pressKey);
	glutSpecialUpFunc(releaseKey);

	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	glutMainLoop();

	return 1;
}

