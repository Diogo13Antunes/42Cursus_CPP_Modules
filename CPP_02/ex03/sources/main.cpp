#include <Fixed.hpp>
#include <Point.hpp>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main()
{
	Point	p1(1.3f, 1.0f);
	Point	p2(1.3f, -2.0f);
	Point	p3(6.4f, 0.0f);
	Point	pFind(1.0f, 1.0f);

	bsp(p1, p2, p3, pFind);
}
