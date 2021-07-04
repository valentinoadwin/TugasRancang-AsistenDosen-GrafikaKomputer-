/*
 * GLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone
 * and torus shapes in GLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

#include <windows.h>
#include <gl/glut.h>

 void init(void);
void tampil(void);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
void mouse(int button, int state, int x, int y);
void mouseMotion(int x, int y);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;

int is_depth;

float xmov = 0.0f;
float ymov = 0.0f;
float zmov = 0.0f;

void idle()
{
    if (!mouseDown)
    {
        xrot += 0.3f;
        yrot += 0.4f;
    }
glutPostRedisplay();
}

void mouse(int button, int state, int x, int y)
{
    if (button == GLUT_LEFT_BUTTON && state ==GLUT_DOWN)
    {
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y)
{
    if (mouseDown)
    {
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
}

void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
    case 'W':
        zmov += 3.0;
        break;
    case 'd':
    case 'D':
        xmov -= 3.0;
        break;
    case 's':
    case 'S':
        zmov -= 3.0;
        break;
    case 'a':
    case 'A':
        xmov += 3.0;
        break;
    case '7':
        ymov += 3.0;
        break;
    case '9':
        ymov -= 3.0;
        break;
    case '2':
        glRotatef(2.0, 1.0, 0.0, 0.0);
        break;
    case '8':
        glRotatef(-2.0, 1.0, 0.0, 0.0);
        break;
    case '6':
        glRotatef(2.0, 0.0, 1.0, 0.0);
        break;
    case '4':
        glRotatef(-2.0, 0.0, 1.0, 0.0);
        break;
    case '1':
        glRotatef(2.0, 0.0, 0.0, 1.0);
        break;
    case '3':
        glRotatef(-2.0, 0.0, 0.0, 1.0);
        break;
    case '5':
        if (is_depth)
        {
            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

void init(void)
{
    glClearColor (0.70,0.70,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(20.0);
    glLineWidth(9.0f);
}

void tampil(void)
{
    if (is_depth){
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }
    else{
        glClear(GL_COLOR_BUFFER_BIT);
    }
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
    glRotatef(xrot, 1.0f, 0.0f, 0.0f);
    glRotatef(yrot, 0.0f, 1.0f, 0.0f);

    glTranslatef(xmov, ymov, zmov);
    glPushMatrix();

//lantai1
	//dinding belakang
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(60.0, 0.0, -40.0 );
    glVertex3f(60.0, 10.0, -40.0);
    glVertex3f(35.0, 10.0, -40.0 );
    glVertex3f(35.0, 0.0, -40.0 );
    glEnd();
    //variasi dinding belakang
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(38.0, 0.0, -40.1 );
    glVertex3f(38.0, 10.0, -40.1);
    glVertex3f(38.4, 10.0, -40.1 );
    glVertex3f(38.4, 0.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(41.8, 0.0, -40.1 );
    glVertex3f(41.8, 10.0, -40.1);
    glVertex3f(42.2, 10.0, -40.1 );
    glVertex3f(42.2, 0.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(46.6, 0.0, -40.1 );
    glVertex3f(46.6, 10.0, -40.1);
    glVertex3f(47.0, 10.0, -40.1 );
    glVertex3f(47.0, 0.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(50.4, 0.0, -40.1 );
    glVertex3f(50.4, 10.0, -40.1);
    glVertex3f(50.8, 10.0, -40.1 );
    glVertex3f(50.8, 0.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(53.2, 0.0, -40.1 );
    glVertex3f(53.2, 10.0, -40.1);
    glVertex3f(53.6, 10.0, -40.1 );
    glVertex3f(53.6, 0.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(56.0, 0.0, -40.1 );
    glVertex3f(56.0, 10.0, -40.1);
    glVertex3f(56.4, 10.0, -40.1 );
    glVertex3f(56.4, 0.0, -40.1);
    glEnd();
 //diding belakang mundur dikit karena dindingnya terlalu cantik
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(35.0, 0.0, -40.0 );
    glVertex3f(35.0, 10.0, -40.0 );
    glVertex3f(35.0, 10.0, -36.0);
    glVertex3f(35.0, 0.0, -36.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(35.0, 0.0,  -36.0);
    glVertex3f(35.0, 10.0, -36.0);
    glVertex3f(25, 10.0, -36.0);
    glVertex3f(25.0, 0.0, -36.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(25.0, 0.0, -36.0);
    glVertex3f(25.0, 28.0, -36.0);
    glVertex3f(25.0, 28.0, -40.0);
    glVertex3f(25.0, 0.0, -40.0);
    glEnd();

    // blakang nongol dikit
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 0.0, -40.0);
    glVertex3f(25.0, 28.0, -40.0);
    glVertex3f(10.0, 28.0, -40.0);
    glVertex3f(10.0, 0.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(4.0,4.0,4.0);
    glVertex3f(25.5, 28.0, -40.5);
    glVertex3f(25.5, 28.0, -36.0);
    glVertex3f(9.5, 28.0, -36.0);
    glVertex3f(9.5, 28.0, -40.5);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(10.0, 0.0, -40.0);
    glVertex3f(10.0, 28.0, -40.0);
    glVertex3f(10.0, 28.0,-36.0);
    glVertex3f(10.0, 0.0, -36.0);
    glEnd();

    // kotak didepan dinding blakang nongol dikit
    glBegin(GL_QUADS);
    glColor3f(4.0, 4.0, 4.0);
    glVertex3f(25.0, 0.0, -43.0);
    glVertex3f(25.0, 5.0, -43.0);
    glVertex3f(0.0, 5.0, -43.0);
    glVertex3f(0.0, 0.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(4.0, 4.0, 4.0);
    glVertex3f(25.0, 0.0, -41.0);
    glVertex3f(25.0, 5.0, -41.0);
    glVertex3f(0.0, 5.0, -41.0);
    glVertex3f(0.0, 0.0, -41.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 5.0, -43.0);
    glVertex3f(25.0, 5.0, -41.0);
    glVertex3f(0.0, 5.0, -41.0);
    glVertex3f(0.0, 5.0, -43.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(0.0, 0.0, -43.0);
    glVertex3f(0.0, 5.0, -43.0);
    glVertex3f(0.0, 5.0,-41.0);
    glVertex3f(0.0, 0.0, -41.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 0.0, -43.0);
    glVertex3f(25.0, 5.0, -43.0);
    glVertex3f(25.0, 5.0,-41.0);
    glVertex3f(25.0, 0.0, -41.0);
    glEnd();



// bagian kaca
    glBegin(GL_QUADS);
    glColor3f(1.5,5.0,4.0);
    glVertex3f(10.0, 0.0, -36.0);
    glVertex3f(10.0, 30.0, -36.0);
    glVertex3f(-6.0, 30.0, -36.0);
    glVertex3f(1.0, 0.0, -36.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(1.0, 0.0, -36.0);
    glVertex3f(-6.0, 30.0, -36.0);
    glVertex3f(-6.0 ,30.0, -42.0);
    glVertex3f(1.0, 0.0 , -42);
    glEnd();

 //kiri
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(1.0, 0.0, -40);
    glVertex3f(-1.2, 10.0, -40.0);
    glVertex3f(-25, 10.0,-40.0);
    glVertex3f(-25, 0.0, -40.0);
    glEnd();

    //samping kiri
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(-25.0, 0.0, -40.0);
    glVertex3f(-25.0, 10.0, -40.0);
    glVertex3f(-25.0, 10.0, 60.0);
    glVertex3f(-25.0, 0.0, 60.0);
    glEnd();

    //depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(-25.0, 0.0, 60.0);
    glVertex3f(-25.0, 10.0, 60.0);
    glVertex3f(-1.2, 10.0, 60.0);
    glVertex3f(1.0, 0.0, 60.0);
    glEnd();

     //depan masuk kaca
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(1.0, 0.0, 60.0);
    glVertex3f(-6.4, 31.5, 60.0);
    glVertex3f(-6.4, 31.5, 56.0);
    glVertex3f(1.0, 0.0, 56.0);
    glEnd();

     //atap kaca
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(-6.4, 31.5, 60.0);
    glVertex3f(-6.4, 31.5, 56.0);
    glVertex3f(11, 31.5, 56.0);
    glVertex3f(11, 31.5, 60.0);
    glEnd();

     // kacadepan
    glBegin(GL_QUADS);
    glColor3f(0.4, 2.0, 3.0);
    glVertex3f(1.0, 0.0, 56.0);
    glVertex3f(-6.4, 31.5, 56.0);
    glVertex3f(10.0, 31.5, 56.0);
    glVertex3f(10.0, 0.0, 56.);
    glEnd();

    //kaca keluar
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(10.0, 0.0, 56.0);
    glVertex3f(10.0, 31.5, 56.0);
    glVertex3f(10.0, 31.5, 60.0);
    glVertex3f(10.0, 0.0, 60.0);
    glEnd();

    // tembok depan
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(10.0, 0.0, 60.0);
    glVertex3f(10.0, 30.0, 60.0);
    glVertex3f(25.0, 30.0, 60.0);
    glVertex3f(25.0, 0.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(25.0, 0.0, 60.0);
    glVertex3f(25.0, 30.0, 60.0);
    glVertex3f(25.0, 30.0, 56.0);
    glVertex3f(25.0, 0.0, 56.0);
    glEnd();
    //garis tembok dpn
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(10.0, 8.5, 60.1);
    glVertex3f(10.0, 8.9, 60.1);
    glVertex3f(25.0, 8.9, 60.1);
    glVertex3f(25.0, 8.5, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(10.0, 17.5, 60.1);
    glVertex3f(10.0, 17.9, 60.1);
    glVertex3f(25.0, 17.9, 60.1);
    glVertex3f(25.0, 17.5, 60.1);
    glEnd();



    //tembok ada jendela
    glBegin(GL_QUADS);
    glColor3f(0.70, 0.70, 0.70);
    glVertex3f(25.0, 0.0, 56.0);
    glVertex3f(25.0, 30.0, 56.0);
    glVertex3f(35.0, 30.0, 56.0);
    glVertex3f(35.0, 0.0, 56.0);
    glEnd();

    // samping tembok
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(35.0, 0.0, 56.0);
    glVertex3f(35.0, 30.0, 56.0);
    glVertex3f(35.0, 30.0, 60.0);
    glVertex3f(35.0, 0.0, 60.0);
    glEnd();

    //4
	glBegin(GL_QUADS);
 	glColor3f(1.5,1.0,0.8);
    glVertex3f(-13.5, 10.0, -43.0);
    glVertex3f(-13.5, 30.0, -43.0);
    glVertex3f(-16.0, 30.0, -40.0);
    glVertex3f(-16.0, 10.0, -40.0);
    glEnd();
    	glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-13.5, 13.0, -43.1);
    glVertex3f(-13.5, 13.4, -43.1);
    glVertex3f(-16.0, 13.4, -40.1);
    glVertex3f(-16.0, 13.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-13.5, 16.8, -43.1);
    glVertex3f(-13.5, 17.2, -43.1);
    glVertex3f(-16.0, 17.2, -40.1);
    glVertex3f(-16.0, 16.8, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-13.5, 20.6, -43.1);
    glVertex3f(-13.5, 21.0, -43.1);
    glVertex3f(-16.0, 21.0, -40.1);
    glVertex3f(-16.0, 20.6, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-13.5, 24.4, -43.1);
    glVertex3f(-13.5, 24.8, -43.1);
    glVertex3f(-16.0, 24.8, -40.1);
    glVertex3f(-16.0, 24.4, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-13.5, 27.2, -43.1);
    glVertex3f(-13.5, 27.6, -43.1);
    glVertex3f(-16.0, 27.6, -40.1);
    glVertex3f(-16.0, 27.2, -40.1);
    glEnd();


    glBegin(GL_QUADS);
 	glColor3f(1.5,1.0,0.8);
    glVertex3f(-10.0, 10.0, -40.0);
    glVertex3f(-10.0, 30.0, -40.0);
    glVertex3f(-13.0, 30.0, -43.0);
    glVertex3f(-13.0, 10.0, -43.0);
    glEnd();
        glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-10.0, 13.0, -40.1);
    glVertex3f(-10.0, 13.4, -40.1);
    glVertex3f(-13.0, 13.4, -43.1);
    glVertex3f(-13.0, 13.0, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-10.0, 16.8, -40.1);
    glVertex3f(-10.0, 17.2, -40.1);
    glVertex3f(-13.0, 17.2, -43.1);
    glVertex3f(-13.0, 16.8, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-10.0, 20.6, -40.1);
    glVertex3f(-10.0, 21.0, -40.1);
    glVertex3f(-13.0, 21.0, -43.1);
    glVertex3f(-13.0, 20.6, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-10.0, 24.4, -40.1);
    glVertex3f(-10.0, 24.8, -40.1);
    glVertex3f(-13.0, 24.8, -43.1);
    glVertex3f(-13.0, 24.4, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-10.0, 27.2, -40.1);
    glVertex3f(-10.0, 27.6, -40.1);
    glVertex3f(-13.0, 27.6, -43.1);
    glVertex3f(-13.0, 27.2, -43.1);
    glEnd();


//5
	glBegin(GL_QUADS);
 	glColor3f(1.5,1.0,0.8);
    glVertex3f(-7.0, 10.0, -43.0);
    glVertex3f(-7.0, 30.0, -43.0);
    glVertex3f(-9.5, 30.0, -40.0);
    glVertex3f(-9.5, 10.0, -40.0);
    glEnd();
        glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-7.0, 13.0, -43.1);
    glVertex3f(-7.0, 13.4, -43.1);
    glVertex3f(-9.5, 13.4, -40.1);
    glVertex3f(-9.5, 13.0, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-7.0, 16.8, -43.1);
    glVertex3f(-7.0, 17.2, -43.1);
    glVertex3f(-9.5, 17.2, -40.1);
    glVertex3f(-9.5, 16.8, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-7.0, 20.6, -43.1);
    glVertex3f(-7.0, 21.0, -43.1);
    glVertex3f(-9.5, 21.0, -40.1);
    glVertex3f(-9.5, 20.6, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-7.0, 24.4, -43.1);
    glVertex3f(-7.0, 24.8, -43.1);
    glVertex3f(-9.5, 24.8, -40.1);
    glVertex3f(-9.5, 24.4, -40.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-7.0, 27.2, -43.1);
    glVertex3f(-7.0, 27.6, -43.1);
    glVertex3f(-9.5, 27.6, -40.1);
    glVertex3f(-9.5, 27.2, -40.1);
    glEnd();

	glBegin(GL_QUADS);
 	glColor3f(1.5,1.0,0.8);
    glVertex3f(-1.5, 10.0, -40.0);
    glVertex3f(-6.0, 30.0, -40.0);
    glVertex3f(-6.5, 30.0, -43.0);
    glVertex3f(-6.5, 10.0, -43.0);
    glEnd();
        glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-1.5, 13.0, -40.1);
    glVertex3f(-6.0, 13.4, -40.1);
    glVertex3f(-6.5, 13.4, -43.1);
    glVertex3f(-6.5, 13.0, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-2.5, 16.8, -40.1);
    glVertex3f(-6.0, 17.2, -40.1);
    glVertex3f(-6.5, 17.2, -43.1);
    glVertex3f(-6.5, 16.8, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-3.5, 20.6, -40.1);
    glVertex3f(-7.0, 21.0, -40.1);
    glVertex3f(-5.5, 21.0, -43.1);
    glVertex3f(-5.5, 20.6, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-4.5, 24.4, -40.1);
    glVertex3f(-7.7, 24.8, -40.1);
    glVertex3f(-5.5, 24.8, -43.1);
    glVertex3f(-5.5, 24.4, -43.1);
    glEnd();
    glBegin(GL_QUADS);
 	glColor3f(0.4,0.3,0.2);
    glVertex3f(-5.3, 27.2, -40.1);
    glVertex3f(-7.7, 27.6, -40.1);
    glVertex3f(-5.5, 27.6, -43.1);
    glVertex3f(-5.5, 27.2, -43.1);
    glEnd();



    // samping kiri
    glBegin(GL_QUADS);
    glColor3f(1.5, 1.0, 0.8);
    glVertex3f(-37.0, 10.0, -40.0);
    glVertex3f(-37.0, 30.0, -40.0);
    glVertex3f(-37.0 ,30.0, 60.0);
    glVertex3f(-37.0, 10.0, 60.0);
    glEnd();
    //variasi samping kiri atas
     glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 13.0, -40.0);
    glVertex3f(-37.1, 13.4, -40.0);
    glVertex3f(-37.1 ,13.4, 60.0);
    glVertex3f(-37.1, 13.0, 60.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 16.8, -40.0);
    glVertex3f(-37.1, 17.2, -40.0);
    glVertex3f(-37.1 ,17.2, 60.0);
    glVertex3f(-37.1, 16.8, 60.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 19.6, -40.0);
    glVertex3f(-37.1, 20.0, -40.0);
    glVertex3f(-37.1 ,20.0, 60.0);
    glVertex3f(-37.1, 19.6, 60.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 19.6, -40.0);
    glVertex3f(-37.1, 20.0, -40.0);
    glVertex3f(-37.1 ,20.0, 60.0);
    glVertex3f(-37.1, 19.6, 60.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 23.4, -40.0);
    glVertex3f(-37.1, 23.8, -40.0);
    glVertex3f(-37.1 ,23.8, 60.0);
    glVertex3f(-37.1, 23.4, 60.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 27.2, -40.0);
    glVertex3f(-37.1, 27.6, -40.0);
    glVertex3f(-37.1 ,27.6, 60.0);
    glVertex3f(-37.1, 27.2, 60.0);
    glEnd();


 glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -36.5);
    glVertex3f(-37.1, 30.0, -36.5);
    glVertex3f(-37.1 ,30.0, -37.0);
    glVertex3f(-37.1, 10.0, -37.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -31.5);
    glVertex3f(-37.1, 30.0, -31.5);
    glVertex3f(-37.1 ,30.0, -32.0);
    glVertex3f(-37.1, 10.0, -32.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -26.5);
    glVertex3f(-37.1, 30.0, -26.5);
    glVertex3f(-37.1 ,30.0, -27.0);
    glVertex3f(-37.1, 10.0, -27.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -21.5);
    glVertex3f(-37.1, 30.0, -21.5);
    glVertex3f(-37.1 ,30.0, -22.0);
    glVertex3f(-37.1, 10.0, -22.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -16.5);
    glVertex3f(-37.1, 30.0, -16.5);
    glVertex3f(-37.1 ,30.0, -17.0);
    glVertex3f(-37.1, 10.0, -17.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -11.5);
    glVertex3f(-37.1, 30.0, -11.5);
    glVertex3f(-37.1 ,30.0, -12.0);
    glVertex3f(-37.1, 10.0, -12.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -6.5);
    glVertex3f(-37.1, 30.0, -6.5);
    glVertex3f(-37.1 ,30.0, -7.0);
    glVertex3f(-37.1, 10.0, -7.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, -1.5);
    glVertex3f(-37.1, 30.0, -1.5);
    glVertex3f(-37.1 ,30.0, -2.0);
    glVertex3f(-37.1, 10.0, -2.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 3.5);
    glVertex3f(-37.1, 30.0, 3.5);
    glVertex3f(-37.1 ,30.0, 3.0);
    glVertex3f(-37.1, 10.0, 3.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 7.5);
    glVertex3f(-37.1, 30.0, 7.5);
    glVertex3f(-37.1 ,30.0, 7.0);
    glVertex3f(-37.1, 10.0, 7.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 12.5);
    glVertex3f(-37.1, 30.0, 12.5);
    glVertex3f(-37.1 ,30.0, 12.0);
    glVertex3f(-37.1, 10.0, 12.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 17.5);
    glVertex3f(-37.1, 30.0, 17.5);
    glVertex3f(-37.1 ,30.0, 17.0);
    glVertex3f(-37.1, 10.0, 17.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 22.5);
    glVertex3f(-37.1, 30.0, 22.5);
    glVertex3f(-37.1 ,30.0, 22.0);
    glVertex3f(-37.1, 10.0, 22.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 27.5);
    glVertex3f(-37.1, 30.0, 27.5);
    glVertex3f(-37.1 ,30.0, 27.0);
    glVertex3f(-37.1, 10.0, 27.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 32.5);
    glVertex3f(-37.1, 30.0, 32.5);
    glVertex3f(-37.1 ,30.0, 32.0);
    glVertex3f(-37.1, 10.0, 32.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 37.5);
    glVertex3f(-37.1, 30.0, 37.5);
    glVertex3f(-37.1 ,30.0, 37.0);
    glVertex3f(-37.1, 10.0, 37.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 42.5);
    glVertex3f(-37.1, 30.0, 42.5);
    glVertex3f(-37.1 ,30.0, 42.0);
    glVertex3f(-37.1, 10.0, 42.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 47.5);
    glVertex3f(-37.1, 30.0, 47.5);
    glVertex3f(-37.1 ,30.0, 47.0);
    glVertex3f(-37.1, 10.0, 47.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 52.5);
    glVertex3f(-37.1, 30.0, 52.5);
    glVertex3f(-37.1 ,30.0, 52.0);
    glVertex3f(-37.1, 10.0, 52.0);
    glEnd();
glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-37.1, 10.0, 57.5);
    glVertex3f(-37.1, 30.0, 57.5);
    glVertex3f(-37.1 ,30.0, 57.0);
    glVertex3f(-37.1, 10.0, 57.0);
    glEnd();



      // samping kiri bawah
    glBegin(GL_QUADS);
    glColor3f(0.6,0.3,0.1);
    glVertex3f(-25.0, 10.0, -40.0);
    glVertex3f(-37.0, 10.0, -40.0);
    glVertex3f(-37.0 ,10.0, 60.0);
    glVertex3f(-25.0, 10.0, 60.0);
    glEnd();

    // depan kiri
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-37.0, 10.0, 60.0);
    glVertex3f(-37.0, 30.0, 60.0);
    glVertex3f(-6.0, 30.0, 60.00);
    glVertex3f(-1.2, 10.0, 60.0);
    glEnd();
    // variasi lekukkan depan kiri
    //1
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-37.0, 10.0, 60.0);
    glVertex3f(-37.0, 30.0, 60.0);
    glVertex3f(-32.0, 30.0, 63.0);
    glVertex3f(-32.0, 10.0, 63.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-37.0, 13.0, 60.1);
    glVertex3f(-37.0, 13.4, 60.1);
    glVertex3f(-32.0, 13.4, 63.1);
    glVertex3f(-32.0, 13.0, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-37.0, 16.8, 60.1);
    glVertex3f(-37.0, 17.2, 60.1);
    glVertex3f(-32.0, 17.2, 63.1);
    glVertex3f(-32.0, 16.8, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-37.0, 20.6, 60.1);
    glVertex3f(-37.0, 21.0, 60.1);
    glVertex3f(-32.0, 21.0, 63.1);
    glVertex3f(-32.0, 20.6, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-37.0, 24.4, 60.1);
    glVertex3f(-37.0, 24.8, 60.1);
    glVertex3f(-32.0, 24.8, 63.1);
    glVertex3f(-32.0, 24.4, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-37.0, 27.2, 60.1);
    glVertex3f(-37.0, 27.6, 60.1);
    glVertex3f(-32.0, 27.6, 63.1);
    glVertex3f(-32.0, 27.2, 63.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-31.5, 10.0, 63.0);
    glVertex3f(-31.5, 30.0, 63.0);
    glVertex3f(-28.5, 30.0, 60.0);
    glVertex3f(-28.5, 10.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-31.5, 13.0, 63.1);
    glVertex3f(-31.5, 13.4, 63.1);
    glVertex3f(-28.5, 13.4, 60.1);
    glVertex3f(-28.5, 13.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-31.5, 16.8, 63.1);
    glVertex3f(-31.5, 17.2, 63.1);
    glVertex3f(-28.5, 17.2, 60.1);
    glVertex3f(-28.5, 16.8, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-31.5, 20.6, 63.1);
    glVertex3f(-31.5, 21.0, 63.1);
    glVertex3f(-28.5, 21.0, 60.1);
    glVertex3f(-28.5, 20.6, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-31.5, 24.4, 63.1);
    glVertex3f(-31.5, 24.8, 63.1);
    glVertex3f(-28.5, 24.8, 60.1);
    glVertex3f(-28.5, 24.4, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-31.5, 27.2, 63.1);
    glVertex3f(-31.5, 27.6, 63.1);
    glVertex3f(-28.5, 27.6, 60.1);
    glVertex3f(-28.5, 27.2, 60.1);
    glEnd();

    //2
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-28.0, 10.0, 60.0);
    glVertex3f(-28.0, 30.0, 60.0);
    glVertex3f(-25.5, 30.0, 63.0);
    glVertex3f(-25.5, 10.0, 63.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-28.0, 13.0, 60.1);
    glVertex3f(-28.0, 13.4, 60.1);
    glVertex3f(-25.5, 13.4, 63.1);
    glVertex3f(-25.5, 13.0, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-28.0, 16.8, 60.1);
    glVertex3f(-28.0, 17.2, 60.1);
    glVertex3f(-25.5, 17.2, 63.1);
    glVertex3f(-25.5, 16.8, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-28.0, 20.6, 60.1);
    glVertex3f(-28.0, 21.0, 60.1);
    glVertex3f(-25.5, 21.0, 63.1);
    glVertex3f(-25.5, 20.6, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-28.0, 24.4, 60.1);
    glVertex3f(-28.0, 24.8, 60.1);
    glVertex3f(-25.5, 24.8, 63.1);
    glVertex3f(-25.5, 24.4, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-28.0, 27.2, 60.1);
    glVertex3f(-28.0, 27.6, 60.1);
    glVertex3f(-25.5, 27.6, 63.1);
    glVertex3f(-25.5, 27.2, 63.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-25.0, 10.0, 63.0);
    glVertex3f(-25.0, 30.0, 63.0);
    glVertex3f(-23.0, 30.0, 60.0);
    glVertex3f(-23.0, 10.0, 60.0);
    glEnd();
       glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-25.0, 13.0, 63.1);
    glVertex3f(-25.0, 13.4, 63.1);
    glVertex3f(-23.0, 13.4, 60.1);
    glVertex3f(-23.0, 13.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-25.0, 16.8, 63.1);
    glVertex3f(-25.0, 17.2, 63.1);
    glVertex3f(-23.0, 17.2, 60.1);
    glVertex3f(-23.0, 16.8, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-25.0, 20.6, 63.1);
    glVertex3f(-25.0, 21.0, 63.1);
    glVertex3f(-23.0, 21.0, 60.1);
    glVertex3f(-23.0, 20.6, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-25.0, 24.4, 63.1);
    glVertex3f(-25.0, 24.8, 63.1);
    glVertex3f(-23.0, 24.8, 60.1);
    glVertex3f(-23.0, 24.4, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-25.0, 27.2, 63.1);
    glVertex3f(-25.0, 27.6, 63.1);
    glVertex3f(-23.0, 27.6, 60.1);
    glVertex3f(-23.0, 27.2, 60.1);
    glEnd();

    //3
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-22.5, 10.0, 60.0);
    glVertex3f(-22.5, 30.0, 60.0);
    glVertex3f(-19.0, 30.0, 63.0);
    glVertex3f(-19.0, 10.0, 63.0);
    glEnd();
      glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.5, 13.0, 60.1);
    glVertex3f(-22.5, 13.4, 60.1);
    glVertex3f(-19.0, 13.4, 63.1);
    glVertex3f(-19.0, 13.0, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.5, 16.8, 60.1);
    glVertex3f(-22.5, 17.2, 60.1);
    glVertex3f(-19.0, 17.2, 63.1);
    glVertex3f(-19.0, 16.8, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.5, 20.6, 60.1);
    glVertex3f(-22.5, 21.0, 60.1);
    glVertex3f(-19.0, 21.0, 63.1);
    glVertex3f(-19.0, 20.6, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.5, 24.4, 60.1);
    glVertex3f(-22.5, 24.8, 60.1);
    glVertex3f(-19.0, 24.8, 63.1);
    glVertex3f(-19.0, 24.4, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-22.5, 27.2, 60.1);
    glVertex3f(-22.5, 27.6, 60.1);
    glVertex3f(-19.0, 27.6, 63.1);
    glVertex3f(-19.0, 27.2, 63.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-18.5, 10.0, 63.0);
    glVertex3f(-18.5, 30.0, 63.0);
    glVertex3f(-16.5, 30.0, 60.0);
    glVertex3f(-16.5, 10.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-18.5, 13.0, 63.1);
    glVertex3f(-18.5, 13.4, 63.1);
    glVertex3f(-16.5, 13.4, 60.1);
    glVertex3f(-16.5, 13.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-18.5, 16.8, 63.1);
    glVertex3f(-18.5, 17.2, 63.1);
    glVertex3f(-16.5, 17.2, 60.1);
    glVertex3f(-16.5, 16.8, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-18.5, 20.6, 63.1);
    glVertex3f(-18.5, 21.0, 63.1);
    glVertex3f(-16.5, 21.0, 60.1);
    glVertex3f(-16.5, 20.6, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-18.5, 24.4, 63.1);
    glVertex3f(-18.5, 24.8, 63.1);
    glVertex3f(-16.5, 24.8, 60.1);
    glVertex3f(-16.5, 24.4, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-18.5, 27.2, 63.1);
    glVertex3f(-18.5, 27.6, 63.1);
    glVertex3f(-16.5, 27.6, 60.1);
    glVertex3f(-16.5, 27.2, 60.1);
    glEnd();

    //4
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-16.0, 10.0, 60.0);
    glVertex3f(-16.0, 30.0, 60.0);
    glVertex3f(-13.5, 30.0, 63.0);
    glVertex3f(-13.5, 10.0, 63.0);
    glEnd();
       glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-16.0, 13.0, 60.1);
    glVertex3f(-16.0, 13.4, 60.1);
    glVertex3f(-13.5, 13.4, 63.1);
    glVertex3f(-13.5, 13.0, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-16.0, 16.8, 60.1);
    glVertex3f(-16.0, 17.2, 60.1);
    glVertex3f(-13.5, 17.2, 63.1);
    glVertex3f(-13.5, 16.8, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-16.0, 20.6, 60.1);
    glVertex3f(-16.0, 21.0, 60.1);
    glVertex3f(-13.5, 21.0, 63.1);
    glVertex3f(-13.5, 20.6, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-16.0, 24.4, 60.1);
    glVertex3f(-16.0, 24.8, 60.1);
    glVertex3f(-13.5, 24.8, 63.1);
    glVertex3f(-13.5, 24.4, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-16.0, 27.2, 60.1);
    glVertex3f(-16.0, 27.6, 60.1);
    glVertex3f(-13.5, 27.6, 63.1);
    glVertex3f(-13.5, 27.2, 63.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-13.0, 10.0, 63.0);
    glVertex3f(-13.0, 30.0, 63.0);
    glVertex3f(-10.0, 30.0, 60.0);
    glVertex3f(-10.0, 10.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-13.0, 13.0, 63.1);
    glVertex3f(-13.0, 13.4, 63.1);
    glVertex3f(-10.0, 13.4, 60.1);
    glVertex3f(-10.0, 13.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-13.0, 16.8, 63.1);
    glVertex3f(-13.0, 17.2, 63.1);
    glVertex3f(-10.0, 17.2, 60.1);
    glVertex3f(-10.0, 16.8, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-13.0, 20.6, 63.1);
    glVertex3f(-13.0, 21.0, 63.1);
    glVertex3f(-10.0, 21.0, 60.1);
    glVertex3f(-10.0, 20.6, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-13.0, 24.4, 63.1);
    glVertex3f(-13.0, 24.8, 63.1);
    glVertex3f(-10.0, 24.8, 60.1);
    glVertex3f(-10.0, 24.4, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-13.0, 27.2, 63.1);
    glVertex3f(-13.0, 27.6, 63.1);
    glVertex3f(-10.0, 27.6, 60.1);
    glVertex3f(-10.0, 27.2, 60.1);
    glEnd();

    //terakhir
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-9.5, 10.0, 60.0);
    glVertex3f(-9.5, 30.0, 60.0);
    glVertex3f(-7.0, 30.0, 63.0);
    glVertex3f(-7.0, 10.0, 63.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-9.5, 13.0, 60.1);
    glVertex3f(-9.5, 13.4, 60.1);
    glVertex3f(-7.0, 13.4, 63.1);
    glVertex3f(-7.0, 13.0, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-9.5, 16.8, 60.1);
    glVertex3f(-9.5, 17.2, 60.1);
    glVertex3f(-7.0, 17.2, 63.1);
    glVertex3f(-7.0, 16.8, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-9.5, 20.6, 60.1);
    glVertex3f(-9.5, 21.0, 60.1);
    glVertex3f(-7.0, 21.0, 63.1);
    glVertex3f(-7.0, 20.6, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-9.5, 24.4, 60.1);
    glVertex3f(-9.5, 24.8, 60.1);
    glVertex3f(-7.0, 24.8, 63.1);
    glVertex3f(-7.0, 24.4, 63.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-9.5, 27.2, 60.1);
    glVertex3f(-9.5, 27.6, 60.1);
    glVertex3f(-7.0, 27.6, 63.1);
    glVertex3f(-7.0, 27.2, 63.1);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(-6.5, 10.0, 63.0);
    glVertex3f(-6.5, 30.0, 63.0);
    glVertex3f(-6.0, 30.0, 60.0);
    glVertex3f(-1.5, 10.0, 60.0);
    glEnd();
  glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-6.5, 13.0, 63.1);
    glVertex3f(-6.5, 13.4, 63.1);
    glVertex3f(-6.0, 13.4, 60.1);
    glVertex3f(-1.5, 13.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-6.5, 16.8, 63.1);
    glVertex3f(-6.5, 17.2, 63.1);
    glVertex3f(-6.0, 17.2, 60.1);
    glVertex3f(-2.5, 16.8, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.5, 20.6, 63.1);
    glVertex3f(-5.5, 21.0, 63.1);
    glVertex3f(-7.0 , 21.0, 60.1);
    glVertex3f(-3.5, 20.6, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.5, 24.4, 63.1);
    glVertex3f(-5.5, 24.8, 63.1);
    glVertex3f(-7.7, 24.8, 60.1);
    glVertex3f(-4.5, 24.4, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-5.5, 27.2, 63.1);
    glVertex3f(-5.5, 27.6, 63.1);
    glVertex3f(-7.7, 27.6, 60.1);
    glVertex3f(-5.3, 27.2, 60.1);
    glEnd();

     // kanan depan
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(35.0, 10.0, 60.0);
    glVertex3f(35.0, 30.0, 60.0);
    glVertex3f(60.0, 30.0, 60.0);
    glVertex3f(60.0, 10.0, 60.0);
    glEnd();

    //tutup kanan depan
    glBegin(GL_QUADS);
    glColor3f(0.4,0.3,0.2);
    glVertex3f(60.0, 10.0, 57.0);
    glVertex3f(35.0, 10.0, 57.0);
    glVertex3f(35.0, 10.0, 60.0);
    glVertex3f(60.0, 10.0, 60.0);
    glEnd();


    //samping kanan
    glBegin(GL_QUADS);
    glColor3f(1.5, 1.0, 0.8);
    glVertex3f(60.0, 10.0, 60.0);
    glVertex3f(60.0, 30.0, 60.0);
    glVertex3f(60.0, 30.0, -40.0);
    glVertex3f(60.0, 10.0, -40.0);
    glEnd();
    //variasi kanan atas
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 13.0, 60.0);
    glVertex3f(60.1, 13.4, 60.0);
    glVertex3f(60.1, 13.4, -40.0);
    glVertex3f(60.1, 13.0, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 16.8, 60.0);
    glVertex3f(60.1, 17.2, 60.0);
    glVertex3f(60.1, 17.2, -40.0);
    glVertex3f(60.1, 16.8, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 19.6, 60.0);
    glVertex3f(60.1, 20.0, 60.0);
    glVertex3f(60.1, 20.0, -40.0);
    glVertex3f(60.1, 19.6, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 23.4, 60.0);
    glVertex3f(60.1, 23.8, 60.0);
    glVertex3f(60.1, 23.8, -40.0);
    glVertex3f(60.1, 23.4, -40.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 27.2, 60.0);
    glVertex3f(60.1, 27.6, 60.0);
    glVertex3f(60.1, 27.6, -40.0);
    glVertex3f(60.1, 27.2, -40.0);

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -36.5);
    glVertex3f(60.1, 30.0, -36.5);
    glVertex3f(60.1, 30.0, -37.0);
    glVertex3f(60.1, 10.0, -37.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -31.5);
    glVertex3f(60.1, 30.0, -31.5);
    glVertex3f(60.1, 30.0, -32.0);
    glVertex3f(60.1, 10.0, -32.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -26.5);
    glVertex3f(60.1, 30.0, -26.5);
    glVertex3f(60.1, 30.0, -27.0);
    glVertex3f(60.1, 10.0, -27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -21.5);
    glVertex3f(60.1, 30.0, -21.5);
    glVertex3f(60.1, 30.0, -22.0);
    glVertex3f(60.1, 10.0, -22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -16.5);
    glVertex3f(60.1, 30.0, -16.5);
    glVertex3f(60.1, 30.0, -17.0);
    glVertex3f(60.1, 10.0, -17.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -11.5);
    glVertex3f(60.1, 30.0, -11.5);
    glVertex3f(60.1, 30.0, -12.0);
    glVertex3f(60.1, 10.0, -12.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -6.5);
    glVertex3f(60.1, 30.0, -6.5);
    glVertex3f(60.1, 30.0, -7.0);
    glVertex3f(60.1, 10.0, -7.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, -1.5);
    glVertex3f(60.1, 30.0, -1.5);
    glVertex3f(60.1, 30.0, -2.0);
    glVertex3f(60.1, 10.0, -2.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 3.5);
    glVertex3f(60.1, 30.0, 3.5);
    glVertex3f(60.1, 30.0, 3.0);
    glVertex3f(60.1, 10.0, 3.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 7.5);
    glVertex3f(60.1, 30.0, 7.5);
    glVertex3f(60.1, 30.0, 7.0);
    glVertex3f(60.1, 10.0, 7.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 12.5);
    glVertex3f(60.1, 30.0, 12.5);
    glVertex3f(60.1, 30.0, 12.0);
    glVertex3f(60.1, 10.0, 12.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 17.5);
    glVertex3f(60.1, 30.0, 17.5);
    glVertex3f(60.1, 30.0, 17.0);
    glVertex3f(60.1, 10.0, 17.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 22.5);
    glVertex3f(60.1, 30.0, 22.5);
    glVertex3f(60.1, 30.0, 22.0);
    glVertex3f(60.1, 10.0, 22.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 27.5);
    glVertex3f(60.1, 30.0, 27.5);
    glVertex3f(60.1, 30.0, 27.0);
    glVertex3f(60.1, 10.0, 27.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 32.5);
    glVertex3f(60.1, 30.0, 32.5);
    glVertex3f(60.1, 30.0, 32.0);
    glVertex3f(60.1, 10.0, 32.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 37.5);
    glVertex3f(60.1, 30.0, 37.5);
    glVertex3f(60.1, 30.0, 37.0);
    glVertex3f(60.1, 10.0, 37.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 42.5);
    glVertex3f(60.1, 30.0, 42.5);
    glVertex3f(60.1, 30.0, 42.0);
    glVertex3f(60.1, 10.0, 42.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 47.5);
    glVertex3f(60.1, 30.0, 47.5);
    glVertex3f(60.1, 30.0, 47.0);
    glVertex3f(60.1, 10.0, 47.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 52.5);
    glVertex3f(60.1, 30.0, 52.5);
    glVertex3f(60.1, 30.0, 52.0);
    glVertex3f(60.1, 10.0, 52.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.1, 10.0, 57.5);
    glVertex3f(60.1, 30.0, 57.5);
    glVertex3f(60.1, 30.0, 57.0);
    glVertex3f(60.1, 10.0, 57.0);
    glEnd();
     //tutup atap
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(60.0, 30.0, -40.0);
    glVertex3f(35.0, 30.0, -40.0);
    glVertex3f(35.0, 30.0, 60.0);
    glVertex3f(60.0, 30.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(25.0, 30.0, 56.0);
    glVertex3f(35.0, 30.0, 56.0);
    glVertex3f(35.0 ,30.0, -36.0);
    glVertex3f(25.0, 30.0, -36.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(25.0, 30.0, 60.0);
    glVertex3f(25.0, 30.0, -36.0);
    glVertex3f(10.0 ,30.0, -36.0);
    glVertex3f(10.0, 30.0, 60.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(10.0, 30.0, 56.0);
    glVertex3f(10.0, 30.0, -36.0);
    glVertex3f(-6.0, 30.0, -36.0);
    glVertex3f(-6.0, 30.0, 56.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,1.0,1.0);
    glVertex3f(-6.0, 30.0, 60.0);
    glVertex3f(-37.0, 30.0, 60.0);
    glVertex3f(-37.0, 30.0, -40.0);
    glVertex3f(-6.0, 30.0, -40.0);
    glEnd();

    //HALAMAN
    glBegin(GL_QUADS);
    glColor3f(1.0, 1.0, 1.0);
    glVertex3f(120.0, -1.0, -120.0);
    glVertex3f(-120.0, -1.0, -120.0);
    glVertex3f(-120.0, -1.0, 120.0);
    glVertex3f(120.0, -1.0, 120.0);
    glEnd();
    //RUMPUT
    glBegin(GL_QUADS);
    glColor3f(0.5, 5.0, 0.5);
    glVertex3f(62.0, 0.0, 62.0);
    glVertex3f(-32.0, 0.0, 62.0);
    glVertex3f(-32.0, 0.0, 100.0);
    glVertex3f(62.0, 0.0, 100.0);
    glEnd();



//lantai gedung pernikahan valen
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(60.0, 0.0, -40.0);
    glVertex3f(35.0, 0.0, -40.0);
    glVertex3f(35.0, 0.0, 62.0);
    glVertex3f(60.0, 0.0, 62.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(25.0, 0.0, 62.0);
    glVertex3f(35.0, 0.0, 62.0);
    glVertex3f(35.0 ,0.0, -36.0);
    glVertex3f(25.0, 0.0, -36.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(25.0, 0.0, 62.0);
    glVertex3f(25.0, 0.0, -40.0);
    glVertex3f(10.0 ,0.0, -40.0);
    glVertex3f(10.0, 0.0, 62.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(10.0, 0.0, 62.0);
    glVertex3f(10.0, 0.0, -36.0);
    glVertex3f(-6.0, 0.0, -36.0);
    glVertex3f(-6.0, 0.0, 62.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.50, 0.50, 0.50);
    glVertex3f(-6.0, 0.0, 62.0);
    glVertex3f(-25.0, 0.0, 62.0);
    glVertex3f(-25.0, 0.0, -40.0);
    glVertex3f(-6.0, 0.0, -40.0);
    glEnd();

 //VARIASI JENDELA
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 23.0, 56.01);
    glVertex3f(32.0, 26.0, 56.01);
    glVertex3f(34.0, 26.0, 56.01);
    glVertex3f(34.0, 23.0, 56.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 26.0, 56.01);
    glVertex3f(32.0, 29.0, 56.01);
    glVertex3f(34.0, 29.0, 56.01);
    glVertex3f(34.0, 26.0, 56.01);
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 26.0, 56.1);
    glVertex3f(32.0, 26.4, 56.1);
    glVertex3f(34.0, 26.4, 56.1);
    glVertex3f(34.0, 26.0, 56.1);
    glEnd();
    //variasi frame jendela1
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 23.0, 56.1);
    glVertex3f(32.0, 23.4, 56.1);
    glVertex3f(34.0, 23.4, 56.1);
    glVertex3f(34.0, 23.0, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 28.8, 56.1);
    glVertex3f(32.0, 29.0, 56.1);
    glVertex3f(34.0, 29.0, 56.1);
    glVertex3f(34.0, 28.8, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 23.0, 56.1);
    glVertex3f(32.0, 29.0, 56.1);
    glVertex3f(32.4, 29.0, 56.1);
    glVertex3f(32.4, 23.0, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(33.8, 23.0, 56.1);
    glVertex3f(33.8, 29.0, 56.1);
    glVertex3f(34.0, 29.0, 56.1);
    glVertex3f(34.0, 23.0, 56.1);
    glEnd();

    //Jendela 2
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 13.0, 56.01);
    glVertex3f(32.0, 16.0, 56.01);
    glVertex3f(34.0, 16.0, 56.01);
    glVertex3f(34.0, 13.0, 56.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 16.0, 56.01);
    glVertex3f(32.0, 19.0, 56.01);
    glVertex3f(34.0, 19.0, 56.01);
    glVertex3f(34.0, 16.0, 56.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 16.0, 56.1);
    glVertex3f(32.0, 16.4, 56.1);
    glVertex3f(34.0, 16.4, 56.1);
    glVertex3f(34.0, 16.0, 56.1);
    glEnd();
    //frame jendela2
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 13.0, 56.1);
    glVertex3f(32.0, 13.4, 56.1);
    glVertex3f(34.0, 13.4, 56.1);
    glVertex3f(34.0, 13.0, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 18.8, 56.1);
    glVertex3f(32.0, 19.0, 56.1);
    glVertex3f(34.0, 19.0, 56.1);
    glVertex3f(34.0, 18.8, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 13.0, 56.1);
    glVertex3f(32.0, 19.0, 56.1);
    glVertex3f(32.4, 19.0, 56.1);
    glVertex3f(32.4, 13.0, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(33.8, 13.0, 56.1);
    glVertex3f(33.8, 19.0, 56.1);
    glVertex3f(34.0, 19.0, 56.1);
    glVertex3f(34.0, 13.0, 56.1);
    glEnd();
    //Jendela3
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 1.5, 56.01);
    glVertex3f(32.0, 3.0, 56.01);
    glVertex3f(34.0, 3.0, 56.01);
    glVertex3f(34.0, 1.5, 56.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 3.0, 56.01);
    glVertex3f(32.0, 6.0, 56.01);
    glVertex3f(34.0, 6.0, 56.01);
    glVertex3f(34.0, 3.0, 56.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(32.0, 6.0, 56.01);
    glVertex3f(32.0, 9.0, 56.01);
    glVertex3f(34.0, 9.0, 56.01);
    glVertex3f(34.0, 6.0, 56.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 3.5, 56.1);
    glVertex3f(32.0, 3.9, 56.1);
    glVertex3f(34.0, 3.9, 56.1);
    glVertex3f(34.0, 3.5, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 6.5, 56.1);
    glVertex3f(32.0, 6.9, 56.1);
    glVertex3f(34.0, 6.9, 56.1);
    glVertex3f(34.0, 6.5, 56.1);
    glEnd();
    //variasi frame jendela3
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 1.5, 56.1);
    glVertex3f(32.0, 1.9, 56.1);
    glVertex3f(34.0, 1.9, 56.1);
    glVertex3f(34.0, 1.5, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 8.8, 56.1);
    glVertex3f(32.0, 9.0, 56.1);
    glVertex3f(34.0, 9.0, 56.1);
    glVertex3f(34.0, 8.8, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(32.0, 1.5, 56.1);
    glVertex3f(32.0, 9.0, 56.1);
    glVertex3f(32.4, 9.0, 56.1);
    glVertex3f(32.4, 1.5, 56.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(33.8, 1.5, 56.1);
    glVertex3f(33.8, 9.0, 56.1);
    glVertex3f(34.0, 9.0, 56.1);
    glVertex3f(34.0, 1.5, 56.1);
    glEnd();

     // JENDELA DEPAN BAWAH KIRI
    glBegin(GL_QUADS);
    glColor3f(0.5, 5.0, 6.0);
    glVertex3f(-23.0, 0.0, 60.01);
    glVertex3f(-23.0, 10.0, 60.01);
    glVertex3f(-20.0, 10.0, 60.01);
    glVertex3f(-20.0, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(-19.8, 0.0, 60.01);
    glVertex3f(-19.8, 10.0, 60.01);
    glVertex3f(-16.8, 10.0, 60.01);
    glVertex3f(-16.8, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(-16.6, 0.0, 60.01);
    glVertex3f(-16.6, 10.0, 60.01);
    glVertex3f(-13.6, 10.0, 60.01);
    glVertex3f(-13.6, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(-13.4, 0.0, 60.01);
    glVertex3f(-13.4, 10.0, 60.01);
    glVertex3f(-10.4, 10.0, 60.01);
    glVertex3f(-10.4, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.4, 4.0, 5.0);
    glVertex3f(-10.2, 0.0, 60.01);
    glVertex3f(-10.2, 10.0, 60.01);
    glVertex3f(-7.2, 10.0, 60.01);
    glVertex3f(-7.2, 0.0, 60.01);
    glEnd();

    // frame
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-23.4, 0.0, 60.01);
    glVertex3f(-23.4, 10.0, 60.01);
    glVertex3f(-23.0, 10.0, 60.01);
    glVertex3f(-23.0, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-19.8, 0.0, 60.01);
    glVertex3f(-19.8, 10.0, 60.01);
    glVertex3f(-20.0, 10.0, 60.01);
    glVertex3f(-20.0, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-16.6, 0.0, 60.01);
    glVertex3f(-16.6, 10.0, 60.01);
    glVertex3f(-16.8, 10.0, 60.01);
    glVertex3f(-16.8, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 00);
    glVertex3f(-13.4, 0.0, 60.01);
    glVertex3f(-13.4, 10.0, 60.01);
    glVertex3f(-13.6, 10.0, 60.01);
    glVertex3f(-13.6, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-10.2, 0.0, 60.01);
    glVertex3f(-10.2, 10.0, 60.01);
    glVertex3f(-10.4, 10.0, 60.01);
    glVertex3f(-10.4, 0.0, 60.01);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-7.0, 0.0, 60.01);
    glVertex3f(-7.0, 10.0, 60.01);
    glVertex3f(-7.2, 10.0, 60.01);
    glVertex3f(-7.2, 0.0, 60.01);
    glEnd();

    // frame kaca depan
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.4, 2.0, 56.02);
    glVertex3f(0.4, 2.2, 56.02);
    glVertex3f(10.0, 2.2, 56.02);
    glVertex3f(10.0, 2.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.1, 4.0, 56.02);
    glVertex3f(0.1, 4.2, 56.02);
    glVertex3f(10.0, 4.2, 56.02);
    glVertex3f(10.0, 4.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.6, 6.0, 56.02);
    glVertex3f(-0.6, 6.2, 56.02);
    glVertex3f(10.0, 6.2, 56.02);
    glVertex3f(10.0, 6.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 00);
    glVertex3f(-0.8, 8.0, 56.02);
    glVertex3f(-0.8, 8.2, 56.02);
    glVertex3f(10.0, 8.2, 56.02);
    glVertex3f(10.0, 8.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 10.0, 56.02);
    glVertex3f(-1.0, 10.2, 56.02);
    glVertex3f(10.0, 10.2, 56.02);
    glVertex3f(10.0, 10.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.6, 12.0, 56.02);
    glVertex3f(-1.6, 12.2, 56.02);
    glVertex3f(10.0, 12.2, 56.02);
    glVertex3f(10.0, 12.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.8, 14.0, 56.02);
    glVertex3f(-1.8, 14.2, 56.02);
    glVertex3f(10.0, 14.2, 56.02);
    glVertex3f(10.0, 14.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.6, 16.0, 56.02);
    glVertex3f(-2.6, 16.2, 56.02);
    glVertex3f(10.0, 16.2, 56.02);
    glVertex3f(10.0, 16.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.8, 18.0, 56.02);
    glVertex3f(-2.8, 18.2, 56.02);
    glVertex3f(10.0, 18.2, 56.02);
    glVertex3f(10.0, 18.0, 56.02);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-3.7, 20.0, 56.02);
    glVertex3f(-3.7, 20.2, 56.02);
    glVertex3f(10.0, 20.2, 56.02);
    glVertex3f(10.0, 20.0, 56.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-4.3, 22.0, 56.02);
    glVertex3f(-4.3, 22.2, 56.02);
    glVertex3f(10.0, 22.2, 56.02);
    glVertex3f(10.0, 22.0, 56.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-4.7, 24.0, 56.02);
    glVertex3f(-4.7, 24.2, 56.02);
    glVertex3f(10.0, 24.2, 56.02);
    glVertex3f(10.0, 24.0, 56.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 26.0, 56.02);
    glVertex3f(-5.0, 26.2, 56.02);
    glVertex3f(10.0, 26.2, 56.02);
    glVertex3f(10.0, 26.0, 56.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.5, 28.0, 56.02);
    glVertex3f(-5.5, 28.2, 56.02);
    glVertex3f(10.0, 28.2, 56.02);
    glVertex3f(10.0, 28.0, 56.02);
    glEnd();

     //frame depan kanan
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(38.0, 0, 57.1);
    glVertex3f(38.0, 10.0, 57.1);
    glVertex3f(38.4, 10.0, 57.1);
    glVertex3f(38.4, 0, 57.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(41.8, 0, 57.1);
    glVertex3f(41.8, 10.0, 57.1);
    glVertex3f(42.2, 10.0, 57.1);
    glVertex3f(42.2, 0, 57.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(45.6, 0, 57.1);
    glVertex3f(45.6, 10.0, 57.1);
    glVertex3f(46.0, 10.0, 57.1);
    glVertex3f(46.0, 0, 57.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(49.4, 0, 57.1);
    glVertex3f(49.4, 10.0, 57.1);
    glVertex3f(49.8, 10.0, 57.1);
    glVertex3f(49.8, 0, 57.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(53.2, 0, 57.1);
    glVertex3f(53.2, 10.0, 57.1);
    glVertex3f(53.6, 10.0, 57.1);
    glVertex3f(53.6, 0, 57.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(56.0, 0, 57.1);
    glVertex3f(56.0, 10.0, 57.1);
    glVertex3f(56.4, 10.0, 57.1);
    glVertex3f(56.4, 0, 57.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.65, 0.65, 0.65);
    glVertex3f(59.8, 0, 57.1);
    glVertex3f(59.8, 10.0, 57.1);
    glVertex3f(60.0, 10.0, 57.1);
    glVertex3f(60.0, 0, 60.1);
    glEnd();

    //frame depan kanan atas vertikal
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(38.0, 10.0, 60.1);
    glVertex3f(38.0, 30.0, 60.1);
    glVertex3f(38.4, 30.0, 60.1);
    glVertex3f(38.4, 10.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(41.8, 10.0, 60.1);
    glVertex3f(41.8, 30.0, 60.1);
    glVertex3f(42.2, 30.0, 60.1);
    glVertex3f(42.2, 10.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(45.6, 10.0, 60.1);
    glVertex3f(45.6, 30.0, 60.1);
    glVertex3f(46.0, 30.0, 60.1);
    glVertex3f(46.0, 10.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(49.4, 10.0, 60.1);
    glVertex3f(49.4, 30.0, 60.1);
    glVertex3f(49.8, 30.0, 60.1);
    glVertex3f(49.8, 10.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(53.2, 10.0, 60.1);
    glVertex3f(53.2, 30.0, 60.1);
    glVertex3f(53.6, 30.0, 60.1);
    glVertex3f(53.6, 10.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(56.0, 10.0, 60.1);
    glVertex3f(56.0, 30.0, 60.1);
    glVertex3f(56.4, 30.0, 60.1);
    glVertex3f(56.4, 10.0, 60.1);
    glEnd();
     glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(59.8, 10.0, 60.1);
    glVertex3f(59.8, 30.0, 60.1);
    glVertex3f(60.0, 30.0, 60.1);
    glVertex3f(60.0, 10.0, 60.1);
    glEnd();

    //frame kanan depan horizontal
     glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(35.0, 13.0, 60.1);
    glVertex3f(35.0, 13.4, 60.1);
    glVertex3f(60.0, 13.4, 60.1);
    glVertex3f(60.0, 13.0, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(35.0, 16.8, 60.1);
    glVertex3f(35.0, 17.2, 60.1);
    glVertex3f(60.0, 17.2, 60.1);
    glVertex3f(60.0, 16.8, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(35.0, 20.6, 60.1);
    glVertex3f(35.0, 21.0, 60.1);
    glVertex3f(60.0, 21.0, 60.1);
    glVertex3f(60.0, 20.6, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(35.0, 24.4, 60.1);
    glVertex3f(35.0, 24.8, 60.1);
    glVertex3f(60.0, 24.8, 60.1);
    glVertex3f(60.0, 24.4, 60.1);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0, 0, 0);
    glVertex3f(35.0, 27.8, 60.1);
    glVertex3f(35.0, 28.2, 60.1);
    glVertex3f(60.0, 28.2, 60.1);
    glVertex3f(60.0, 27.8, 60.1);
    glEnd();

    // frame jendela kiri bawah


//PERABOTAN
//Meja
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 5.0, -10.0);
    glVertex3f(25.0, 5.0, 0.0);
    glVertex3f(0.0, 5.0, 0.0);
    glVertex3f(0.0, 5.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(0.0, 0.0, -10.0);
    glVertex3f(0.0, 5.0, -10.0);
    glVertex3f(0.0, 5.0, 0.0);
    glVertex3f(0.0, 0.0, 00);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 0.0, -10.0);
    glVertex3f(25.0, 5.0, -10.0);
    glVertex3f(25.0, 5.0, 0.0);
    glVertex3f(25.0, 0.0, 0.0);
    glEnd();
    // rak buku
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.0, -30.0);
    glVertex3f(60.0, 10.0, -30.0);
    glVertex3f(55.0, 10.0, -30.0);
    glVertex3f(55.0, 0.0, -30.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.0, -25.0);
    glVertex3f(60.0, 10.0, -25.0);
    glVertex3f(55.0, 10.0, -25.0);
    glVertex3f(55.0, 0.0, -25.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.0, -20.0);
    glVertex3f(60.0, 10.0, -20.0);
    glVertex3f(55.0, 10.0, -20.0);
    glVertex3f(55.0, 0.0, -20.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.0, -15.0);
    glVertex3f(60.0, 10.0, -15.0);
    glVertex3f(55.0, 10.0, -15.0);
    glVertex3f(55.0, 0.0, -15.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 0.0, -10.0);
    glVertex3f(60.0, 10.0, -10.0);
    glVertex3f(55.0, 10.0, -10.0);
    glVertex3f(55.0, 0.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 10.0, -30.0);
    glVertex3f(55.0, 10.0, -30.0);
    glVertex3f(55.0, 10.0, -10.0);
    glVertex3f(60.0, 10.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(60.0, 5.0, -30.0);
    glVertex3f(55.0, 5.0, -30.0);
    glVertex3f(55.0, 5.0, -10.0);
    glVertex3f(60.0, 5.0, -10.0);
    glEnd();

    // acc
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(60.0, 27.0, 0.0);
    glVertex3f(57.0, 27.0, 0.0);
    glVertex3f(57.0, 27.0, -10.0);
    glVertex3f(60.0, 27.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(57.0, 27.0, 0.0);
    glVertex3f(55.0, 25.0, 0.0);
    glVertex3f(55.0, 25.0, -10.0);
    glVertex3f(57.0, 27.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(55.0, 25.0, 0.0);
    glVertex3f(55.0, 24.0, 0.0);
    glVertex3f(55.0, 24.0, -10.0);
    glVertex3f(55.0, 25.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(54.8, 24.6, 0.0);
    glVertex3f(54.8, 24.3, 0.0);
    glVertex3f(54.8, 24.3, -10.0);
    glVertex3f(54.8, 24.6, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(60.0, 24.0, 0.0);
    glVertex3f(55.0, 24.0, 0.0);
    glVertex3f(55.0, 24.0, -10.0);
    glVertex3f(60.0, 24.0, -10.0);
    glEnd();
    // tutup ac
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(60.0, 27.0, -10.0);
    glVertex3f(57.0, 27.0, -10.0);
    glVertex3f(57.0, 24.0, -10.0);
    glVertex3f(60.0, 24.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(57.0, 27.0, -10.0);
    glVertex3f(55.0, 25.0, -10.0);
    glVertex3f(55.0, 24.0, -10.0);
    glVertex3f(57.0, 24.0, -10.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(60.0, 27.0, 0.0);
    glVertex3f(57.0, 27.0, 0.0);
    glVertex3f(57.0, 24.0, 0.0);
    glVertex3f(60.0, 24.0, 0.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(57.0, 27.0, 0.0);
    glVertex3f(55.0, 25.0, 0.0);
    glVertex3f(55.0, 24.0, 0.0);
    glVertex3f(57.0, 24.0, 0.0);
    glEnd();

//TV dan lemarinya
  glBegin(GL_QUADS);
    glColor3f(4.0, 4.0, 4.0);
    glVertex3f(25.0, 0.0, 50.0);
    glVertex3f(25.0, 8.0, 50.0);
    glVertex3f(0.0, 8.0, 50.0);
    glVertex3f(0.0, 0.0, 50.0);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(4.0, 4.0, 4.0);
    glVertex3f(25.0, 0.0, 50.0);
    glVertex3f(25.0, 8.0, 50.0);
    glVertex3f(0.0, 8.0, 50.0);
    glVertex3f(0.0, 0.0, 50.0);
    glEnd();

glBegin(GL_QUADS);
    glColor3f(4.0, 4.0, 4.0);
    glVertex3f(25.0, 0.0, 45.0);
    glVertex3f(25.0, 8.0, 45.0);
    glVertex3f(0.0, 8.0, 45.0);
    glVertex3f(0.0, 0.0, 45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(2.5, 2.5, 2.5);
    glVertex3f(12.3, 0.0, 44.0);
    glVertex3f(12.3, 8.0, 44.0);
    glVertex3f(12.0, 8.0, 44.0);
    glVertex3f(12.0, 0.0, 44.0);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 8.0, 50.0);
    glVertex3f(25.0, 8.0, 45.0);
    glVertex3f(0.0, 8.0, 45.0);
    glVertex3f(0.0, 8.0, 50.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(0.0, 0.0, 50.0);
    glVertex3f(0.0, 8.0, 50.0);
    glVertex3f(0.0, 8.0, 45.0);
    glVertex3f(0.0, 0.0, 45.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(25.0, 0.0, 50.0);
    glVertex3f(25.0, 8.0, 50.0);
    glVertex3f(25.0, 8.0, 45.0);
    glVertex3f(25.0, 0.0, 45.0);
    glEnd();
    //tv
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(23.0, 13.0, 44.0);
    glVertex3f(23.0, 24.0, 44.0);
    glVertex3f(0.0, 24.0, 44.0);
    glVertex3f(0.0, 13.0, 44.0);
    glEnd();
    // pintu belakang kiri
    glBegin(GL_QUADS);
    glColor3f(3.5, 3.5, 3.5);
    glVertex3f(-15.0, 0.0, -40.2);
    glVertex3f(-15.0, 7.0, -40.2);
    glVertex3f(-20.0, 7.0, -40.2);
    glVertex3f(-20.0, 0.0, -40.2);
    glEnd();
    // frame pintu blakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-14.5, 0.0, -40.2);
    glVertex3f(-14.5, 7.0, -40.2);
    glVertex3f(-15.0, 7.0, -40.2);
    glVertex3f(-15.0, 0.0, -40.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-14.5, 7.0, -40.2);
    glVertex3f(-14.5, 7.2, -40.2);
    glVertex3f(-20.5, 7.2, -40.2);
    glVertex3f(-20.5, 7.0, -40.2);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-20.0, 0.0, -40.2);
    glVertex3f(-20.0, 7.2, -40.2);
    glVertex3f(-20.5, 7.2, -40.2);
    glVertex3f(-20.5, 0.0, -40.2);
    glEnd();
    // frame kaca belakang
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.4, 2.0, -36.02);
    glVertex3f(0.4, 2.2, -36.02);
    glVertex3f(10.0, 2.2, -36.02);
    glVertex3f(10.0, 2.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(0.1, 4.0, -36.02);
    glVertex3f(0.1, 4.2, -36.02);
    glVertex3f(10.0, 4.2, -36.02);
    glVertex3f(10.0, 4.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-0.6, 6.0, -36.02);
    glVertex3f(-0.6, 6.2, -36.02);
    glVertex3f(10.0, 6.2, -36.02);
    glVertex3f(10.0, 6.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 00);
    glVertex3f(-0.8, 8.0, -36.02);
    glVertex3f(-0.8, 8.2, -36.02);
    glVertex3f(10.0, 8.2, -36.02);
    glVertex3f(10.0, 8.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.0, 10.0, -36.02);
    glVertex3f(-1.0, 10.2, -36.02);
    glVertex3f(10.0, 10.2, -36.02);
    glVertex3f(10.0, 10.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.6, 12.0, -36.02);
    glVertex3f(-1.6, 12.2, -36.02);
    glVertex3f(10.0, 12.2, -36.02);
    glVertex3f(10.0, 12.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-1.8, 14.0, -36.02);
    glVertex3f(-1.8, 14.2, -36.02);
    glVertex3f(10.0, 14.2, -36.02);
    glVertex3f(10.0, 14.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.6, 16.0, -36.02);
    glVertex3f(-2.6, 16.2, -36.02);
    glVertex3f(10.0, 16.2, -36.02);
    glVertex3f(10.0, 16.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-2.8, 18.0, -36.02);
    glVertex3f(-2.8, 18.2, -36.02);
    glVertex3f(10.0, 18.2, -36.02);
    glVertex3f(10.0, 18.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-3.7, 20.0, -36.02);
    glVertex3f(-3.7, 20.2, -36.02);
    glVertex3f(10.0, 20.2, -36.02);
    glVertex3f(10.0, 20.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-4.3, 22.0, -36.02);
    glVertex3f(-4.3, 22.2, -36.02);
    glVertex3f(10.0, 22.2, -36.02);
    glVertex3f(10.0, 22.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-4.7, 24.0, -36.02);
    glVertex3f(-4.7, 24.2, -36.02);
    glVertex3f(10.0, 24.2, -36.02);
    glVertex3f(10.0, 24.0, -36.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex3f(-5.0, 26.0, -36.02);
    glVertex3f(-5.0, 26.2, -36.02);
    glVertex3f(10.0, 26.2, -36.02);
    glVertex3f(10.0, 26.0, -36.02);
    glEnd();
    // frame dinding tengah
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(25.0, 9.5, -40.02);
    glVertex3f(25.0, 10.0, -40.02);
    glVertex3f(10.0, 10.0, -40.02);
    glVertex3f(10.0, 9.5, -40.02);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(3.0, 3.0, 3.0);
    glVertex3f(25.0, 19.5, -40.02);
    glVertex3f(25.0, 20.0, -40.02);
    glVertex3f(10.0, 20.0, -40.02);
    glVertex3f(10.0, 19.5, -40.02);
    glEnd();


 glPopMatrix();
    glutSwapBuffers();

}

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(80.0, lebar / tinggi, 8.0, 800.0);
    glTranslatef(0.0, -5.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(900, 900);
    glutInitWindowPosition(400, 200);
    glutCreateWindow("Royal Melbourne Institute Of Technology");
    init();
    glutDisplayFunc(tampil);
    glutReshapeFunc(ukuran);

    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMotion);

    glutIdleFunc(tampil);
    glutMainLoop();
    return 0;
}
