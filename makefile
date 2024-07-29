Tum :derleme calistirma


derleme:
	g++ -I ./include/ -o ./lib/Yigin.o -c ./src/Yigin.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/Bst.o -c ./src/Bst.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/SayilarListesi.o -c ./src/SayilarListesi.cpp	
	g++ -I ./include/ -o ./bin/Test ./lib/Bst.o ./lib/Dugum.o ./lib/Node.o ./lib/SayilarListesi.o ./lib/Yigin.o ./src/Test.cpp
	


calistirma:
	./bin/Test
	