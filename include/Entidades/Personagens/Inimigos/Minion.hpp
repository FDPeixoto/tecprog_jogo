#include "Inimigo.hpp"

namespace Personagens{
    namespace Inimigos{
        class Minion: public Inimigo{
            private:
            static int tam_grupo;
            sf::RectangleShape retangulo;

            public:
            Minion();
            ~Minion();
            void perseguir (Jogador* p);
            void salvar();
            void salvarDataBuffer();
            void executar();
            void atualizar(float deltaTime, Jogador& jogador1, Jogador& jogador2, sf::RectangleShape& plataforma);
            static int get_tam_grupo();

        };
        int Minion::tam_grupo=3;
    }
}