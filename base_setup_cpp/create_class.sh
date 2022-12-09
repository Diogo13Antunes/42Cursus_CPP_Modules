cd includes
touch $1.hpp

echo "#pragma once" >> $1.hpp
echo "" >> $1.hpp
echo "class $1" >> $1.hpp
echo "{" >> $1.hpp
echo "	public:" >> $1.hpp
echo "		$1 &operator=(const $1 &src);" >> $1.hpp
echo "		$1(const $1 &src);" >> $1.hpp
echo "		$1();" >> $1.hpp
echo "		~$1();" >> $1.hpp
echo "};" >> $1.hpp
echo "" >> $1.hpp

cd ..
cd sources
touch $1.cpp

echo "#include <$1.hpp>" >> $1.cpp
echo "" >> $1.cpp
echo "$1::$1()\n{\n	//Default $1 Constructor\n}\n" >> $1.cpp
echo "" >> $1.cpp
echo "$1::$1(const $1 &src)\n{\n	//$1 Copy Constructor\n}\n" >> $1.cpp
echo "" >> $1.cpp
echo "$1::~$1()\n{\n	//Default $1 Destructor\n}\n" >> $1.cpp
echo "" >> $1.cpp
echo "$1 &$1::operator=(const $1 &src)\n{\n	//$1 Copy Assignment Operator\n}\n" >> $1.cpp
echo "" >> $1.cpp

cd ..
