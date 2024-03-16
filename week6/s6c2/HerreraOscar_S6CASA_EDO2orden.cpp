#include<iostream>
#include<cstdlib>
#include<fstream>
#include<array>
#include<cmath>

using namespace std;
const int N=1000;
const double k=15;
const double m=5;
const double v_0=0;
const double x_0=0.1;
void RungeKutta (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name);
void Euler (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name);
void Error(std::array<double,N> t,std::array<double,N> x,std::string name);

int main(){
	double t_fin=10;
	double h = t_fin/N;
	std::array<double,N> t;
	std::array<double,N> v_x;
	v_x[0]=v_0;
    std::array<double,N> x;
	x[0]=x_0;

	Euler(h,t,v_x,x,"DatosE2.dat");
	RungeKutta(h,t,v_x,x,"DatosRK2.dat");

return 0;
}
void Error(std::array<double,N> t,std::array<double,N> x,std::string name){
ofstream outfile;
outfile.open(name);
double y,ey;
for(int i=0;i<N;i++){
        y=(v_0/sqrt(k/m)*sin(sqrt(k/m)*t[i])+x_0*cos(sqrt(k/m)*t[i]));
		ey=y-x[i];//Caso sin amortiguamiento
		outfile << t[i] <<" "<< ey << endl;
		}
outfile.close();
}

void Euler (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name){
ofstream outfile;
outfile.open(name);
outfile << t[0] <<" "<<x[0] << endl;		
for(int i=0;i<N-1;i++){
		t[i+1]   = t[i]+h;
		v_x[i+1] = v_x[i]-k/m*h*x[i];
		x[i+1]   = x[i]+h*v_x[i];
		outfile << t[i+1] <<" "<<x[i+1] << endl;
		}
outfile.close();

Error(t,x,"ErrorE2.dat");
}

void RungeKutta (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name){
	ofstream outfile;
	outfile.open(name);
	outfile << t[0] <<" "<<x[0] << endl;
	double K11,K12,K13,K14,K21,K22,K23,K24;
	for(int i=0;i<N-1;i++){
		K11=h*v_x[i];
		K12=h*(v_x[i]+K11/2.0);
		K13=h*(v_x[i]+K12/2.0);
		K14=h*(v_x[i]+K13);

		K21=h*k/m*x[i];
		K22=h*(k/m*x[i]+K11/2.0);
		K23=h*(k/m*x[i]+K12/2.0);
		K24=h*(k/m*x[i]+K13);

		t[i+1]=t[i]+h;
		v_x[i+1]=v_x[i]+(1.0/6.0)*(K21+2.0*K22+2.0*K23+K24);
		x[i+1]=x[i]-(1.0/6.0)*(K11+2.0*K12+2.0*K13+K14);

		outfile << t[i+1] <<" "<<x[i+1] << endl;
	}
outfile.close();
Error(t,x,"ErrorRK2.dat");
}