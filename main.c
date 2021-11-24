#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MenuPrincipal(){
    printf("\t \t \t \t Menu Principal \n");
    printf("1-Introduire un compte bancaire \n");
    printf("2-Introduire plusieurs comptes bancaires \n");
    printf("3- Operations \n");
    printf("4-Affichage\n");
    printf("5-Fidelisation \n");
    printf("6-Quitter l'application \n \n \n");
}

int main()
{



    char CIN[30][10],Nom[30][50],Prenom[30][50];
    double Montant[30];
    char tmpCIN[10];
    int nombre = 0; // Nombre de compte
    int plusCompte; // chhal mn compte andkhlo
    int i=0;
    int choix1;
    int choix2;
    int rech=-1;
    double NM; //Nouveau montant
    int j;
    double Montant1;
    char CIN1[10];
    char Nom1[50];
    char Prenom1[50];
    int chiffre;
    int result_;
    char rechCIN[1][10];
mp:
    system("cls");
    MenuPrincipal();
    printf("donnez votre choix : \n");
    scanf("%d",&choix1);

    switch(choix1)
    {
    case 1:
        i=0;
        system("cls");
        printf("\t \t \t \t Ajouter un compte bancaire \n");
        printf("Saisir CIN : \n");
        scanf("%s",CIN[i]);
        printf("Saisir Nom : \n");
        scanf("%s",Nom[i]);
        printf("Saisir Prenom : \n");
        scanf("%s",Prenom[i]);
        printf("Saisir Montant : \n");
        scanf("%lf",&Montant[i]);
        nombre++;
        system("pause");
        goto mp;
        break;

    case 2:
        system("cls");
        printf("Entrer le nombre de des comptes a ajouter : \n");
        scanf("%d",&plusCompte);
        for(i=nombre; i<nombre+plusCompte; i++)
        {
            printf("Saisir CIN : \n");
            scanf("%s",CIN[i]);
            printf("Saisir Nom : \n");
            scanf("%s",Nom[i]);
            printf("Saisir Prenom : \n");
            scanf("%s",Prenom[i]);
            printf("Saisir Montant : \n");
            scanf("%lf",&Montant[i]);

        }
        nombre=nombre+plusCompte;
        system("pause");
        goto mp;




        break;

    case 3:
       if(nombre == 0)
        {
            printf("Cree un compte svp ...\n");
            system("pause");
            goto mp;
            break;
        }
        system("cls");
        printf("\t \t \t \t Operations \n");
        printf("Choisir votre operations : \n 1: Depot \n2: Retrait \n");
        scanf("%d",&choix2);

        switch(choix2)
        {
        case 1:
            rech = -1;
            printf("1- Depot \n");
            printf("Entrer le CIN \n");
            scanf("%s",tmpCIN);
            for(i=0; i<nombre; i++)
            {
                if(strcmp(tmpCIN,CIN[i])==0)  //strcmp==> Comparaison
                {
                    rech=i;// i est l'emplacement actuel de CIN rechercher:
                    break;
                }
            }
            if(rech == -1)
            {
                printf("le compte est introuvable \n ");
            }
            else
            {
                printf("Entrer le Montant \n");
                scanf("%lf",&NM);

                Montant[rech] = Montant[rech] + NM; // Montant=Montant+NM
            }
            printf("Nouveau Solde %lf \n",Montant[rech]);


            system("pause");
            goto mp;
            break;

        case 2:
            if(nombre == 0)
            {
                printf("Cree un compte svp...\n");
                system("pause");
                goto mp;
                break;
            }
            rech = -1;
            printf("2- Retrait \n");
            printf("Entrer le CIN \n");
            scanf("%s",tmpCIN);
            for(i=0; i<nombre; i++)
            {
                if(strcmp(tmpCIN,CIN[i])==0)
                {
                    rech=i;// i est l'emplacement actuel de CIN rechercher
                    break;
                }
            }
            if(rech==-1)
            {
                printf("le compte est introuvable ");
            }
            else
            {
                printf("Entrer le Montant \n");
                scanf("%lf",&NM);
                if (NM>Montant[rech])
                {
                    printf("Votre Montant n'est pas suffisante  ");
                }
                else
                {
                    Montant[rech] = Montant[rech] - NM;
                }// Montant=Montant+NM
            }
            printf("Nouveau Solde %lf \n",Montant[rech]);

            system("pause");
            goto mp;
            break;

        }

        system("pause");
        goto mp;
        break;

    case 4:
       if(nombre == 0)
        {
            printf("Cree un compte svp ...\n");
            system("pause");
            goto mp;
            break;
        }
        system("cls");
        printf("\t \t \t \t Menu Affichage \n");
        printf("1-Par Ordre Ascendant\n");
        printf("2-Par Ordre Descendant\n");
        printf("3-Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit) \n");
        printf("4-Par Ordre Descendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit) \n");
        printf("5-Recherche par CIN \n");
        printf("6-Quittez l'application \n");


        int choix3;
        printf("donnez votre choix : \n");
        scanf("%d",&choix3);
        switch(choix3)
        {
        case 1:
            printf("Affichage Par Ordre Ascendant \n");
            for (i=0; i<nombre; i++)
            {
                for(j=i+1; j<nombre; j++)
                {
                    if(Montant[i]>Montant[j])
                    {

                        Montant1=Montant[j];
                        Montant[j]=Montant[i];
                        Montant[i]=Montant1;

                        strcpy(CIN1,CIN[j]);
                        strcpy(CIN[j],CIN[i]);
                        strcpy(CIN[i],CIN1);

                        strcpy(Nom1,Nom[j]);
                        strcpy(Nom[j],Nom[i]);
                        strcpy(Nom[i],Nom1);

                        strcpy(Prenom1,Prenom[j]);
                        strcpy(Prenom[j],Prenom[i]);
                        strcpy(Prenom[i],Prenom1);

                    }
                }
            }
            for (i=0; i<nombre; i++)
            {
                printf("\n %lf %s %s %s \n", Montant[i],CIN[i],Nom[i],Prenom[i]);
            }


            system("pause");
            goto mp;
            break;

        case 2:
            printf("Affichage Par Ordre Descendant\n");
            for (i=0; i<nombre; i++)
            {
                for(j=i+1; j<nombre; j++)
                {
                    if(Montant[i]<Montant[j])
                    {

                        Montant1=Montant[j];
                        Montant[j]=Montant[i];
                        Montant[i]=Montant1;

                        strcpy(CIN1,CIN[j]);
                        strcpy(CIN[j],CIN[i]);
                        strcpy(CIN[i],CIN1);

                        strcpy(Nom1,Nom[j]);
                        strcpy(Nom[j],Nom[i]);
                        strcpy(Nom[i],Nom1);

                        strcpy(Prenom1,Prenom[j]);
                        strcpy(Prenom[j],Prenom[i]);
                        strcpy(Prenom[i],Prenom1);

                    }
                }
            }
            for (i=0; i<nombre; i++)
            {
                printf("\n %lf %s %s %s \n%", Montant[i],CIN[i],Nom[i],Prenom[i]);
            }
            system("pause");
            goto mp;
            break;

        case 3:
            printf("Affichage Par Ordre Ascendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit) \n");
            printf("Entrer un nombre \n");
            scanf("%d",&chiffre);
            for (i=0; i<nombre; i++)
            {
                for(j=i+1; j<nombre; j++)
                {
                    if(Montant[i]>Montant[j])
                    {

                        Montant1=Montant[j];
                        Montant[j]=Montant[i];
                        Montant[i]=Montant1;

                        strcpy(CIN1,CIN[j]);
                        strcpy(CIN[j],CIN[i]);
                        strcpy(CIN[i],CIN1);

                        strcpy(Nom1,Nom[j]);
                        strcpy(Nom[j],Nom[i]);
                        strcpy(Nom[i],Nom1);

                        strcpy(Prenom1,Prenom[j]);
                        strcpy(Prenom[j],Prenom[i]);
                        strcpy(Prenom[i],Prenom1);

                    }
                }
            }
            for (i=0; i<nombre; i++)
            {
                if(Montant[i]>chiffre)
                    printf("\n %lf %s %s %s ", Montant[i],CIN[i],Nom[i],Prenom[i]);
            }
            system("pause");
            goto mp;

            break;

        case 4:
            printf("Affichage Par Ordre Descendant (les comptes bancaire ayant un montant supérieur à un chiffre introduit) \n");
            printf("Entrer un nombre \n");
            scanf("%d",&chiffre);
            for (i=0; i<nombre; i++)
            {
                for(j=i+1; j<nombre; j++)
                {
                    if(Montant[i]<Montant[j])
                    {

                        Montant1=Montant[j];
                        Montant[j]=Montant[i];
                        Montant[i]=Montant1;

                        strcpy(CIN1,CIN[j]);
                        strcpy(CIN[j],CIN[i]);
                        strcpy(CIN[i],CIN1);

                        strcpy(Nom1,Nom[j]);
                        strcpy(Nom[j],Nom[i]);
                        strcpy(Nom[i],Nom1);

                        strcpy(Prenom1,Prenom[j]);
                        strcpy(Prenom[j],Prenom[i]);
                        strcpy(Prenom[i],Prenom1);

                    }
                }
            }
            for (i=0; i<nombre; i++)
            {
                if(Montant[i]>chiffre)
                    printf("\n %lf %s %s %s ", Montant[i],CIN[i],Nom[i],Prenom[i]);
            }

            system("pause");
            goto mp;
            break;

        case 5:
            printf("Entrer le CIN \n");
            scanf("%s",&rechCIN[0]);
            for(i=0;i<nombre;i++){
                if(strcmp(rechCIN[0],CIN[i])==0){
                    printf("Nom : %s\n",Nom[i]);
                    printf("Prenom : %s\n",Prenom[i]);
                    printf("Montant : %lf\n",Montant[i]);

                    system("pause");
                    goto mp;
                }
            }  printf("Le CIN est introuvable \n");
                   system("pause");
                   goto mp;
            break;
        }

    case 5:
        if(nombre == 0)
        {
            printf("Cree un compte svp ...\n");
            system("pause");
            goto mp;
            break;
        }
        system("cls");
        printf("\t \t \t \t Fidelisation \n");

        system("pause");
        goto mp;
        break;

    case 6:
          goto exit;
        break;

    }
     exit:

    return 0;
}

