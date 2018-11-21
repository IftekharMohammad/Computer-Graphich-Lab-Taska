#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

int initialX,initialY,finalX,finalY,length,xIncrement,yIncrement,d,incE,incNE;
void swap (int* a, int* b){

    int x;
    x = *a;
    *a = *b;
    *b = x;

}

void plot(int x,int y){
    glPointSize(1);
    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();
}
void myDisplay(void)
{
    glClear (GL_COLOR_BUFFER_BIT);
    xIncrement = finalX-initialX;
    yIncrement = finalY-initialY;
    d=2*yIncrement-xIncrement;
    incE = 2*yIncrement;
    incNE = 2*(yIncrement-xIncrement);

    plot(initialX,initialY);

    while(initialX<finalX){
        initialX++;
        if(d<0){
            d=d+incE;
        }else{
            d=d+incNE;
            initialY++;
        }
        plot(initialX,initialY);
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
    printf("Enter Final X Value: ");
    scanf("%d",&finalX);
    printf("Enter Final Y Value: ");
    scanf("%d",&finalY);
    if(initialX>finalX){
        swap(&initialX,&finalX);
    }
    if(initialY>finalY){
        swap(&initialY,&finalY);
    }

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (800, 400);
    glutInitWindowPosition (200,0);
    glutCreateWindow ("my first attempt");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}
