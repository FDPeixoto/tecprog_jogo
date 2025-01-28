#include <Canhao.hpp>


        Entidades::Obstaculos::Canhao::Canhao( float alt, float larg,const sf::Vector2f posicao): Entidades::Obstaculos::Obstaculo(sf::Vector2f(larg, alt), posicao, false){}
        Entidades::Obstaculos::Canhao::~Canhao(){}
        void Entidades::Obstaculos::Canhao::obstacular(Entidades::Jogador *pJogador)
        {           
        }
         void Entidades::Obstaculos::Canhao::lancar(Entidades::Jogador * pJogador)
        {
        }
        void Entidades::Obstaculos::Canhao::executar(){}
        void Entidades::Obstaculos::Canhao::salvar(){}
        void Entidades::Obstaculos::Canhao::atualizar(float dt){}
        void Entidades::Obstaculos::Canhao::colisao(Entidade *outraEntidade){}
        void Entidades::Obstaculos::Canhao::inicializar(){}
        void Entidades::Obstaculos::Canhao::atualizarPosicao(float dt){}
