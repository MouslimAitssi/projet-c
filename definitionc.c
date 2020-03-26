#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitionc.h"

Personne saisir_personne()
{
	Personne p;
	int j;
	
	
	printf("\nDonner le nom de la Personne:\t");
	gets(p.nom);
	printf("\nDonner le prenom de la Personne:\t");
	gets(p.prenom);
	printf("\nDonner son sexe(homme/femme) :\t");
	gets(p.sexe);
	printf("\nDonner CIN:\t");
	scanf("%d",&p.CIN);
	printf("\nDonner sa date de naissance:");
	printf("\nLe jour:\t");
	scanf("%d",&p.date.jour);
	printf("\nLe mois:\t");
	scanf("%d",&p.date.mois);
	printf("\nL'annee':\t");
	scanf("%d",&p.date.annee);
	printf("\nDonner le nombre d'enfants de cette personne:\t");
	scanf("%d",&p.nbr_enfants);
    
    p.T_id_enf=Malloc(int,p.nbr_enfants);

    for(j=0;j<p.nbr_enfants;j++)
    {
    	printf("\nDonner l'identifiant de l'enfant Numero %d:\t",j+1);
    	scanf("%d",&p.T_id_enf[j]);
    }
    
	
	return p;
}

ARB *new_element(Personne p)
{

	ARB *ne;
	int i;

	ne=Malloc(ARB,1);
	if(ne==NULL)
	{
	    printf("\nerreur allocation dynamique");
	}
	else
	{
       	strcpy(ne->perso.nom,p.nom);
       	strcpy(ne->perso.prenom,p.prenom);
       	strcpy(ne->perso.sexe,p.sexe);
       	ne->perso.CIN=p.CIN;
       	ne->perso.date.jour=p.date.jour;
       	ne->perso.date.mois=p.date.mois;
       	ne->perso.date.annee=p.date.annee;
       	ne->perso.nbr_enfants=p.nbr_enfants;
       	ne->perso.T_id_enf=Malloc(int,p.nbr_enfants);
        for(i=0;i<p.nbr_enfants;i++)
        {
        	ne->perso.T_id_enf[i]=p.T_id_enf[i];
        }
      ne->gauche=NULL;
      ne->droite=NULL;
	}
	return ne;
}

ARB *ajouter_noeud(ARB *racine,Personne p)
{
	
	
	if(racine==NULL)
	{
	   
	   racine=new_element(p);
    }

    else
    {
    	if(racine->perso.CIN<p.CIN)
    	{
    		racine->droite=ajouter_noeud(racine->droite,p);

    	}
    	else if (racine->perso.CIN>p.CIN)
    	{
    		racine->gauche=ajouter_noeud(racine->gauche,p);
    	}
      else
      {
        printf("\nCe code CIN existe deja ");
        pause();
        return racine;
      }
    }
    return racine;
}


void chercher_personne(ARB *racine,int X,int *r)
{

	if(racine==NULL)
	{
	   
	   return;
	}
	else
	{
		if(racine->perso.CIN<X)
    	{
    		chercher_personne(racine->droite,X,r);

    	}
    	else if(racine->perso.CIN>X)
    	{
    		chercher_personne(racine->gauche,X,r);
    	}
    	else
    	{
    		*r=vrai;
    	}

	}

}

