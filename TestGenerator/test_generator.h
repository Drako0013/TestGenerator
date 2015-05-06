#pragma once

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>
#include "shape.h"

class TestGenerator
{
public:
	TestGenerator(std::string dir, int width, int height, int fps);
	~TestGenerator();
	void GenerateTest(int shapesNo, int frames);
	void Draw(cv::Mat &mat);
	void Update();
	void saveFile(int frame);

private:
	std::string fileName;
	int width;
	int height;
	int fps;
	std::vector<Shape> shapes;

};

