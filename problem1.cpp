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
bool singleRotationMode = false;
bool animationMode = false;
int width = 500;
int height = 500;
float size = 0.05;
float degree = 0;
float r = 0.1;
float dg = 0;
int n = 360;
float increase = 360.0 / n;

GLfloat Lshape[7][2] = {
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0} // Reference point
};

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

void drawL() {

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3fv(RED_RGB);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++)
        glVertex2fv(Lshape[i]);
    glEnd();

}

void setVerticesAgain() {

    Lshape[0][0] = Lshape[6][0] + ((size)*cos((degree + 180) * 3.14159 / 180));
    Lshape[0][1] = Lshape[6][1] + ((size)*sin((degree + 180) * 3.14159 / 180));

    Lshape[1][0] = Lshape[6][0] + ((size)*cos((degree) * 3.14159 / 180));
    Lshape[1][1] = Lshape[6][1] + ((size)*sin((degree) * 3.14159 / 180));

    Lshape[2][0] = Lshape[6][0] + ((size * sqrt(2)) * cos((degree + 45) * 3.14159 / 180));
    Lshape[2][1] = Lshape[6][1] + ((size * sqrt(2)) * sin((degree + 45) * 3.14159 / 180));

    Lshape[3][0] = Lshape[6][0] + ((size)*cos((degree + 90) * 3.14159 / 180));
    Lshape[3][1] = Lshape[6][1] + ((size)*sin((degree + 90) * 3.14159 / 180));

    Lshape[4][0] = Lshape[6][0] + ((size * 3) * cos((degree + 90) * 3.14159 / 180));
    Lshape[4][1] = Lshape[6][1] + ((size * 3) * sin((degree + 90) * 3.14159 / 180));

    Lshape[5][0] = Lshape[6][0] + ((size * sqrt(10)) * cos(((atan(1.0 / 3) * 180 / 3.14159) + 90 + degree) * 3.14159 / 180));
    Lshape[5][1] = Lshape[6][1] + ((size * sqrt(10)) * sin(((atan(1.0 / 3) * 180 / 3.14159) + 90 + degree) * 3.14159 / 180));

}

void rollingL() {


    Lshape[6][0] = 0.5 + r * cos((dg) * 3.14159 / 180);
    Lshape[6][1] = 0.5 + r * sin((dg) * 3.14159 / 180);

    degree = dg - 90;
    setVerticesAgain();

}

void drawLAt(GLfloat x, GLfloat y) {

    Lshape[6][0] = x;
    Lshape[6][1] = y;

    setVerticesAgain();
}

void myDisplay() {

    if (animationMode) {
        rollingL();
        dg += increase;
    }

    drawL();
    glFlush();
    glutSwapBuffers();
}

void keyboardFunct(unsigned char c, int x, int y) {

    switch (c) {
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 'r':
    case 'R':
        if (singleRotationMode) {
            degree += 5;
            setVerticesAgain();
        }
        break;
    case 'a':
    case 'A':
        animationMode = true;
        singleRotationMode = false;
        break;
    default:
        break;
    }
}

void mouseFunct(int b, int s, int x, int y) {

    if (s == GLUT_DOWN) {
        if (b == GLUT_LEFT_BUTTON) {

        }
        if (b == GLUT_RIGHT_BUTTON) {

            singleRotationMode = true;
            animationMode = false;
            GLfloat mouseX = 1.0 * x / width;
            GLfloat mouseY = 1.0 * (height - y) / height;

            degree = 30;
            drawLAt(mouseX, mouseY);
            
        }
    }
}

void myTimeOut(int id) {

    glutPostRedisplay();
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
}

int main(int argc, char** argv) {

    drawLAt(0.5 + size, 0.5);
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
