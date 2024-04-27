#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char X[3][3] = {{'.', '.', '.'}, {'.', '.', '.'}, {'.', '.', '.'}};
int fin = 1;

void table()
{

    for (int i = 0; i < 3; i++)
    {
        if (i != 0)
        {
            printf("------------------------------------------------\n");
            printf("\t\t|\t\t|\t\t\n");
            printf("\t%c\t|\t%c\t|\t%c\t\n", X[i][0], X[i][1], X[i][2]);
            printf("\t\t|\t\t|\t\t\n");
        }
        else
        {
            printf("\t\t|\t\t|\t\t\n");
            printf("\t%c\t|\t%c\t|\t%c\t\n", X[i][0], X[i][1], X[i][2]);
            printf("\t\t|\t\t|\t\t\n");
        }
    }
    printf("\n");
}
void jeu()
{
    int i, j;
    printf("\nChoisissez une case libre\n");
    while (1)
    {
        printf("Colonne : ");
        scanf("%d", &j);
        printf("Ligne : ");
        scanf("%d", &i);

        if (X[i - 1][j - 1] == 'O' || X[i - 1][j - 1] == 'X' || i < 0 || i > 3 || j < 0 || j > 3)
        {
            printf("Impossible de cocher cette case.\n");
        }
        else
        {
            X[i - 1][j - 1] = 'X';
            break;
        }
    }
}
void jeu2()
{
    int i, j;
    printf("\nChoisissez une case libre\n");
    while (1)
    {
        printf("Colonne : ");
        scanf("%d", &j);
        printf("Ligne : ");
        scanf("%d", &i);

        if (X[i - 1][j - 1] == 'O' || X[i - 1][j - 1] == 'X' || i < 0 || i > 3 || j < 0 || j > 3)
        {
            printf("Impossible de cocher cette case.\n");
        }
        else
        {
            X[i - 1][j - 1] = 'O';
            break;
        }
    }
}
int ia1()
{
    srand(time(NULL));
    int iRandom, jRandom;
    do
    {
        iRandom = rand() % 3;
        jRandom = rand() % 3;
    } while (X[iRandom][jRandom] == 'X' || X[iRandom][jRandom] == 'O');

    X[iRandom][jRandom] = 'O';
    return 0;
}
int findejeu()
{
    int nul = 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if ((X[0][j] != '.' && X[0][j] == X[1][j] && X[1][j] == X[2][j]) ||
                (X[i][0] != '.' && X[i][0] == X[i][1] && X[i][1] == X[i][2]) ||
                (X[0][0] != '.' && X[0][0] == X[1][1] && X[1][1] == X[2][2]) ||
                (X[0][2] != '.' && X[0][2] == X[1][1] && X[1][1] == X[2][0]))
            {
                return 1;
            }
            if (X[i][j] != '.')
            {
                nul++;
                if (nul > 9)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}
int gagnant()
{
    table();
    for (int i = 0; i < 3; i++)
    {
        if ((X[0][i] == 'X' && X[0][i] == X[1][i] && X[1][i] == X[2][i]) ||
            (X[i][0] == 'X' && X[i][0] == X[i][1] && X[i][1] == X[i][2]) ||
            (X[0][0] == 'X' && X[0][0] == X[1][1] && X[1][1] == X[2][2]) ||
            (X[0][2] == 'X' && X[0][2] == X[1][1] && X[1][1] == X[2][0]))
        {
            return 1; // victoire
        }
        else if ((X[0][i] == 'O' && X[0][i] == X[1][i] && X[1][i] == X[2][i]) ||
                 (X[i][0] == 'O' && X[i][0] == X[i][1] && X[i][1] == X[i][2]) ||
                 (X[0][0] == 'O' && X[0][0] == X[1][1] && X[1][1] == X[2][2]) ||
                 (X[0][2] == 'O' && X[0][2] == X[1][1] && X[1][1] == X[2][0]))
        {
            return -1; // defaite
        }
    }
    return 0; // nul
}
int tour()
{
    if (findejeu())
    {
        if (gagnant() == 1)
        {
            printf("Tu as gagne !! :D\n");
        }
        else if (gagnant() == -1)
        {
            printf("Tu as perdu :(\n");
        }
        else
        {
            printf("Match nul.\n");
        }
        return 1;
    }
    return 0;
}
int tour2()
{
    if (findejeu())
    {
        if (gagnant() == 1)
        {
            printf("Joueur 1 a gagne !! :D\n");
        }
        else if (gagnant() == -1)
        {
            printf("Joueur 2 a gagne !! :D\n");
        }
        else
        {
            printf("Match nul.\n");
        }
        return 1;
    }
    return 0;
}

int main()
{
    int fin = 1;
    int dif;

    while (fin)
    {
        printf("\nChoisissez votre difficulte : \n\nFacile = 1\nNormal = 2\nDifficile = 3\nMulti = 4\n");
        scanf("%d", &dif);

        switch (dif)
        {
        case 1:
            printf("\n\n\t\tDebut de la partie : \n\n");
            while (!findejeu())
            {
                table();
                jeu();
                if (tour())
                {
                    fin--;
                    break;
                }
                ia1();
                if (tour())
                {
                    fin--;
                    break;
                }
            }
            break;
        case 2:
            printf("\n\n\tDebut de la partie : \n\n");
            // a faire
            break;
        case 3:
            printf("\n\n\tDebut de la partie : \n\n");
            // a faire
            break;
        case 4:
            printf("\n\n\t\tDebut de la partie : \n\n");
            while (!findejeu())
            {
                table();
                jeu();
                if (tour2())
                {
                    fin--;
                    break;
                }
                table();
                jeu2();
                if (tour2())
                {
                    fin--;
                    break;
                }
            }
            break;

        default:
            printf("Choisissez une difficultee valide\n");
            break;
        }
    }

    return 0;
}
