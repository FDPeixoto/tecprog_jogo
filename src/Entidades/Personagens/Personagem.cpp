#include "../../../include/Entidades/Personagens/Personagem.hpp"
namespace Personagens{
    Personagem::Personagem(){
    num_vidas = 5;
    velocidade = 50.f;
  }
  Personagem::~Personagem(){};
  void Personagem::salvarDataBuffer(){};
  void Personagem::mover(){};
  void Personagem::executar() {};
  void Personagem::salvar(){};
  
}