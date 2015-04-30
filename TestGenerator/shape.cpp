#include "shape.h"

Shape::Shape(int type, int color, int posX, int posY, int velX, int velY, int size){
	this->type = type;
	this->color = color;
	this->posX = posX;
	this->posY = posY;
	this->size = size;
	this->velX = velX;
	this->velY = velY;
}

void Shape::Update(){
	this->posX += this->velX;
	this->posY += this->velY;
}

void Shape::Draw(cv::Mat &mat){
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			mat.at<uchar>(i + this->posY, j + this->posY) = this->color;
		}
	}
}

