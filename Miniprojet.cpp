#include<stdio.h>
#include<string.h>

//  la structure Bouquin 
typedef struct 
 { 
    char RefBouquin[50];
     char Nom[50];
	float Prix;  
 } Bouquin;
 
// la structure Bibliothecaire 
typedef struct
{
    char Refbibliothecaire[50];
    char nom[50];
    char prenom[50];
    char AdressEmail[100];
} Bibliothecaire;


// structure Date 
typedef struct 
{
	int j;
	int m;
	int a;
} Date;

//la structure Client
typedef struct 
{ 
   char RefClient[50];
   Date Datedupret;
   Bouquin Bouquinprete;        
} Client;
 
 void liste();
 void modifier();
 void suprimer(void);
 
 void liste2();
 void modifier2();
 void suprimer2(void);
 
  void liste3();
 void modifier3();
 void suprimer3(void);
 
 //afficahge du menu avec un choix valide 
 int menu()
{    
    int choix = 0;
    
    while (choix < 1 || choix > 12)
    {
    	printf("\n\t\t\t     _________________________________");
        printf("\n\t\t\t    /                                 /");
        printf("\n\t\t\t   /   Gestionnaire                  / ");
        printf("\n\t\t\t  /       de                        /  ");
        printf("\n\t\t\t / bibliotheque                    /   ");
        printf("\n\t\t\t/_______________________________ _/\n\n\n\n\n");
        printf("Menu :\n");
        printf("1 :  Ajouter un Bouquin\n");
        printf("2 :  Modifier un Bouquin\n");
        printf("3 :  Supprimer un Bouquin\n");
        printf("4 :  Afficher un Bouquin\n");
        printf("5 :  Ajouter un Biblothecaire\n");
        printf("6 :  Modifier un Bibliothecaire \n");
        printf("7 :  Supprimer un Bibliothecaire \n");
        printf("8 :  Afficher un Bibliothecaire \n");
        printf("9 :  Ajouter un Client \n");
        printf("10:  Modifier un Client \n");
        printf("11:  Supprimer un Client \n");
        printf("12:  Afficher un Client\n");
        printf("   Votre choix ? ");
        scanf("%d", &choix);
    }    
    
    return choix;
}
 
 
int main(int argc, char *argv[])
{    
    FILE* fichier = NULL;
    int option;
    while(option=menu())
	{
    switch (option)
    {          
        case 1: 
            Bouquin bouquin ;
            printf("Formulaire d'enregistrement d'un Bouquin \n");
            printf("-------------------------------------------\n");
            gets( bouquin.RefBouquin);
            printf("Entrez la Reference du Bouquin :");
            gets( bouquin.RefBouquin);
            printf("Entrez le nom Bouquin  :");
            gets(bouquin.Nom);
            printf("Entrez le Prix du Bouquin :");
            scanf("%f", &bouquin.Prix);    
		    fichier = fopen("test.txt", "a+");
		    if (fichier != NULL)
		    {
			    fseek(fichier, 0L, SEEK_END);
		     	fwrite(&bouquin, sizeof(Bouquin), 1, fichier);
			    fclose(fichier);
		    }
		    else
			{
				printf("impossible d'ouvrire le ficher");
			}
            break;
        case 2:
			modifier();
            break;
        case 3:
        	suprimer();
            break;
        case 4:
            liste();
            break;   
	    case 5: 
	        Bibliothecaire bibliothecaire ;
	        printf("Formulaire d'enregistrement d'un Bibliothecaire : \n");
            printf("-------------------------------------------\n");
            gets(bibliothecaire.Refbibliothecaire);
            printf("Entrez la Reference du Bibliothecaire :");
            gets(bibliothecaire.Refbibliothecaire);
            printf("Entrez le nom du Bibliothecaire :");
            gets( bibliothecaire.nom);
            printf("Entrez le prenom du Bibliothecaire :");
            gets(bibliothecaire.prenom);
            printf("Entrez l'adresse Email du bibliothecaire :");
            gets( bibliothecaire.AdressEmail);    
		    fichier = fopen("test2.txt", "a+");
		    if (fichier != NULL)
		    {
		         //fprintf(fichier, "%s %s %f\n",bouquin.RefBouquin,bouquin.Nom,bouquin.Prix ); 
			    fseek(fichier, 0L, SEEK_END);
		     	fwrite(&bibliothecaire, sizeof(Bibliothecaire), 1, fichier);
			    fclose(fichier);
		    }
		    else
			{
			printf("impossible d'ouvrire le ficher");
			}
            printf("Vous avez Ajoutez un Biblothecaire\n");
            break;
		case 6:
			modifier2();
            break;
		case 7:
			suprimer2();
            break;
		case 8:
			liste2();
            break;
		case 9:
			Client client;
			 printf("Formulaire d'enregistrement d'un Clients : \n");
            printf("-------------------------------------------\n");
            gets(client.RefClient);
            printf("Entrez la Reference du Client :");
            gets(client.RefClient);
            printf("Entrez le nom du Bouquin prete :");
            gets(client.Bouquinprete.Nom);
            printf("Entrez la Reference du Bouquin prete :");
            gets(client.Bouquinprete.RefBouquin);
            printf("Entrez le Prix du Bouquin prete :");
            scanf("%f", &client.Bouquinprete.Prix); 
             printf("Entrez le date de pret du Bouquin jour/Mois/Année:");
            scanf("%d %d %d", &client.Datedupret.j,&client.Datedupret.m,&client.Datedupret.a);    
		    fichier = fopen("test3.txt", "a+");
		    if (fichier != NULL)
		    {
		         //fprintf(fichier, "%s %s %f\n",bouquin.RefBouquin,bouquin.Nom,bouquin.Prix ); 
			    fseek(fichier, 0L, SEEK_END);
		     	fwrite(&client, sizeof(Client), 1, fichier);
			    fclose(fichier);
			    printf("Vous avez  Ajoutez un Client\n");
		    }
		    else
			{
				printf("impossible d'ouvrire le ficher");
			}
            break;
		case 10:
			modifier3();
            break;
		case 11:
			suprimer3;
            break;
		case 12:
			liste3();
            break; 
    }
 }
    return 0;
}




