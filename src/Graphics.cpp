#include "Graphics.h"

using namespace std;

Graphics::Graphics():_position_of_camera(0,0,550),_position_of_center_point(0,0,0){

}
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
    gluPerspective(70,(double)640/480,1,100000);

    //Place the camera:
    gluLookAt(_position_of_camera.getX(),_position_of_camera.getY(),_position_of_camera.getZ(),_position_of_center_point.getX(),_position_of_center_point.getY(),_position_of_center_point.getZ(),0,1,0);
}
void Graphics::clearScreen(){
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f );
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //Draw floor:
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_QUADS);
        glVertex4f(-1, -1, 0, 0);
        glVertex4f(-1, 1, 0, 0);
        glVertex4f(1, 1, 0, 0);
        glVertex4f(1, -1, 0, 0);
    glEnd();

    //Draw 3D landmark:
    glColor3f(1.0,0,0);
    glBegin(GL_LINES);
        glVertex3i(-100000,0,0);
        glVertex3i(100000,0,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3i(0,-100000,0);
        glVertex3i(0,100000,0);
    glEnd();
    glBegin(GL_LINES);
        glVertex3i(0,0,-100000);
        glVertex3i(0,0,100000);
    glEnd();
}
void Graphics::setPositionOfCamera(Vector3D const& v){
    _position_of_camera=v;
    cout<<"Position of camera: ";v.display();

    //Define the projection mode:
    glMatrixMode( GL_PROJECTION );

    //Load the identity matrix:
    glLoadIdentity( );

    //Enable Z buffer:
    glEnable(GL_DEPTH_TEST);

    //Restart perspective:
    gluPerspective(70,(double)640/480,1,100000);

    //Change position of camera:
    gluLookAt(_position_of_camera.getX(),_position_of_camera.getY(),_position_of_camera.getZ(),_position_of_center_point.getX(),_position_of_center_point.getY(),_position_of_center_point.getZ(),0,1,0);

}
void Graphics::setPositionOfCenterPoint(Vector3D const& v){
    _position_of_center_point=v;

    //Define the projection mode:
    glMatrixMode( GL_PROJECTION );

    //Load the identity matrix:
    glLoadIdentity( );

    //Enable Z buffer:
    glEnable(GL_DEPTH_TEST);

    //Restart perspective:
    gluPerspective(70,(double)640/480,1,100000);

    //Change position of camera:
    gluLookAt(_position_of_camera.getX(),_position_of_camera.getY(),_position_of_camera.getZ(),_position_of_center_point.getX(),_position_of_center_point.getY(),_position_of_center_point.getZ(),0,1,0);
}
void Graphics::cameraZoomIn(){
    _position_of_camera-=30.0f;
    setPositionOfCamera(_position_of_camera);
}
void Graphics::cameraZoomOut(){
    _position_of_camera+=30.0f;
    setPositionOfCamera(_position_of_camera);
}
void Graphics::drawSphere(double posX,double posY,double posZ){
    GLUquadric* params;
    _all_quadric.push_back(params);
    params = gluNewQuadric();

    gluQuadricDrawStyle(params,GLU_FILL);
    glTranslatef(posX,posY,posZ);
    glColor3f(0.0f, 1.0f, 0.0f);
    gluSphere(params,10,50,50);
}
void Graphics::drawCube(double posX,double posY,double posZ,int red,int green,int blue){
    double R=red/255.0f;
    double G=green/255.0f;
    double B=blue/255.0f;

    // White side - BACK
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
    glVertex3f(posX + 5,posY - 5,posZ + 5 );
    glVertex3f(posX + 5,posY + 5,posZ + 5 );
    glVertex3f(posX - 5,posY + 5,posZ + 5 );
    glVertex3f(posX - 5,posY - 5,posZ + 5 );
    glEnd();

    // Purple side - RIGHT
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
    glVertex3f(posX + 5,posY - 5,posZ - 5 );
    glVertex3f(posX + 5,posY + 5,posZ - 5 );
    glVertex3f(posX + 5,posY + 5,posZ + 5 );
    glVertex3f(posX + 5,posY - 5,posZ + 5 );
    glEnd();

    // Green side - LEFT
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
    glVertex3f(posX - 5,posY - 5,posZ + 5 );
    glVertex3f(posX - 5,posY + 5,posZ + 5 );
    glVertex3f(posX - 5,posY + 5,posZ - 5 );
    glVertex3f(posX - 5,posY - 5,posZ - 5 );
    glEnd();

    // Blue side - TOP
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
    glVertex3f(posX + 5,posY + 5,posZ + 5 );
    glVertex3f(posX + 5,posY + 5,posZ - 5 );
    glVertex3f(posX - 5,posY + 5,posZ - 5 );
    glVertex3f(posX - 5,posY + 5,posZ + 5 );
    glEnd();

    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(R,G,B);
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