#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#include <iostream>

GLint TIMER_DELAY = 10;
GLfloat RED_RGB[] = { 1, 0, 0 };
GLfloat BLUE_RGB[] = { 0, 0, 1 };
GLfloat WHITE_RGB[] = { 1, 1, 1 };
GLfloat BLACK_RGB[] = { 0, 0, 0 };
int width = 500;
int height = 500;
GLfloat pirateFace[1][2] = {
    {0.5, 0.5}
};
float size = 0.2;

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

void drawFace() {

    float x1, y1, x2, y2;
    float angle;
    double radius = size;

    x1 = pirateFace[0][0];
    y1 = pirateFace[0][1];

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(WHITE_RGB);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2) {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();


    radius = size / 6.6666;

    x1 = pirateFace[0][0] + size / 2.5;
    y1 = pirateFace[0][1] + size / 6.6666;

    glColor3fv(BLACK_RGB);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2) {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();

    x1 = pirateFace[0][0] - size / 2.5;
    y1 = pirateFace[0][1] + size / 6.6666;
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2) {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();

    radius = size / 7.4074;
    glColor3fv(WHITE_RGB);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2) {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();


    radius = size / 2;
    glColor3fv(BLACK_RGB);
    glBegin(GL_POINTS);
    for (float i = 2; i < 4.22; i += 0.001)
        glVertex2f((sin(i) * radius) + pirateFace[0][0], (cos(i) * radius) + pirateFace[0][1] - size / 6.6666);
    glEnd();

    glRectf((pirateFace[0][0] + size / 2.5) - size / 7.14285, (pirateFace[0][1] + size / 6.6666), (pirateFace[0][0] + size / 2.5) + size / 7.14285, (pirateFace[0][1] + size / 6.6666) + size / 2.85714);
    glRectf(size * sin(60 * 3.14159 / 180) + pirateFace[0][0], size * cos(60 * 3.14159 / 180) + pirateFace[0][1], size * sin(300 * 3.14159 / 180) + pirateFace[0][0], size * cos(300 * 3.14159 / 180) + pirateFace[0][1] + size / 20);
}

void myDisplay() {

    drawFace();
    glFlush();
    glutSwapBuffers();
}

// Keyboard function. Catches q,Q,1,2,3,enter
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
    glutCreateWindow("Problem 1");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboardFunct);
    glutReshapeFunc(myReshape);
    glutMouseFunc(mouseFunct);
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
    myInit();
    glutMainLoop();
    return 0;
}