// affichage
  void liste()
{
	FILE *pf;
	Bouquin bouquin;
	int cont=0;
	pf = fopen("test.txt", "rb");
	if (pf == NULL)
	{
		printf("\n IMPOSSIBLE D'OUVRIR LE FICHIER");
		
	}
	else
	{
		fread(&bouquin, sizeof(Bouquin), 1, pf);
		printf("\n\n------------------------------------------------------------------------------\n");
		printf("                         LISTE DES BOUQUINS\n");
		printf("------------------------------------------------------------------------------\n\n");
		while(!feof(pf))
		{
			cont++;
			printf("\n[%d] - RefBouquin: %s   Nom:%s   Prix: %f   \n ",cont, bouquin.RefBouquin,bouquin.Nom,bouquin.Prix);
			fread(&bouquin, sizeof(Bouquin), 1, pf);

		}
		fclose(pf);
		printf("\n\n\n\n\n\n");
	}
}


//Modification
void modifier ()
{
	char cod[50];

	FILE *pf;
	Bouquin bouquin;
	pf = fopen("test.txt","rb+");
	if (pf == NULL)
	{
		printf("impossible de modifier ");
	
	}
	else
	{   gets(cod);
		printf("\n Entrez la RefBouquin a modifier \n\n ");
		gets(cod);
		fread(&bouquin, sizeof(Bouquin), 1, pf);
		while(!feof(pf))
		{
			if (strcmp(bouquin.RefBouquin,cod)==0)
			{
				printf("Modificacion de Bouquin avec RefBouquin: %s\n",cod);
				printf("introdusez la nouvelle RefBouquin:");
				gets(bouquin.RefBouquin);
				printf("introdusez le nouveau Nom:");
				gets(bouquin.Nom);
				printf("introdusez le nouveau Prix:\n");
				scanf("%f",&bouquin.Prix);

				fseek(pf,((-1)*(int)sizeof(Bouquin)),SEEK_CUR);
				fwrite(&bouquin, sizeof(Bouquin),1,pf);
				fseek(pf,0,SEEK_CUR);

				fclose(pf);
				return;
			}
			fread(&bouquin, sizeof(Bouquin),1,pf);
			if (strcmp(bouquin.RefBouquin,cod) !=0)
			{
				printf("\n REFBOUQUIN EST INEXISTENTE\n\n\n\n");
				fclose(pf);
				return;
			}
		}


		fclose(pf);
	}
}

//Supression

