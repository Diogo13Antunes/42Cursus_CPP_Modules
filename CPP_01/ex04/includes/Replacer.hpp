#pragma once

#include <fstream>
#include <iostream>
#include "Terminal.hpp"
#include "head.hpp"

class Replacer
{
    public:
        int         setFile(std::string newFile);

        void        setString1(std::string str1);
        std::string getString1(void) const;
        void        setString2(std::string str2);
        std::string getString2(void) const;

        void	    createNewFile(void);

        void        makeReplace(void);

        Replacer();
        ~Replacer();

    private:
        std::string     fileName;
        std::string     newFileName;
        std::string     finalString;
        std::fstream    oldFile;
        std::fstream    newFile;
        std::string     string1;
        std::string     string2;
};
