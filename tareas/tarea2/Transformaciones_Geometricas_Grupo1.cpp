#include <GL/glut.h> 

GLfloat anguloCuboX = 0.0f;  
GLfloat anguloCuboY = 0.0f; 
GLfloat anguloEsfera = 0.0f; 
GLfloat desp = 0.0f; 

GLint ancho, alto; 
int hazPerspectiva = 0; 

void reshape(int width, int height) 
{ 
	glViewport(0, 0, width, height); 
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	if(hazPerspectiva) 
		gluPerspective(60.0f, (GLfloat)width/(GLfloat)height, 1.0f, 20.0f); 
	else 
		glOrtho(-4, 4, -4, 4, 1, 10); 
	
	glMatrixMode(GL_MODELVIEW); 
	
	ancho = width; 
	alto = height; 
} 

void drawCube(void) 
{ 
	// Cara frontal
	glColor3f(1.0f, 0.0f, 0.0f); 
	glBegin(GL_QUADS); 
	glVertex3f(-1.0f, -1.0f,  1.0f); 
	glVertex3f( 1.0f, -1.0f,  1.0f); 
	glVertex3f( 1.0f,  1.0f,  1.0f); 
	glVertex3f(-1.0f,  1.0f,  1.0f); 
	glEnd(); 
	
	// Cara trasera
	glColor3f(0.0f, 1.0f, 0.0f); 
	glBegin(GL_QUADS); 
	glVertex3f(-1.0f, -1.0f, -1.0f); 
	glVertex3f( 1.0f, -1.0f, -1.0f); 
	glVertex3f( 1.0f,  1.0f, -1.0f); 
	glVertex3f(-1.0f,  1.0f, -1.0f); 
	glEnd(); 
	
	// Cara lateral izquierda
	glColor3f(0.0f, 0.0f, 1.0f); 
	glBegin(GL_QUADS); 
	glVertex3f(-1.0f, -1.0f, -1.0f); 
	glVertex3f(-1.0f, -1.0f,  1.0f); 
	glVertex3f(-1.0f,  1.0f,  1.0f); 
	glVertex3f(-1.0f,  1.0f, -1.0f); 
	glEnd();
	
	// Cara lateral derecha
	glColor3f(1.0f, 1.0f, 0.0f); 
	glBegin(GL_QUADS); 
	glVertex3f( 1.0f, -1.0f,  1.0f); 
	glVertex3f( 1.0f, -1.0f, -1.0f); 
	glVertex3f( 1.0f,  1.0f, -1.0f); 
	glVertex3f( 1.0f,  1.0f,  1.0f); 
	glEnd(); 
	
	// Cara superior
	glColor3f(0.0f, 1.0f, 1.0f); 
	glBegin(GL_QUADS); 
	glVertex3f(-1.0f,  1.0f,  1.0f); 
	glVertex3f( 1.0f,  1.0f,  1.0f); 
	glVertex3f( 1.0f,  1.0f, -1.0f); 
	glVertex3f(-1.0f,  1.0f, -1.0f); 
	glEnd(); 
	
	// Cara inferior
	glColor3f(1.0f, 0.0f, 1.0f); 
	glBegin(GL_QUADS); 
	glVertex3f( 1.0f, -1.0f, -1.0f); 
	glVertex3f( 1.0f, -1.0f,  1.0f); 
	glVertex3f(-1.0f, -1.0f,  1.0f); 
	glVertex3f(-1.0f, -1.0f, -1.0f); 
	glEnd(); 
} 

void display() 
{ 
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	
	glLoadIdentity(); 
	glTranslatef(0.0f, 0.0f, -5.0f); 
	glRotatef(anguloCuboX, 1.0f, 0.0f, 0.0f); 
	glRotatef(anguloCuboY, 0.0f, 1.0f, 0.0f); 
	glTranslatef(desp, 0.0f, 0.0f);
	drawCube(); 
	
	glFlush(); 
	glutSwapBuffers(); 
} 

void init() 
{ 
	glClearColor(0,0,0,0); 
	glEnable(GL_DEPTH_TEST); 
	ancho = 400; 
	alto = 400; 
} 

void keyboard(unsigned char key, int x, int y) 
{ 
	switch(key) 
	{ 
	case 'f': // Avanza hacia adelante 5 unidades
		desp -= 0.05f;
		break;
	case 'b': // Retrocede 5 unidades
		desp += 0.05f;
		break;
	case 'r': // Gira a la derecha 10 grados
		anguloCuboY -= 10.0f;
		break;
	case 'l': // Gira a la izquierda 10 grados
		anguloCuboY += 10.0f;
		break;
	case 'u': // Gira hacia arriba 10 grados
		anguloCuboX -= 10.0f;
		break;
	case 'd': // Gira hacia abajo 10 grados
		anguloCuboX += 1.00f;
		break;
	case 27:   // Escape 
		exit(0); 
		break; 
	} 
	glutPostRedisplay(); // Solicita redibujar la escena
} 

int main(int argc, char **argv) 
{ 
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
	glutInitWindowPosition(100, 100); 
	glutInitWindowSize(ancho, alto); 
	glutCreateWindow("Cubo 1"); 
	init(); 
	glutDisplayFunc(display); 
	glutReshapeFunc(reshape); 
	glutKeyboardFunc(keyboard); 
	glutMainLoop(); 
	return 0; 
}
