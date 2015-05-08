#ifndef SHAPE_H_
#define SHAPE_H_

#include <cstdlib>
#include <ctime>

#include "opencv2/imgproc/imgproc.hpp"

class Shape{
public:
	Shape( int type, int color, int posX, int posY, int velX, int velY, int size );
	//~Shape();
	void Draw(cv::Mat &mat);
	void DrawBorder(cv::Mat &mat, int size);
	void Update();
	void addToFile(std::vector< std::vector< std::pair<float, float> > > &data);

private:
	int type;
	int color;
	int size;
	int posX;
	int posY;
	int velX;
	int velY;

};

#endif