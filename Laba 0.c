Лаба 1 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
	double x;
	double y;
} POINT;

typedef struct poly {
	int n;
	POINT *p;
} POLY;

double dist (POINT p1, POINT p2)
 {
  register double t;
  return sqrt( ( t=(p2.x-p1.x) )*t + ( t=(p2.y-p1.y) )*t);
 }
 
double perimeter ( POLY p)
 {
  double s;
  s=0;
    for (int i=0; i<p.n; i++)
         s+= dist(p.p[(i+1)%p.n], p.p[i]);
    return s;
  }
  

double area (POLY p)
  {
  	double s;
  s=0;
    for (int i=0;i<p.n; i++);
         s+= (p.p[(i+1)%p.n].x - p.p[(i)].x) * (p.p[(i+1)%p.n].y+p.p[(i)].y);
         return fabs (s/2);
  }
  
  double diameter ( POLY p)
    { double s;
s=0;
for (int i=0; i<p.n; i++)
s+= dist (p.p[i],p.p[i+1] ); 
	}


int main ( int argc, char*argv[])
 {
  FILE *F; 
  POLY p;
  
   F=fopen(argv[1],"r");
   
   
fscanf(F,"%d",&p.n);
p.p=malloc(p.n*sizeof(POINT));
   for (int i=0;i<p.n; i++)
   fscanf(F,"%lf%lf%lf%lf%lf%lf", &p.p[i].x,&p.p[i].y);
   printf("%lf %lf %lf %lf %lf %lf\n", dist( p.p[0], p.p[1]), dist(p.p[1],p.p[2]),perimeter(p), area(p),diameter(p));
   
 return 0;
}


Лаба 2
