// TestGenerator.cpp : Defines the entry point for the console application.
//
#include "test_generator.h"

int main(int argc, char* argv[]){
	TestGenerator tG(std::string(argv[1]), 480, 360, 24);
	tG.GenerateTest(5, 30);

	return 0;
}

