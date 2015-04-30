#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include "shape.h"

class TestGenerator
{
public:
	TestGenerator();
	~TestGenerator();
	void GenerateTest(std::string dir, int width, int height, int shapesNo, int frames);
	void Draw(cv::Mat &mat);
	void Update();

private:
	std::string fileName;
	int width;
	int height;
	int speed;
	std::vector<Shape> shapes;

};

