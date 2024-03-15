resultados.pdf: resultados.tex plot.pdf plot1.pdf
	pdflatex resultados.tex
plot.pdf:plotdatos.py
	python plotdatos.py
plot1.pdf:plotdatos1.py
	python plotdatos1.py
plotdatos.py:makedatos.py
	python makedatos.py
plotdatos1.py:makedatos.py
	g++ makedatos1.cpp -o makedatos1
	./makedatos1
clean:
	rm -f plot.pdf plot1.pdf datos.dat datos1.dat resultados.aux resultados.log makedatos1.exe