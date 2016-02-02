

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

using namespace std;

float t=-1.0;
float delta=0.1;


int sumaTotal = 0;
bool start = false;


void myTimer(int i) {
    if ( start){
        sumaTotal += 1;
    }

    
    
    if (i == 1)
    {   delta = 0.1;
        t += delta;
        if ( t >= 1) {
            t = -1;
            glutPostRedisplay();
            glutTimerFunc(1,myTimer,1);
        }
        else
        {
            glutPostRedisplay();
            glutTimerFunc(1,myTimer,1);
        }
    }
    
    

}



int	screenWidth = 640, screenHeight = 480;

void reshape(int ancho, int alto) {
    
    screenHeight = alto;
    screenWidth = ancho;
    
    glViewport(0.0,0.0,(GLdouble) ancho,(GLdouble)  alto);
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    
    // hace la conversion a openGL
    gluOrtho2D( 0.0,(GLdouble) ancho, 0.0,(GLdouble)  alto);
    
    
}

void cronometro() {
    
    GLint k;
    
    char msg [200] = "";
    
    int a,b,c;
    
    float x = sumaTotal / 10.0;
    b = x;
    
    x = x - b;
    
    x = x * 10;
    c=x;
    
    a = b /60;
    b = b %60;
    
  

    
    sprintf(msg, "%d : %d . %d", a, b , c);
    
    
    
    glColor3f(1, 1, 1);
    glRasterPos2f(10, 10); // inicializa raster position
    for (k=0; msg[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[k]);
    }
    
    
    
//    char mensaje [200] = "";
//    sprintf(mensaje, "%s", "S-Iniciar, D-Detener, R-Reset");
//    glColor3f(1, 1, 1);
//    glRasterPos2f(-1.4, -1); // inicializa raster position
//    for (k=0; mensaje[k] != '\0'; k++) {
//        glColor3f(1, 1, 1);
//        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje[k]);
//    }
}

void myDisplay()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  //Color del background
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0f, 0.0f, 0.0f ); //Color para pintar
    cronometro();
    
    
    glutSwapBuffers();
    
}


void myKeyboard(unsigned char theKey, int mouseX, int mouseY) {
       switch (theKey)
    {
        case 'S':
        case 's':
            start = true;
            break;
            
        case 'R':
        case 'r':
            start = false;
            sumaTotal = 0;
            break;
        case 'D':
        case 'd':
            start = false;
            break;
        default:
            break;		      // do nothing
    }
}





int main( int argc, char ** argv ) {
    
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB); // dos buffers
    glutInitWindowSize( screenWidth, screenHeight );
    glutInitWindowPosition( 0, 0 );// create window
    glutCreateWindow( "Cronómetro" );
    glutDisplayFunc( myDisplay );
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(reshape);
    glutTimerFunc(100,myTimer,1);
    
    
    glutMainLoop();
    return 0;
    
    
}


//#ifdef __APPLE__
//#include <GLUT/glut.h>
//#else
//#include <GL/glut.h>
//#endif
//
//#include <stdlib.h>
//
//
//float t=-1.0;
//float delta=0.1;
//
//void myTimer(int i) {
//    if (i == 1)
//    {   delta = 0.1;
//        t += delta;
//        if ( t >= 1) {
//            t = -1;
//            glutPostRedisplay();
//            glutTimerFunc(500,myTimer,1);
//        }
//        else
//        {
//            glutPostRedisplay();
//            glutTimerFunc(1000,myTimer,1);
//        }
//    }
//    
//}
//
//void display(){ // primera funcion que se manda llamar porque no hay reshape
//    glClear(GL_COLOR_BUFFER_BIT);
//    glPointSize(50);
//    glBegin(GL_POINTS);
//    glColor3f(1,1,0);
//    glVertex2f(t,0);
//    glColor3f(1,0,1);
//    glVertex2f(0,t);
//    
//    glColor3f(1, 1, 0);
//    glVertex2f(-t, 0);
//    glColor3f(1, 0, 1);
//    glVertex2f(0, -t);
//    glEnd();
//    glutSwapBuffers();//ya tiene integrado el glFlush
//    
//}
//void myMouseButton(int button, int state, int x, int y)
//{
//    
//    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
//        exit(0);
//    else// estar conscientes de que cuando se oprime el mouse siempre se generan 2 eventos.
//        if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
//            glClearColor(1, 1, 1, 1);
//        else
//            if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
//                glClearColor(1, 0, 0, 1);
//    
//}
//
//
//int main(int argc, char *argv[])
//{
//    // como no se definió ningun ortho, el default va de -1 a 1 en X y de -1 a 1 en Y
//    
//    glutInit(&argc, argv);
//    glutInitWindowSize(640,480);
//    glutInitWindowPosition(10,10);
//    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE ); // dos buffers siempre que sea animación hay que tener dos buffers
//    glutCreateWindow("Animacion");
//    glutDisplayFunc(display); // se registra la funcion a desplegar
//    glutMouseFunc(myMouseButton);
//    glutTimerFunc(33,myTimer,1); // despues de 33mseg se manda lamar a la funcion timer
//    glutMainLoop(); // manda llamar primero a la funcion display
//    return EXIT_SUCCESS;
//}
//
