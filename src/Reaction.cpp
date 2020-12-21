
/**********************************************************
	Main file for reaction definition
	Program name: Reaction.cpp
	Nirajan Adhikari (04-23-2020)
**********************************************************/

#include "Reaction.h"

Reaction::Reaction(){
	//nothing to do
}
Reaction::Reaction(Species *AB, Species *CD){
	diss_molecule = *AB;
	coll_partner = *CD;
	//cout << "Address AB = " << AB << " Address of diss_molecule = " << &diss_molecule << endl;
}
Reaction::~Reaction(){
	//
}
double Reaction::get_collision_mu(){
	double mu;
	return mu = (diss_molecule.get_MW() * coll_partner.get_MW())/(diss_molecule.get_MW() + coll_partner.get_MW());
}
double Reaction::get_MF_alpha(){
	double alpha, alpha_min = 1e+3;
	double diss_mol_wt[diss_molecule.no_of_atom], coll_mol_wt[coll_partner.no_of_atom];
	diss_mol_wt[0] = diss_molecule.get_mw1();
	if(diss_molecule.no_of_atom == 2) 
		diss_mol_wt[1] = diss_molecule.get_MW() - diss_molecule.get_mw1();
	coll_mol_wt[0] = coll_partner.get_mw1();
	if(coll_partner.no_of_atom == 2) 
		coll_mol_wt[1] = coll_partner.get_MW() - coll_partner.get_mw1();

	int i,j;
	double mu1 = diss_molecule.get_reduced_mass(), m_d, Mc;
	for (i = 0; i < diss_molecule.no_of_atom; ++i) {
		for (j = 0; j < coll_partner.no_of_atom; ++j) {
			m_d = diss_mol_wt[i];
			Mc = coll_mol_wt[j];
			alpha = 1.0 - 2.0 *  mu1 / m_d * Mc /(m_d + Mc); 
			alpha_min = (alpha_min < alpha) ? alpha_min : alpha;
		}
	}
	return alpha_min*alpha_min;
}
double Reaction::get_MF_C1(){
	if (coll_partner.no_of_atom == 1) return 1.0;
	else{ 
		double alpha, alpha_min = 1e+3;
		double diss_mol_wt[diss_molecule.no_of_atom], coll_mol_wt[coll_partner.no_of_atom];
		diss_mol_wt[0] = diss_molecule.get_mw1();
		if(diss_molecule.no_of_atom == 2) 
			diss_mol_wt[1] = diss_molecule.get_MW() - diss_molecule.get_mw1();
		coll_mol_wt[0] = coll_partner.get_mw1();
		if(coll_partner.no_of_atom == 2) 
			coll_mol_wt[1] = coll_partner.get_MW() - coll_partner.get_mw1();

		int i,j;
		double m_d, Mc, m, M;
		double mu1 = diss_molecule.get_reduced_mass();
		double mu = get_collision_mu();
		for (i = 0; i < diss_molecule.no_of_atom; ++i) {
			for (j = 0; j < coll_partner.no_of_atom; ++j) {
				m_d = diss_mol_wt[i];
				Mc = coll_mol_wt[j];
				alpha = 1.0 - 2.0 *  mu1 / m_d * Mc /(m_d + Mc); 
				if (alpha < alpha_min){
					alpha_min = alpha;
					m = m_d;
					M = Mc;
				}
			}
		}
		alpha = alpha_min;
		alpha *= alpha;
		return mu * mu1 /(m * m) / (1.0 - sqrt(alpha));
	}
}
double Reaction::get_MF_C2(){
	if (coll_partner.no_of_atom == 1) return 1.0;
	else{ 
		double alpha, alpha_min = 1e+3;
		double diss_mol_wt[diss_molecule.no_of_atom], coll_mol_wt[coll_partner.no_of_atom];
		diss_mol_wt[0] = diss_molecule.get_mw1();
		if(diss_molecule.no_of_atom == 2) 
			diss_mol_wt[1] = diss_molecule.get_MW() - diss_molecule.get_mw1();
		coll_mol_wt[0] = coll_partner.get_mw1();
		if(coll_partner.no_of_atom == 2) 
			coll_mol_wt[1] = coll_partner.get_MW() - coll_partner.get_mw1();

		int i,j;
		double m_d, Mc, m, M;
		double mu1 = diss_molecule.get_reduced_mass(), mu2 = coll_partner.get_reduced_mass();
		for (i = 0; i < diss_molecule.no_of_atom; ++i) {
			for (j = 0; j < coll_partner.no_of_atom; ++j) {
				m_d = diss_mol_wt[i];
				Mc = coll_mol_wt[j];
				alpha = 1.0 - 2.0 *  mu1 / m_d * Mc /(m_d + Mc); 
				if (alpha < alpha_min){
					alpha_min = alpha;
					m = m_d;
					M = Mc;
				}
			}
		}
		alpha = alpha_min;
		alpha *= alpha;
		return sqrt((1.0 - sqrt(alpha)) / sqrt(alpha)) * sqrt(mu2/mu1) * m/M;
	}
}
std::string Reaction::get_Rxn_label(){
	return diss_molecule.get_symbol() + " + " + coll_partner.get_symbol();
}
void Reaction::def_rxn(Species AB, Species CD){
	diss_molecule = AB;
	coll_partner = CD;
}