void Recherche_generale(ARB *racine)
{
	int X,r=faux;
	printf("\ndonner le code de la personne que vous cherchez\t");
	scanf("%d",&X);
	chercher_personne(racine,X,&r);
    if(r==vrai)
    {
    	printf("\nla personne existe");
    	pause();

    }
    else
    {
    	printf("\nce code ne correspond a aucune une personne");
    	pause();
    }
}






	void consulter_arbre(ARB *racine)
	{

	if(racine==NULL)
	{
		printf("\nliste vide"); return ;
	}
	printf("\n **** CIN :\t                         %d",racine->perso.CIN);
	printf("\n **** Nom :\t                         %s",racine->perso.nom);
	printf("\n **** Prenom :\t                         %s",racine->perso.prenom);
	printf("\n **** Sexe :\t                         %s",racine->perso.sexe);

	printf("\n **** date de naissance:\t         %d/%d/%d",racine->perso.date.jour,racine->perso.date.mois,racine->perso.date.annee);
	printf("\n **** le nombre de ses enfants: \t %d",racine->perso.nbr_enfants);
	     
    for(int i=0;i<racine->perso.nbr_enfants;i++)
    {
    	printf("\n ****le CIN de l'enfants Numero %d est :\t %d",i+1,racine->perso.T_id_enf[i]);

    }
    printf("\n________________________________________________________________________________________");
    if(racine->gauche!=NULL)
    consulter_arbre(racine->gauche);
  if(racine->droite!=NULL)
    consulter_arbre(racine->droite);
	}

	void age_personne(ARB *racine,int X,int *age)
	{
	if(racine==NULL)
	{
	   printf("\n cette personne n'existe pas");
     getchar();
     pause();
	   return;
	}
	else
	{
		if(racine->perso.CIN<X)
    	{
    		 age_personne(racine->droite,X,age);

    	}
    	else if(racine->perso.CIN>X)
    	{
    		age_personne(racine->gauche,X,age);
    	}
    	else
    	{
    		*age=2018-racine->perso.date.annee;
    	}

	}
	}
	void age_personne_general(ARB *racine)
	{
		int age=0,X;
		printf("\ndonner le CIN de la personne\t");
		scanf("%d",&X);
		age_personne(racine,X,&age);
    if(age!=0)
    {
		printf("\nl'age de cette personne est:%d annees",age);
    }
		pause();
	}
	
	
	
	


    void Afficher_une_personne(ARB *racine,int X)
    {
    	
    if(racine==NULL)
	{
	    
      
	   return;
	}
	    
		if (racine->perso.CIN==X)
    	
    	{  
    		
    		printf("\n **** CIN :\t                         %d",racine->perso.CIN);
			printf("\n **** Nom :\t                         %s",racine->perso.nom);
			printf("\n **** Prenom :\t                         %s",racine->perso.prenom);
			printf("\n **** Sexe :\t                         %s",racine->perso.sexe);

			printf("\n **** date de naissance:\t         %d/%d/%d",racine->perso.date.jour,racine->perso.date.mois,racine->perso.date.annee);
			printf("\n **** le nombre de ses enfants: \t %d",racine->perso.nbr_enfants);

			 for(int i=0;i<racine->perso.nbr_enfants;i++)
   			 {
    			printf("\n ****le CIN de l'enfants Numero %d est :\t %d",i+1,racine->perso.T_id_enf[i]);

   			 }
   			 printf("\n________________________________________________________________________________________");
   			 
            

    	}
    	
		   if(racine->perso.CIN<X) Afficher_une_personne(racine->droite,X);

    	
       	if(racine->perso.CIN>X) Afficher_une_personne(racine->gauche,X);

        //if (racine->gauche ==NULL){
          
        
       return;
   	    
    	 
	
    }
   
    void Afficher_enfants(ARB *racine,int X)
    {
          Personne *T;
          int N,i=0,ver=faux;
          N=count(racine);
          T=Malloc(Personne,N);
          Passage_ARB_tab(racine,T,&i);
          for (i = 0; i < N; i++)
          {
          	
             if(X==T[i].CIN)
             {
             	if(T[i].nbr_enfants==0)printf("\nil n'a pas d'enfants");
             	else
             	{
             		 for (int j = 0; j < T[i].nbr_enfants;j++)
             		 {
             		 
             		 	Afficher_une_personne(racine,T[i].T_id_enf[j]);
                  ver=vrai;
             		 }
             	}
             }
          }
          if(ver==faux)  
                  { printf("\ncette personne n'existe pas"); 
                    pause();}
          return;
    }
   
 	void Afficher_enfants_general(ARB *racine)
 	{
 	int X;
 	printf("\ndonner le code de la personne\t");
 	scanf("%d",&X);
    
     Afficher_enfants(racine,X);
     pause();
 	}

    //fonction qui copie un element b de type Personne dans un element a de meme type
    void copier_personne(Personne *a,Personne *b) 
    {   int i;
    	strcpy((*a).nom,(*b).nom);
        strcpy((*a).prenom,(*b).prenom);
        strcpy((*a).sexe,(*b).sexe);
        (*a).CIN=(*b).CIN;
        (*a).nbr_enfants=(*b).nbr_enfants;
        (*a).date.jour=(*b).date.jour;
        (*a).date.mois=(*b).date.mois;
        (*a).date.annee=(*b).date.annee;
       
        (*a).T_id_enf=Malloc(int,(*b).nbr_enfants);
        if((*a).T_id_enf==NULL) printf("\nerreur");
       else
       { for(i=0;i<(*b).nbr_enfants;i++)
        {
        	(*a).T_id_enf[i]=(*b).T_id_enf[i];
        }
       }
     }

     int count(ARB *racine)
     {
     	int c=1;
     	if(racine==NULL) return 0;
     	else
     	{
     		c=c+count(racine->gauche);
     		c=c+count(racine->droite);

     		return c;
     	}

      }
     //fonction qui copie une arbre dans un tableau 
     void Passage_ARB_tab(ARB *racine,Personne *T,int *i)
     {
     	if(racine==NULL) return ;
     	
     	
     		copier_personne(&T[*i],&(racine->perso));
     		(*i)++;
     		if(racine->gauche!=NULL) Passage_ARB_tab(racine->gauche,T,i);
     		if(racine->droite!=NULL) Passage_ARB_tab(racine->droite,T,i);  
     		  	
     }	 

     //fonction qui trie le tableau
    
     Personne *Tri_Bulle_nom(Personne *T,int N)
     {
     	Personne tmp;
     	for(int j=N-1;j>0;j--)   
     	{
     	 for(int i=0;i<j;i++)
     		{
               if(strcmp(T[i+1].nom,T[i].nom)<0)
               {
               	copier_personne(&tmp,&T[i]);
               	copier_personne(&T[i],&T[i+1]);
               	copier_personne(&T[i+1],&tmp);
               }
     		}
     	}
     	return T;
     }
     //fonction qui affiche le tableau
   void Affciher_tab(Personne *T,int N)
   {
    for(int i=0;i<N;i++)
    {
      
     printf("\n **** CIN :\t                         %d",T[i].CIN);
			printf("\n **** Nom :\t                         %s",T[i].nom);
			printf("\n **** Prenom :\t                         %s",T[i].prenom);
			printf("\n **** Sexe :\t                         %s",T[i].sexe);
			printf("\n **** date de naissance:\t         %d/%d/%d",T[i].date.jour,T[i].date.mois,T[i].date.annee);
			printf("\n **** le nombre de ses enfants: \t %d",T[i].nbr_enfants);
			 for(int j=0;j<T[i].nbr_enfants;j++)
   			 {
    			printf("\n ****le CIN de l'enfants Numero %d est :\t %d",j+1,T[i].T_id_enf[j]);

   			 }
   			 printf("\n____________________________________________________________________________");
      
    }
   }

    // fonction qui trie toute l'arbre
   void Tri_arbre_nom(ARB *racine)
   {
   	Personne *T;
   	int N=count(racine);
   	int i=0;
   	T=Malloc(Personne,N);
    Passage_ARB_tab(racine,T,&i);
    
   	T=Tri_Bulle_nom(T,N);
   	Affciher_tab(T,N);
   }
