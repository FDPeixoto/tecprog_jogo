#include "Inimigo.hpp"

namespace Personagens{
    namespace Inimigos{
        class Minion: public Personagem{
            private:
            static int tam_grupo;

            public:
            Minion();
            ~Minion();
            void perseguir (Jogador* p);
            void salvar();
            void salvarDataBuffer();
            void executar();
            void setCor(sf::Color c);
            void atualizar(float deltaTime, Jogador* jogador1, Jogador* jogador2, sf::RectangleShape& plataforma);
            static int get_tam_grupo();
            sf::RectangleShape& getRetangulo();
        };
        //int Minion::tam_grupo=1;//Testando 1 minion por enquanto
    }
}