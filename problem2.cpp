#include <GL/glut.h>
#include <math.h>

GLint TIMER_DELAY = 10;
GLfloat WHITE_RGB[] = { 1, 1, 1 };
GLfloat BLACK_RGB[] = { 0, 0, 0 };
GLfloat pirateFace[1][2] = {{0.5, 0.5}};
int width = 500;
int height = 500;
int degree = 0;
float size = 0.2;
float halfSize = size / 2;
bool reduceSize = false;
bool rotate = false;
bool finish = false;
int n = 360;
float increaseDegree = 360.0 / n;

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

    x1 = pirateFace[0][0] + ((size / 2.34192) * sin((degree + 69.444) * 3.14159 / 180));
    y1 = pirateFace[0][1] + ((size / 2.34192) * cos((degree + 69.444) * 3.14159 / 180));

    glColor3fv(BLACK_RGB);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x1, y1);
    for (angle = 1.0f; angle < 361.0f; angle += 0.2) {
        x2 = x1 + sin(angle) * radius;
        y2 = y1 + cos(angle) * radius;
        glVertex2f(x2, y2);
    }
    glEnd();

    x1 = pirateFace[0][0] - ((size / 2.34192) * sin((degree + 110.556) * 3.14159 / 180));
    y1 = pirateFace[0][1] - ((size / 2.34192) * cos((degree + 110.556) * 3.14159 / 180));

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
        glVertex2f((sin(i + degree / 58.0) * radius) + pirateFace[0][0], (cos(i + degree / 58.0) * radius) + pirateFace[0][1]);
    glEnd();

    float ax1 = pirateFace[0][0] + ((size / 3.3333) * cos((-1 * degree + 29.982) * 3.14159 / 180));
    float ay1 = pirateFace[0][1] + ((size / 3.3333) * sin((-1 * degree + 29.982) * 3.14159 / 180));

    float bx1 = pirateFace[0][0] + ((size / 1.7857) * cos((-1 * degree + 15.524) * 3.14159 / 180));
    float by1 = pirateFace[0][1] + ((size / 1.7857) * sin((-1 * degree + 15.524) * 3.14159 / 180));

    float cx1 = pirateFace[0][0] + ((size / 1.36054) * cos((-1 * degree + 42.797) * 3.14159 / 180));
    float cy1 = pirateFace[0][1] + ((size / 1.36054) * sin((-1 * degree + 42.797) * 3.14159 / 180));

    float dx1 = pirateFace[0][0] + ((size / 1.7857) * cos((-1 * degree + 62.526) * 3.14159 / 180));
    float dy1 = pirateFace[0][1] + ((size / 1.7857) * sin((-1 * degree + 62.526) * 3.14159 / 180));

    glBegin(GL_POLYGON);
    glVertex2f(ax1, ay1);
    glVertex2f(bx1, by1);
    glVertex2f(cx1, cy1);
    glVertex2f(dx1, dy1);
    glEnd();

    glLineWidth(size * 25);
    glBegin(GL_LINES);
    glVertex2f(size * sin((degree + 60) * 3.14159 / 180) + pirateFace[0][0], size * cos((degree + 60) * 3.14159 / 180) + pirateFace[0][1]);
    glVertex2f(size * sin((degree + 300) * 3.14159 / 180) + pirateFace[0][0], size * cos((degree + 300) * 3.14159 / 180) + pirateFace[0][1]);
    glEnd();
}

void myDisplay() {

    if (reduceSize) {
        if (size > halfSize) size -= 0.001;
        else if (pirateFace[0][0] > 0.1) pirateFace[0][0] -= 0.002;
        else rotate = true;
    }
    if (rotate) {
        reduceSize = false;
        pirateFace[0][0] += 0.0015;
        if (degree < 360) degree += increaseDegree;
        else finish = true;
    }
    if (finish) {
        rotate = false;
        degree = 0;
        if (pirateFace[0][0] > 0.5) pirateFace[0][0] -= 0.001;
        else if (pirateFace[0][0] < 0.49) pirateFace[0][0] += 0.001;
        else if (size < halfSize * 2) size += 0.001;
        else finish = false;
    }

    drawFace();
    glFlush();
    glutSwapBuffers();
}

void keyboardFunct(unsigned char c, int x, int y) {

    switch (c) {
    case 'q':
    case 'Q':
        exit(0);
        break;
    case 'a':
        reduceSize = true;
        break;
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
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Problem 2");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(keyboardFunct);
    glutReshapeFunc(myReshape);
    glutTimerFunc(TIMER_DELAY, myTimeOut, 0);
    myInit();
    glutMainLoop();
    return 0;
}