void Tri_arbre_CIN(ARB *racine)
{
 		if(racine==NULL) return;
 		Tri_arbre_CIN(racine->gauche);
 		Afficher_une_personne(racine,racine->perso.CIN);
 		Tri_arbre_CIN(racine->droite);
}
     
void sauvegarder_fichier(ARB *racine)
{
	int N,i=0,j;
	Personne *T;
	FILE *fichier;
	N=count(racine);
	T=Malloc(Personne,N);
    Passage_ARB_tab(racine,T,&i);
    fichier=fopen("pain.bin","wb+");
    if(fichier==NULL)
    {
    	printf("\nerreur de creation du fichier"); return;

    }
    fwrite(&N,sizeof(int),1,fichier);
    for(j=0;j<N;j++)
    {
    	
    	fwrite(T[j].nom,sizeof(T[j].nom),1,fichier);
    	fwrite(T[j].prenom,sizeof(T[j].prenom),1,fichier);
    	fwrite(T[j].sexe,sizeof(T[j].sexe),1,fichier);
    	fwrite(&T[j].CIN,sizeof(T[j].CIN),1,fichier);
    	fwrite(&T[j].date.jour,sizeof(T[j].date.jour),1,fichier);
    	fwrite(&T[j].date.mois,sizeof(T[j].date.mois),1,fichier);
    	fwrite(&T[j].date.annee,sizeof(T[j].date.annee),1,fichier);
    	fwrite(&T[j].nbr_enfants,sizeof(T[j].nbr_enfants),1,fichier);
    	for(i=0;i<T[j].nbr_enfants;i++)
    	{
    		fwrite(&T[j].T_id_enf[i],sizeof(int),1,fichier);
    		
    	}
    }
    fclose(fichier);

}

