/**********************************************************
	Header file for species definition
	Program name: Species_Defintion.cpp
	Nirajan Adhikari (04-23-2020)
**********************************************************/
#ifndef _SPECIES_H
#define _SPECIES_H

#include "Elements.h"

class Species{
	public:
		int no_of_atom;
		double get_MW(void);
		double get_reduced_mass(void);
		double get_mw1(void);
		std::string get_symbol(void);
		void def_species(Element mem1, Element mem2);
		void def_species(Element mem1);
		Species(void);
		Species(Element *mem);
		Species(Element *mem1, Element *mem2);
		~Species(void);

	private:
		Element *Elem;
};

#endif 