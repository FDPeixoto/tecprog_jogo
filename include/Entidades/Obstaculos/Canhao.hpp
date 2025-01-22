#include <Obstaculo.hpp>

namespace Entidades{
    namespace Obstaculos{
        class Canhao: public Obstaculo{
            private:
                int velocidade_inicial;
            public:
                Canhao(const sf::Vector2f tamanho, const sf::Vector2f posicao);
                ~Canhao();
                void obstacular(Entidades::Jogador* pJogador);
                void lancar(Entidades::Jogador* pJogador);
        };
    }
}