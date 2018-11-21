#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
    int a;
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (0, 0, 0);
    glPointSize(11);
    glLineWidth(10);
//background
    glBegin(GL_LINES);
        glVertex2i(-150, 30);
        glVertex2i(-150, -30);
    glEnd();
    a=0;
    for(int i=0;i<6;i++){
        glColor3ub (0, 0, 0);
        glBegin(GL_LINES);
            glVertex2i(-140+a, 40+a);
            glVertex2i(-140+a, -40-a);
        glEnd();
        a+=10;
    }
    a=0;
    for(int i=0;i<6;i++){
        glColor3ub (139, 253, 13);
        glBegin(GL_LINES);
            glVertex2i(-140+a, 30+a);
            glVertex2i(-140+a, -30-a);
        glEnd();
        a+=10;
    }


    a=0;
    for(int i=0;i<17;i++){
        glColor3ub (0, 0, 0);
        glBegin(GL_LINES);
            glVertex2i(-80+a, 100);
            glVertex2i(-80+a, -100);
        glEnd();
        a+=10;
    }
    a=0;
    for(int i=0;i<17;i++){
        glColor3ub (139, 253, 13);
        glBegin(GL_LINES);
            glVertex2i(-80+a, 90);
            glVertex2i(-80+a, -90);
        glEnd();
        a+=10;
    }


    glColor3ub (0, 0, 0);
    glBegin(GL_LINES);
        glVertex2i(150, 30);
        glVertex2i(150, -30);
    glEnd();

    a=0;
    for(int i=0;i<6;i++){
        glColor3ub (0, 0, 0);
        glBegin(GL_LINES);
            glVertex2i(140-a, 40+a);
            glVertex2i(140-a, -40-a);
        glEnd();
        a+=10;
    }
    a=0;
    for(int i=0;i<6;i++){
        glColor3ub (139, 253, 13);
        glBegin(GL_LINES);
            glVertex2i(140-a, 30+a);
            glVertex2i(140-a, -30-a);
        glEnd();
        a+=10;
    }
//background end

    glColor3ub (0, 0, 0);
    a=0;
    for(int i=0;i<6;i++){
        glBegin(GL_LINES);
            glVertex2i(-130+a, 20+a);
            glVertex2i(-130+a, -20-a);
        glEnd();
        a+=10;
    }
    glBegin(GL_LINES);
        glVertex2i(-70, 70);
        glVertex2i(-70, -70);
    glEnd();

    glBegin(GL_POINTS);
        glVertex2i(-60, 64);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(-60, 30);
        glVertex2i(-60, -80);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(-50, 20);
        glVertex2i(-50, -60);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(-40, 20);
        glVertex2i(-40, -50);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(-30, 30);
        glVertex2i(-30, -40);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(-20, 80);
        glVertex2i(-20, -50);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(-10, 70);
        glVertex2i(-10, -70);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(0, 70);
        glVertex2i(0, -80);
    glEnd();



    glBegin(GL_LINES);
        glVertex2i(10, 70);
        glVertex2i(10, -70);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(20, 80);
        glVertex2i(20, -50);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(30, 30);
        glVertex2i(30, -40);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(40, 20);
        glVertex2i(40, -50);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(50, 20);
        glVertex2i(50, -60);
    glEnd();
    glBegin(GL_LINES);
        glVertex2i(60, 30);
        glVertex2i(60, -80);
    glEnd();
    glBegin(GL_POINTS);
        glVertex2i(60, 64);
    glEnd();

    glBegin(GL_LINES);
        glVertex2i(70, 70);
        glVertex2i(70, -70);
    glEnd();
    a=0;
    for(int i=0;i<6;i++){
        glBegin(GL_LINES);
            glVertex2i(130-a, 20+a);
            glVertex2i(130-a, -20-a);
        glEnd();
        a+=10;
    }
    glFlush ();
}
void myInit (void)
{
glClearColor(1.0, 1.0, 1.0, 0.0);
glColor3f(0.0f, 0.0f, 0.0f);
glPointSize(100);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-330, 330, -240, 240);
}

main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (660, 480);
glutInitWindowPosition (0,0);
glutCreateWindow ("my first attempt");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}
