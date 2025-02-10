#include <Esqueleto.hpp>
#define ALCANCEESQUELETO 45.f

namespace Entidades
{
    namespace Inimigos
    {
        Esqueleto::Esqueleto(const sf::Vector2f posicao) : Inimigo(sf::Vector2f(ESQUELETOLARGURA, ESQUELETOALTURA), posicao, IDESQUELETO)
        {
            velocidade = sf::Vector2f(VELOCIDADEX_ESQ, VELOCIDADEY_ESQ);
            setCor(sf::Color::White); // Laranja (255, 165, 0)
            float alcanceExtra = 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (10.0f - 1.0f)));
            setAlcance(ALCANCEESQUELETO + alcanceExtra);
            if (!textura.loadFromFile("Texturas/esqueleto6.png"))
            {
            }
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

        void Esqueleto::salvar() {}
        void Esqueleto::salvarDataBuffer() {}
    }
}