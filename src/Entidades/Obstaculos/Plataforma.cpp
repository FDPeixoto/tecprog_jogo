#include "../include/Entidades/Obstaculos/Plataforma.hpp"
#include "Plataforma.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Plataforma::Plataforma(float alt, float larg, sf::Vector2f posicao) : Obstaculo(sf::Vector2f(larg, 64.f), posicao, false, IDPLATAFORMA), largura(larg)
        {
            setCor(sf::Color(6, 64, 43)); // Verde Escuro
            //if (!textura.loadFromFile("Texturas/plataforma-64x64.png")) {}
            //Entidade::carregarTextura(&textura); 
        }
        Plataforma::Plataforma(sf::Vector2f posicao) : Obstaculo(sf::Vector2f(64.f, 64.f), posicao, false, IDPLATAFORMA)
        {
            setCor(sf::Color(6, 64, 43));
        }
        Plataforma::~Plataforma() {}
        void Plataforma::executar()
        {
            return;
        }
        void Plataforma::obstacular(Entidades::Jogador *pJogador)
        {
            return;
        }
        const float Plataforma::getAltura() { return altura; }
        const float Plataforma::getLargura() { return largura; }
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