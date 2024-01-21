#include <iostream>
#include <time.h>
#include <string.h>

#define TAM 10
using namespace std;

int boas_vindas(){
    int resposta;
    cout<<"Bem vindo(a) a melhor FORCA do mundo!"<<endl;
    cout<<"Quer comecar a jogar? (1- SIM, 0 - NAO)"<<endl;
    cin>>resposta;

    return resposta;
}

void sortear_palavra(char palavra[], char palavras[][21], char Vet_acertos[]){ //OK
    int sorteado = rand()%TAM;
    int tamanho = strlen(palavras[sorteado]);
    strcpy(palavra, palavras[sorteado]);

    for(int i = 0; i<tamanho; i++){
        Vet_acertos[i]='_';
    }
    Vet_acertos[tamanho] = '\0';

}

void desenhar_forca(int erros){

    switch(erros){
    case 0: cout << endl << "--------|" << endl << "|" << endl << "|" << endl << "|" << endl << "|" << endl << "|";
        break;
    case 1:
        cout << endl << "--------|" << endl << "|       0"  << endl << "|" << endl << "|" << endl << "|" << endl << "|";
        break;
    case 2:
        cout << endl << "--------|" << endl << "|       0"  << endl << "|       |" << endl << "|" << endl << "|" << endl << "|";
        break;
    case 3:
         cout << endl << "--------|" << endl << "|       0"  << endl << "|       |" << endl << "|       /" << endl << "|" << endl << "|";
        break;
    case 4:
        cout << endl << "--------|" << endl << "|       0"  << endl << "|       |" << endl << "|       /\\" << endl << "|" << endl << "|";
        break;
    case 5:
        cout << endl << "--------|" << endl << "|       0"  << endl << "|     --|" << endl << "|       /\\" << endl << "|" << endl << "|";
        break;
    case 6:
        cout << endl << "--------|" << endl << "|       0"  << endl << "|     --|--" << endl << "|       /\\" << endl << "|" << endl << "|";
        break;
    }
}

void mostrar_palavra(char vet_acerto[],int acertos,int erros, char vet_erros[]){

    desenhar_forca(erros);
    cout << endl;

    int comp = strlen(vet_acerto), i;

    cout << endl;
    for(i = 0; i<comp; i++){
        cout<<vet_acerto[i]<<" ";

    }
    cout<<endl;
    cout<<"Acertos: "<<acertos<<endl;
    cout<<"Erros: "<<erros<<endl;

    for(i = 0; i < 6; i++){
         cout<<vet_erros[i]<<" ";
    }

    if(acertos == comp){
        cout << endl;
        cout << "PARABENS VOCE VENCEU!!!";
    }
    else if(erros == 6){
        cout << endl;
        cout << "VOCE PERDEU, TENTE NOVAMENTE!";
    }
}


int rodada(char palavra[], char vet_acertos[], char vet_erros[], int *acertos, int *erros){ // DESENHAR FORCA
    int comp = strlen(palavra), position = 0;
    while((*acertos != comp) && (*erros != 6)){
        int achou = 0 ;
        char resposta;
        cout << endl;
        cout<<"Digite uma letra: ";
        cin>>resposta;

        if(resposta == '*'){
            return 0;
        }else if (!isalpha(resposta)) {
            do{
                cout << endl;
                cout<<"Digite uma letra: ";
                cin>>resposta;

            }while(!isalpha(resposta));
        }

        if(resposta == '*'){
            cout<<"Saindo do programa...";
            exit(1);
        }
        for(int i = 0; i < comp; i++){
        if(resposta == palavra[i]){
            achou = 1;
            (*acertos)++;
            vet_acertos[i] = resposta;
            mostrar_palavra(vet_acertos,*acertos,*erros, vet_erros);
            }
        }
        if(achou == 0){
            (*erros)++;
            vet_erros[position] = resposta;
            position++;
            cout<<"Voce errou, tente outra letra."<<endl;

        }
    }

}

int main()
{
    int opcao = boas_vindas();
    if(opcao == 0){
        cout<<"Obrigado, nos fez de bobos";
    }else{
        srand(time(0));

        int erros = 0, acertos = 0;
        char palavra[21];
        char vet_acertos[21];
        char BancoPalavras[TAM][21] = {"ARROZ", "CARNE", "HAMBURGUER", "PERA", "BANANA", "SALADA", "LASANHA", "FRANGO", "CHOCOLATE", "PARMEGIANA"};
        char vet_erros[26] = " ";

        sortear_palavra(palavra, BancoPalavras, vet_acertos);

        mostrar_palavra(vet_acertos,acertos,erros, vet_erros);

        rodada(palavra, vet_acertos, vet_erros, &acertos, &erros);
    }


    return 0;
}
