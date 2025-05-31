all: bin compile run

bin:
	@mkdir -p bin

compile: bin
	@g++ -I include/ -o bin/program src/Gen.cpp src/Kromozom.cpp src/Dna.cpp src/main.cpp

run:
	@bin/program
