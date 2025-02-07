#include <Esqueleto.hpp>

namespace Entidades
{
    namespace Inimigos
    {
        Esqueleto::Esqueleto(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(ESQUELETOLARGURA, ESQUELETOALTURA), posicao, IDESQUELETO)
        {
            velocidade = sf::Vector2f(VELOCIDADEX_ESQ, VELOCIDADEY_ESQ);
            setCor(sf::Color::White); // Laranja (255, 165, 0)
            if (!textura.loadFromFile("Texturas/esqueleto6.png")) {}
            Entidade::carregarTextura(&textura); 
        }
        Esqueleto::~Esqueleto()
        {
            alcance = 0;
        }

        void Esqueleto::executar()
        {
            Inimigo::executar();
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
    }
}