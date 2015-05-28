// TestGenerator.cpp : Defines the entry point for the console application.
//
#include "test_generator.h"

int main(int argc, char* argv[]){
	TestGenerator tG(std::string(argv[1]), 480, 360, 24);

	if( argc > 2 ){
		tG.GenerateTest(std::string(argv[2]), 30);
	} else {
		tG.GenerateTest(5, 30);
	}

	return 0;
}

