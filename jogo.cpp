#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;

int main (){
  cout << "***************************************" << std::endl;
  cout << "* Boas vindas ao Jogo da Adivinhacao! *" << std::endl;
  cout << "***************************************" << std::endl;

  cout << "Escolha o seu nível de dificuldade: " << endl;
  cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;

  char dificuldade;
  cin >> dificuldade;

  int numero_de_tentativas;

  if (dificuldade == 'F'){
      numero_de_tentativas = 15;
  }
  else if (dificuldade == 'M'){
      numero_de_tentativas = 10;
  }
  else {
      numero_de_tentativas = 5;
  }

  srand(time(NULL));
  const int NUMERO_SECRETO = rand() % 100;

  bool nao_acertou = true;
  int tentativas = 0;
  double pontos = 1000.0;

  while (nao_acertou){
    tentativas++;
    int chute;
    cout << "Tentativa " << tentativas << endl;
    cout << "Qual seu chute?";
    cin >> chute;

    double pontos_perdidos = abs((chute - NUMERO_SECRETO)/2.0);
    pontos = pontos - pontos_perdidos;
    cout << "O valor do seu chute e: " << chute << endl;
    bool acertou = chute == NUMERO_SECRETO;
    bool maior = chute > NUMERO_SECRETO;

    cout << pontos << endl;
    if (acertou)
    {
      cout << "Parabens! Você acertou o numero secreto!" << endl;
      nao_acertou = false;
      break;
    }
    else if (maior)
    {
      cout << "Seu chute foi maior que o numero secreto!" << endl;
    }
    else
    {
      cout << "Seu chute foi menor que numero secreto!" << endl;
    }
  } 
  cout << "Fim de Jogo" << endl;
  if (nao_acertou){
    cout << "Você perdeu! Tente novamente!" << endl;
  }
  else {
    cout << "Você acertou o numero secreto em " << tentativas << " tentativas" << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Sua pontuacao foi de " << pontos << " pontos." << endl;
  }
}