#include <iostream>
//Import openGL
#include <GL/glut.h>

#include "Vector3D.h"
#include "UnitTests.h"

using namespace std;

void update_graphics(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
}
void gameloop() {
    
}
 
int main(int argc, char** argv)
{
    runTests();
    //initialization of GLUT library
    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(400, 300);
    glutInitWindowPosition(0, 100);

    glutCreateWindow("My first windows created with GLUT!");

    //Function called when a graphic update is possible
    glutDisplayFunc(update_graphics);

    //Function called betyween graphics update 
    glutIdleFunc(gameloop);

    //This function never return
    glutMainLoop();
    
    return 0;
}