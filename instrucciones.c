#include "instrucciones.h"


void ADDS(int *Rd,int Rn,int Rm){

        *Rd=Rn+Rm;


        }

void AND(int *Rd,int Rm){


        *Rd&=Rm;


         };

void EOR(int *Rd,int Rm){

         *Rd^=Rm;

        };

void MOV(int *Rd,int Rm){

        *Rd=Rm;

        };

void ORR(int *Rd,int Rm){

        *Rd|=Rm;

        };

void SUB(int *Rd,int Rn,int Rm){

         *Rd=Rn-Rm;

        };