ARB *charger_fichier(ARB *racine)
{
	FILE *fichier;
	int i,j,N;

	Personne *T;
	fichier=fopen("pain.bin","rb");
	if(fichier==NULL) {
		 printf("\nerreur d'ouverture du fichier"); return racine;
	}
	
    fread(&N,sizeof(int),1,fichier);
     
     T=Malloc(Personne,N);
     for(j=0;j<N;j++)
    {
    	
    	fread(T[j].nom,sizeof(T[j].nom),1,fichier);
    	fread(T[j].prenom,sizeof(T[j].prenom),1,fichier);
    	fread(T[j].sexe,sizeof(T[j].sexe),1,fichier);
    	fread(&T[j].CIN,sizeof(T[j].CIN),1,fichier);
    	fread(&T[j].date.jour,sizeof(T[j].date.jour),1,fichier);
    	fread(&T[j].date.mois,sizeof(T[j].date.mois),1,fichier);
    	fread(&T[j].date.annee,sizeof(T[j].date.annee),1,fichier);
    	fread(&T[j].nbr_enfants,sizeof(T[j].nbr_enfants),1,fichier);
    	T[j].T_id_enf=Malloc(int,T[j].nbr_enfants);
    	for(i=0;i<T[j].nbr_enfants;i++)
    	{  
    		fread(&T[j].T_id_enf[i],sizeof(int),1,fichier);
    	     
    	}
    	racine=ajouter_noeud(racine,T[j]);
    }
    
    
  fclose(fichier);
  
  return racine;
}



char  *pere_personne(ARB *racine,int code,char *nom_pere)
{
	if(racine==NULL)  return nom_pere; 
    if((racine->perso.nbr_enfants!=0)&&(strcmp(racine->perso.sexe,"homme")==0)) // on verifie si la personne est un homme et qu'il a des enfants
    {
    	for (int i = 0; i < racine->perso.nbr_enfants; i++)
    	{
    		if(racine->perso.T_id_enf[i]==code) 
    		{
                  
             	strcpy(nom_pere,racine->perso.nom); 
             	strcat(nom_pere," ");
             	strcat(nom_pere,racine->perso.prenom);
             	return nom_pere;
               
    		}
    	}
    }
    if(racine->gauche!=NULL) pere_personne(racine->gauche,code,nom_pere);
    if(racine->droite!=NULL) pere_personne(racine->droite,code,nom_pere);
    return nom_pere;

}



char  *mere_personne(ARB *racine,int code,char *nom_mere)
{
	if(racine==NULL) return nom_mere; 
    if((racine->perso.nbr_enfants!=0)&&(strcmp(racine->perso.sexe,"femme")==0)) // on verifie si la personne est un homme et qu'il a des enfants
    {
    	for (int i = 0; i < racine->perso.nbr_enfants; i++)
    	{
    		if(racine->perso.T_id_enf[i]==code) 
    		{
                  
             	strcpy(nom_mere,racine->perso.nom); 
             	strcat(nom_mere," ");
             	strcat(nom_mere,racine->perso.prenom);
             	return nom_mere;
               
    		}
    	}
    }
    if(racine->gauche!=NULL) mere_personne(racine->gauche,code,nom_mere);
    if(racine->droite!=NULL) mere_personne(racine->droite,code,nom_mere);
    return nom_mere;

}


void Afficher_parents(ARB *racine)
{
	char nom_mere[60];
	char nom_pere[60];
	int code;
	printf("\n\ndonner le code de la personne:\t");
	scanf("%d",&code);
	getchar();
	strcpy(nom_mere,"sans");
	strcpy(nom_mere,mere_personne(racine,code,nom_mere));
	printf("\nle nom de la mere:\t%s",nom_mere);

	strcpy(nom_pere,"sans");
	strcpy(nom_pere,pere_personne(racine,code,nom_pere));
	printf("\nle nom du pere: \t%s",nom_pere);
	//pause();
}

