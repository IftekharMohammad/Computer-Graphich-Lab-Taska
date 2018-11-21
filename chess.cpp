#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>

void myDisplay(void)
{
int a=0;
int b=0;
int f=255;
int g=0;
glClear (GL_COLOR_BUFFER_BIT);
glPointSize(100);
for(int i=0;i<8;i++){
    for(int j=0;j<8;j++){
        if(j%2==0){
            glColor3ub (f,f,f);
        }else{
            glColor3ub (g,g,g);
        }
        glBegin(GL_POINTS);
            glVertex2i(50+a, 50+b);
            //printf("X:%d,Y:%d\n",a,b);
        glEnd();
        a+=100;
    }
    a=0;
    b+=100;
    int temp=f;
    f=g;
    g=temp;
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
gluOrtho2D(0.0, 800.0, 0.0, 800.0);
}

main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (800, 800);
glutInitWindowPosition (0,0);
glutCreateWindow ("my first attempt");
glutDisplayFunc(myDisplay);
myInit ();
glutMainLoop();
}

