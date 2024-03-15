plot:Datos.dat
	python PLOTS_OscarHerrara_S6C2_EDO.py
Datos.dat:HerreraOscar_S6C2_EDO
	./EDO.out
HerreraOscar_S6C2_EDO:HerreraOscar_S6C2_EDO.cpp
	g++ HerreraOscar_S6C2_EDO.cpp -o EDO.out
clean:
	rm -f EDO.out datos.dat