void suprimer(void)
{
	FILE *pf, *pfaux;
	Bouquin bouquin;
	char RefBouquin[50];
	pf = fopen("test.txt", "rb");
	pfaux = fopen("temp.txt", "ab");
	gets(RefBouquin);
	printf("\n Entrez la Reference pour suprimer le Bouquin:");
	gets(RefBouquin);
	fflush(stdin);

	fread(&bouquin, sizeof(Bouquin), 1, pf);


	while(!feof(pf))
	{
		if (strcmp(bouquin.RefBouquin,RefBouquin) !=0)
		{
			fseek(pfaux, 01, SEEK_END);
			fwrite(&bouquin, sizeof(Bouquin), 1, pfaux);
		}
		fread(&bouquin, sizeof(Bouquin), 1, pf);
	}
	fclose(pf);
	fclose(pfaux);
	remove("test.txt");
	rename("temp.txt","test.txt");
	printf("la supression a ete realiser correctement \n\n");
	return;
}     

//Modification2
 void modifier2()
        	{
			char cod[50];

		FILE *pf;
		Bibliothecaire bibliothecaire;
		pf = fopen("test2.txt","rb+");
		if (pf == NULL)
		{
			printf("impossible de modifier ");
		
		}
		else
		{   gets(cod);
			printf("\n Entrez la RefBibliothecaire a modifier \n\n ");
			gets(cod);
			fread(&bibliothecaire, sizeof(Bibliothecaire), 1, pf);
			while(!feof(pf))
			{
				if (strcmp(bibliothecaire.Refbibliothecaire,cod)==0)
				{
					printf("Modificacion du Bibliothecaire avec RefBibliothecaire: %s\n",cod);
					printf("introdusez la nouvelle RefBibliothecaire:");
					gets(bibliothecaire.Refbibliothecaire);
					printf("introdusez le nouveau Nom :");
					gets(bibliothecaire.nom);
					printf("introdusez le nouveau prenom:");
					gets(bibliothecaire.prenom);
				    printf("introdusez le nouveau Adress Email:");
					gets(bibliothecaire.AdressEmail);
	
					fseek(pf,((-1)*(int)sizeof(Bibliothecaire)),SEEK_CUR);
					fwrite(&bibliothecaire, sizeof(Bibliothecaire),1,pf);
					fseek(pf,0,SEEK_CUR);
	
					fclose(pf);
					return;
				}
				fread(&bibliothecaire, sizeof(Bibliothecaire),1,pf);
				if (strcmp(bibliothecaire.Refbibliothecaire,cod) !=0)
				{
					printf("\n REFBIBLIOTHECAIRE EST INEXISTENTE\n\n\n\n");
					fclose(pf);
					return;
				}
			}
	
	
			fclose(pf);
       }
}                
 
 //suprimer2
 void suprimer2(void)
{
	FILE *pf, *pfaux;
	Bibliothecaire bibliothecaire;
	char RefBibliothecaire[50];
	pf = fopen("test2.txt", "rb");
	pfaux = fopen("temp2.txt", "ab");
	gets(RefBibliothecaire);
	printf("\n Entrez la Reference pour suprimer le Bibliothecaire:");
	gets(RefBibliothecaire);
	fflush(stdin);

	fread(&bibliothecaire, sizeof(Bibliothecaire), 1, pf);

	while(!feof(pf))
	{
		if (strcmp(bibliothecaire.Refbibliothecaire,RefBibliothecaire) !=0)
		{
			fseek(pfaux, 01, SEEK_END);
			fwrite(&bibliothecaire, sizeof(Bibliothecaire), 1, pfaux);
		}
		fread(&bibliothecaire, sizeof(Bibliothecaire), 1, pf);
	}
	fclose(pf);
	fclose(pfaux);
	remove("test2.txt");
	rename("temp2.txt","test2.txt");
	printf("la supression a ete realiser correctement \n\n");
	return;
}  
//affichage2   
 void liste2()
{
	FILE *pf;
	Bibliothecaire bibliothecaire;
	int cont=0;
	pf = fopen("test2.txt", "rb");
	if (pf == NULL)
	{
		printf("\n IMPOSSIBLE D'OUVRIR LE FICHIER");
		
	}
	else
	{
		fread(&bibliothecaire, sizeof(Bibliothecaire), 1, pf);
		printf("\n\n------------------------------------------------------------------------------\n");
		printf("                         LISTE DES BIBLIOTHECAIRES\n");
		printf("------------------------------------------------------------------------------\n\n");
		while(!feof(pf))
		{
			cont++;
			printf("\n[%d] - RefBibliothecaire: %s   Nom:%s   Prenom: %s    AdressEmail:%s   \n ",cont, bibliothecaire.Refbibliothecaire,bibliothecaire.nom,bibliothecaire.prenom,bibliothecaire.AdressEmail);
			fread(&bibliothecaire, sizeof(Bibliothecaire), 1, pf);

		}
		fclose(pf);
		printf("\n\n\n\n\n\n");
	}
}

