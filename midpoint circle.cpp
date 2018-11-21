#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

int initialX,initialY,finalX,finalY,length,xIncrement,yIncrement,d,incE,incSE,radius;

void plot(int x,int y){
    glPointSize(1);
    glBegin(GL_POINTS);
        glVertex2i(x+initialX, y+initialY);
    glEnd();
}
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    int x = 0;
	int y = radius;
	float d = 5/4 - radius;

    plot(x,y);
    plot(-x,y);
    plot(x,-y);
    plot(-x,-y);

    plot(y,x);
    plot(-y,x);
    plot(y,-x);
    plot(-y,-x);

    while(y>x){
        if(d<0){
            d+= 2*x+1;
        }else{
            d+= 2*(x-y)+1;
            y--;
        }
        x++;
        plot(x,y);
        plot(-x,y);
        plot(x,-y);
        plot(-x,-y);

        plot(y,x);
        plot(-y,x);
        plot(y,-x);
        plot(-y,-x);
    }


    glFlush ();
}
void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-400.0, 400.0, -200.0, 200.0);
}

main(int argc, char** argv)
{
    printf("Enter Initial X Value: ");
    scanf("%d",&initialX);
    printf("Enter Initial Y Value: ");
    scanf("%d",&initialY);
    printf("Enter Radius Value: ");
    scanf("%d",&radius);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 400);
    glutInitWindowPosition (200,0);
    glutCreateWindow ("Circle Mid Point");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
