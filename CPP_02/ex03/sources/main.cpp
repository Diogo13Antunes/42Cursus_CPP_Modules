#include <Fixed.hpp>
#include <Point.hpp>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point	p1(0.0f, 0.0f);
	Point	p2(0.0f, -2.0f);
	Point	p3(6.0f, 0.0f);
	Point	pFind_0(0.0f, 0.0f);
	Point	pFind_1(0.0f, 1.0f);
	Point	pFind_2(3.5f, -0.25f);
	Point	pFind_3(1.25f, -0.02f);

	std::cout << std::endl;

	std::cout << "Point 1 - " << pFind_0.getXFixedPoint() << " / " << pFind_0.getYFixedPoint() <<std::endl;
	if (bsp(p1, p2, p3, pFind_0) == true)
		std::cout << "The point is inside the triangle!" << std::endl;
	else
		std::cout << "The point is not inside the triangle!" << std::endl;

	std::cout << std::endl;

	std::cout << "Point 2 - " << pFind_1.getXFixedPoint() << " / " << pFind_1.getYFixedPoint() <<std::endl;
	if (bsp(p1, p2, p3, pFind_1) == true)
		std::cout << "The point is inside the triangle!" << std::endl;
	else
		std::cout << "The point is not inside the triangle!" << std::endl;

	std::cout << std::endl;

	std::cout << "Point 3 - " << pFind_2.getXFixedPoint() << " / " << pFind_2.getYFixedPoint() <<std::endl;
	if (bsp(p1, p2, p3, pFind_2) == true)
		std::cout << "The point is inside the triangle!" << std::endl;
	else
		std::cout << "The point is not inside the triangle!" << std::endl;

	std::cout << std::endl;

	std::cout << "Point 4 - " << pFind_3.getXFixedPoint() << " / " << pFind_3.getYFixedPoint() <<std::endl;
	if (bsp(p1, p2, p3, pFind_3) == true)
		std::cout << "The point is inside the triangle!" << std::endl;
	else
		std::cout << "The point is not inside the triangle!" << std::endl;

	std::cout << std::endl;
}
