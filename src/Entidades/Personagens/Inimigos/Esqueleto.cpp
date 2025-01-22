#include <Esqueleto.hpp>

namespace Entidades{
    namespace Inimigos{
        Esqueleto::Esqueleto(const sf::Vector2f tamanho, const sf::Vector2f posicao): Inimigo(tamanho, posicao){}
        Esqueleto::~Esqueleto(){}

        void Esqueleto::executar()
        {
        }
        void Esqueleto::danificar(Entidades::Jogador *pJogador)
        {
        }
        bool Esqueleto::foraPantano()
        {
            return false;
        }
    }
}