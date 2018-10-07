#include"PrintShapes.h"
#include"Shapes.h"
#include"Tools.h"
#include<string>
using namespace std;
using namespace tools;
using namespace shapes;

namespace printShapes
{
	void PrintShapes(string prompt)
	{
		int option, size;
		bool shapeSolid;
		do
		{
			option = getOption(prompt);
			size = getSize("Please enter a size for the shape: ");
			shapeSolid = getBool("Do you want the shape solid? ");
			PrintShape(option, size, shapeSolid);
		} while (getBool("Do you want to do another? "));
	}

	void PrintShape(int option, int size, bool shapeSolid)
	{
		switch (option)
		{
		case 1:
			printSquare(size, shapeSolid);
			break;
		case 2:
			triangleRightAngle_Southwest(size, shapeSolid);
			break;
		case 3:
			triangleRightAngle_Southeast(size, shapeSolid);
			break;
		case 4:
			triangleRightAngle_Northwest(size, shapeSolid);
			break;
		case 5:
			triangleRightAngle_Northeast(size, shapeSolid);
			break;
		case 6:
			triangleRightAngle_North(size, shapeSolid);
			break;
		case 7:
			triangleRightAngle_East(size, shapeSolid);
			break;
		case 8:
			triangleRightAngle_West(size, shapeSolid);
			break;
		case 9:
			triangleRightAngle_South(size, shapeSolid);
			break;
		case 10:
			printCircle(size, shapeSolid);
			break;
		}
	}
}