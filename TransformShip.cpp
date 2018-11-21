#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
using namespace std;
int width,height;
float _move = 0.0f;
float getX(int x){
    //return (float)x/(width/2);
    return (float)x/(640/2);
}
float getY(int y){
    //return (float)y/(height/2);
    return (float)y/(480/2);
}
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1,0,0);
    glClearColor(0.90, 0.30, 0.0, 0.0);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

    glPushMatrix();
	glTranslatef(-_move,0.0f, 0.0f);
        glColor3ub (0, 0, 0);
    glPointSize(5.0);

    glBegin(GL_POLYGON);
        glVertex2f(getX(30), getY(50));
        glVertex2f(getX(30), getY(150));
        glVertex2f(getX(-20), getY(150));
        glVertex2f(getX(-20), getY(50));
    glEnd();

    glColor3ub (0, 250, 0);
    glBegin(GL_POLYGON);
        glVertex2f(getX(120), getY(50));
        glVertex2f(getX(120), getY(100));
        glVertex2f(getX(100), getY(100));
        glVertex2f(getX(100), getY(50));
    glEnd();

    glColor3ub (0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2f(getX(-60), getY(50));
        glVertex2f(getX(-60), getY(100));
        glVertex2f(getX(-80), getY(100));
        glVertex2f(getX(-80), getY(50));
    glEnd();

    glColor3ub (255, 250, 250);
    glBegin(GL_POLYGON);
        glVertex2f(getX(100), getY(-50));
        glVertex2f(getX(150), getY(50));
        glVertex2f(getX(-130), getY(50));
        glVertex2f(getX(-100), getY(-50));
    glEnd();
/*
    glColor3ub (100, 100, 255);
    glBegin(GL_POLYGON);
        glVertex2f(getX(320), getY(-240));
        glVertex2f(getX(320), getY(0));
        glVertex2f(getX(-320), getY(0));
        glVertex2f(getX(-320), getY(-240));
    glEnd();
*/
    glColor3ub (250, 250, 250);
    glBegin(GL_POLYGON);
        glVertex2f(getX(25), getY(200));
        glVertex2f(getX(25), getY(210));
        glVertex2f(getX(15), getY(210));
        glVertex2f(getX(15), getY(200));
    glEnd();

    glColor3ub (250, 250, 250);
    glBegin(GL_POLYGON);
        glVertex2f(getX(18), getY(180));
        glVertex2f(getX(18), getY(190));
        glVertex2f(getX(8), getY(190));
        glVertex2f(getX(8), getY(180));
    glEnd();


    glColor3ub (250, 250, 250);
    glBegin(GL_POLYGON);
        glVertex2f(getX(-8), getY(160));
        glVertex2f(getX(-8), getY(170));
        glVertex2f(getX(-17), getY(170));
        glVertex2f(getX(-17), getY(160));
    glEnd();
    glPopMatrix();

    glColor3ub (100, 100, 255);
    glBegin(GL_POLYGON);
        glVertex2f(getX(320), getY(-240));
        glVertex2f(getX(320), getY(0));
        glVertex2f(getX(-320), getY(0));
        glVertex2f(getX(-320), getY(-240));
    glEnd();
	glutSwapBuffers();
}

void update(int value) {

    _move += .02;
    if(_move-1.3 > 1.0)
    {
        _move = -1.0;
    }
	glutPostRedisplay(); //Notify GLUT that the display has changed

	glutTimerFunc(20, update, 0); //Notify GLUT to call update again in 25 milliseconds
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	//width = glutGet(GLUT_WINDOW_WIDTH);
	//height = glutGet(GLUT_WINDOW_HEIGHT);
	glutCreateWindow("Transformation");
	glutDisplayFunc(drawScene);
	glutTimerFunc(20, update, 0); //Add a timer
	glutMainLoop();
	return 0;
}