void Imprimer_Actes(ARB *racine,int code,char *pere,char *mere)
{
	
 	int i,jj,aa,mm;
  FILE *fichier;
  char Ville[25],etat[25],nom_fichier[55],enociation[55];

 if(racine==NULL) {  printf("\nCette Personne n'existe pas ");
                     //pause();
                   return;}
 if(racine->perso.CIN==code)
 {       
 	
        
        
       
    
 	     strcat(nom_fichier,racine->perso.nom);
 	     strcat(nom_fichier,"_");
 	     strcat(nom_fichier,racine->perso.prenom);
 	     strcat(nom_fichier,".html");
  		fichier=fopen(nom_fichier,"w+");
  		if(fichier==NULL)
  		{
  			printf("\nerreur de creation du fichier"); pause(); return;
  		}
             
  		
      		
      		  
      		printf("\ndonnez votre ville:\t");
     	    gets(Ville);
            printf("\ndonnez autres enociations:\t");
     	    gets(enociation); 
     	    printf("\ndonnez la date de delivrance:\t");
     	    printf("\nle jour:\t");
     	    scanf("%d",&jj);
            printf("\nle mois:\t");
      		scanf("%d",&mm);
      		printf("\nl'annee:\t");
      		scanf("%d",&aa);
   fprintf(fichier,"\n<!DOCTYPE html>\n<html>\n<head>\n<style>\ntable {\nfont-family: arial;\nborder-collapse: collapse;\nwidth: 200%;}\nth, td {\npadding: 15px;\nborder: 1px solid blue;\ntext-align: left;}\n</style>\n</head>\n<body style=background-color:powderblue;>\n<h2 style=color:blue>Etat de sortie (Acte de naissance) </h2>\n<h3>1) ETAT:MAROC</h3><h3>2) ETAT CIVIL DE:  %s</h3>\n<table>\n<tr>\n<th colspan=3>3) EXTRAIT ACTE DE NAISSANCE NUMERO:</th>\n<td> %d</td>\n</tr>\n<tr>\n<th colspan=3>4) DATE DE NAISSANCE:</th>\n<td> %d/%d/%d</td>\n</tr>\n<tr>\n<th colspan=3>5) Nom</th>\n<td> %s</td>\n</tr>\n<tr>\n<th colspan=3>6) Prenom</th>\n<td> %s</td>\n</tr>\n<tr>\n<th>7) Sexe</th>\n<td> %s</td>\n<th >8 Pere </th>\n<th>9 Mere </th>\n</tr>\n<tr>\n<th colspan=2>5 Nom</th>\n<td> %s </td>\n<td> %s </td>\n</tr>\n<th colspan=3 >10) Autres enociations</th>\n<td> %s</td>\n</tr>\n<tr>\n<th colspan=3>11)Date de delivrance </th>\n<td> %d/%d/%d</td>\n</tr>\n</table>\n</body>\n</html>",Ville,racine->perso.CIN,racine->perso.date.jour,racine->perso.date.mois,racine->perso.date.annee,racine->perso.nom,racine->perso.prenom,racine->perso.sexe,pere,mere,enociation,jj,mm,aa );
            printf("\n c'est fait");
          
         fclose(fichier);
          pause();

  		
  }		
  if(racine->perso.CIN>code) Imprimer_Actes(racine->gauche,code,pere,mere);
  
  if(racine->perso.CIN<code){Imprimer_Actes(racine->droite,code,pere,mere);}
  
}
void Imprimer_Actes_general(ARB *racine)
{
	int code;
	char pere[20],mere[20];
	
	printf("\ndonner le code de la personne que vous voulez imprimer ses donnees:\t");
	scanf("%d",&code);
	strcpy(mere,"sans");
	strcpy(pere,"sans");
	strcpy(pere,pere_personne(racine,code,pere));
	strcpy(mere,mere_personne(racine,code,mere));
	
    getchar();
	Imprimer_Actes(racine,code,pere,mere);
}


ARB * minArbre(ARB * racine) 
{ 
    ARB * p = racine; 
  
    while (p->gauche != NULL) 
        p = p->gauche; 
  
    return p; 
}

