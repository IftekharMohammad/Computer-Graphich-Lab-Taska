#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>

using namespace std;

//Initializes 3D rendering
void initRendering() {
	glEnable(GL_DEPTH_TEST);
}
//Called when the window is resized
void handleResize(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float _angle1 = 30.0f;
//float _move = 0.0f;


void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
	glLoadIdentity(); //Reset the drawing perspective
	glMatrixMode(GL_MODELVIEW);

   // glRotatef(_angle, 1.0f, 0.0f, 0.0f); //Rotate the camera
///////////////////// Earth ///////////////////////////
    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.8, 0.0, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(0.0,1.0,0.7);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///////////////////// Orbit ///////////////////////////
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);

	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.8;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///////////////////// SUN ///////////////////////////
    glPushMatrix();
        glColor3f(1.0,0.0,0.0);
        glutSolidSphere(.3,50,50);
    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.8, 0.0, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(0.0,1.0,0.7);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.10;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();
///////////////////// Orbit ///////////////////////////
    glPushMatrix();

    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.5;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();


    //sub

    glPushMatrix();
    glRotatef(-_angle1, 0.0, 0.0, 1.0);
    glTranslatef(0.25,0.43, 0.0);
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.15;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(-_angle1 - 30, 0.0, 0.0, 1.0);
	glTranslatef(0.0, 0.5, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0.7);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.08;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();




//moon
    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(-_angle1-30, 0.0, 0.0, 1.0);
	glTranslatef(0.15, 0.5, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0.7);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.06;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}
	glEnd();
    glPopMatrix();

	glutSwapBuffers();
}

void update(int value) {

	_angle1 += 2.0f;
	if (_angle1 > 360) {
		_angle1 -= 360;
	}

	glutPostRedisplay(); //Tell GLUT that the display has changed

	//Tell GLUT to call update again in 25 milliseconds
	glutTimerFunc(25, update, 0);
}

int main(int argc, char** argv) {
	//Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 800);

	//Create the window
	glutCreateWindow("Transformation");
	initRendering();

	//Set handler functions
	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}









