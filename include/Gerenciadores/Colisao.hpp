#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include <math.h>

namespace Gerenciadores{
    class Colisao{
        private:
            Listas::ListaEntidades* listaDeEntidades;

            
        public:
            Colisao(Listas::ListaEntidades* entidades);
            ~Colisao();
            const sf::Vector2f calculaColisao(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
            void executar();
    };
}