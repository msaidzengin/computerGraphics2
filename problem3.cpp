#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>
#include <cmath>
#include <iostream>
#include <cmath>
using namespace std;


GLint TIMER_DELAY = 200;
GLfloat RED_RGB[] = { 1, 0, 0 };
GLfloat BLUE_RGB[] = { 0, 0, 1 };
GLfloat WHITE_RGB[] = { 1, 1, 1 };
GLfloat BLACK_RGB[] = { 0, 0, 0 };
GLfloat SUN_RGB[] = { 0.9, 0.3, 0.2 };
int width = 500;
int height = 500;
GLfloat sun[1][3] = { 0.5, 0.5, 0.5 };
float sunSize = 0.2;


void myInit() {
    glClearColor(0, 0, 0, 1);
    glShadeModel(GL_SMOOTH);
}

void myReshape(int winWidth, int winHeight) {
    width = winWidth;
    height = winHeight;
    glViewport(0, 0, winWidth, winHeight);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();

}

void myWireSphere(float r, int nParal, int nMerid) {
    float x, y, z, i, j;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(SUN_RGB);
    for (j = 0; j < 3.14159; j += 3.14159 / (nParal + 1)) {
        glBegin(GL_LINE_LOOP);
        y = (float)(r * cos(j));
        for (i = 0; i < 2 * 3.14159; i += 3.14159 / 60) {
            x = (float)(r * cos(i) * sin(j));
            z = (float)(r * sin(i) * sin(j));
            glVertex3f(x + 0.8, y + 0.8, z);
        }
        glEnd();
    }

    for (j = 0; j < 3.14159; j += 3.14159 / nMerid) {
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 2 * 3.14159; i += 3.14159 / 60) {
            x = (float)(r * sin(i) * cos(j));
            y = (float)(r * cos(i + 0.5));
            z = (float)(r * sin(j) * sin(i));
            glVertex3f(x + 0.2, y + 0.2, z);
        }
        glEnd();
    }
}

void drawSun() {

    myWireSphere(0.2, 20, 20);
}

void myDisplay() {

    drawSun();
    glFlush();
    glutSwapBuffers();
}

// Keyboard function.
void keyboardFunct(unsigned char c, int x, int y) {

    switch (c) {
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 'r':
        break;
    case 'a':
        break;
    default:
        break;
    }
}

// Catches arrow keys.
void catchKeyFunct(int key, int x, int y) {

    if (key == GLUT_KEY_LEFT) {

    }
    else if (key == GLUT_KEY_RIGHT) {

    }
    else if (key == GLUT_KEY_DOWN) {

    }
    else if (key == GLUT_KEY_UP) {

    }
}

void mouseFunct(int b, int s, int x, int y) {

    if (s == GLUT_DOWN) {
        if (b == GLUT_LEFT_BUTTON) {

        }
        if (b == GLUT_RIGHT_BUTTON) {

        }
    }
}

void myTimeOut(int id) {

    glutPostRedisplay();
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 3");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboardFunct);
    glutReshapeFunc(myReshape);
    glutMouseFunc(mouseFunct);
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
    myInit();
    glutMainLoop();
    return 0;
}
