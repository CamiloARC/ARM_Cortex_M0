#include "instrucciones.h"

#define HALF ((1<<31)-1)

void ADDS(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera)
{
     *Rd=Rn+Rm;




if( ( (Rn&HALF)==1 ) && ((Rm&HALF) ==1) && ((*Rd&HALF)==0)   )    {

    bandera->C=1;
}

else{

   bandera->C=0;
}


if( *Rd>(1<<31)    ){

    bandera->N=1;

}
else{

    bandera->N=0;

}


if(*Rd==0){

 bandera->Z=1;

}

else{

    bandera->Z=0;
}

if( (Rn&HALF) == (Rm&HALF)  ){

    if( (Rn&HALF)!= (*Rd&HALF) )
    {

 bandera->V=1;


}
 }
else{

     bandera->V=0;
}

}

void AND(unsigned long *Rd,unsigned long Rm,flags_t *bandera)
{
	*Rd&=Rm;

if( (*Rd&(1<<31-1)==1)&&(Rm&(1<<31-1)==1)&&(*Rd&(1<<31-1)==0)) {
bandera->C=1;
}

else{

   bandera->C=0;
}


if((*Rd&(1<<31))==(1<<31)){

    bandera->N=1;

}
else{

    bandera->N=0;

}
if(*Rd==0){

 bandera->Z=1;

}

else{

    bandera->Z=0;
}

if(((*Rd&((1<<31)-1))==(Rm&1<<31-1))!=(*Rd&1<<31-1)){

 bandera->V=1;


}
else{

     bandera->V=0;
}



};

void EOR(unsigned long *Rd,unsigned long Rm,flags_t *bandera)
{
	*Rd^=Rm;

if( (*Rd&(1<<31-1)==1)&&(Rm&(1<<31-1)==1)&&(*Rd&(1<<31-1)==0)) {
bandera->C=1;
}

else{

   bandera->C=0;
}


if((*Rd&(1<<31))==(1<<31)){

    bandera->N=1;

}
else{

    bandera->N=0;

}
if(*Rd==0){

 bandera->Z=1;

}

else{

    bandera->Z=0;
}

if(((*Rd&1<<31-1)==(Rm&1<<31-1))!=(*Rd&1<<31-1)){

 bandera->V=1;


}
else{

     bandera->V=0;
}




};

void MOV(unsigned long *Rd,unsigned long Rm,flags_t *bandera)
{
	*Rd=Rm;

if( (*Rd&(1<<31-1)==1)&&(Rm&(1<<31-1)==1)&&(*Rd&(1<<31-1)==0)) {
bandera->C=1;
}

else{

   bandera->C=0;
}


if((*Rd&(1<<31))==(1<<31)){

    bandera->N=1;

}
else{

    bandera->N=0;

}
if(*Rd==0){

 bandera->Z=1;

}

else{

    bandera->Z=0;
}

if(((*Rd&1<<31-1)==(Rm&1<<31-1))!=(*Rd&1<<31-1)){

 bandera->V=1;


}
else{

     bandera->V=0;
}





};

void ORR(unsigned long *Rd,unsigned long Rm,flags_t *bandera)
{
	*Rd|=Rm;

	if( (*Rd&(1<<31-1)==1)&&(Rm&(1<<31-1)==1)&&(*Rd&(1<<31-1)==0)) {
bandera->C=1;
}

else{

   bandera->C=0;
}


if((*Rd&(1<<31))==(1<<31)){

    bandera->N=1;

}
else{

    bandera->N=0;

}
if(*Rd==0){

 bandera->Z=1;

}

else{

    bandera->Z=0;
}

if(((*Rd&1<<31-1)==(Rm&1<<31-1))!=(*Rd&1<<31-1)){

 bandera->V=1;


}
else{

     bandera->V=0;
}




};

void SUB(unsigned long *Rd,unsigned long Rn,unsigned long Rm,flags_t *bandera)
{
	*Rd=Rn-Rm;



if( (Rn&(1<<31-1)==1)&&(Rm&(1<<31-1)==1)&&(*Rd&(1<<31-1)==0)) {
bandera->C=1;
}

else{

   bandera->C=0;
}


if((*Rd&(1<<31))==(1<<31)){

    bandera->N=1;

}
else{

    bandera->N=0;

}
if(*Rd==0){

 bandera->Z=1;

}

else{

    bandera->Z=0;
}

if(((Rn&1<<31-1)==(Rm&1<<31-1))!=(*Rd&1<<31-1)){

 bandera->V=1;


}
else{

     bandera->V=0;
}



};

