#include <GL\glut.h>

GLfloat xRotated, yRotated, zRotated;
GLdouble radius = 2;

void reshape(int x, int y) {
    if (y == 0 || x == 0) return;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(100, (GLdouble)x / (GLdouble)y, 3, 50);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0, 0, x, y);
}

void display(void) {

    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glTranslatef(0.0, 0.0, -5.0);
    glColor3f(0.9, 0.3, 0.2);

    glRotatef(xRotated, 1.0, 0.0, 0.0);
    glRotatef(yRotated, 0.0, 1.0, 0.0);
    glRotatef(zRotated, 0.0, 0.0, 1.0);

    glScalef(1.0, 1, 1.0);
    glutWireSphere(radius, 20, 20);

    glutWireSphere(10, 100, 20);

    glFlush();
}

void idle(void) {

    xRotated += 0.01;
    yRotated += 0.01;
    zRotated += 0.01;
    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Solid Sphere");
    xRotated = 0;
    yRotated = 0;
    zRotated = 0;

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}