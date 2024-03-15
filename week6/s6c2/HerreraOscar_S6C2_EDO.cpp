#include<iostream>
#include<cstdlib>
#include<fstream>
#include<array>
#include<cmath>

using namespace std;
const int N=10000	;
void RungeKutta (double h,std::array<double,N> x,std::array<double,N> y);

void Euler (double h,std::array<double,N> x,std::array<double,N> y);

int main(){
	double t_fin=1;
	double h = t_fin/N;
	std::array<double,N> x;
	x[0]=0;
	std::array<double,N> y;
	y[0]=1;
	// Euler(h,x,y);
	RungeKutta(h,x,y);
return 0;
}

void Euler (double h,std::array<double,N> x,std::array<double,N> y){
for(int i=0;i<N-1;i++){
		ofstream outfile;
		outfile.open("datos.dat");
		outfile << x[0] <<" "<<y[0] << endl;
		x[i+1]=x[i]+h;
		y[i+1]=y[i]-h*y[i];
		outfile << x[i+1] <<" "<<y[i+1] << endl;
		}
}

void RungeKutta (double h,std::array<double,N> x,std::array<double,N> y){
	ofstream outfile;
	outfile.open("datos.dat");
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
}