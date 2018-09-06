#include <iostream>
#include <chrono>
#include <unistd.h>
//Import openGL
#include <GL/glut.h>

#include "Vector3D.h"
#include "Particule.h"
#include "UnitTests.h"

using namespace std;

//Create a particule class:
Particule p(Vector3D(100,100,0),Vector3D(0,0,0),Vector3D(0,0,0),10,0.7);

void update_graphics(void)
{
    //glClear(GL_COLOR_BUFFER_BIT);
    /*
    glBegin(GL_POINTS);
    glColor3f(0.3, 0.3, 0.3);
    glPointSize(5.0f);
    glVertex3f(p.getPosition()[0], p.getPosition()[1], p.getPosition()[2]);
    glEnd();
    */
    float radius=50.0f;
    const float DEG2RAD = 3.14159/180;
   
    glColor3f(0, 1, 0);
    glBegin(GL_QUADS);
    glVertex2f(0.1, 0.1);
    glVertex2f(0.1, -0.1);
    glVertex2f(-0.1, 0.1);
    glVertex2f(-0.1, -0.1);
    glEnd();

}
void gameloop() {
    // Record start time
    static auto start = std::chrono::high_resolution_clock::now();

    // Portion of code to be timed
    p.getPosition().display();

    // Record end time
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    cout<<elapsed.count()<<endl;
    start=finish;

    usleep(33333);
}
 
int main(int argc, char** argv)
{
    //Unit test ... remove this function in production
    //runTests();

    //initialization of GLUT library
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE);

    glutInitWindowSize(500, 500);
    //glutInitWindowPosition(0, 100);

    glutCreateWindow("GAME ENGINE");

    //Function called when a graphic update is possible
    glutDisplayFunc(update_graphics);

    //Function called betyween graphics update 
    glutIdleFunc(gameloop);

    //This function never return
    glutMainLoop();
    
    return 0;
}