//modification 3
void modifier3()
{
        char cod[50];

		FILE *pf;
		Client client;
		pf = fopen("test3.txt","rb+");
		if (pf == NULL)
		{
			printf("impossible de modifier ");
		
		}
		else
		{   gets(cod);
			printf("\n Entrez la Ref du client  a modifier \n\n ");
			gets(cod);
			fread(&client, sizeof(Client), 1, pf);
			while(!feof(pf))
			{
				if (strcmp(client.RefClient,cod)==0)
				{
					printf("Modificacion du Client avec RefClient: %s\n",cod);
					printf("introdusez la nouvelle RefClients:");
					gets(client.RefClient);
					printf("introdusez le nouveau Nom du bouquin prete:");
					gets(client.Bouquinprete.Nom);
					printf("introdusez le nouveau prix du bouquin prete:");
					scanf("%f",&client.Bouquinprete.Prix);
				    printf("introdusez la nouvelle Ref du bouquin prete:");
					gets(client.RefClient);
	                printf("introdusez la nouvelle date du bouquin prete sous forme jour/Mois/Année:"); 
					scanf("%d %d %d",&client.Datedupret.j,&client.Datedupret.m,&client.Datedupret.a);
					fseek(pf,((-1)*(int)sizeof(Client)),SEEK_CUR);
					fwrite(&client, sizeof(Client),1,pf);
					fseek(pf,0,SEEK_CUR);
	
					fclose(pf);
					return;
				}
				fread(&client, sizeof(Client),1,pf);
				if (strcmp(client.RefClient,cod) !=0)
				{
					printf("\n REFCLIENT EST INEXISTENTE\n\n\n\n");
					fclose(pf);
					return;
				}
			}
	
	
			fclose(pf);
       }
}                


//suprssion3
void suprimer3(void)
{
	FILE *pf, *pfaux;
	Client client;
	char RefClient[50];
	pf = fopen("test3.txt", "rb");
	pfaux = fopen("temp3.txt", "ab");
	gets(RefClient);
	printf("\n Entrez la Reference pour suprimer le Clients:");
	gets(RefClient);
	fflush(stdin);

	fread(&client, sizeof(Client), 1, pf);


	while(!feof(pf))
	{
		if (strcmp(client.RefClient,RefClient) !=0)
		{
			fseek(pfaux, 01, SEEK_END);
			fwrite(&client, sizeof(Client), 1, pfaux);
		}
		fread(&client, sizeof(Client), 1, pf);
	}
	fclose(pf);
	fclose(pfaux);
	remove("test3.txt");
	rename("temp3.txt","test3.txt");
	printf("\n la supression a ete realiser correctement \n\n");
	return;
}     

// affichage 3
  void liste3()
{
	FILE *pf;
	Client client;
	int cont=0;
	pf = fopen("test3.txt", "rb");
	if (pf == NULL)
	{
		printf("\n IMPOSSIBLE D'OUVRIR LE FICHIER");
		
	}
	else
	{
		fread(&client, sizeof(Client), 1, pf);
		printf("\n\n------------------------------------------------------------------------------\n");
		printf("                         LISTE DES BOUQUINS\n");
		printf("------------------------------------------------------------------------------\n\n");
		while(!feof(pf))
		{
			cont++;
			printf("\n[%d] - RefClient: %s   bouquinpret nom:%s   bouquinpret RefBouquin:%s  bouquin pret prix :%f  datedupret:%d /%d /%d \n ",cont, client.RefClient,client.Bouquinprete.Nom,client.Bouquinprete.RefBouquin,client.Bouquinprete.Prix,client.Datedupret.j,client.Datedupret.m,client.Datedupret.a);
			fread(&client, sizeof(Client), 1, pf);

		}
		fclose(pf);
		printf("\n\n\n\n\n\n");
	}
}                                                                                                     



