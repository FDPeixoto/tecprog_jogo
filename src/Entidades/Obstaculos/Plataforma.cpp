#include "../include/Entidades/Obstaculos/Plataforma.hpp"
#include "Plataforma.hpp"

namespace Entidades{
    namespace Obstaculos{
        Plataforma::Plataforma(float alt, float larg, sf::Vector2f posicao): Obstaculo(sf::Vector2f(larg, alt), posicao, false), largura(larg){}
        Plataforma::Plataforma(sf::Vector2f posicao): Obstaculo(sf::Vector2f(50.f, 50.f), posicao, false), largura(50.f)
        {
            
        }
        Plataforma::~Plataforma(){}
        void Plataforma::executar()
        {
            return;
        }
        void Plataforma::obstacular(Entidades::Jogador *pJogador)
        {
            return;
        }
        const float Plataforma::getAltura() { return altura; }
        const float Plataforma::getLargura(){return largura;}
        void Plataforma::salvar()
        {
            return;
        }
        void Plataforma::atualizar(float dt)
        {
            return;
        }
        void Plataforma::inicializar()
        {
            return;
        }
        void Plataforma::colisao(Entidade *outraEntidade)
        {
            return;
        }
    }
}