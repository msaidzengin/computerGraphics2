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
float size = 0.1;
GLfloat Lshape[7][2] = {
    {0, 0},
    {size * 2, 0},
    {size * 2, size},
    {size, size},
    {size, size * 3},
    {0, size * 3},
    {size, 0} // Reference point
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

void setVerticesAgain(GLfloat degree) {

    Lshape[0][0] = Lshape[6][0] + ((size) * cos((degree + 180) * 3.14159 / 180));
    Lshape[0][1] = Lshape[6][1] + ((size) * sin((degree + 180) * 3.14159 / 180));

    Lshape[1][0] = Lshape[6][0] + ((size) * cos((degree) * 3.14159 / 180));
    Lshape[1][1] = Lshape[6][1] + ((size) * sin((degree) * 3.14159 / 180));

    Lshape[2][0] = Lshape[6][0] + ((size * sqrt(2)) * cos((degree + 45) * 3.14159 / 180));
    Lshape[2][1] = Lshape[6][1] + ((size * sqrt(2)) * sin((degree + 45) * 3.14159 / 180));

    Lshape[3][0] = Lshape[6][0] + ((size) * cos((degree + 90) * 3.14159 / 180));
    Lshape[3][1] = Lshape[6][1] + ((size) * sin((degree + 90) * 3.14159 / 180));

    Lshape[4][0] = Lshape[6][0] + ((size * 3) * cos((degree + 90) * 3.14159 / 180));
    Lshape[4][1] = Lshape[6][1] + ((size * 3) * sin((degree + 90) * 3.14159 / 180));

    Lshape[5][0] = Lshape[6][0] + ((size * sqrt(10)) * cos((180 - atan(3) + degree) * 3.14159 / 180));
    Lshape[5][1] = Lshape[6][1] + ((size * sqrt(10)) * sin((180 - atan(3) + degree) * 3.14159 / 180));

    std::cout << ((size * sqrt(10)) * cos((180 - atan(3) + degree) * 3.14159 / 180)) << "\n";
    std::cout << ((size * sqrt(10)) * sin((180 - atan(3) + degree) * 3.14159 / 180)) << "\n";

}

void drawLAt(GLfloat x, GLfloat y, GLfloat degree) {

    Lshape[6][0] = x;
    Lshape[6][1] = y;

    setVerticesAgain(degree);

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
    case 'Q':
        exit(0);
        break;
    case 'a':
        animationMode = true;
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
            singleRotationMode = true;
            GLfloat mouseX = 1.0 * x / width;
            GLfloat mouseY = 1.0 * (height - y) / height;

            drawLAt(mouseX, mouseY, 30);

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
