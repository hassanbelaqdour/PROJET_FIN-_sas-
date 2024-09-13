#include <stdio.h>
#include <string.h>

struct etudiant
{ // struct
    int nbr_unique;
    char nom[100];
    char prenom[100];
    char naissance[30];
    char depar[100];
    int note_gene;
   
};
struct etudiant all[100] = {
    {1234, "hassan","belaqdour","23/8/2006","pc", 12},
    {2945,"hamza","nol","7/2/2004" ,"Math",9},
    {5937,"monir","boo","19/11/2002","Svt",15},
    {5738,"said","vez","12/7/2000","Pc",8},
    {2780,"maryeme","csu","9/6/2005","Math",11}
};
struct etudiant copie[100];
int i;
int choix;
int totale_etudiant = 5;    

// fonction d'ajouter un etudiant
void ajouter_etu()
{
    printf("____ajouter un etudiant____\n");
    printf("saiser son nombre unique\n");
    scanf(" %d", &all[totale_etudiant].nbr_unique);
    printf("saiser son nom\n");
    scanf(" %s", all[totale_etudiant].nom);
    printf("saiser son prenom\n");
    scanf(" %s", all[totale_etudiant].prenom);
    printf("saiser sa date de naissance\n");
    scanf(" %s", all[totale_etudiant].naissance);
    printf("saiser son departement (pc), (math), (svt)\n");
    scanf(" %s", all[totale_etudiant].depar);
    printf("saiser sa note generale\n");
    scanf(" %d", &all[totale_etudiant].note_gene);
    totale_etudiant++;
}
// fonction d'ajouter plusieurs etudiants
void ajouter_plus()
{
    int nombre_etudiant;
    printf("combien d'etudiants voules vous ajouter\n");
    scanf(" %d", &nombre_etudiant);
    if ((nombre_etudiant < 10) && (nombre_etudiant > 0))
    {
        for (int i = 0; i < nombre_etudiant; i++)
        {

            struct etudiant all[nombre_etudiant];
            ajouter_etu();
        }
    }
    else
    {
        printf("entrer un nombre entre 1 et 9");
    }
}
// fonction de modification
void modifier_info()
{
    char none[100];
    printf("____entrer le nom d'etudiant a modifier ses informations____\n");
    scanf("%s", none);
    for (i = 0; i < totale_etudiant; i++)
    {
        if (strcmp(all[i].nom, none) == 0)
        {
            printf("saiser le nouveau nombre unique\n");
            scanf(" %d", &all[i].nbr_unique);
            printf("saiser le nouveau nom\n");
            scanf(" %s", all[i].nom);
            printf("saiser le nouveau prenom\n");
            scanf(" %s", all[i].prenom);
            printf("saiser la nouvelle date de naissance\n");
            scanf(" %s", all[i].naissance);
            printf("saiser le nouveau departement\n");
            scanf(" %s", all[i].depar);
            printf("saiser la nouvelle note generale\n");
            scanf(" %d", &all[i].note_gene);
        }
    }
}
// fonction de la recherche
void chercher_etu()
{
    char none[100];
    printf("saiser le nom d'etudiant a chercher\n");
    scanf("%s", none);
    int exist = 0;
    for (i = 0; i < totale_etudiant; i++)
    {
        if (strcmp(all[i].nom, none) == 0)
        {
            printf("l'etudiant existe____\n");
            printf("le nom de l'etudiant est %s\n", all[i].nom);
            printf("son prenom est %s\n", all[i].prenom);
            printf("son nombre unique est %d\n", all[i].nbr_unique);
            printf("sa date de naissance est %s\n", all[i].naissance);
            printf("son departement est %s\n", all[i].depar);
            printf("sa note generale est %d\n", all[i].note_gene);
            exist = 1;
        }
    }
    if (exist = 0)
    {
        printf("l'etudiant n'existe pas____\n");
    }

} // fonction de la supprission
void supprission_etu()
{
    char none[100];
    printf("____le nom d'etudiant a supprimer____\n");
    scanf(" %s", none);
    for (i = 0; i < totale_etudiant; i++)
    {
        if (strcmp(all[i].nom, none) == 0)
        {
            for (int j = i; j < totale_etudiant - 1; j++)
            {
                all[j] = all[j + 1];
            }
        }
    }
    totale_etudiant--;
}
// fonction d'affichage
void affichage_etu()
{
    printf("_______tout les etudiants de l'universite_______\n");
    for (i = 0; i < totale_etudiant; i++)
    {
        printf("son nombre unique est %d\n", all[i].nbr_unique);
        printf("le nom de l'etudiant est %s\n", all[i].nom);
        printf("son prenom est %s\n", all[i].prenom);
        printf("sa date de naissance est %s\n", all[i].naissance);
        printf("son departement est %s\n", all[i].depar);
        printf("sa note generale est %d\n", all[i].note_gene);
       printf("=====================================================\n\n");

    }
}
void calcul_moyen_depar() {
    int total_pc = 0, total_math = 0, total_svt = 0;
    int count_pc = 0, count_math = 0, count_svt = 0;
    float moyenne_pc, moyenne_math, moyenne_svt, moyenne_univ;
    int total_notes = 0;

    // calculer la somme des notes pour depar et le nombre d'etud
    for (i = 0; i < totale_etudiant; i++) {
        if (strcmp(all[i].depar, "pc") == 0) {
            total_pc += all[i].note_gene;
            count_pc++;
        } else if (strcmp(all[i].depar, "Math") == 0) {
            total_math += all[i].note_gene;
            count_math++;
        } else if (strcmp(all[i].depar, "Svt") == 0) {
            total_svt += all[i].note_gene;
            count_svt++;
        }
        total_notes += all[i].note_gene;
    }

    // calculer les moyen chaque departement
    if (count_pc > 0) {
        moyenne_pc = (float)total_pc / count_pc;
        printf("moyenne pour le departement PC: %.2f\n", moyenne_pc);
    } else {
        printf("aucun etudiant dans le departement PC.\n");
    }

    if (count_math > 0) {
        moyenne_math = (float)total_math / count_math;
        printf("moyenne pour le departement math: %.2f\n", moyenne_math);
    } else {
        printf("aucun etudiant dans le departement math.\n");
    }

    if (count_svt > 0) {
        moyenne_svt = (float)total_svt / count_svt;
        printf("moyenne pour le departement svt: %.2f\n", moyenne_svt);
    } else {
        printf("aucun etudiant dans le departement svt.\n");
    }

    // calculer la moyen d'universite 
    if (totale_etudiant > 0) {
        moyenne_univ = (float)total_notes / totale_etudiant;
        printf("moyenne generale de l'universite: %.2f\n", moyenne_univ);
    } else {
        printf("aucun etudiant dans l'universite.\n");
    }
}
void afficher_etudiants_seuil(int seuil)
{
    printf("Etudiants avec une note generale superieure ou egale a %d:\n", seuil);
    for (i = 0; i < totale_etudiant; i++)
    {
        if (all[i].note_gene >= seuil)
        {
            printf("Nom: %s, Note: %d\n", all[i].nom, all[i].note_gene);
        }
    }
}

