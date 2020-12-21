/**********************************************************
	Header file for species definition
	Program name: Species_Defintion.cpp
	Nirajan Adhikari (04-23-2020)
**********************************************************/
#ifndef _ELEMENTS_H
#define _ELEMENTS_H

#include <string>

class Element{
	public:
		std::string symbol;
		double atom_wt;
		Element (void);
		Element(std::string sym, double wt);
};

#endif 