ARB* supprimer_personne(ARB *racine, int CIN) 
{ 
    
    if (racine == NULL) {
      printf("\nla personne n'existe pas !!"); pause();
      return racine; 
    }
  
    if (CIN < racine->perso.CIN) 
        racine->gauche = supprimer_personne(racine->gauche,CIN); 

    else if (CIN > racine->perso.CIN) 
        racine->droite = supprimer_personne(racine->droite,CIN); 
  
    else
    { 
        if (racine->gauche == NULL) 
        { 
            ARB *ptr = racine->droite; 
            free(racine); 
            return ptr; 
        } 
        else if (racine->droite == NULL) 
        { 
            ARB * ptr = racine->gauche; 
            free(racine); 
            return ptr; 
        } 
  
        ARB * ptr = minArbre(racine->droite); 
  
        racine->perso.CIN =ptr->perso.CIN; 
  

        racine->droite = supprimer_personne(racine->droite , ptr->perso.CIN); 
    } 
    return racine ; 
}

void pause()
{
while(getchar()!='\n'); return;
}

void menu()
{
	ARB *racine=NULL;
	int i=0;
	int N=1;
  int CIN;
	int choix;
	Personne *T;
	Personne p,e;
	racine=charger_fichier(racine);
	do
	{ 
		system("cls");
		printf(" \n*.* *.* *.* *.* *.* Menu du choix *.* *.* *.* *.* *.* \n");
    printf("\n\n*.* *.* *.* I) Gestion des personnes:*.* *.* *.*\n");
		printf("\n 1) Ajouter une personne\n 2) Supprimer une personne\n 3) Modifier les enregistrements\n 4) Consulter la liste des personnes\n 5) Chercher une personne par son CIN");
    
    printf("\n 6) Retourner le nom des parents d'une personne\n 7) Retourner l'age d'une personne\n 8) Trier la liste d'une personne selon CIN\n 9) Trier la liste d'une personne selon le nom\n 10) Afficher une personne\n 11) Afficher le nombre de personnes enregistrees\n 14) Imprimer les donnees");
    printf("\n\n*.* *.* *.* II) Gestion des enfants d'une personne:*.* *.* *.*\n");
    printf("\n 12) Afficher les enfants d'une personne\n 13) Ajouter des enfants a une personne\n 14) Imprimer les donnees\n 15) Quitter l'application\n   Votre choix :");
       
        scanf("%d",&choix);
        getchar();
        switch(choix)
        {
         case 1:
        	system("cls");
        	printf("*.* *.* *.* Insertion des donnes *.* *.* *.*");
        	p=saisir_personne();
			racine=ajouter_noeud(racine,p);
			pause();
			break;
		 case 2:
		 	system("cls");
		 	printf("*.* *.* *.* Suppression des donnes *.* *.* *.*");
      printf("\nDonner le CIN de celui que vous voulez supprimer :");
      scanf("%d",&CIN);
		  racine =supprimer_personne(racine,CIN);
      pause();
		 	break;
		 case 3:
			 system("cls");
		 	 printf("*.* *.* *.* Modification des donnes *.* *.* *.*");
		 	 printf("\nDonner le CIN de celui que vous voulez modifier :");
       scanf("%d",&CIN);
       modifier_personne(CIN,racine);
		 	 break;
		 case 4:
		 	 system("cls");
		 	 printf("*.* *.* *.* Affichage des donnes *.* *.* *.*");
		 	 consulter_arbre(racine);
		 	 pause();
		 	 break;
         case 5:
          	 system("cls");
		 	 printf("*.* *.* *.* Chercher une personne *.* *.* *.*");
		 	 Recherche_generale(racine); 
		 	 pause();
		 	 break;
		 case 6:
 			 system("cls");
		 	 printf("*.* *.* *.* Affichage le(s) parent(s) d'une personne *.* *.* *.*");
		 	 Afficher_parents(racine);
		 	 pause();
		 	 break;
		 case 7:
		 	 system("cls");
		 	 printf("*.* *.* *.* l'age d'une personne *.* *.* *.*");
		 	 age_personne_general(racine);
		 	 pause();
		 	 break;
		 case 8:
		  	 system("cls"); 
		 	 printf("*.* *.* *.* Tri des donnees selon le CIN *.* *.* *.*");

 			 Tri_arbre_CIN(racine);
 			  pause();
 			 break;
         case 9:
         	 system("cls");
		 	 printf("*.* *.* *.* Tri des donnees selon le nom *.* *.* *.*");
		 	 Tri_arbre_nom(racine);
		 	  pause();
		 	 break;
      case 10:
              system("cls");
              printf("\n*.* *.* *.* Afficher une personne:*.* *.* *.* ");
              printf("\nDonner le code de la personne que vous voulez afficher:  ");
              scanf("%d",&CIN);
              Afficher_une_personne(racine,CIN);
              getchar();
              pause();
              break;
		 case 12:
            
           	 system("cls");
		 	 printf("*.* *.* Affichage des enfants d'une personne (les enfants qui sont enregistres dans l'application) *.* *.*");
		   	 Afficher_enfants_general(racine); 
		   	  pause();
		     break;
		 case 11:

             system("cls");
		 	 printf("*.* *.* *.* Le nombre de personnes dans l'application *.* *.* *.*");
		     printf("\nle nombre de personnes enregistrees est : \t%d ",count(racine));
		      pause();
		     break;
     case 13:
     
             system("cls");
             printf("*.* *.* *.* Ajouter des enfants *.* *.* *.*");
             printf("\n\nDonner le CIN de celui que vous voulez lui ajouter des enfants :");
             scanf("%d",&CIN);
             ajouter_enfants(CIN,racine);
             pause();
             break;
		 case 14:

             system("cls");
		 	 printf("*.* *.* *.* Imprimer les donnees *.* *.* *.*");
		 	 Imprimer_Actes_general(racine);
		 	   pause();
		 	 // à compléter

		 	 break;
		 case 15:


             system("cls");
		 	 printf("*.* *.* *.* A bientot  *.* *.* *.*");
		     sauvegarder_fichier(racine); 
		     pause();
		     break;	 
		 default: system("cls"); 
		 printf("\nchoix invalide, essayez encore une fois");
		 pause(); 
		 break; 
        }
	}while(choix!=15);
  return;
}
/*void ajouter_enfants(int CIN ,ARB *racine){
    ARB* ptr = racine;
    if(racine==NULL)
    {
      printf("\n Cette personne n'existe pas!!!!!");
      pause();
      return;
    }
    if (ptr->perso.CIN<CIN){
        ajouter_enfants(CIN,ptr->droite);
        return;
    }
    else if(ptr->perso.CIN>CIN){
        ajouter_enfants(CIN,ptr->gauche);
        return ;
    }
    else{
        int n;
        int j;
        printf("Donner le nombre d'enfants a ajouter :");
        scanf("%d",&n);
        Personne p[n]; 
        ptr->perso.T_id_enf=realloc(ptr->perso.T_id_enf,(ptr->perso.nbr_enfants+n)*sizeof(int));
        for(int i=ptr->perso.nbr_enfants;i<ptr->perso.nbr_enfants+n;i++){
            //getchar();
            printf("\nDonner le nom de l'enfant %d :\t",i+1);
            scanf("%s",p[i-ptr->perso.nbr_enfants].nom);
            printf("\nDonner le prenom de l'enfant :\t");
            scanf("%s",p[i-ptr->perso.nbr_enfants].prenom);
            printf("\nDonner son sexe (homme/femme) :\t");
            scanf("%s",p[i-ptr->perso.nbr_enfants].sexe);
            printf("\nDonner son CIN :\t");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].CIN);
            ptr->perso.T_id_enf[i]=p[i-ptr->perso.nbr_enfants].CIN;
            printf("\nDonner sa date de naissance : ");
            printf("\nle jour: ");

            scanf("%d",&p[i-ptr->perso.nbr_enfants].date.jour);
            printf("\nle mois: ");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].date.mois);
            printf("\nl'annee: ");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].date.annee);
            printf("\nDonner le nombre de ses fils :\t");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].nbr_enfants);
            p[i-ptr->perso.nbr_enfants].T_id_enf=Malloc(int,p[i-ptr->perso.nbr_enfants].nbr_enfants);
            for(j=0;j<p[i-ptr->perso.nbr_enfants].nbr_enfants;j++)
            {
                printf("\nDonner l'identifiant de son fils numero %d :\t",j+1);
                scanf("%d",&p[i-ptr->perso.nbr_enfants].T_id_enf[j]);
            }
            
            //getchar();
            racine=ajouter_noeud(racine,p[i-ptr->perso.nbr_enfants]);   
        }
        ptr->perso.nbr_enfants=ptr->perso.nbr_enfants+n;
    }
}*/
void ajouter_enfants(int CIN ,ARB *racine)
{
           Personne *T;
             ARB* ptr = racine;
          int N,i=0,ver=faux;
          int n;
           int j;
          N=count(racine);
          T=Malloc(Personne,N);
          Passage_ARB_tab(racine,T,&i);
          for (i = 0; i < N; i++)
          {
            
             if(CIN==T[i].CIN)
             {
              
        printf("Donner le nombre d'enfants a ajouter :");
        scanf("%d",&n);
        Personne p[n]; 
        ptr->perso.T_id_enf=realloc(ptr->perso.T_id_enf,(ptr->perso.nbr_enfants+n)*sizeof(int));
        for(int i=ptr->perso.nbr_enfants;i<ptr->perso.nbr_enfants+n;i++){
            getchar();
            printf("\nDonner le nom de l'enfant %d :\t",i+1);
            scanf("%s",p[i-ptr->perso.nbr_enfants].nom);
            printf("\nDonner le prenom de l'enfant :\t");
            scanf("%s",p[i-ptr->perso.nbr_enfants].prenom);
            printf("\nDonner son sexe (homme/femme) :\t");
            scanf("%s",p[i-ptr->perso.nbr_enfants].sexe);
            printf("\nDonner son CIN :\t");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].CIN);
            ptr->perso.T_id_enf[i]=p[i-ptr->perso.nbr_enfants].CIN;
            printf("\nDonner sa date de naissance : ");
            printf("\nle jour: ");

            scanf("%d",&p[i-ptr->perso.nbr_enfants].date.jour);
            printf("\nle mois: ");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].date.mois);
            printf("\nl'annee: ");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].date.annee);
            printf("\nDonner le nombre de ses fils :\t");
            scanf("%d",&p[i-ptr->perso.nbr_enfants].nbr_enfants);
            p[i-ptr->perso.nbr_enfants].T_id_enf=Malloc(int,p[i-ptr->perso.nbr_enfants].nbr_enfants);
            for(j=0;j<p[i-ptr->perso.nbr_enfants].nbr_enfants;j++)
            {
                printf("\nDonner l'identifiant de son fils numero %d :\t",j+1);
                scanf("%d",&p[i-ptr->perso.nbr_enfants].T_id_enf[j]);
            }
            
            //getchar();
            racine=ajouter_noeud(racine,p[i-ptr->perso.nbr_enfants]);
             }
             ptr->perso.nbr_enfants=ptr->perso.nbr_enfants+n;

          }
         

       }
       return;
}
void modifier_personne(int CIN,ARB *racine){
    ARB * ptr =racine;
    if(racine==NULL)
    {
       printf("\nLa personne n' existe pas !! .");
       getchar();
       pause();
       return;
    }
    else
    {
        if(racine->perso.CIN<CIN)
        {
            modifier_personne(CIN,racine->droite);

        }
        else if(racine->perso.CIN>CIN)
        {
            modifier_personne(CIN,racine->gauche);
        }
        else{
           getchar();
            printf("Donner le nom :");
            gets(ptr->perso.nom);
            printf("Donner le prenom :");
            gets(ptr->perso.prenom);
            printf("Donner le sexe(homme/femme) :");
            gets(ptr->perso.sexe);
            printf("Donner le CIN :");
            scanf("%d",&ptr->perso.CIN);
            printf("Donner le jour de naissance :");
            scanf("%d",&ptr->perso.date.jour);
            printf("Donner le mois de naissance :");
            scanf("%d",&ptr->perso.date.mois);
            printf("Donner l'annee de naissance :");
            scanf("%d",&ptr->perso.date.annee);
            printf("Donner le nombre d'enfants :");
            scanf("%d",&ptr->perso.nbr_enfants);
            ptr->perso.T_id_enf=Malloc(int,ptr->perso.nbr_enfants);
            for (int i=0;i<ptr->perso.nbr_enfants;i++){
                printf("Donner le CIN de l'enfant %d :",i+1);
                scanf("%d",&ptr->perso.T_id_enf[i]);
            }
        }
    }
}


