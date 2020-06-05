#include <windows.h>
#include <GL/glut.h>
#include<bits/stdc++.h>
using namespace std;
 float Pi = 3.1415926535897932384626433832795;
void DrawStar(float fX, float fY) {


	// Draw ten triangles
	const float Radius = 0.1;
	const float InnerRadius = Radius*(1.0/(sin((2.0*Pi)/5.0)*2.0*cos(Pi/10.0) + sin((3.0*Pi)/10.0)));
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(fX, fY, 0.0);
		for (int i = 0; i < 10; ++i) {
			float fAngleStart	= Pi/2.0 + (i*2.0*Pi)/10.0;
			float fAngleEnd		= fAngleStart + Pi/5.0;
			if (i % 2 == 0) {
				glVertex3f((fX + Radius*cos(fAngleStart)/1.9), (fY + Radius*sin(fAngleStart)), 0.0);
				glVertex3f((fX + InnerRadius*cos(fAngleEnd)/1.9), (fY + InnerRadius*sin(fAngleEnd)), 0.0);
			} else {
				glVertex3f((fX + InnerRadius*cos(fAngleStart)/1.9), (fY + InnerRadius*sin(fAngleStart)), 0.0);
				glVertex3f((fX + Radius*cos(fAngleEnd)/1.9), (fY + Radius*sin(fAngleEnd)), 0.0);
			}
		}
	glEnd();
}

void quad()
{
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.0, 0.0);///red
        glVertex3f(.2,.8,0.0);
		glVertex3f(.8,.8,0.0);
		glVertex3f(.8,.2,0.0);
		glVertex3f(.2,.2,0.0);
		glColor3f(0.0, 0.5, 0.0);///green
        glVertex3f(.3,.7,0.0);
		glVertex3f(.7,.7,0.0);
		glVertex3f(.7,.3,0.0);
		glVertex3f(.3,.3,0.0);


		glEnd();

}
void circle()
{
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 1.0, 1.0);///blue
        float x;
        for(int i=0;i<360;i++)
        {
            x=2.0*i*Pi/180;
            glVertex3f(.5+.08*cos(x),.5+.08*sin(x),0.0);
        }
      glEnd();
        glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.0, 0.5, .0);///blue

        for(int i=0;i<360;i++)
        {
            x=2.0*i*Pi/180;
            glVertex3f(.53+.08*cos(x),.5+.08*sin(x),0.0);
        }

}

void Draw() {
	glClear(GL_COLOR_BUFFER_BIT);


    quad();
     circle();

    glEnd();
	glFlush();
}

void Initialize() {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int iArgc, char** cppArgv) {
	glutInit(&iArgc, cppArgv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(950, 500);///black windows er length and wide
	glutInitWindowPosition(200, 200);
	glutCreateWindow("XoaX.net");
	Initialize();
	glutDisplayFunc(Draw);
	glutMainLoop();
	return 0;
}
