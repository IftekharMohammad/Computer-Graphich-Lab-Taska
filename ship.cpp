#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (255, 0, 0);
    glPointSize(5.0);

    glBegin(GL_POLYGON);
        glVertex2i(30, 50);
        glVertex2i(30, 150);
        glVertex2i(-20, 150);
        glVertex2i(-20, 50);
    glEnd();

    glColor3ub (0, 250, 0);
    glBegin(GL_POLYGON);
        glVertex2i(120, 50);
        glVertex2i(120, 100);
        glVertex2i(100, 100);
        glVertex2i(100, 50);
    glEnd();

    glColor3ub (0, 0, 255);
    glBegin(GL_POLYGON);
        glVertex2i(-60, 50);
        glVertex2i(-60, 100);
        glVertex2i(-80, 100);
        glVertex2i(-80, 50);
    glEnd();

    glColor3ub (0, 0, 0);
    glBegin(GL_POLYGON);
        glVertex2i(100, -50);
        glVertex2i(150, 50);
        glVertex2i(-130, 50);
        glVertex2i(-100, -50);
    glEnd();

    glColor3ub (100, 100, 255);
    glBegin(GL_POLYGON);
        glVertex2i(320, -240);
        glVertex2i(320, 0);
        glVertex2i(-320, 0);
        glVertex2i(-320, -240);
    glEnd();

    glColor3ub (50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2i(25, 200);
        glVertex2i(25, 210);
        glVertex2i(15, 210);
        glVertex2i(15, 200);
    glEnd();

    glColor3ub (50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2i(18, 180);
        glVertex2i(18, 190);
        glVertex2i(8, 190);
        glVertex2i(8, 180);
    glEnd();

    glColor3ub (50, 50, 50);
    glBegin(GL_POLYGON);
        glVertex2i(-8, 160);
        glVertex2i(-8, 170);
        glVertex2i(-17, 170);
        glVertex2i(-17, 160);
    glEnd();

    glFlush ();
}

void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-320.0, 320.0, -240.0, 240.0);
}

  main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (640, 480);
    glutInitWindowPosition (200, 150);
    glutCreateWindow ("Ship");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}

