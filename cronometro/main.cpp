

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
            glutTimerFunc(100,myTimer,1);
        }
        else
        {
            glutPostRedisplay();
            glutTimerFunc(100,myTimer,1);
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
    
  

    if (b <= 9) {
        sprintf(msg, "%d : 0%d . %d", a, b , c);
    } else {
        sprintf(msg, "%d : %d . %d", a, b , c);
    }
    
    
    
    glColor3f(1, 1, 1);
    glRasterPos2f(200, 200); // inicializa raster position
    for (k=0; msg[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[k]);
    }
    
    
    
    char mensaje [200] = "";
    sprintf(mensaje, "%s", "I-Iniciar, S-Stop, R-Reset");
    glColor3f(1, 1, 1);
    glRasterPos2f(100, 100); // inicializa raster position
    for (k=0; mensaje[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje[k]);
    }
    
    char mensaje2 [200] = "";
    sprintf(mensaje2, "%s", "Esc-Salir");
    glColor3f(1, 1, 1);
    glRasterPos2f(300, 70);
    for (k=0; mensaje2[k] != '\0'; k++) {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mensaje2[k]);
    }
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
        case 'I':
        case 'i':
            start = true;
            break;
            
        case 'R':
        case 'r':
            start = false;
            sumaTotal = 0;
            break;
        case 'S':
        case 's':
            start = false;
            break;
            
        case 27:
            exit(-1);
            
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
