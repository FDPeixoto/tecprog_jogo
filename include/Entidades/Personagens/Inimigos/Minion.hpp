#include "Inimigo.hpp"
#include "Jogador.hpp"

namespace Entidades{
    class Minion: public Inimigo{
        private:
        static int tam_grupo;

        public:
        Minion();
        ~Minion();
        void salvar();
        void salvarDataBuffer();
        void executar();
        void atualizar(float deltaTime, Entidades::Jogador* jogador1, Entidades::Jogador* jogador2, sf::RectangleShape& plataforma);
        static int get_tam_grupo();
        sf::RectangleShape& getRetangulo();
    };
        //int Minion::tam_grupo=1;//Testando 1 minion por enquanto
}