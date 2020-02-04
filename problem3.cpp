#include <GL\glut.h>
#include <iostream>
using namespace std;

GLfloat xRotated;
GLdouble radius = 1;

void reshape(int x, int y) {
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLdouble size = 1.0 * x / y;
    gluPerspective(30, size, 3, 70);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

void display(void) {

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0, 0, -5);
    glColor3f(0.9, 0.3, 0.2);
    glRotatef(xRotated, 0, 1, 0);
    glScalef(1, 1, 1);
    glutWireSphere(radius, 20, 20);

    glTranslatef(0., 0, -5);
    glColor3f(0.9, 0.3, 0.2);
    glRotatef(xRotated, 0, 1, 0);
    glScalef(0.5, 0.5, 0.5);
    glutWireSphere(radius, 20, 20);

    glFlush();
}

void idle(void) {

    xRotated += 0.01;
    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Solid Sphere");
    xRotated = 0;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}