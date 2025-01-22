#include "ListaEntidades.hpp"
#include "Lista.hpp"
#include <math.h>

namespace Gerenciadores{
    class Colisao{
        private:
            Listas::ListaEntidades* listaDeEntidades;

            static Colisao* pColisao;
            Colisao();
        public:
            ~Colisao();
            static Colisao* getGerenciadorColisao();
            void setListaEntidades(Listas::ListaEntidades* entidades);
            const sf::Vector2f calculaColisao(Entidades::Entidade* entidade1, Entidades::Entidade* entidade2);
            void executar();
    };
}