#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
using namespace std;

int X1,Y1,rx,ry;

void plot(int x,int y){
    glBegin(GL_POINTS);
    glVertex2i(x+X1,y+Y1);
    glVertex2i(X1-x,Y1-y);
    glVertex2i(X1+x,Y1-y);
    glVertex2i(X1-x,Y1+y);
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

void midpointellipse(){

        int x,y;
        float d1,d2,dx,dy;
        x=0;y=ry;
        d1=pow(ry,2)-(pow(rx,2)*ry)+(0.25*(pow(rx,2)));
        dx=2*(pow(ry,2))*x;
        dy=2*y*(pow(rx,2));
        do{
            plot(x,y);
            if(d1<0){
                x++;
                dx += (2 * (pow(ry,2)));
                d1 +=dx +(pow(ry,2));
            }
            else{
                x++;y--;
                dx+=2*(pow(ry,2));
                dy-=(2*(pow(rx,2)));
                d1+=dx-dy+pow(ry,2);
            }
        }while(dx<dy);
        d2=d1;
        do{
            plot(x,y);
            if(d2>0){
              y--;
              dy-=(2*(pow(rx,2)));
              d2-=dy+pow(rx,2);
            }
            else{
                x++;
                y--;
                dy -= (2 * (pow(rx,2)));
                dx += (2 * (pow(ry,2)));
                d2 +=dx - dy + pow(rx,2);
            }
        }while(y>0);
}


void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.0,0.0);
    glPointSize(1.0);
    midpointellipse();
    glFlush();
}

void reshape(int w, int h)
{
    glViewport(0.0, 0.0, w, h);
}
int main(int argc,char** argv){

    printf("Enter the coordinates of center\n");
    scanf("%d %d",&X1,&Y1);
    printf("Enter the radius x-direction\n");
    scanf("%d",&rx);
    printf("Enter the radius y-direction\n");
    scanf("%d",&ry);

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(100,100);
    glutCreateWindow("Ellipse drawing");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;

}