// Fonction pour afficher les 3 meilleurs étudiants
void afficher_top_3_etudiants()
{
    if (totale_etudiant < 3)
    {
        printf("Moins de 3 etudiants disponibles.\n");
        return;
    }

    // Copier les données
    for (i = 0; i < totale_etudiant; i++)
    {
        copie[i] = all[i];
    }

    // Tri par note générale (ordre décroissant)
    for (i = 0; i < totale_etudiant - 1; i++)
    {
        for (int j = 0; j < totale_etudiant - i - 1; j++)
        {
            if (copie[j].note_gene < copie[j + 1].note_gene)
            {
                struct etudiant tmp = copie[j];
                copie[j] = copie[j + 1];
                copie[j + 1] = tmp;
            }
        }
    }

    // Affichage des 3 meilleurs étudiants
    printf("Les 3 meilleurs etudiants:\n");
    for (i = 0; i < 3; i++)
    {
        printf("Nom: %s, Note: %d\n", copie[i].nom, copie[i].note_gene);
    }
}

// Fonction pour afficher le nombre d'étudiants ayant réussi dans chaque département
void afficher_reussite_depar()
{
    int reussit_pc = 0, reussit_math = 0, reussit_svt = 0;

    for (i = 0; i < totale_etudiant; i++)
    {
        if (all[i].note_gene >= 10)
        {
            if (strcmp(all[i].depar, "pc") == 0)
            {
                reussit_pc++;
            }
            else if (strcmp(all[i].depar, "Math") == 0)
            {
                reussit_math++;
            }
            else if (strcmp(all[i].depar, "Svt") == 0)
            {
                reussit_svt++;
            }
        }
    }

    printf("Nombre d'etudiants ayant reussi dans le departement PC: %d\n", reussit_pc);
    printf("Nombre d'etudiants ayant reussi dans le departement Math: %d\n", reussit_math);
    printf("Nombre d'etudiants ayant reussi dans le departement SVT: %d\n", reussit_svt);
}

