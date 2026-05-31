all: run

executar: main.o noticia.o listaencadeada.o listacabcau.o 
	gcc main.o noticia.o listaencadeada.o listacabcau.o -o ED1Juliana

main.o: main.c
	gcc -c main.c

noticia.o: noticia.c
	gcc -c noticia.c

listaencadeada.o: listaencadeada.c
	gcc -c listaencadeada.c

listacabcau.o: listacabcau.c
	gcc -c listacabcau.c

run: executar
	.\ED1Juliana

clean:
	rm -f *.o ED1Juliana
	