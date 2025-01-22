#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include <math.h>

namespace Gerenciadores{
    class Colisao{
        private:
            Listas::ListaEntidades* listaMoveis;
            Listas::ListaEntidades* listaFixos;

            static Colisao* pColisao;
            Colisao();
        public:
            ~Colisao();
            static Colisao* getGerenciadorColisao();
            void setMoveis(Listas::ListaEntidades* moveis);
            void setFixos(Listas::ListaEntidades* fixos);
            const sf::Vector2f calculaColisao(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
            void executar();
    };
}