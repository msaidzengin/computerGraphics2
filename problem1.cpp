#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

GLint TIMER_DELAY = 10;
GLfloat RED_RGB[] = { 1, 0, 0 };
GLfloat BLUE_RGB[] = { 0, 0, 1 };
GLfloat WHITE_RGB[] = { 1, 1, 1 };
GLfloat BLACK_RGB[] = { 0, 0, 0 };

void reshapeFunct(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

// Display function.
void displayFunct(void) {

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

}

// Timer function.
void timerFunct(int id) {

    glutPostRedisplay();
    glutTimerFunc(TIMER_DELAY, timerFunct, 0);

}

// Mouse function. For left and right click.
void mouseFunct(int b, int s, int x, int y) {

    if (s == GLUT_DOWN) {
        if (b == GLUT_LEFT_BUTTON) {

        }
        if (b == GLUT_RIGHT_BUTTON) {
  
        }
    }
    
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

// Main function.
int main(int argc, char** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);

    glutDisplayFunc(displayFunct);
    glutReshapeFunc(reshapeFunct);
    glutMouseFunc(mouseFunct);
    glutKeyboardFunc(keyboardFunct);
    glutSpecialFunc(catchKeyFunct);
    glutTimerFunc(TIMER_DELAY, timerFunct, 0);
    glutMainLoop();
    return 0;

}