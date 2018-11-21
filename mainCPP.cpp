#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
float t=0.0;
int n=2;
float arrX1[3]={-70,0,-70};
float arrY1[3]={70,10,-60};

float arrX2[3]={70,0,70};
float arrY2[3]={70,10,-60};


float arrX3[3]={70,0,70};
float arrY3[3]={70,10,-60};

int factorial(int n)
{
  return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

float returnX(float t,int n,float arrX[]){
    float valX=0;
    for(int i=0;i<=n;i++){
        valX+=(factorial(n)/(factorial(i)*factorial(n-i)))* pow((1-t),(n-i))* pow(t,i)* arrX[i];
    }
    return valX;
}

float returnY(float t,int n,float arrY[]){
    float valY=0;
    for(int i=0;i<=n;i++){
        valY+=(factorial(n)/(factorial(i)*factorial(n-i)))* pow((1-t),(n-i))* pow(t,i)*arrY[i];
    }
    return valY;
}

void myDisplay(void){
    glClear (GL_COLOR_BUFFER_BIT);
    glColor3ub (0, 0, 0);
    glBegin(GL_POINTS);
        while(t<=1){
            glVertex2f(returnX(t,n,arrX1),returnY(t,n,arrY1));
            t+=0.01;
        }
        t=0;
        while(t<=1){
            glVertex2f(returnX(t,n,arrX2),returnY(t,n,arrY2));
            t+=0.01;
        }

        t=0;
        while(t<=1){
            glVertex2f(returnX(t,n,arrX3),returnY(t,n,arrY3));
            t+=0.01;
        }
    glEnd();
    glFlush();

}
void myInit (void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glPointSize(5);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-330, 330, -240, 240);
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (660, 480);
    glutInitWindowPosition (0,0);
    glutCreateWindow ("my first attempt");
    glutDisplayFunc(myDisplay);
    myInit ();
    glutMainLoop();
}


