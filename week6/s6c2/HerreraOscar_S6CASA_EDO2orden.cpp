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
const double b=0.08;

void RungeKutta (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool er,bool frig);
void Euler (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool er,bool frig);
void LeadFrog_E(double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool frig);
void LeadFrog_RK(double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool frig);

void Error(std::array<double,N> t,std::array<double,N> x,std::string name);//NOTA:la funcion error solo se hizo para el caso sin friccion

int main(){
	double t_fin=10;
	double h = t_fin/N;
	std::array<double,N> t;
	std::array<double,N> v_x;
	v_x[0]=v_0;
    std::array<double,N> x;
	x[0]=x_0;
    bool frigccion=false;
    bool error=true;
	Euler(h,t,v_x,x,"DatosE2.dat",error,frigccion);
	RungeKutta(h,t,v_x,x,"DatosRK2.dat",error,frigccion);
    LeadFrog_E(h,t,v_x,x,"DatLFE.dat",frigccion);
    LeadFrog_RK(h,t,v_x,x,"DatLFRK.dat",frigccion);    
return 0;
}
void Error(std::array<double,N> t,std::array<double,N> x,std::string name){
ofstream outfile;
outfile.open(name);
double y,ey;
for(int i=0;i<N;i++){
        y=(v_0/sqrt(k/m)*sin(sqrt(k/m)*t[i])+x_0*cos(sqrt(k/m)*t[i]));      //Caso sin amortiguamiento
        y=(v_0/sqrt(k/m)*sin(sqrt(k/m)*t[i])+x_0*cos(sqrt(k/m)*t[i]));      //Caso con amortiguamiento
		ey=y-x[i];
		outfile << t[i] <<" "<< ey << endl;
		}
outfile.close();
}

void Euler (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool er,bool frig){
ofstream outfile;
outfile.open(name);
outfile << t[0] <<" "<<x[0] << endl;	
if (frig==true)
{
    for(int i=0;i<N-1;i++){
		t[i+1]   = t[i]+h;
		v_x[i+1] = v_x[i]-k/m*h*x[i]-b*h*v_x[i];        //con friccion
		x[i+1]   = x[i]+h*v_x[i+1];
		outfile << t[i+1] <<" "<<x[i+1] << endl;
		}
}else
{
   for(int i=0;i<N-1;i++){
		t[i+1]   = t[i]+h;
		v_x[i+1] = v_x[i]-k/m*h*x[i];                //Sin friccion
		x[i+1]   = x[i]+h*v_x[i+1];
		outfile << t[i+1] <<" "<<x[i+1] << endl;
		}
}
outfile.close();
if (er == true)
{
    Error(t,x,"ErrorE2.dat");
}
}

void RungeKutta (double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool er,bool frig){
	ofstream outfile;
	outfile.open(name);
	outfile << t[0] <<" "<<x[0] << endl;
	double Kx1,Kx2,Kx3,Kx4,Kv1,Kv2,Kv3,Kv4;
    if (frig==true)
    {
        for(int i=0;i<N-1;i++){		
                        //Con Friccion
		Kx1=h*(-k/m*x[i]-b*v_x[i]);
		Kx2=h*(-k/m*x[i]-b*v_x[i]+Kx1/2.0);
		Kx3=h*(-k/m*x[i]-b*v_x[i]+Kx2/2.0);
		Kx4=h*(-k/m*x[i]-b*v_x[i]+Kx3);

        v_x[i+1]=v_x[i]+(1.0/6.0)*(Kx1+2.0*Kx2+2.0*Kx3+Kx4);

		Kv1=h*v_x[i+1];
		Kv2=h*(v_x[i+1]+Kv1/2.0);
		Kv3=h*(v_x[i+1]+Kv2/2.0);
		Kv4=h*(v_x[i+1]+Kv3);

		t[i+1]=t[i]+h;
		x[i+1]=x[i]+(1.0/6.0)*(Kv1+2.0*Kv2+2.0*Kv3+Kv4);

		outfile << t[i+1] <<" "<<x[i+1] << endl;
    }
    }else
    {
        for(int i=0;i<N-1;i++){
                        //Sin Friccion
        Kx1=-h*k/m*x[i];
		Kx2=-h*(k/m*x[i]+Kx1/2.0);
		Kx3=-h*(k/m*x[i]+Kx2/2.0);
		Kx4=-h*(k/m*x[i]+Kx3);

        v_x[i+1]=v_x[i]+(1.0/6.0)*(Kx1+2.0*Kx2+2.0*Kx3+Kx4);

		Kv1=h*v_x[i+1];
		Kv2=h*(v_x[i+1]+Kv1/2.0);
		Kv3=h*(v_x[i+1]+Kv2/2.0);
		Kv4=h*(v_x[i+1]+Kv3);

		t[i+1]=t[i]+h;
		x[i+1]=x[i]+(1.0/6.0)*(Kv1+2.0*Kv2+2.0*Kv3+Kv4);

		outfile << t[i+1] <<" "<<x[i+1] << endl;
    }
    }
    
    
	
outfile.close();
if (er==true)
{
    Error(t,x,"ErrorRK2.dat");
}
}

void LeadFrog_E(double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool frig){
    double h2=h/2;
    v_x[0]=v_x[0]-k/m*h2*x[0]-b*h2*v_x[0];
	Euler(h,t,v_x,x,name,false,frig);
}

void LeadFrog_RK(double h,std::array<double,N> t,std::array<double,N> v_x,std::array<double,N> x,std::string name,bool frig){
    double h2=h/2;
    v_x[0]=v_x[0]-k/m*h2*x[0]-b*h2*v_x[0];
	RungeKutta(h,t,v_x,x,name,false,frig);
}

