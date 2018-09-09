#include "Graphics.h"

using namespace std;

Graphics::Graphics(){}
void Graphics::init(int* argc,char **argv){
    //initialization of GLUT library
    glutInit(argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    //glutInitWindowPosition(0, 100);

    glutCreateWindow(NAME_OF_WINDOW);
    
    //Define the projection mode:
    glMatrixMode( GL_PROJECTION );

    //Load the identity matrix:
    glLoadIdentity( );

    //Enable Z buffer:
    glEnable(GL_DEPTH_TEST);

    //Define perspectrive parameters:
    gluPerspective(70,(double)640/480,1,1000);

    //Place the camera:
    gluLookAt(100,100,100,0,0,0,0,1,0);
}
void Graphics::clearScreen(){
    //Remove all Quadric
    for(unsigned i=0;i<_all_quadric.size();i++){
        //gluDeleteQuadric(_all_quadric[i]);
    }
    for(unsigned i=0;i<_all_quadric.size();i++){
        _all_quadric.pop_back();
    }
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Draw 3D landmark:
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_LINES);
        glVertex3i(-1000,0,0);
        glVertex3i(1000,0,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3i(0,-1000,0);
        glVertex3i(0,1000,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3i(0,0,-1000);
        glVertex3i(0,0,1000);
    glEnd();
}
void Graphics::drawSphere(double posX,double posY,double posZ){
    GLUquadric* params;
    _all_quadric.push_back(params);
    params = gluNewQuadric();

    gluQuadricDrawStyle(params,GLU_FILL);
    glTranslatef(posX,posY,posZ);
    gluSphere(params,10,50,50);
  
}
void Graphics::drawCube(double posX,double posY,double posZ){
    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  1.0, 1.0 );
    glVertex3f(posX + 5,posY - 5,posZ + 5 );
    glVertex3f(posX + 5,posY + 5,posZ + 5 );
    glVertex3f(posX - 5,posY + 5,posZ + 5 );
    glVertex3f(posX - 5,posY - 5,posZ + 5 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(  1.0,  0.0,  1.0 );
    glVertex3f(posX + 5,posY - 5,posZ - 5 );
    glVertex3f(posX + 5,posY + 5,posZ - 5 );
    glVertex3f(posX + 5,posY + 5,posZ + 5 );
    glVertex3f(posX + 5,posY - 5,posZ + 5 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  1.0,  0.0 );
    glVertex3f(posX - 5,posY - 5,posZ + 5 );
    glVertex3f(posX - 5,posY + 5,posZ + 5 );
    glVertex3f(posX - 5,posY + 5,posZ - 5 );
    glVertex3f(posX - 5,posY - 5,posZ - 5 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(   0.0,  0.0,  1.0 );
    glVertex3f(posX + 5,posY + 5,posZ + 5 );
    glVertex3f(posX + 5,posY + 5,posZ - 5 );
    glVertex3f(posX - 5,posY + 5,posZ - 5 );
    glVertex3f(posX - 5,posY + 5,posZ + 5 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(   1.0,  0.0,  0.0 );
    glVertex3f(posX + 5,posY - 5,posZ - 5 );
    glVertex3f(posX + 5,posY - 5,posZ + 5 );
    glVertex3f(posX - 5,posY - 5,posZ + 5 );
    glVertex3f(posX - 5,posY - 5,posZ - 5 );
    glEnd();

    glFlush();
    glutSwapBuffers();
 
  
}
void Graphics::start(){
    glutMainLoop();
}