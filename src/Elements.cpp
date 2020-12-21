/**********************************************************
	Main file for species definition
	Program name: Species_Definition.cpp
	Nirajan Adhikari (04-23-2020)
**********************************************************/

#include "Elements.h"

Element::Element(){
	symbol = "";
	atom_wt = 0.0;
}
Element::Element(std::string sym, double wt){
	symbol = sym;
	atom_wt = wt;
}