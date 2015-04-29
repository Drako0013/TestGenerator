#include <cstdlib>
#include <ctime>

#include "opencv2/imgproc/imgproc.hpp"

class Shape{
public:
	Shape( int type, int color );
	~Shape();
	void Draw(cv::Mat &mat);
	void Update();

private:
	int type;
	int color;
	int size;
	int posX;
	int posY;
	int velX;
	int velY;

};