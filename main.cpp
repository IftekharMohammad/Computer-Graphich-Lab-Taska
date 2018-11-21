#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
glClear (GL_COLOR_BUFFER_BIT);

glColor3ub(255,201,14);
glBegin(GL_POLYGON);
    glVertex2i(200, 280);
    glVertex2i(200, 550);
    glVertex2i(0, 550);
    glVertex2i(0, 280);
glEnd();


glColor3ub(255,201,14);
glBegin(GL_POLYGON);
    glVertex2i(400, 0);
    glVertex2i(400, 280);
    glVertex2i(200, 280);
    glVertex2i(200, 0);
glEnd();

glColor3ub(255,201,14);
glBegin(GL_POLYGON);
    glVertex2i(600, 280);
    glVertex2i(600, 550);
    glVertex2i(400, 550);
    glVertex2i(400, 280);
glEnd();


glColor3ub(255,201,14);
glBegin(GL_POLYGON);
    glVertex2i(800, 0);
    glVertex2i(800, 280);
    glVertex2i(600, 280);
    glVertex2i(600, 0);
glEnd();

glColor3ub(255,201,14);
glBegin(GL_POLYGON);
    glVertex2i(1000, 280);
    glVertex2i(1000, 550);
    glVertex2i(800, 550);
    glVertex2i(800, 280);
glEnd();


glColor3ub (0,0,0);
glBegin(GL_POLYGON);
    glVertex2i(60, 130);
    glVertex2i(60, 430);
    glVertex2i(20, 430);
    glVertex2i(20, 130);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(360, 150);
    glVertex2i(360, 380);
    glVertex2i(320, 380);
    glVertex2i(320, 150);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(320, 170);
    glVertex2i(320, 400);
    glVertex2i(280, 400);
    glVertex2i(280, 170);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(300, 190);
    glVertex2i(300, 400);
    glVertex2i(260, 400);
    glVertex2i(260, 190);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(280, 210);
    glVertex2i(280, 360);
    glVertex2i(240, 360);
    glVertex2i(240, 210);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(380, 170);
    glVertex2i(380, 400);
    glVertex2i(360, 400);
    glVertex2i(360, 170);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(400, 170);
    glVertex2i(400, 400);
    glVertex2i(380, 400);
    glVertex2i(380, 170);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(420, 190);
    glVertex2i(420, 400);
    glVertex2i(400, 400);
    glVertex2i(400, 190);
glEnd();

glColor3ub (250,36,5);
glBegin(GL_POLYGON);
    glVertex2i(440, 210);
    glVertex2i(440, 360);
    glVertex2i(420, 360);
    glVertex2i(420, 210);
glEnd();

glColor3ub (0,0,0);
glBegin(GL_POLYGON);
    glVertex2i(660, 190);
    glVertex2i(660, 430);
    glVertex2i(620, 430);
    glVertex2i(620, 190);
glEnd();

glColor3ub (0,0,0);
glBegin(GL_POLYGON);
    glVertex2i(830, 190);
    glVertex2i(830, 430);
    glVertex2i(790, 430);
    glVertex2i(790, 190);
glEnd();

glColor3ub (0,0,0);
glBegin(GL_POLYGON);
    glVertex2i(800, 140);
    glVertex2i(800, 160);
    glVertex2i(660, 160);
    glVertex2i(660, 140);
glEnd();


glColor3ub (0,0,0);
glPointSize(40);
glBegin(GL_POINTS);
    glVertex2i(790, 180);
glEnd();

glBegin(GL_POINTS);
    glVertex2i(660, 180);
glEnd();

glFlush ();
}
void myInit (void)
{
glClearColor(1.0, 1.0, 0.0, 0.0);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
gluOrtho2D(0.0, 1000.0, 0.0, 550.0);
}

main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (1000, 550);
glutInitWindowPosition (0, 0);
glutCreateWindow ("Lab Exam");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
