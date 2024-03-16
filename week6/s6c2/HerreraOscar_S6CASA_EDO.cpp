#include<iostream>
#include<cstdlib>
#include<fstream>
#include<array>
#include<cmath>

using namespace std;
const int N=100000;

void RungeKutta (double h,std::array<double,N> x,std::array<double,N> y,std::string name);
void Euler (double h,std::array<double,N> x,std::array<double,N> y,std::string name);
void Error(std::array<double,N> x,std::array<double,N> y,std::string name);

int main(){
	double t_fin=10;
	double h = t_fin/N;
	std::array<double,N> x;
	x[0]=0;
	std::array<double,N> y;
	y[0]=1;

	Euler(h,x,y,"datosE.dat");
	RungeKutta(h,x,y,"datosRK.dat");

return 0;
}
void Error(std::array<double,N> x,std::array<double,N> y,std::string name){
ofstream outfile;
outfile.open(name);
double ey;
for(int i=0;i<N;i++){
		ey=exp(-x[i])-y[i];
		outfile << x[i] <<" "<< ey << endl;
		}
outfile.close();
}

void Euler (double h,std::array<double,N> x,std::array<double,N> y,std::string name){
ofstream outfile;
outfile.open(name);
outfile << x[0] <<" "<<y[0] << endl;		
for(int i=0;i<N-1;i++){
		x[i+1]=x[i]+h;
		y[i+1]=y[i]-h*y[i];
		outfile << x[i+1] <<" "<<y[i+1] << endl;
		}
outfile.close();

Error(x,y,"ErrorE.dat");
}

void RungeKutta (double h,std::array<double,N> x,std::array<double,N> y,std::string name){
	ofstream outfile;
	outfile.open(name);
	outfile << x[0] <<" "<<y[0] << endl;
	double K1,K2,K3,K4;
	for(int i=0;i<N-1;i++){
		K1=h*y[i];
		K2=h*(y[i]+K1/2.0);
		K3=h*(y[i]+K2/2.0);
		K4=h*(y[i]+K3);
		x[i+1]=x[i]+h;
		y[i+1]=y[i]-(1.0/6.0)*(K1+2.0*K2+2.0*K3+K4);
		outfile << x[i+1] <<" "<<y[i+1] << endl;
	}
outfile.close();
Error(x,y,"ErrorRK.dat");
}