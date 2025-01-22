#include <Obstaculo.hpp>

namespace Entidades{
    namespace Obstaculos{
        class Plataforma: public Obstaculo{
            private:
                float altura;
                float largura;
            public:
                Plataforma(float alt, float larg, sf::Vector2f posicao);
                ~Plataforma();
                void executar() = 0;
                void obstacular(Entidades::Jogador* pJogador);
                const float getAltura();
                const float getLargura();
        };
    }
}