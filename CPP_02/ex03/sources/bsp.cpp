#include <Point.hpp>
#include <Fixed.hpp>

static Fixed	getTriangleArea(const Point p1, const Point p2, const Point p3);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea;
	// Fixed	area1;
	// Fixed	area2;
	// Fixed	area3;

	(void)point;
	totalArea = getTriangleArea(a, b, c);
	std::cout << "Triangle area 1 = " << totalArea.toFloat() << std::endl;
	return (1);
}

static Fixed	getTriangleArea(const Point p1, const Point p2, const Point p3)
{
	Fixed	areaFixedPoint;
	Fixed	resultX1;
	Fixed	resultX2;
	Fixed	resultX3;

	std::cout << "P1 - " << p1.getXFixedPoint() << " / " << p1.getYFixedPoint() << std::endl;
	std::cout << "P2 - " << p2.getXFixedPoint() << " / " << p2.getYFixedPoint() << std::endl;
	std::cout << "P3 - " << p3.getXFixedPoint() << " / " << p3.getYFixedPoint() << std::endl;
	resultX1 = p1.getXFixedPoint() * (p2.getYFixedPoint() - p3.getYFixedPoint());
	resultX2 = p2.getXFixedPoint() * (p3.getYFixedPoint() - p1.getYFixedPoint());
	resultX3 = p3.getXFixedPoint() * (p1.getYFixedPoint() - p2.getYFixedPoint());
	areaFixedPoint =  (resultX1 + resultX2 + resultX3) / 2;
	if (areaFixedPoint.toFloat() < 0)
		areaFixedPoint = Fixed(-1) * areaFixedPoint;
	return (areaFixedPoint);
}
