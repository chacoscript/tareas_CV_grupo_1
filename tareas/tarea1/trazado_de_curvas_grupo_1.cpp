#include <GL/glut.h>
#include <stdio.h>

int x1, y1, x2, y2;

void reshape(int width, int height)
{
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100, 100, -100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}

void write_pixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex3f(x, y, 0);
	glEnd();
}

void parabola(float a, float b, float c)
{
	glColor3f(1.0, 0.0, 0.0);  // Color rojo para la parábola
	glPointSize(4.0);
	for (int x = -100; x <= 100; x++)
	{
		float y = a * x * x + b * x + c; // Ecuación de la parábola
		write_pixel(x, y);
	}
}

void display()
{
	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0, 0, 0); // Color verde para los ejes
	glLoadIdentity();
	
	// Dibujar ejes X y Y
	glBegin(GL_LINES);
	glVertex2i(-100, 0);
	glVertex2i(100, 0); // Eje X
	glVertex2i(0, -100);
	glVertex2i(0, 100); // Eje Y
	glEnd();
	
	printf("Ingrese los coeficientes de la parabola (a, b, c): ");
	float a, b, c;
	scanf("%f %f %f", &a, &b, &c);
	parabola(a, b, c); // Dibujar la parábola con los coeficientes ingresados por el usuario
	
	glFlush();
}

void init()
{
	glClearColor(0.839, 0.667, 0.349, 1.0); // Color de fondo moztasa
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 50);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Parabola con OpenGL");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
