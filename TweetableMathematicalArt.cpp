// NOTE: compile with g++ filename.cpp -std=c++11
 
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#define DIMX 1366
#define DIMY 768
#define _sq(x) ((x)*(x)) // square
#define _cb(x) abs((x)*(x)*(x)) // absolute value of cube
#define _cr(x) (unsigned char)(pow((x),1.0/3.0)) // cube root

using namespace std;
 
unsigned char GR(int,int);
unsigned char BL(int,int);
unsigned char RD(int i,int j){
double a=0,b=0,c,d,n=0;
while((c=a*a)+(d=b*b)<4&&n++<880)
{b=2*a*b+j*8e-9-.645411;a=c-d+i*8e-9+.356888;}
return 255*pow((n-80)/800,3.);
}
 
unsigned char GR(int i,int j){
double a=0,b=0,c,d,n=0;
while((c=a*a)+(d=b*b)<4&&n++<880)
{b=2*a*b+j*8e-9-.645411;a=c-d+i*8e-9+.356888;}
return 255*pow((n-80)/800,.7);
}
 
unsigned char BL(int i,int j){
double a=0,b=0,c,d,n=0;
while((c=a*a)+(d=b*b)<4&&n++<880)
{b=2*a*b+j*8e-9-.645411;a=c-d+i*8e-9+.356888;}
return 255*pow((n-80)/800,.5);
}
 
void pixel_write(int,int);
FILE *fp;
int main(){
    fp = fopen("MathPic.ppm","wb");
    fprintf(fp, "P6\n%d %d\n255\n", DIMX, DIMY);
    for(int j=0;j<DIMY;j++)
        for(int i=0;i<DIMX;i++)
            pixel_write(i,j);
    fclose(fp);
    return 0;
}
void pixel_write(int i, int j){
    static unsigned char color[3];
    i -= 350;
    color[0] = RD(i,j)&255;
    color[1] = GR(i,j)&255;
    color[2] = BL(i,j)&255;
    fwrite(color, 1, 3, fp);
}