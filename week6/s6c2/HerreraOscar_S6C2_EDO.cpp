#include<iostream>
#include<cstdlib>
#include<fstream>
#include<array>
#include<cmath>

using namespace std;
const int N=1000	;

int main(){
	double t_fin=10;
	double n = 1000;
	double h = t_fin/n;
	std::array<double,N> x;
	x[0]=0;
	std::array<double,N> y;
	y[0]=1;
	ofstream outfile;
	outfile.open("datos.dat");
	outfile << x[0] <<" "<<y[0] << endl;
	//EULER
// 	for(int i=0;i<N-1;i++){
// 		x[i+1]=x[i]+h;
// 		y[i+1]=y[i]-h*y[i];
// 		outfile << x[i+1] <<" "<<y[i+1] << endl;
// 	}
	std::cout<<h;
	double K1,K2,K3,K4;
	for(int i=0;i<N-1;i++){
		K1=-h*y[i];
		K2=-h*(y[i]+K1/2);
		K3=-h*(y[i]+K2/2);
		K4=-h*(y[i]+K3);
		x[i+1]=x[i]+h;
		y[i+1]=y[i]+(1/6)*(K1+2*K2+2*K3+K4);
		std::cout<<y[i+1];
		// outfile << x[i+1] <<" "<<y[i+1] << endl;
	}
	outfile.close();
return 0;
}
/*
std::array<double,N>RungeKutta(std::array<double,N>x,std::array<double,N>y,double h){
	for(int i=0;i<N;i++){
		K1=h*y[i];
		K2=h*(y[i]+K1/2);
		k3=h*(y[i]+k2/2);
		K4=h*(y[i]+K3);
		x[i+1]=x[i]+h;
		y[i+1]=y[i]+1-6*(K1+2*K2+2*K3+K4);
	}
	return y;
}*/
