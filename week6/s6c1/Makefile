plot:Datos.dat
	python PLOTS_OscarHerrara_S6C1_EDO.py
Datos.dat:OscarHerrera_S6C1_EDO
	./EDO.out
OscarHerrera_S6C1_EDO:OscarHerrera_S6C1_EDO.cpp
	g++ OscarHerrera_S6C1_EDO.cpp -o EDO.out
clean:
	rm -f EDO.out datos.dat
