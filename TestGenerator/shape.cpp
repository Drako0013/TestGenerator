#include "shape.h"

Shape::Shape(int type, int color){
	this->type = type;
	this->color = color;
	this->size = rand() % 30;
	this->velX = rand() % 50;
	this->velY = rand() % 50;
}

void Shape::Draw(cv::Mat &mat){
	
}

