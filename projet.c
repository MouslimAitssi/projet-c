#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitionc.h"

int main(int argc, char const *argv[])
{
	
    char mot_de_passe[60];

    printf("\ndonner le mot de passe:\t");
   gets(mot_de_passe);
    //if(mot_de_passe==key) menu();
 	
    while(strcmp(mot_de_passe,key)!=0){
    	system("cls");
    	printf("\nMOT DE PASSE INCORRECT !!!");
    	printf("\nReessayer avec le mot de passe:\t");
    	gets(mot_de_passe);
    	//pause();
    }
    menu();
	return 0;
}