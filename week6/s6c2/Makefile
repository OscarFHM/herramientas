DatosEDO = datosE.dat datosRK.dat ErrorE.dat ErrorRK.dat
DatosEDO2 = DatosE2.dat
Plots = solucion.jpg Error.jpg
plot2 = solucionEdo2.jpg

all: programa

programa: plot1 plot2

plot1:PLOTS_OscarHerrara_S6C2_EDO.py DatosEDO
	python PLOTS_OscarHerrara_S6C2_EDO.py
DatosEDO:EDO.out 
	./EDO.out
EDO.out: HerreraOscar_S6CASA_EDO.cpp
	g++ HerreraOscar_S6CASA_EDO.cpp -o EDO.out

plot2:PLOTS_OscarHerrara_S6CASA_EDO.py DatosEDO2
	python PLOTS_OscarHerrara_S6CASA_EDO.py
DatosEDO2:EDO2.out 
	./EDO2.out
EDO2.out: HerreraOscar_S6CASA_EDO2orden.cpp
	g++ HerreraOscar_S6CASA_EDO2orden.cpp -o EDO2.out


clean:	
	rm -f  *.dat *.out 
clearall:
	rm -f  *.dat *.out *.jpg *.pdf *.png
