/*#include "BolaCanhao.hpp"

namespace Entidades{
    BolaCanhao::BolaCanhao(const sf::Vector2f posicao):Entidade( sf::Vector2f (TAM_X_BOLACANHAO,TAM_Y_BOLACANHAO), posicao, IDBOLACANHAO), vxP(0.0f), velocidade(sf::Vector2f(200.0f,0.0f)){
        if(pos.x>=(LARGURA/2)){
            direita=false; //atira para a esquerda
        }
        else{
            direita=true;
        }
    }
    BolaCanhao::~BolaCanhao(){}
    //void BolaCanhao::atirar(Jogador* pAlvo){}
    void BolaCanhao::setVelocidade(sf::Vector2f vel){
    velocidade = vel;
    }
    void BolaCanhao::atirar(const sf::Vector2f posCanhao) {
        setPos(posCanhao); // O projétil começa na posição do inimigo (Durahan)
        if(direita==true){
            setVelocidade(sf::Vector2f(VEL_X_P, 0.f));
        }
        else{
            setVelocidade(sf::Vector2f(-VEL_X_P, 0.f));
        }
        setCor(sf::Color::White);
        
    }
    void BolaCanhao::executar() {
        return;
    }
    void BolaCanhao::inicializar() {
        return;
    }
    void BolaCanhao::atualizar(float dt ){
        float ds = velocidade.x * dt;//ou velocidadeFinal.x
        corpo.move(ds, 0.f);
        return;
    }
    void BolaCanhao::atualizarPosicao(float dt){}
    void BolaCanhao::colisao(Entidade *outraEntidade){}
    void BolaCanhao::salvar(){}
}*/