/**********************************************************
	Program to calculate reaction parameters in MF models
	Program name: Determining_MF_parameters.cpp alias main
	Nirajan Adhikari (04-23-2020)
**********************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

#include "Elements.h"
#include "Species.h"
#include "Reaction.h"

using namespace std;

// Main function for the program
int main(int argc, char **argv){

	cout << setprecision(4) << fixed;// << scientific;

	Element Nitrogen("N", 14.0067);
	Element Oxygen  ("O", 15.9994);

	int N_spe = 5, N_Molecules = 3;
	
	int N_RXN = N_Molecules * N_spe;
	int i, j, k;

	// Species Definitions
	Species *Spe;
	Spe = new Species[N_spe];
	Spe[0].def_species(Nitrogen, Nitrogen); // N2
	Spe[1].def_species(Oxygen, Oxygen);		// O2
	Spe[2].def_species(Nitrogen, Oxygen);	// NO
	Spe[3].def_species(Nitrogen);			// N
	Spe[4].def_species(Oxygen);				// O

	// Reaction Definitions
	Reaction Rxn[N_RXN];
	for(j=0; j<N_Molecules; ++j)
		for(k=0; k<N_spe; ++k)
			Rxn[j*N_spe+k].def_rxn(Spe[j], Spe[k]);
	
	for(i=0; i<N_RXN; ++i)
		cout << i+1 <<"."<< Rxn[i].get_Rxn_label() <<  "\t\u03B1 = " << Rxn[i].get_MF_alpha() << " C1 = " << Rxn[i].get_MF_C1() << " C2 = " << Rxn[i].get_MF_C2() << endl;

	return 0;

}