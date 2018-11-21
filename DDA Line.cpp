#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

int initialX,initialY,finalX,finalY,length;
void plot(int x,int y){
    glPointSize(1);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    double xIncrement,yIncrement;
    length= abs(finalX-initialX);
    if(abs(finalY-initialY)>length){
        length = abs(finalY-initialY);
    }

    xIncrement = (finalX-initialX)/length;
    yIncrement = (finalY-initialY)/length;

    for(int i=0;i<length;i++){
        plot(round(initialX),round(initialY));
        initialX=initialX+xIncrement;
        initialY=initialY+yIncrement;
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
    gluOrtho2D(-400.0, 400.0, -400.0, 400.0);
}

main(int argc, char** argv)
{
    printf("Enter Initial X Value: ");
    scanf("%d",&initialX);
    printf("Enter Initial Y Value: ");
    scanf("%d",&initialY);
    printf("Enter Final X Value: ");
    scanf("%d",&finalX);
    printf("Enter Final Y Value: ");
    scanf("%d",&finalY);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 800);
    glutInitWindowPosition (200,200);
    glutCreateWindow ("my first attempt");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
