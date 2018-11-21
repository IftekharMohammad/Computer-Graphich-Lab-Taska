#include <iostream>
#include <stdlib.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<cstring>
using namespace std;
void update(int);
float _angle1 = 30.0f;
float speed = 0.0f;
float savedSpeed = 0.0f;
bool paused = false;
char mercury[] = "Mercury";
char venus[] = "Venus";
char earth[] = "Earth";
char mars[] = "Mars";
char name[] = "Iftekhar Mohammad";
char id[] = "16-31115-1";
char t[] = "End";


//Print
void Sprint( float x, float y, char *st)
{
    int l,i;


    l=strlen( st ); // see how many characters are in text string.
    glColor3f(1.0,1.0,0.7);
    //glDisable(GL_LIGHTING);
    glRasterPos2f( x, y); // location to start printing text
    for( i=0; i < l; i++) // loop until i is greater then l
    {
       glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

    }


}/*
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
*/
void specialKeys(int key, int x, int y) {
    switch (key) {
      case GLUT_KEY_UP:
          speed+=0.05f;
          update(0);
          break;
      case GLUT_KEY_DOWN:
          speed-=0.05f;
          update(0);
          break;
    }
}
void keyboard(unsigned char key, int x, int y) {
//find key codes: https://www.cambiaresearch.com/articles/15/javascript-char-codes-key-codes
   switch (key) {
      case 27:     // ESC key
         exit(0);
         break;
      case 77:
          speed+=0.05f;
          update(0);
          break;
      /*case GLUT_KEY_DOWN:
          speed-=0.05f;
          update(0);
          break;*/
   }
}
void mouse(int button, int state, int x, int y) {
   if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) { // Pause/resume
      paused = !paused;         // Toggle state
      if (paused) {
         savedSpeed = speed;  // Save parameters for restore later
         speed = 0;            // Stop movement

      } else {
         speed = savedSpeed;  // Restore parameters

      }
   }
}
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
	glTranslatef(0.75, 0.3, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0.7);
	Sprint(-0.02,0.15,mars);
	glColor3f(1.0,0.0,0.0);
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


    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(0.3, 0.5, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0.7);
	Sprint(-0.02,0.15,earth);
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.09;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}

	glEnd();
    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(-0.2, 0.35, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0.7);
	Sprint(-0.02,0.15,venus);
	glColor3f(0.0,0.0,1.0);
	glBegin(GL_POLYGON);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.07;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );
	}

	glEnd();
    glPopMatrix();


    glPushMatrix(); //Save the current state of transformations
	 //Move to the center of the triangle
	glRotatef(_angle1, 0.0, 0.0, 1.0);
	glTranslatef(-0.1, -0.16, 0.0);//Rotate about the the vector (1, 2, 3)
	glColor3f(1.0,1.0,0.7);
	Sprint(-0.01,-0.10,mercury);
	glColor3f(1.0,1.0,1.0);
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



///////////////////// Orbit ///////////////////////////
    glPushMatrix();
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.2;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );

	}

	glEnd();
    glPopMatrix();

        glPushMatrix();
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.4;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );

	}

	glEnd();
    glPopMatrix();

        glPushMatrix();
    glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINES);
	for(int i=0;i<200;i++)
	{
		float pi=3.1416;
		float A=(i*2*pi)/50 ;
		float r=0.6;
		float x = r * cos(A);
		float y = r * sin(A);
		glVertex2f(x,y );

	}

	glEnd();
    glPopMatrix();

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
        glutSolidSphere(.1,50,50);
        Sprint(-0.9,0.9,name);
		Sprint(-0.9,0.8,id);
    glPopMatrix();

    /*glPushMatrix();
        Sprint(.9,.9,text);
    glPopMatrix();
*/
	glutSwapBuffers();
}

void update(int value) {
    if(speed>1 || speed<0)
    {
        //cout<<speed<<endl;
        speed = 0.0f;
    }
	_angle1 -= speed;
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

	//Set handler functions
	glutDisplayFunc(drawScene);

	glutSpecialFunc(specialKeys); //Special Key Handler
	glutKeyboardFunc(keyboard);   //Basic keyboard key handler
	glutMouseFunc(mouse);         //Mouse Handler

	glutTimerFunc(25, update, 0); //Add a timer

	glutMainLoop();
	return 0;
}
