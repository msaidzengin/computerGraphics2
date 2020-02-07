#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

GLint TIMER_DELAY = 10;
GLfloat RED_RGB[] = { 1, 0, 0 };
GLfloat BLUE_RGB[] = { 0, 0, 1 };
GLfloat WHITE_RGB[] = { 1, 1, 1 };
GLfloat BLACK_RGB[] = { 0, 0, 0 };

GLfloat Lshape[7][2] = {
    {0.00, 0.00},
    {0.25, 0.00},
    {0.25, 0.10},
    {0.10, 0.10},
    {0.10, 0.40},
    {0.00, 0.40},
    {0.15, 0.00} // Reference point
};

void myInit() {
    glClearColor(0, 0, 0, 1);
    glShadeModel(GL_SMOOTH);

}

void myReshape(int winWidth, int winHeight) {
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

void myDisplay() {
    drawL();
    glFlush();
    glutSwapBuffers();
}

// Keyboard function. Catches q,Q,1,2,3,enter
void keyboardFunct(unsigned char c, int x, int y) {

    switch (c) {
    case 'q':
        exit(0);
        break;
    case '1':
        break;
    case '2':
        break;
    case '3':
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

void myMouse(int b, int s, int x, int y) {

    switch (b) {
    case GLUT_LEFT_BUTTON:
        if (s == GLUT_DOWN) {

        }
        else if (s == GLUT_UP) {

        }
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
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 1");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboardFunct);
    glutReshapeFunc(myReshape);
    glutMouseFunc(myMouse);
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
    myInit();
    glutMainLoop();
    return 0;
}
