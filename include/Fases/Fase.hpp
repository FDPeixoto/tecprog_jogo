#include "Gerenciadores/Colisao.hpp"
#include "../Listas/ListaEntidades.hpp"

namespace Fases{
    class Fase{

        protected:
        Listas::ListaEntidades* listaPersonagens;
        Listas::ListaEntidades* listaObstaculos;

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