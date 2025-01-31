#include "Fase.hpp"

namespace Fases{
    class Castelo_Assombrado: public Fase{
        private:
            const int maxChefoes;
        public:
            Castelo_Assombrado();
            ~Castelo_Assombrado();
            void criarInimigos();
            void criarObstaculos();
            void criarMapa();
    };
}