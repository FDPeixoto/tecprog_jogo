#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Entidades{
    namespace Inimigos{
        class Minion: public Inimigo{
            private:
            static int tam_grupo;

            public:
            Minion();
            Minion(const sf::Vector2f posicao);
            ~Minion();
            void salvar();
            void salvarDataBuffer();
            void executar();
            void atualizar(float deltaTime, Entidades::Jogador* jogador1, Entidades::Jogador* jogador2, sf::RectangleShape& plataforma);
            static int get_tam_grupo();
            void colisao(Entidade *outraEntidade);
            void mover();
        };
    }
}