#define _CRT_SECURE_NO_WARNINGS

#include "test_generator.h"
#include "video_factory.h"
#include "frame.h"
#include "shape.h"

#include <cstdlib>
#include <cstdio>
#include <iostream>

TestGenerator::TestGenerator(std::string dir, int width, int height, int fps){
	this->fileName = dir;
	this->fileName_border = dir + std::string("_border.avi");
	this->width = width;
	this->height = height;
	this->fps = fps;
}


TestGenerator::~TestGenerator(){
}

void TestGenerator::GenerateTest(int shapesNo, int frames){
	std::cout << "Saving video " << this->fileName << std::endl;
	VideoFactory vf(this->fileName, this->width, this->height, this->fps);
	VideoFactory vf_border(this->fileName_border, this->width, this->height, this->fps);

	cv::Mat v(this->height, this->width, CV_8U);
	cv::Mat b(this->height, this->width, CV_8U);

	shapes.clear();
	for(int i = 0; i < shapesNo; i++){
		int color = 255 * (i + 1) / (shapesNo + 1);
		std::cout << "Color: " << color << std::endl;
		Shape s(0, color, 100, 100, i, i * 2, 2 * (i + 1), 0, 0 );
		shapes.push_back( s );
	}

	int f = 0;
	while(frames--){
		std::cout << "Processing frame " << frames << std::endl;
		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				v.at<uchar>(i, j) = 0;
				b.at<uchar>(i, j) = 0;
			}
		}
		this->Draw(v);
		this->DrawBorder(b, 5);
		this->Update();
		vf.AddFrame(v);
		vf_border.AddFrame(b);
		this->saveFile(f);
		f++;
	}
}

void TestGenerator::GenerateTest(std::string shapesInfo, int frames){
	std::cout << "Saving video " << this->fileName << std::endl;
	VideoFactory vf(this->fileName, this->width, this->height, this->fps);
	VideoFactory vf_border(this->fileName_border, this->width, this->height, this->fps);

	cv::Mat v(this->height, this->width, CV_8U);
	cv::Mat b(this->height, this->width, CV_8U);

	int shapesNo = 0;
	FILE *in = fopen(shapesInfo.c_str(), "r");
	fscanf(in, "%d", &shapesNo);
	shapes.clear();
	for(int i = 0; i < shapesNo; i++){
		int color = 255 * (i + 1) / (shapesNo + 1);
		std::cout << "Color: " << color << std::endl;
		int posX = 0, posY = 0, velX = 0, velY = 0, size = 0, accelX = 0, accelY = 0;

		fscanf(in, "%d %d %d %d %d %d %d", &posX, &posY, &velX, &velY, &size, &accelX, &accelY);

		Shape s(0, color, posX, posY, velX, velY, size, accelX, accelY );
		shapes.push_back( s );
	}

	int f = 0;
	while(frames--){
		std::cout << "Processing frame " << frames << std::endl;
		for (int i = 0; i < this->height; i++) {
			for (int j = 0; j < this->width; j++) {
				v.at<uchar>(i, j) = 0;
				b.at<uchar>(i, j) = 0;
			}
		}
		this->Draw(v);
		this->DrawBorder(b, 5);
		this->Update();
		vf.AddFrame(v);
		vf_border.AddFrame(b);
		this->saveFile(f);
		f++;
	}

}

void TestGenerator::Draw(cv::Mat &mat){
	for(int i = 0; i < this->shapes.size(); i++){
		this->shapes[i].Draw(mat);
	}
}

void TestGenerator::DrawBorder(cv::Mat &mat, int size){
	for (int i = 0; i < this->shapes.size(); i++){
		this->shapes[i].DrawBorder(mat, size);
	}
}

void TestGenerator::Update(){
	for(int i = 0; i < this->shapes.size(); i++){
		this->shapes[i].Update();
	}
}

void TestGenerator::saveFile(int frame){
	std::string fileName = this->fileName + "_" + std::to_string(frame) + ".txt";
	FILE *out = fopen( fileName.c_str(), "w" );
	//version 1: just demonstrative
	//Not working for other shapes
	std::vector< std::vector< std::pair<float, float> > > frameFlowData( this->height );
	for(int i = 0; i < this->height; i++){
		for(int j = 0; j < this->width; j++){
			frameFlowData[i].push_back( std::make_pair(0.0, 0.0) );
		}
	}

	for(int i = 0; i < this->shapes.size(); i++){
		shapes[i].addToFile( frameFlowData );
	}

	for(int i = 0; i < this->height; i++){
		for(int j = 0; j < this->width; j++){
			fprintf(out, "(%.2f,%.2f)", frameFlowData[i][j].first, frameFlowData[i][j].second);
		}
		fprintf(out, "\n");
	}

}
