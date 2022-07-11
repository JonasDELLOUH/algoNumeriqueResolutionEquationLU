#include <iostream>

using namespace std;

int main()
{
    int choix;
    double matriceA[4][4];
    double matriceB[4][1];
    double matriceL[4][4], matriceU[4][4];
    double y1, y2, y3, y4, x1, x2, x3, x4;
    do{
        printf("\n \n --------------------------------------------------------");
        printf("\n MENU des operations");
        printf("\n--------------------------------------------------------");
        printf("\n OPERATIONS : ");

        printf("\n 1- Lis les matrices A et b associees a (S)");
        printf("\n 2- Affiche les matrices A et b associées a (S)");
        printf("\n 3- Affiche les matrices L et U de la factorisation de (A)");
        printf("\n 4-Affiche la solution [X] du systeme (S)");
        printf("\n Appuyez n'importe quel autre caractère pour quitter");
        printf("\n Quelle opération voulez vous effectuer :");
        scanf("%d",&choix);

        switch(choix){
        case 1:
            printf("\n 1- Entrez les elements de A : \n");
            for(int i=0; i<4; i++){
               for(int j=0; j<4; j++){
                   cout<<"Entrez la case "<< i+1 <<","<< j+1 <<"de la matrice A : ";
                   cin>>matriceA[i][j];
               }
            }
            cout<<"\n \n";
            printf("\n 1- Entrez les elements de b : \n");
            for(int i=0; i<4; i++){
               for(int j=0; j<1; j++){
                  cout<<"Entrez la case "<< i+1 <<","<< j+1 <<"de la matrice B : ";
                  cin>>matriceB[i][j];
               }
            }
            cout<<"\n \n";
            break;
        case 2:
            printf("\n Voici afficher la matrice A : \n");
            for(int i=0; i<4; i++){
               for(int j=0; j<4; j++){
                 cout<<matriceA[i][j]<<"\t";
               }
               cout<<"\n";
            }
            printf("\n Voici afficher la matrice A : \n");
            for(int i=0; i<4; i++){
               for(int j=0; j<1; j++){
                   cout<<matriceB[i][j]<<"\t";
               }
               cout<<"\n";
            }
            cout<<"\n \n";
            break;
        case 3:
            matriceL[0][0] = 1;
            matriceL[0][1] = 0;
            matriceL[0][2] = 0;
            matriceL[0][3] = 0;

            matriceL[1][1] = 1;
            matriceL[1][2] = 0;
            matriceL[1][3] = 0;

            matriceL[2][2] = 1;
            matriceL[2][3] = 0;

            matriceL[3][3] = 1;


            matriceU[1][0] = 0;

            matriceU[2][0] = 0;
            matriceU[2][1] = 0;

            matriceU[3][0] = 0;
            matriceU[3][1] = 0;
            matriceU[3][2] = 0;



            matriceU[0][0] = matriceA[0][0];
            matriceU[0][1] = matriceA[0][1];
            matriceU[0][2] = matriceA[0][2];
            matriceU[0][3] = matriceA[0][3];
            matriceL[1][0] = matriceA[1][0]/matriceU[0][0];
            matriceU[1][1] = matriceA[1][1] - matriceL[1][0]*matriceU[0][1];
            matriceU[1][2] = matriceA[1][2] - matriceL[1][0]*matriceU[0][2];
            matriceU[1][3] = matriceA[1][3] - matriceL[1][0]*matriceU[0][3];
            matriceL[2][0] = matriceA[2][0] / matriceU[0][0];
            matriceL[3][0] = matriceA[3][0] / matriceU[0][0];
            matriceL[2][1] = (matriceA[2][1] - matriceL[2][0]*matriceU[0][1]) / matriceU[1][1];
            matriceL[3][1] = (matriceA[3][1] - matriceL[3][0]*matriceU[0][1]) / matriceU[1][1];
            matriceU[2][2] = matriceA[2][2] - matriceL[2][0]*matriceU[0][2] - matriceL[2][1]*matriceU[1][2];
            matriceU[2][3] = matriceA[2][3] - matriceL[2][0]*matriceU[0][3] - matriceL[2][1]*matriceU[1][3];
            matriceL[3][2] = (matriceA[3][2] - matriceL[3][0]*matriceU[0][2] - matriceL[3][1]*matriceU[1][2]) / matriceU[2][2];
            matriceU[3][3] = matriceA[3][3] - matriceL[3][0]*matriceU[0][3] - matriceL[3][1]*matriceU[1][3] - matriceL[3][2]*matriceU[2][3];
            printf("\n Voici afficher la matrice L : \n");
            for(int i=0; i<4; i++){
               for(int j=0; j<4; j++){
                   cout<<matriceL[i][j]<<"\t";
               }
               cout<<"\n \n";
            }
            cout<<"\n \n";
            printf("\n Voici afficher la matrice U : \n");
            for(int i=0; i<4; i++){
               for(int j=0; j<4; j++){
                   cout<<matriceU[i][j]<<"\t";
               }
               cout<<"\n \n";
            }
            break;
        case 4:
            y1 = matriceB[0][0];
            y2 = matriceB[1][0] - matriceL[1][0]*y1;
            y3 = matriceB[2][0] - matriceL[2][0]*y1 - matriceL[2][1]*y2;
            y4 = matriceB[3][0] - matriceL[3][0]*y1 - matriceL[3][1]*y2 - matriceL[3][2]*y3;

            x4 = y4 / matriceU[3][3];
            x3 = (y3 - matriceU[2][3]*x4) / matriceU[2][2];
            x2 = (y2 - matriceU[1][2]*x3 - matriceU[1][3]*x4) / matriceU[1][1];
            x1 = (y1 - matriceU[0][1]*x2 - matriceU[0][2]*x3 - matriceU[0][3]*x4) / matriceU[0][0];
            printf("\n Voici les solutions du systèmes: \n");
            cout << "x1 =" <<x1<<"\t x2 ="<<x2<<"\t x3 ="<<x3<<"\t x4 ="<<x4;
            break;
        default:
            break;
        }

    }while(choix!=4);

    return 0;
}
