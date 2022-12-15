#pragma once

class Data
{
	public:
		Data &operator=(const Data &src);
		Data(const Data &src);
		Data(void);
		~Data(void);
};
