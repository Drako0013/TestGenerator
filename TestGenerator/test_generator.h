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
	static void GenerateTest(std::string dir, int width, int height, int speed);
	void Draw(cv::Mat &mat);

private:
	std::string fileName;
	int width;
	int height;
	int speed;
	std::vector<Shape> shapes;

};

