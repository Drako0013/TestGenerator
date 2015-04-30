#include "test_generator.h"
#include "video_factory.h"
#include "frame.h"
#include "shape.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>

TestGenerator::TestGenerator()
{
}


TestGenerator::~TestGenerator()
{
}

void TestGenerator::GenerateTest(std::string dir, int width, int height, int shapesNo, int frames){
	std::cout << "Saving video " << dir << std::endl;
	VideoFactory vf(dir, width, height, 24);

	cv::Mat v(height, width, CV_8U);

	shapes.clear();
	for(int i = 0; i < shapesNo; i++){
		int color = 255 * (int)( (float)(i + 1) / (float)(shapesNo + 1));
		std::cout << "Color: " << color << std::endl;
		Shape s(0, color, 100, 100, i, i * 2, 2 * (i + 1) );
		shapes.push_back( s );
	}

	while(frames--){
		std::cout << "Processing frame " << frames << std::endl;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				v.at<uchar>(i, j) = 0;
			}
		}
		this->Draw(v);
		this->Update();
		vf.AddFrame(v);
	}
}

void TestGenerator::Draw(cv::Mat &mat){
	for(int i = 0; i < this->shapes.size(); i++){
		this->shapes[i].Draw(mat);
	}
}

void TestGenerator::Update(){
	for(int i = 0; i < this->shapes.size(); i++){
		this->shapes[i].Update();
	}
}
