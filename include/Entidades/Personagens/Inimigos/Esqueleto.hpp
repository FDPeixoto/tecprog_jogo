#include <Inimigo.hpp>

namespace Entidades{
    namespace Inimigos{
        class Esqueleto:public Inimigo{
            private:
                float alcance;
            public:
                Esqueleto(const sf::Vector2f tamanho, const sf::Vector2f posicao);
                ~Esqueleto();
                void executar();
                void danificar(Entidades::Jogador* pJogador);
                bool foraPantano();
        };
    }
}