#include "shape.h"

#define WHITE 0xff;

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
			mat.at<uchar>(i + this->posY, j + this->posX) = this->color;
		}
	}
}

void Shape::DrawBorder(cv::Mat &mat, int bsize){
	for (int i = -bsize; i < this->size + bsize; i++){
		for (int j = -bsize; j < this->size + bsize; j++){
			if (i < bsize || i >= this->size || j < bsize || j >= this->size) {
				mat.at<uchar>(i + this->posY, j + this->posX) = WHITE;
			}
		}
	}
}


void Shape::addToFile( std::vector< std::vector< std::pair<float, float> > > &data){
	for(int i = 0; i < this->size; i++){
		for(int j = 0; j < this->size; j++){
			int y = i + this->posY;
			int x = j + this->posX;
			if( y >= 0 && y < data.size() && x >= 0 && x < data[0].size() ){
				data[y][x] = std::make_pair((float)this->velY, (float)this->velX);
			}
		}
	}
}
