#include <stdio.h>
#include <math.h>
#include <GL/glut.h>
#define pi 3.142
static GLfloat angle = 0;

static int submenu;
static int mainmenu;
static int value = -1;

void init()
{
    gluOrtho2D(-1000, 1000, -1000, 1000); //for clipping window
}
void circle(float rad) // for drawing Orbits
{
    glBegin(GL_POINTS);
    glColor3f(1, 1, 0);
    for (float i = 0; i < (2 * pi); i += 0.00001)   //for drawing points to create the orbit: i value represents distance btwn points
    {
        glVertex2i(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void drawString(float x, float y, float z, char *string) //Labelling text
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, *c);
    }
}

void drawhead(float x, float y, float z, char *string) // for title heading colors
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
    }
}
void drawsubhead(float x, float y, float z, char *string)  // for subheading color and font
{
    glColor3f(1, 1, 1);
    glRasterPos3f(x, y, z);

    for (char *c = string; *c != '\0'; c++)
    {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
    }
}
void nuc(float rad) // Nucleas
{
    glBegin(GL_POLYGON);
    glColor3f(1.0,0.5,0.0);
    for (float i = 0; i < (2 * pi); i = i + 0.00001)
    {
        glVertex2f(rad * cos(i), rad * sin(i));
    }
    glEnd();
}
void eleright(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(rad + 20 * cos(i), 20 * sin(i));
    }
    glEnd();
}
void eleleft(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(-(rad + 20 * cos(i)), 20 * sin(i));
    }
    glEnd();
}
void eletop(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), rad + 20 * sin(i));
    }
    glEnd();
}
void eledown(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(20 * cos(i), -(rad + 20 * sin(i)));
    }
    glEnd();
}
void eletr(float rad)
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    for (float i = 0; i < (2 * pi); i += 0.00001)
    {
        glVertex2i(((rad - 175) + 20 * cos(i)), ((rad - 175) + 20 * sin(i)));
    }
    glEnd();
}

void display()
{
    glClearColor(0, 0, 0.1, 0.8);

    if (value == -1)
    {
        char prn[] = "A Mini Project On";
        drawsubhead(-100, 450, 0, prn);
        char pro[] = "ATOM VISUALIZATION";
        drawhead(-150, 350, 0, pro);

        char pb[] = "PROJECT BY: ";
        drawhead(-250, -150, 0, pb);

        char in[] = "Press enter to Continue";
        drawhead(-150, -700, 0, in);

        glutSwapBuffers();
        glutDetachMenu(GLUT_RIGHT_BUTTON);
    }
    if (value != -1)
    {
        nuc(250); // Nucleus size
        char n[] = "NUCLEUS";
        drawString(-100, 20, 0, n);
        char d[] = "(NEUTRON + PROTON)";
        drawString(-120, -30, 0, d);
        if (value == 0)
        {
            char nu[] = "SELECT THE ELEMENT USING MENU";
            drawhead(-490, 900, 0, nu);
        }
    }
    if (value == 1)
    {
        char n[] = "HYDROGEN";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix(); //OpenGL keeps a stack of matrices to quickly apply and remove transformations. glPushMatrix copies the top matrix and pushes it onto the stack acts like a loop
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        char e[] = "ELECTRON";
        drawString(440, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 2)
    {
        char n[] = "HELIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        char o[] = "ORBIT";
        drawString(410, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        char e[] = "ELECTRON";
        drawString(440, 0, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 3)
    {
        char n[] = "LITHIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        char e[] = "ELECTRON";
        drawString(30, 650, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 4)
    {
        char n[] = "BERYLLIUM";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        char e[] = "ELECTRON";
        drawString(30, 650, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }
    if (value == 5)
    {
        char n[] = "BORON";
        drawhead(-100, 900, 0, n);
        circle(400);
        circle(600);
        char o[] = "ORBIT";
        drawString(610, 0, 0, o);
        glPushMatrix();
        glRotatef(angle, 0, 0, 1);
        eleright(400);
        eleleft(400);
        eletop(600);
        eledown(600);
        eletr(600);
        char e[] = "ELECTRON";
        drawString(30, 650, 0, e);
        glPopMatrix();
        glutSwapBuffers();
    }

    glutSwapBuffers();
}
void rotate()
{
    angle = angle + 1.0;  // speed of electrons...change + to - for clockwise
    if (angle > 360)
    {
        angle = angle - 360;
    }
    glClear(GL_COLOR_BUFFER_BIT);
    glutPostRedisplay();
}
void mouseControl(int button, int state, int x, int y)
{
    switch (button)
    {
    case GLUT_LEFT_BUTTON:  //when we click on left button and select element simulation will start
        if (state == GLUT_DOWN)
            glutIdleFunc(rotate);
        break;
    default:
        break;
    }
}
void keyboard(unsigned char key, int x, int y)  // main menu
{
    if (key == 13) //Enter Key 
    {
        value = 0;
        glClear(GL_COLOR_BUFFER_BIT);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutPostRedisplay();
    }
    else if (key == 's') //to stop simulation
    {
        glutIdleFunc(NULL);
    }
    else if (key == 32) // spacebar to start simulattion
    {
        glutIdleFunc(rotate);
    }
    else if (key == 'q' || key == 'Q') // to exit
    {
        exit(0);
    }
    else if (key == 27) //minimize the window
    {
        glutReshapeWindow(700, 700);
    }
}

void menu(int option) // on choosing sub menu
{
    if (option == 13)
    {
        exit(0);
    }
    else if (option == 11)
    {
        glutIdleFunc(rotate);
    }
    else if (option == 12)
    {
        glutIdleFunc(NULL);
    }
    else if(option==14){
        value=-1;
    }
    else
    {
        value = option;
    }
    glClear(GL_COLOR_BUFFER_BIT);

    glutPostRedisplay();
}
void createMenu(void)  // for displaying menu
{
    submenu = glutCreateMenu(menu);
    glutAddMenuEntry("HYDROGEN", 1);
    glutAddMenuEntry("HELIUM", 2);
    glutAddMenuEntry("LITHIUM", 3);
    glutAddMenuEntry("BERILIUM", 4);
    glutAddMenuEntry("BORON", 5);
    mainmenu = glutCreateMenu(menu);
    glutAddSubMenu("SELECT THE ELEMENT", submenu);
    glutAddMenuEntry("START VISUALIZATION", 11);
    glutAddMenuEntry("STOP VISUALIZATION", 12);
    glutAddMenuEntry("GOTO HOME SCREEN",14);
    glutAddMenuEntry("EXIT", 13);

    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowPosition(300, 10); // Initial window position
    glutInitWindowSize(700, 700); //window default size
    glutCreateWindow("ATOM VISUALIZATION");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouseControl);
    glutKeyboardFunc(keyboard);
    createMenu();
    glutMainLoop();
    return 0;
}
