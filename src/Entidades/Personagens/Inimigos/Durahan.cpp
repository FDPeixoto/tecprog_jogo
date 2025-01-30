#include "Durahan.hpp"

namespace Entidades{
    namespace Inimigos{
        Durahan::Durahan(const sf::Vector2f posicao): Inimigo(sf::Vector2f(DURAHANLARGURA,DURAHANALTURA ), posicao), listaProjetil() {
            velocidade = sf::Vector2f(VELOCIDADEX_DU,VELOCIDADEY_DU );
            antidoto_mortal=false;
            tiros=0;
            it=0;
            srand((unsigned int)time(NULL));  
            aleatorio= (rand() % (FAIXA_ALEATORIO*3)); 
            
            criarProjetil();
        }
        Durahan::~Durahan(){
            antidoto_mortal=false;
            listaProjetil.clear();
        }
        void Durahan::criarProjetil(){
            Entidades::Projetil* proj=new Entidades::Projetil(sf::Vector2f(0.0f, 0.0f));
            //for(int i=0; i<TAM_MAX_P; i++){
                    if(proj != nullptr){
                        proj->setCor(sf::Color::White);
                        listaProjetil.push_back(proj);
                    }
                //}
        }
        void Durahan::atirar(){
            if(tiros<TAM_MAX_P){
                int contador = 0;
                for (auto it = listaProjetil.begin(); it != listaProjetil.end(); ++it) {
                    if (contador == tiros) {
                        Entidades::Entidade* proj = *it;
                        if(proj != nullptr){
                            proj->setAtivo(true);
                            proj->atirar(this->getPos());
                            proj->executar();
                        }
                        break;  // Não precisa continuar após encontrar
                    }
                    ++contador;
                }
                /*if(listaProjetil[tiros]!=nullptr){
                    //Entidades::Projetil proj= new Entidades::Projetil(getPos(this));
                    Entidades::Projetil* proj=listaProjetil[tiros];
                    proj->setAtivo(true);
                    proj->executar();
                }*/
            }
            /*criarProjetil();
            proj->setAtivo(true);
            proj->atirar(this->getPos);*/

        }
        void Durahan::salvar(){}
        void Durahan::salvarDataBuffer(){}
        void Durahan::executar(){
            Inimigo::executar();
            it++;
            if(aleatorio>FAIXA_ALEATORIO){
                atirar();
            }
            if(it>=10){
                tiros++;
                srand((unsigned int)time(NULL));  
                // Gera um número aleatório entre 0 e 99
                aleatorio = (rand() % (FAIXA_ALEATORIO*3)); 
                it=0; 
            }
        }
        void Durahan::danificar(Entidades::Jogador* pJogador){}
        void Durahan::golpeMortal(){}
        void Durahan::setAntidotoMortal(bool flg){
            antidoto_mortal=flg;
        }
        void Durahan::colisao(Entidade *outraEntidade){}
        std::list<Entidades::Entidade*>& Durahan::getListaProjetil(){
            return listaProjetil;
        }
    }
}