// Integrar una ec. dif. ordinaria de 1er orden por Runge-Kutta 4
#include <iostream>
#include <cmath>
using namespace std;

const double T=2*M_PI;
const double Omega=2*M_PI/T;

double f1(double t,double x1,double x2){
  return -Omega*Omega*x2;
}
double f2(double t,double x1,double x2){
  return x1;
}
void UnPasoRungeKutta4(double & t,double & x1,double & x2,double dt){
  double dx11,dx21,dx31,dx41;                    double dx12,dx22,dx32,dx42;
  dx11=dt*f1(t,x1,x2);                           dx12=dt*f2(t,x1,x2);
  dx21=dt*f1(t+0.5*dt,x1+0.5*dx11,x2+0.5*dx12);  dx22=dt*f2(t+0.5*dt,x1+0.5*dx11,x2+0.5*dx12);
  dx31=dt*f1(t+0.5*dt,x1+0.5*dx21,x2+0.5*dx22);  dx32=dt*f2(t+0.5*dt,x1+0.5*dx21,x2+0.5*dx22);
  dx41=dt*f1(t+dt,x1+dx31,x2+dx32);              dx42=dt*f2(t+dt,x1+dx31,x2+dx32);

  x1+=(dx11+2*(dx21+dx31)+dx41)/6;               x2+=(dx12+2*(dx22+dx32)+dx42)/6;
  t+=dt;
}
  
int main(void){
  double t,x1,x2;
  double dt=0.1;
  
  for(t=0,x1=1,x2=0;t<10; ){
    cout<<t<<" "<<x1<<" "<<x2<<endl;
    UnPasoRungeKutta4(t,x1,x2,dt);
  }
  
  return 0;
}

  
