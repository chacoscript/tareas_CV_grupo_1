#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

void anillo(float R, float y, int N) {
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < N; ++i) {
		float angle = (2 * M_PI * i) / N;
		glVertex3f(R * cos(angle), y, R * sin(angle));
	}
	glEnd();
}

void drawCone(float height, float radius, int segments) {
	for (int i = 0; i <= segments; ++i) {
		float y = (float)i * height / segments;
		float r = radius * (1.0f - y / height);
		anillo(r, y, segments);
	}
}

void drawSphere(float radius, int slices, int stacks) {
	for (int i = 0; i <= stacks; ++i) {
		float y = radius * cos(M_PI * i / stacks);
		float r = sqrt(radius * radius - y * y);
		anillo(r, y, slices);
	}
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f, 0.0f, 0.0f);  // Red color
	
	glPushMatrix();
	glTranslatef(-25.0f, 0.0f, 0.0f); // mover a la izquierda
	glScalef(1.0f, 1.0f, 1.0f); // Scale down
	// Draw the cone
	drawCone(50.0f, 25.0f, 25);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(50.0f, 0.0f, 0.0f); // mover a la derecha
	glScalef(0.5f, 0.5f, 0.5f); // Scale down
	glColor3f(0.0f, 0.0f, 1.0f);  // Blue color
	// Draw the sphere
	drawSphere(50.0f, 25, 25);
	glPopMatrix();
	
	glFlush();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (float)w / (float)h, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0, 0, 200, 0, 0, 0, 0, 1, 0);
}

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 1.0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(200, 30);
	glutCreateWindow(argv[0]);
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
