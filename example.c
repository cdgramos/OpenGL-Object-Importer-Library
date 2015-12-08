#include <GL/glut.h>

#include "objImporter.h"

//Model declaration
Model humanModel;

void camera(void){
    glRotatef(15,1.0,0.0,0.0);  
    glRotatef(0,0.0,1.0,0.0); 
    glTranslated(-0,-0,-8); 
}

void enable(void){
    glEnable (GL_DEPTH_TEST); 
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei)w, (GLsizei)h); 
    glMatrixMode (GL_PROJECTION); 
    glLoadIdentity ();
    gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 2000.0); 
    glMatrixMode (GL_MODELVIEW);
    
}

void display (void) {
    glClearColor (1.0,1.0,1.0,1.0);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
    glLoadIdentity();  
    camera();
    enable();

    //human.obj is on obj sample files folder
    humanModel = loadModel("human.obj");

    glColor3f(1.0, 0.0, 0.0);
    //draw model vertex
    drawModelVertices(2.0,humanModel);
    glColor3f(0.0, 0.0, 1.0);
    //draw model faces
    drawModelFaces(humanModel);

    glutSwapBuffers(); 
}


int main(int argc, char** argv){
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_DEPTH); 
    glutInitWindowSize(600,600);
    glutCreateWindow("OBJ importer");
    glutInitWindowPosition (100, 100);

    glutDisplayFunc (display); 
    glutIdleFunc (display); 
    glutReshapeFunc (reshape);

    glutMainLoop ();
    return 0;
}