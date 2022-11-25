#include <Point.hpp>
#include <Fixed.hpp>

static Fixed	getTriangleArea(const Point p1, const Point p2, const Point p3);

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	totalArea;
	Fixed	area1;
	Fixed	area2;
	Fixed	area3;

	(void)point;
	totalArea = getTriangleArea(a, b, c);
	area1 = getTriangleArea(a, b, point);
	area2 = getTriangleArea(a, c, point);
	area3 = getTriangleArea(b, c, point);
	if (area1.toFloat() == 0 || area2.toFloat() == 0 || area3.toFloat() == 0)
		return (false);
	if (totalArea.toFloat() != area1.toFloat() + area2.toFloat() + area3.toFloat())
		return (false);
	return (true);
}

static Fixed	getTriangleArea(const Point p1, const Point p2, const Point p3)
{
	Fixed	areaFixedPoint;
	Fixed	resultX1;
	Fixed	resultX2;
	Fixed	resultX3;

	resultX1 = p1.getXFixedPoint() * (p2.getYFixedPoint() - p3.getYFixedPoint());
	resultX2 = p2.getXFixedPoint() * (p3.getYFixedPoint() - p1.getYFixedPoint());
	resultX3 = p3.getXFixedPoint() * (p1.getYFixedPoint() - p2.getYFixedPoint());
	areaFixedPoint =  (resultX1 + resultX2 + resultX3) / 2;
	if (areaFixedPoint < 0)
		areaFixedPoint = Fixed(-1) * areaFixedPoint;
	return (areaFixedPoint);
}
