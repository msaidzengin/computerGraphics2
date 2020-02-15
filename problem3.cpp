# include <GL/glut.h>
# include <math.h>

GLint TIMER_DELAY = 20;
GLfloat BLUE_RGB[] = { 0, 0, 1 };
GLfloat SUN_RGB[] = { 0.9, 0.3, 0.2 };
GLfloat sun[1][2] = { 0.5, 0.5 };
float sunSize = 0.2;
float yearDegree = 0;

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

void myWireSphere(float r, int nParal, int nMerid, GLfloat color[], float xx, float yy) {
    float x, y, z, i, j;
    glColor3fv(color);
    for (j = 0; j < 3.14159; j += 3.14159 / (nParal + 1)) {
        glBegin(GL_LINE_LOOP);
        y = (float)(r * cos(j));
        for (i = 0; i < 2 * 3.14159; i += 3.14159 / 60) {
            x = (float)(r * cos(i) * sin(j));
            z = (float)(r * sin(i) * sin(j));
            glVertex3f(x + xx, y + yy, z);
        }
        glEnd();
    }

    for (j = 0; j < 3.14159; j += 3.14159 / nMerid) {
        glBegin(GL_LINE_LOOP);
        for (i = 0; i < 2 * 3.14159; i += 3.14159 / 60) {
            x = (float)(r * sin(i) * cos(j));
            y = (float)(r * cos(i));
            z = (float)(r * sin(j) * sin(i));
            glVertex3f(x + xx, y + yy, z);
        }
        glEnd();
    }
}

void myDisplay() {

    glClear(GL_COLOR_BUFFER_BIT);

    float x = 0.50 * cos(yearDegree * 3.14159 / 180) + sun[0][0];
    float y = 0.12 * sin(yearDegree * 3.14159 / 180) + sun[0][1];
    float worldSize = -1 * 0.07 * sin(yearDegree * 3.14159 / 180) + 0.20;
    worldSize /= 2;
    yearDegree += 1;
    if (yearDegree == 360) yearDegree = 1;

    if (y < 0.5) {
        myWireSphere(sunSize, 20, 20, SUN_RGB, sun[0][0], sun[0][1]);
        myWireSphere(worldSize, 20, 20, BLUE_RGB, x, y);
    }
    else {
        myWireSphere(worldSize, 20, 20, BLUE_RGB, x, y);
        myWireSphere(sunSize, 20, 20, SUN_RGB, sun[0][0], sun[0][1]);
    }

    glFlush();
    glutSwapBuffers();
}

void keyboardFunct(unsigned char c, int x, int y) {

    switch (c) {
    case 'q':
        exit(0);
    default:
        break;
    }
}

void myTimeOut(int id) {

    glutPostRedisplay();
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 3");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboardFunct);
    glutReshapeFunc(myReshape);
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
    myInit();
    glutMainLoop();
    return 0;
}
