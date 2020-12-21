/**********************************************************
	Main file for species definition
	Program name: Species_Definition.cpp
	Nirajan Adhikari (04-23-2020)
**********************************************************/

#include "Species.h"

Species::Species(){
	//nothing to do
}
Species::Species(Element *mem){
	no_of_atom = 1;
	Elem = new Element[no_of_atom];
	Elem[0] = *mem;
}
Species::Species(Element *mem1, Element *mem2){
	no_of_atom = 2;
	Elem = new Element[no_of_atom];
	Elem[0] = *mem1;
	Elem[1] = *mem2;
}
Species::~Species(){
	//
}
double Species::get_MW(){
	double sum = 0.0;
	for(int i = 0; i < no_of_atom; i++){
		sum += Elem[i].atom_wt;
	}
	return sum;
}
double Species::get_reduced_mass(){
	double mu = get_MW();
	double num = 1.0, denom = 1e-16;
	if(no_of_atom != 1){
		for(int i = 0; i < no_of_atom; i++){
			num *= Elem[i].atom_wt;
			denom += Elem[i].atom_wt;
		}
		mu = num/denom;
	}
	return mu;
}
double Species::get_mw1(){
	return Elem[0].atom_wt;
}
std::string Species::get_symbol(){
	if(no_of_atom == 1) return Elem[0].symbol;
	else if( Elem[0].symbol == Elem[1].symbol) return Elem[0].symbol + "2";
		else return Elem[0].symbol + Elem[1].symbol;
}
void Species::def_species(Element mem1, Element mem2){
	no_of_atom = 2;
	Elem = new Element[no_of_atom];
	Elem[0] = mem1;
	Elem[1] = mem2;
}
void Species::def_species(Element mem1){
	no_of_atom = 1;
	Elem = new Element[no_of_atom];
	Elem[0] = mem1;
}