#include<windows.h>
#include <stdio.h>
#include <math.h>
#include<cmath>
#include<stdlib.h>
#include <GL/glut.h>

int X1, Y1, X2, Y2;

void init2D(float r,float g,float b){
    glClearColor(r,g,b,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}

void midpoint(void)
{
  int dx=(X2-X1);
  int dy=(Y2-Y1);
  int d=dy-(dx/2);
  glClear(GL_COLOR_BUFFER_BIT);
  int x;
  int y;
  x=X1;
  y=Y1;
  glBegin(GL_POINTS);
  glVertex2d(x,y);

  while(x<X2){

        x++;

        if(d<0)
            d=d+dy;
        else{
            d+=(dy-dx);
            y++;
        }
            glVertex2d(x,y);
    }
  glEnd();

  glFlush();
}
void Init()
{
  glClearColor(1.0,1.0,1.0,0);
  glColor3f(0.0,0.0,0.0);
  gluOrtho2D(0 , 640 , 0 , 480);
}
int main(int argc, char **argv)
{
  printf("Enter two end points of the line to be drawn:\n");
  printf("\n************************************");
  printf("\nEnter Point1( X1 , Y1):\n");
  scanf("%d%d",&X1,&Y1);
  printf("\n************************************");
  printf("\nEnter Point1( X2 , Y2):\n");
  scanf("%d%d",&X2,&Y2);

  glutInit(&argc,argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowPosition(0,0);
  glutInitWindowSize(640,480);
  glutCreateWindow("midpoint");
  Init();
  glutDisplayFunc(midpoint);
  glutMainLoop();
  return 0;
}
