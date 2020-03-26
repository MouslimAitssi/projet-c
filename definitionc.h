#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define vrai 1
#define faux 0
#define key "0000"
#define Malloc(t,n) (t*)malloc(n*sizeof(t))



typedef struct 
{
	int jour,annee,mois;
}Date;

typedef struct 
{
	char nom[25];
	char prenom[25];
	char sexe[25];
	int CIN;
	Date date;
	int nbr_enfants;
	int *T_id_enf;

}Personne;

typedef struct arbre
{
  Personne perso;
  struct arbre *gauche;
  struct arbre *droite;
}ARB;


Personne saisir_personne(void);
ARB *new_element(Personne p);
ARB *ajouter_noeud(ARB *racine,Personne p);
void consulter_arbre(ARB *racine);
void chercher_personne(ARB *racine,int X,int *r);
void Recherche_generale(ARB *racine);
void age_personne(ARB *racine,int X,int *age);
void age_personne_general(ARB *racine);
void Afficher_une_personne(ARB *racine,int X);
void Afficher_enfants(ARB *racine,int X);
void Afficher_enfants_general(ARB *racine);
void copier_personne(Personne *a,Personne *b);  
int count(ARB *racine);
void Passage_ARB_tab(ARB *racine,Personne *T,int *i);
Personne *Tri_Bulle_nom(Personne *T,int N);
void Affciher_tab(Personne *T,int N);
void Tri_arbre_nom(ARB *racine);
void Tri_arbre_CIN(ARB *racine);
void sauvegarder_fichier(ARB *racine);
ARB *charger_fichier(ARB *racine);
void pause();
void Imprimer_Actes_general(ARB *racine);
void Imprimer_Actes(ARB *racine,int code,char *pere,char *mere);
void menu();
char  *pere_personne(ARB *racine,int code,char *nom_pere);
char  *mere_personne(ARB *racine,int code,char *nom_mere);
void Afficher_parents(ARB *racine);
//void enfants(ARB *racine,int code);
void ajouter_enfants(int CIN ,ARB *racine);
void modifier_personne(int CIN,ARB *racine);

ARB * minArbre(ARB * racine) ;
ARB* supprimer_personne(ARB *racine, int CIN); 

