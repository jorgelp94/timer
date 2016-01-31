

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct GLintPoint
{
    GLint x, y;
};
GLintPoint List [1000];
int last =-1;
int anterior = -1;

void drawDot(GLint x, GLint y)

{
    // glColor3f( 1.0f, 0.0f, 0.0f ); //Color para pintar
    glPointSize(8.0);
    List[++last].x = x;
    List[  last].y = y;
    glBegin (GL_POINTS);
    glVertex2i(x,y);
    glEnd();
    glFlush();
    
}
void draw( )
{
    //glClear( GL_COLOR_BUFFER_BIT ); // borra los puntos
    glBegin (GL_LINE_STRIP);
    for (int i=0; i <= last ; i++)
    {
        glVertex2i(List[i].x,List[i].y);
    }
    glEnd();
    
    glBegin (GL_POINTS);
    for (int i=0; i <= last ; i++)
    {
        glVertex2i(List[i].x,List[i].y);
    }
    
    glEnd();
    
    glFlush();
    
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
//    glColor3f(0.5,1,1);
//    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
//    glBegin(GL_POLYGON);
//    glColor3f(0.5,1,1);
//    glVertex2f(-2, -1.5);
//    glColor3f(0.5,1,1);
//    glVertex2f(-2, 1.5);
//    glColor3f(0.5,1,1);
//    glVertex2f(2, 1.5);
//    glColor3f(0.5,1,1);
//    glVertex2f(2, -1.5);
//    glEnd();
    
    GLint k;
    
    char msg [200] = "";
    char mat [200] = "";
    sprintf(msg, "%s", "0:0:0");
    sprintf(mat, "%s", "S-Iniciar, D-Detener, R-Reset");
    
    // dibuja nombre
    glColor3f(1, 1, 1);
    glRasterPos2f(0, 0); // inicializa raster position
    for (k=0; msg[k] != '\0'; k++)
    {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, msg[k]);
    }
    
    glColor3f(1, 1, 1);
    glRasterPos2f(-1.4, -1); // inicializa raster position
    for (k=0; mat[k] != '\0'; k++)
    {
        glColor3f(1, 1, 1);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, mat[k]);
    }
}

void myDisplay()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  //Color del background
    glClear( GL_COLOR_BUFFER_BIT );
    glColor3f( 1.0f, 0.0f, 0.0f ); //Color para pintar
    cronometro();
    
    //    glBegin (GL_POINTS);
    //    glVertex2i(100,100);
    //    glEnd();
    
    
    glutSwapBuffers();
    
}


void myKeyboard(unsigned char theKey, int mouseX, int mouseY)
{
    GLint x = mouseX;
    GLint y = screenHeight - mouseY; // cambiar las coordenadas a coordenadas de openGL
    switch (theKey)
    {
        case 'S':
        case 's':
            draw();
            break;
            
        case 'R':
        case 'r':
            anterior = last;
            last = -1;
            glClear( GL_COLOR_BUFFER_BIT );
            glFlush();// Limpia la pantalla
            
            break;
        case 'D':
        case 'd':
            // algo
            break;
            

        case 27: // tecla ESC
            exit(-1);
            break;
            
        default:
            break;		      // do nothing
    }
}


// al mover el mouse dibuja
void mueveMouse(int x, int y) {
    
    y = screenHeight - y;
    
    drawDot(x, y);
}


int main( int argc, char ** argv )
{
    
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE| GLUT_RGB); // dos buffers
    glutInitWindowSize( screenWidth, screenHeight );
    glutInitWindowPosition( 0, 0 );// create window
    glutCreateWindow( "Cronómetro" );
    glutDisplayFunc( myDisplay );
    glutKeyboardFunc(myKeyboard);
    glutReshapeFunc(reshape);
    
    glutMotionFunc(mueveMouse);
    
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
