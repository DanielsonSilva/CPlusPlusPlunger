//---------------------------------------------------------------------------


#pragma hdrstop

#include "VariaveisAuxiliares.h"

#include<stdlib.h>
#include <fstream>
using namespace std;

VariaveisAuxiliares* VariaveisAuxiliares :: instance = NULL ;
bool VariaveisAuxiliares :: instanceFlag = false ;

VariaveisAuxiliares* VariaveisAuxiliares :: getInstance() {
		if ( ! instanceFlag ){
				VariaveisAuxiliares :: instance = new VariaveisAuxiliares();
				instanceFlag = true;
		}
		return VariaveisAuxiliares :: instance;
}

void VariaveisAuxiliares::Limpar() {
	this->init();
}

VariaveisAuxiliares::VariaveisAuxiliares()
{
	this->init();
}

void VariaveisAuxiliares::init() {
	this->Ntotal    = 0;
	this->PtbgB     = 0;
	this->save_Hplg = 0;
	this->CP        = 0;
	this->LslgX     = 0;
	this->velocity  = 0;
	this->H         = 0;
	this->delta_h   = 0;
	this->delta_v   = 0;
	this->temp      = 0;
	this->templ     = 0;
	this->Ppart_csg = 0;
	this->Ppart_tbg = 0;
	this->V         = 0;
	this->delta_V   = 0;
	this->PPcsg     = 0;
	this->N         = 0;
	this->PP        = 0;
	this->TT        = 0;
	this->z         = 0;
	this->B         = 0;
	this->transient = 0;
	this->n         = 0;
	this->qq        = 0;
	this->qqq       = 0;
	this->nn        = 0;
	this->ppp       = 0;
	this->y         = 0;
	this->Pt        = 0;
	this->fatorT    = 0;
	this->fatorB    = 0;
	this->APIapar   = 0;
	this->I         = 0;
	this->Pfric     = 0;
	this->j         = 0;
    this->cont3		= 0;
	this->k         = 0;
	this->m         = 0;
	this->LtbgY     = 0;
	this->LtbgZ     = 0;
	this->flag      = 0;
	this->d         = 0;
	this->i         = 0;
	this->o         = 0;
	this->u         = 0;
	this->Ptt       = 0;
	this->PplgJ     = 0;
	this->PplgM     = 0;
	this->Visc      = 0;
	this->Rey       = 0;
	this->Fric      = 0;
	this->Pwf       = 0;
	this->Vt        = 0;
	this->TTt       = 0;
	this->Nt        = 0;
	this->v0        = 0;
	this->save_v0   = 0;
	this->Na        = 0;
	this->save_Na   = 0;
	this->save_PPt  = 0;
	this->p_        = 0;
	this->PPt       = 0;
	this->Pbt       = 0;
	this->F_        = 0;
	this->Pba       = 0;
	this->Nt_       = 0;
	this->Ntt       = 0;
	this->delta_P   = 0;
	this->count     = 0;
	this->contador  = 0;
	this->cont      = 0;
	this->limite    = 0;
	this->LtbgX     = 0;
	this->q         = 0;
	this->temp_Offtime   = 0;
	this->production     = 0;
	this->total_production = 0;
	this->piston_arrival = 0;
	this->save_Offtime   = 0;
	this->save_Afterflow = 0;
	this->save_PPcsg     = 0;
	this->save_PplgM     = 0;
}
//---------------------------------------------------------------------------
/**
 * @brief Prints the variables from the class
 * @param file File that the variables will be printed
 */
