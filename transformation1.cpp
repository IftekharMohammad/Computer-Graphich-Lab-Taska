#include <stdio.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
int edges=4,scalePoint;
int points[2][4],transformed[2][4],tFactor[2];
int resultantArr[3][3];
void matrixMult(int arr1 [3][3],int arr2[3][3]){
    int k=0;
    for(int i=0;i<3;i++){
        int res = 0;
        for(int j=0;j<3;j++){
            res+=arr1[i][j]*arr2[j][i];
        }
        int p = k%3;
        resultantArr[i][p] = res;
        k++;
    }
}

void myDisplay(void)
{
    glPointSize(1);
    glClear (GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        for(int i=0;i<edges;i++){
            glVertex2i(points[0][i],points[1][i]);
        }
    glEnd();

    glBegin(GL_POLYGON);
        for(int i=0;i<edges;i++){
            glVertex2i(transformed[0][i],transformed[1][i]);
        }
    glEnd();
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
    int options;
    printf("Enter Your Choice: \n1.Translation\n2.Scaling\n3.Exit\n");
    scanf("%d",&options);

        switch(options){
        case 1:
            //printf("Enter Number of edges: ");
            //scanf("%d",&edges);

            for(int i=0;i<edges;i++){
                printf("Enter the coordinate of vertex %d: ",i+1);
                scanf("%d %d",&points[0][i],&points[1][i]);
            }

            printf("Enter the Translation factor of x and y :");
            scanf("%d %d",&tFactor[0],&tFactor[1]);

            for(int i=0;i<edges;i++){
                transformed[0][i] = points[0][i] + tFactor[0];
                transformed[1][i] = points[1][i] + tFactor[1];
            }
            glutDisplayFunc(myDisplay);
            break;
        case 2:
            {
            int trn[3][3] = {{1,0,-5},{0,1,-2},{0,0,1}};
            int scl[3][3] = {{2,0,0},{0,2,0},{0,0,1}};
            int revTrn[3][3] = {{1,0,5},{0,1,2},{0,0,1}};
            int ptn[3][3] = {{0,1,5},{0,1,2},{0,0,0}};
            matrixMult(scl,trn);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("%d ",resultantArr[i][j]);
                }
                printf("\n");
            }
            matrixMult(resultantArr,revTrn);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("%d ",resultantArr[i][j]);
                }
                printf("\n");
            }
            matrixMult(resultantArr,ptn);
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    printf("%d ",resultantArr[i][j]);
                }
                printf("\n");
            }
            //glutDisplayFunc(myDisplay);
            break;
            }
        case 3:
            return 0;
            break;
        default:
            break;
        }
        glutInit(&argc, argv);
        glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize (800, 400);
        glutInitWindowPosition (200,0);
        glutCreateWindow ("Transformation");
        myInit();
        glutMainLoop();
}
