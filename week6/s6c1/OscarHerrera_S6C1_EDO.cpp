#include<iostream>
#include<cstdlib>
#include<fstream>
#include<cmath>

using namespace std;

int main(){
	float t_fin=10;
	float h=0.1;
	int N=t_fin/h;
	float x[N];
	x[0]=0;
	float y[N];
	y[0]=1;
	ofstream outfile;
	outfile.open("datos.dat");
	outfile << x[0] <<" "<<y[0] << endl;
	for(int i=0;i<N-1;i++){
		x[i+1]=x[i]+h;
		y[i+1]=y[i]-h*y[i];
		outfile << x[i+1] <<" "<<y[i+1] << endl;
	}
	outfile.close();
return 0;
}
