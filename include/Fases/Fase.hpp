#include "Gerenciadores/Colisao.hpp"
#include "../Listas/ListaEntidades.hpp"

namespace Fases{
    class Fase: public Ente{

        protected:
        Listas::ListaEntidades* listaPersonagens;
        Listas::ListaEntidades* listaObstaculos;
        Gerenciadores::Colisao* pGerenciadorColisao;

        protected:
        void criarInimFaceis();
        void criarObstFaceis();
        void criarObstMedios();

        public:
        Fase();
        ~Fase();
        void criarPlataformas();
        void gerenciarColisoes();
        void executar();
        virtual void criarInimigos()=0;
        virtual void criarObstaculos()=0;
        virtual bool completou()=0;
        void criarJogador(const sf::Vector2f posicao);
        void criarMinion(const sf::Vector2f posicao);
        void criarPlataforma(const sf::Vector2f posicao);
        void criarEspinho(const sf::Vector2f posicao);
        void criarEntidade(char letra, const sf::Vector2f posicao);
        void desenhar();
        void criarCenario();
    };
}