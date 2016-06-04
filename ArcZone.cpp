#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

#define PI 3.141592654



int main(int argc, char* argv[])
{
	if(argc < 2)
		{
			std::cout << "Error: Need output file name" << std::endl;
			return -1;
		}
//	std::cout << argc;

	float centerX, centerY, innerRadius,outerRadius, startAngle, totalAngle;
	int resolution;

	std::cout << "Center X:" << std::endl;
	std::cin >> centerX;

	std::cout << "\r\nCenter Y:" << std::endl;
	std::cin >> centerY;

	std::cout << "\r\n Inner Radius: " << std::endl;
	std::cin >> innerRadius;
	
	std::cout << "\r\nOuter Radius: " <<std::endl;
	std::cin >> outerRadius;
	
	std::cout << "\r\nStart Angle: " << std::endl;
	std::cin >> startAngle;
	startAngle *= PI/180.; //convert to radians

	std::cout << "\r\nTotal Angle: " << std::endl;
	std::cin >> totalAngle;
	totalAngle *= PI/180.; //Convert to radians

	std::cout << "\r\nResolution: " << std::endl;
	std::cin >> resolution;
	
	int numPoints = resolution * 2; 
//	float points[numpoints][2];
	
	int i = 0;
	int j = 0;
	double x, y, angle;
//	j = 0; // 0 = x, 1 = y
	
//	std::string listOfPoints;
//	std::string temp;

//Calculate point coordinates


//


//Start file stream -- always output to this.
	std::ofstream coordOut(argv[1]);
//	coordOut << "Hello There";

//Add poly preamble
	coordOut << "     (polygon" << std::endl << "      (pts" << std::endl;

//Add coordinates
	

	i = 0;
	j = 0;
	while(i < numPoints)
	{
	
		angle = (double) totalAngle * j / (resolution - 1);
		if(i < resolution)
		{
			x = centerX + innerRadius * std::cos(angle);
			y = centerY + innerRadius * std::sin(angle);
			j++; //Increment Angle
		}else 
		{
			x = centerX + outerRadius * std::cos(angle);
			y = centerY + outerRadius * std::sin(angle);
			j--; //Decrement Angle
		}
		//debug
		std::cout << i << std::endl;
		std::cout << "x: " << x << std::endl;
		std::cout << "y: " << y << std::endl;
		std::cout << "A: " << angle << std::endl;
		//temp = "(xy " +  std::to_string(x) + " " + std::to_string(y) + ") " 
//		points[i][0] = centerX + radius * std::cos(angle);
//		points[i][1] = centerY + radius * std::sin(angle);
	//	listOfPoints.append(temp);
		coordOut <<  "(xy " << std::to_string(x) << " " << std::to_string(y) << ") ";
		i++;
	}

//Add final parentheses
	coordOut << std::endl << "      )" << std::endl << "     )" <<std::endl;

//Filled polygon
	coordOut << "     (filled_polygon" << std::endl << "      (pts" << std::endl;

//Add coordinates

//coordOut << "Change this" << std::endl;
	
	i = 0;
	j = 0;
	while(i < numPoints)
	{
	
		angle = (double) totalAngle * j / (resolution - 1);
		if(i < resolution)
		{
			x = centerX + innerRadius * std::cos(angle);
			y = centerY + innerRadius * std::sin(angle);
			j++; //Increment Angle
		}else 
		{
			x = centerX + outerRadius * std::cos(angle);
			y = centerY + outerRadius * std::sin(angle);
			j--; //Decrement Angle
		}

		//temp = "(xy " +  std::to_string(x) + " " + std::to_string(y) + ") " 
//		points[i][0] = centerX + radius * std::cos(angle);
//		points[i][1] = centerY + radius * std::sin(angle);
	//	listOfPoints.append(temp);
		coordOut <<  "(xy " << std::to_string(x) << " " << std::to_string(y) << ") ";
		i++;
	}

//Add final parentheses	
	coordOut << std::endl << "      )" << std::endl << "     )" <<std::endl;

	coordOut.close();
	
//	std::cout << "El Fin";
	return 0;

}
