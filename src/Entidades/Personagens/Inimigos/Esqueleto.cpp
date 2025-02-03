#include <Esqueleto.hpp>

namespace Entidades
{
    namespace Inimigos
    {
        /*Esqueleto::Esqueleto(){
            alcance=ALCANCE
        }*/
        Esqueleto::Esqueleto(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(ESQUELETOLARGURA, ESQUELETOALTURA), posicao, IDESQUELETO)
        {
            velocidade = sf::Vector2f(VELOCIDADEX_ESQ, VELOCIDADEY_ESQ);
            setCor(sf::Color(255, 165, 0)); // Laranja
        }
        Esqueleto::~Esqueleto()
        {
            alcance = 0;
        }

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
        void Esqueleto::salvar() {}
        void Esqueleto::salvarDataBuffer() {}
        // void Esqueleto::colisao(Entidade *outraEntidade){}
    }
}