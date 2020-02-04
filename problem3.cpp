#include <GL\glut.h>

GLfloat rotate = 0;
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

    glTranslatef(0, 0, -20);

    glColor3f(0.9, 0.3, 0.2);
    glRotatef(70, 1, 0, 0);
    glRotatef(0, 0, 1, 0);
    glRotatef(0, 0, 0, 1);
    glScalef(1, 1, 1);
    glutWireSphere(1, 20, 20);


    glColor3f(0, 0, 1);
    glRotatef(0, 1, 0, 0);
    glRotatef(0, 0, 1, 0);
    glRotatef(rotate, 0, 0, 1);
    glScalef(1, 1, 1);
    glTranslatef(5,1,0);
    glutWireSphere(2, 20, 10);

    glFlush();
}

void idle(void) {

    rotate += 0.01;
    display();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Solid Sphere");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}