#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
using namespace std;

int X1,Y1,r;

void plot(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x+X1,y+Y1);
    glEnd();
}

void init(){
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(0.0,0.0,0.0);
    glPointSize(4.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,640.0,0.0,480.0);
}

void midpointcircle(){

    int x=0;
    int y=r;
    int decision=1-r;
    plot(x,y);
    plot(-x,y);
    plot(-x,-y);
    plot(x,-y);
    while(y>x){
        if(decision<0){
            x++;
            decision+=2*x+1;
        }
        else{
            y--;
            x++;
            decision+=2*(x-y)+1;
        }
        plot(x,y);
        plot(x,-y);
        plot(-x, y);
		plot(-x, -y);
		plot(y, x);
		plot(-y, x);
		plot(y, -x);
		plot(-y, -x);
    }
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    midpointcircle();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0.0, 0.0, w, h);
}
int main(int argc,char** argv){

    printf("Enter the coordinates of center\n");
    scanf("%d %d",&X1,&Y1);
    printf("Enter the radius of the circle\n");
    scanf("%d",&r);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Circle drawing");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;

}
