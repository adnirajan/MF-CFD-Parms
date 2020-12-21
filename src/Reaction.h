
/**********************************************************
	Header file for reaction definition
	Program name: Reaction.h
	Nirajan Adhikari (04-23-2020)
**********************************************************/
#ifndef _REACTION_H
#define _REACTION_H

#include <cmath>
#include "Species.h"

class Reaction{
	public:
		double get_collision_mu(void);
		double get_MF_alpha(void);
		double get_MF_C1(void);
		double get_MF_C2(void);
		std::string get_Rxn_label(void);
		void def_rxn(Species AB, Species CD);
		Reaction(void);
		Reaction(Species *AB, Species *CD);
		~Reaction(void);

	private:
		Species diss_molecule;
		Species coll_partner;
};

#endif