void VariaveisAuxiliares::imprimirVariaveis(ofstream& file) {
    file << "Auxiliary Variables Data:\n";
    file << "Ntotal = " << this->Ntotal << "\n";
    file << "PtbgB = " << this->PtbgB << "\n";
    file << "save_Hplg = " << this->save_Hplg << "\n";
    file << "CP = " << this->CP << "\n";
    file << "LslgX = " << this->LslgX << "\n";
    file << "velocity = " << this->velocity << "\n";
    file << "H = " << this->H << "\n";
    file << "delta_h = " << this->delta_h << "\n";
    file << "delta_v = " << this->delta_v << "\n";
    file << "temp_Offtime = " << this->temp_Offtime << "\n";
    file << "temp = " << this->temp << "\n";
    file << "templ = " << this->templ << "\n";
    file << "Ppart_csg = " << this->Ppart_csg << "\n";
    file << "Ppart_tbg = " << this->Ppart_tbg << "\n";
    file << "V = " << this->V << "\n";
    file << "delta_V = " << this->delta_V << "\n";
    file << "PPcsg = " << this->PPcsg << "\n";
    file << "N = " << this->N << "\n";
    file << "PP = " << this->PP << "\n";
    file << "TT = " << this->TT << "\n";
    file << "z = " << this->z << "\n";
    file << "B = " << this->B << "\n";
    file << "transient = " << this->transient << "\n";
    file << "n = " << this->n << "\n";
    file << "q = " << this->q << "\n";
    file << "qq = " << this->qq << "\n";
    file << "qqq = " << this->qqq << "\n";
    file << "nn = " << this->nn << "\n";
    file << "ppp = " << this->ppp << "\n";
    file << "y = " << this->y << "\n";
    file << "Pt = " << this->Pt << "\n";
    file << "fatorT = " << this->fatorT << "\n";
    file << "fatorB = " << this->fatorB << "\n";
    file << "APIapar = " << this->APIapar << "\n";
    file << "I = " << this->I << "\n";
    file << "Pfric = " << this->Pfric << "\n";
    file << "j = " << this->j << "\n";
    file << "cont3 = " << this->cont3 << "\n";
    file << "k = " << this->k << "\n";
    file << "m = " << this->m << "\n";
    file << "LtbgY = " << this->LtbgY << "\n";
    file << "LtbgX = " << this->LtbgX << "\n";
    file << "LtbgZ = " << this->LtbgZ << "\n";
    file << "flag = " << this->flag << "\n";
    file << "d = " << this->d << "\n";
    file << "i = " << this->i << "\n";
    file << "o = " << this->o << "\n";
    file << "u = " << this->u << "\n";
    file << "Ptt = " << this->Ptt << "\n";
    file << "PplgJ = " << this->PplgJ << "\n";
    file << "PplgM = " << this->PplgM << "\n";
    file << "save_PplgM = " << this->save_PplgM << "\n";
    file << "Visc = " << this->Visc << "\n";
    file << "Rey = " << this->Rey << "\n";
    file << "Fric = " << this->Fric << "\n";
    file << "Pwf = " << this->Pwf << "\n";
    file << "Vt = " << this->Vt << "\n";
    file << "TTt = " << this->TTt << "\n";
    file << "Nt = " << this->Nt << "\n";
    file << "v0 = " << this->v0 << "\n";
    file << "save_v0 = " << this->save_v0 << "\n";
    file << "Na = " << this->Na << "\n";
    file << "save_Na = " << this->save_Na << "\n";
    file << "save_PPt = " << this->save_PPt << "\n";
    file << "save_PPcsg = " << this->save_PPcsg << "\n";
    file << "p_ = " << this->p_ << "\n";
    file << "PPt = " << this->PPt << "\n";
    file << "Pbt = " << this->Pbt << "\n";
    file << "F_ = " << this->F_ << "\n";
    file << "Pba = " << this->Pba << "\n";
    file << "Nt_ = " << this->Nt_ << "\n";
    file << "Ntt = " << this->Ntt << "\n";
    file << "delta_P = " << this->delta_P << "\n";
    file << "piston_arrival = " << this->piston_arrival << "\n";
    file << "count = " << this->count << "\n";
    file << "save_Offtime = " << this->save_Offtime << "\n";
    file << "save_Afterflow = " << this->save_Afterflow << "\n";
    file << "contador = " << this->contador << "\n";
    file << "cont = " << this->cont << "\n";
    file << "production = " << this->production << "\n";
    file << "total_production = " << this->total_production << "\n";
    file << "limite = " << this->limite << "\n";
    file << "Cav = " << this->Cav << "\n";
    file << "--------------------------------\n";
}
//---------------------------------------------------------------------------
#pragma package(smart_init)