int main()
{
    // struct etudiant all[100];
    int i;
    int choix;
    char none[100];
    do
    {
        printf("_______gestion des etudiants dans une universite_______\n");
        printf("1_ ajouter des etudiants\n");
        printf("2_ modifier les informations d'un etudiant\n");
        printf("3_chercher un etudiant\n");
        printf("4_supprimer un etudiant\n");
        printf("5_afficher tout les etudiants\n");
        printf("6_calculer la moyenne generle de chaque departement\n");
        printf("7_statistiques\n");
        printf("8_trier les etudiants par:\n");
        printf("9_ quitter l'application\n");
        printf("______saiser votre choix______\n");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("voulez vous ajouter un etudiant (1) ou plusieur etudiants (2)\n");
            scanf(" %d", &choix);
            if (choix == 1)
            {
                struct etudiant all;
                ajouter_etu();
            }
            else if (choix == 2)
            {
                struct etudiant all;
                ajouter_plus();
            }
            else
            {
                printf("le choix est non valider\n");
            }

            break;

        case 2:
            modifier_info();
            break;

        case 3:
            chercher_etu();
            break;

        case 4:
            supprission_etu();
            break;

        case 5:
            affichage_etu();
            break;
        case 6:
            calcul_moyen_depar();
            break;
        case 7:
                printf("1_ Afficher les etudiants avec une note >= seuil\n");
                printf("2_ Afficher les 3 meilleurs etudiants\n");
                printf("3_ Afficher le nombre d'etudiants ayant reussi dans chaque departement\n");
                scanf("%d", &choix);
                if (choix == 1)
                {
                    int seuil;
                    printf("Saisir le seuil: ");
                    scanf("%d", &seuil);
                    afficher_etudiants_seuil(seuil);
                }
                else if (choix == 2)
                {
                    afficher_top_3_etudiants();
                }
                else if (choix == 3)
                {
                    afficher_reussite_depar();
                }
                else
                {
                    printf("Choix non valide\n");
                }
                break;

        case 8:
            printf("trier alphabetiquement (1)___ trier par moyenne (2)___ trier par statut (3)\n");
            scanf(" %d", &choix);

            if (choix == 1) // Tri alphabetique par nom
            {
                printf("Trie alphabetique des etudiants par nom\n");
                for (int i = 0; i < totale_etudiant; i++)
                {
                    copie[i] = all[i];
                }
                // Tri alphabetique par nom
                for (int i = 0; i < totale_etudiant - 1; i++)
                {
                    for (int j = 0; j < totale_etudiant - i - 1; j++)
                    {
                        if (strcmp(copie[j].nom, copie[j+1].nom) > 0)
                        {
                            struct etudiant tmp = copie[j];
                            copie[j] = copie[j+1];
                            copie[j+1] = tmp;
                        }
                    }
                }
                // Affichage des nom trie
                for (int i = 0; i < totale_etudiant; i++)
                {
                    printf("%s\n", copie[i].nom);
                }
            }
           else if (choix == 2) // Tri par note générale
{
    printf("Tri des etudiants par note generale\n");

    // Copier les donnes
    for (int i = 0; i < totale_etudiant; i++)
    {
        copie[i] = all[i];
    }

    // Tri par note generale (ordre decroissant)
    for (int i = 0; i < totale_etudiant - 1; i++)
    {
        for (int j = 0; j < totale_etudiant - i - 1; j++)
        {
            if (copie[j].note_gene < copie[j + 1].note_gene)
            {
                struct etudiant tmp = copie[j];
                copie[j] = copie[j + 1];
                copie[j + 1] = tmp;
            }
        }
    }

    // Affichage des noms triés par note générale
    for (int i = 0; i < totale_etudiant; i++)
    {
        printf("%s: %d\n", copie[i].nom, copie[i].note_gene);
    }
}
            // Ajouter les cas pour le tri par statut si necessaire
            else if ( choix = 3 ){
              //  reussit
    printf("Trie des etudiants selon leur statut de reussite\n");

    // Copier les donnees
    for (int i = 0; i < totale_etudiant; i++)
    {
        copie[i] = all[i];
    }

    // Afficher les reussit
    printf("etudiants reussis (note >= 10) :\n");
    for (int i = 0; i < totale_etudiant; i++)
    {
        if (copie[i].note_gene >= 10)
        {
            printf("%s: %d\n", copie[i].nom, copie[i].note_gene);
        }
    }

    // Afficher les non reussit
    printf("etudiants non reussis (note < 10) :\n");
    for (int i = 0; i < totale_etudiant; i++)
    {
        if (copie[i].note_gene < 10)
        {
            printf("%s: %d\n", copie[i].nom, copie[i].note_gene);
        }
    }
}


            
            break;

    
        }
    }while (choix != 9);
        return 0;
    
}