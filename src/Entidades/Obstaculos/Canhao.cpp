#include <Canhao.hpp>

Entidades::Obstaculos::Canhao::Canhao(const sf::Vector2f posicao) : Entidades::Obstaculos::Obstaculo(sf::Vector2f(LARGURA_CANHAO, ALTURA_CANHAO), posicao, false, IDCANHAO), lancamentos(0) //,listaBolasCanhao(){
{
    setCor(sf::Color::Yellow);
    it = 0;
    srand((unsigned int)time(NULL));
    aleatorio = (rand() % (FAIXA_ALEATORIO * 5));
    // listaBolasCanhao.clear();

    // criarBolasCanhao();
}
Entidades::Obstaculos::Canhao::~Canhao()
{
    // listaBolasCanhao.clear();
}
/*void Entidades::Obstaculos::Canhao::criarBolasCanhao(){

        for(int i=0; i<TAM_MAX_BOLAS_CANHAO; i++){
            Entidades::BolaCanhao* canhao=new Entidades::BolaCanhao(sf::Vector2f(1000.0f, 0.0f));//posicão
            if(canhao != nullptr){
                canhao->setCor(sf::Color::Cyan);
                listaBolasCanhao.push_back(proj);
            }
        }
}*/
void Entidades::Obstaculos::Canhao::obstacular(Entidades::Jogador *pJogador)
{
}
void Entidades::Obstaculos::Canhao::lancar(Entidades::Jogador *pJogador)
{
}
void Entidades::Obstaculos::Canhao::executar()
{
    // atualizarListB (dt);
}
/*void Entidades::Obstaculos::Canhao::atualizarListB(float dt)
{
    for (std::list<Entidades::Entidade*>::iterator it = listaBolasCanhao.begin(); it != listaBolasCanhao.end(); ++it) {
        if (*it != nullptr) {
            if((*it)->getAtivo()==true){
                (*it)->atualizar(dt);  // Chama a função atualizar para cada projétil
            }
        }
    }
}*/

void Entidades::Obstaculos::Canhao::salvar() {}
void Entidades::Obstaculos::Canhao::atualizar(float dt) {}
void Entidades::Obstaculos::Canhao::inicializar() {}
void Entidades::Obstaculos::Canhao::atualizarPosicao(float dt) {}
