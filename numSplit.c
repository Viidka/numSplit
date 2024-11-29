#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int ipow(int b, int e);             // Fonction de puissance entière
void num_split(const char *num);    // Fonction pour décomposer un nombre

int main(void)
{
    char myNum[100];
    printf("Type a number: \n");
    scanf("%s", myNum);
    num_split(myNum);

    system("pause"); 
    return 0;
}

// Calcul de la puissance entière b^e
int ipow(int b, int e)
{
  if (e==0) 
  {
    return 1;
  } 
  else if (b==0) 
  {
    return 0;
  } 
  else 
  {
    return b*ipow(b,e-1);
  }
}

// Décompose un nombre et affiche les composants
void num_split(const char *num)
{
    int length = strlen(num); // Longueur de la chaîne
    int negatif = 0;          // Indicateur pour les nombres négatifs

    // Vérifier si le nombre est négatif
    if (num[0] == '-')
    {
        negatif = 1;
    }

    // Itérer sur chaque chiffre
    for (int i = negatif; i < length; i++)
    {
        int convSum = num[i] - '0';
        int expo = ipow(10, length - i - 1);
        convSum *= expo;

        if (negatif)
        {
            convSum = -convSum;
        }

        if (i != length - 1)
        {
            printf("%d, ", convSum);
        }
        else
        {
            printf("%d\n", convSum);
        }
    }
}
