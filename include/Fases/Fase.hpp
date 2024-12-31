#include "../Gerenciadores/Colisao.hpp"

namespace Fases{
    class Fase{
        private:
        Gerenciadores::Colisao GC;

        protected:
        void criarInimFaceis();
        void criarObstFaceis();
        void criarObstMedios();

        public:
        Fase();
        ~Fase();
        void criarPlataformas();
        void gerenciarColisoes();
        virtual void executar()=0;
        virtual void criarInimigos()=0;
        virtual void criarObstaculos()=0;
        virtual bool completou()=0;
        void criarCenario();
    };
}