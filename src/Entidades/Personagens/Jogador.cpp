#include "Jogador.hpp"


 namespace Entidades{
    Jogador::Jogador(const sf::Vector2f posicao, bool jogador2): 
        Personagem(sf::Vector2f(JOGADORLARGURA, JOGADORALTURA), posicao, IDJOGADOR),
        pontos(0), numero_baixas(0), espada (false), magia (false), antidoto (false), ehJogador2(ehJogador2), pulando(false)
    {
        if(jogador2){
            setCor(sf::Color::Green);
            setPosTexto(330.f, 200.f);
        }
        else{
            setCor(sf::Color::Blue);
        }
        setVelocidade(sf::Vector2f(0.f, 0.f));
    }

    Jogador::~Jogador() {}

    void Jogador::atualizar(float dt){

        if(noChao && pulando){
            velocidade.y = -120.f;
            corpo.move(0.f, velocidade.y *  dt);
            pulando = false;
            noChao = false;
        }
        //ou float dt=relogio.getElapsedTime().asSeconds();
        //Andando só na horizontal por enquanto
        
        if(!noChao){
            velocidade.y += 1.f;
            if(velocidade.y > 300.f){velocidade.y = 300.f;}
        }
        else{
            velocidade.y = 0;
        }
        noChao = false;
        corpo.move(velocidade.x * dt, velocidade.y *  dt);
        //setPos(sf::Vector2f(corpo.getPosition().x + velocidade.x * dt, corpo.getPosition().y + velocidade.y * dt));
    }

    void Jogador::andar(const bool ehEsquerda){
        atacando = false;
        andando = true;
        paraEsquerda = ehEsquerda;
        if(paraEsquerda){
            velocidade.x = -500.0f;
        }
        else{
            velocidade.x = 500.f;
        }
    }
    void Jogador::parar(){
        andando = false;
        velocidade.x = 0.0f;
    }
    const bool Jogador::getAndando() const{
        return andando;
    }

    void Jogador::salvarDataBuffer(){}

    void Jogador::executar() {
        /*std::string vidaStr = "Vida: " + std::to_string(num_vidas);  // Concatena a string
        textoVida.setString(vidaStr); 
        return (textoVida);*/
     }
    
    void Jogador::salvar(){}

    void Jogador::colisao(Entidade *outraEntidade)
    {   
        sf::Vector2f pos1 = getCorpo().getPosition();
        sf::Vector2f pos2 = outraEntidade->getCorpo().getPosition();

        sf::Vector2f tam1 = getCorpo().getSize();
        sf::Vector2f tam2 = outraEntidade->getCorpo().getSize();

        sf::Vector2f distancia(fabs((pos1.x + tam1.x/2.0f) - (pos2.x + tam2.x/2.0f)), fabs((pos1.y + tam1.y/2.0f) - (pos2.y + tam2.y/2.0f)));

        int ID = outraEntidade->getID();
        switch(ID){
            case IDINIMIGO:
                if(pos1.x < pos2.x){
                    if(pos1.y < pos2.y){
                        if(!getAndando()){setPos(sf::Vector2f(pos1.x -  0.1f * distancia.x, pos1.y -  0.1f * distancia.y));}
                        else{outraEntidade->setPos(sf::Vector2f(pos2.x +  0.1f * distancia.x, pos2.y +  0.1f * distancia.y));}
                    }
                    else{
                        if(!getAndando()){setPos(sf::Vector2f(pos1.x -  0.1f * distancia.x, pos1.y +  0.1f * distancia.y));}
                        else{outraEntidade->setPos(sf::Vector2f(pos2.x +  0.1f * distancia.x, pos2.y -  0.1f * distancia.y));}
                    }
                }
                else{
                    if(pos1.y < pos2.y){
                        if(!getAndando()){setPos(sf::Vector2f(pos1.x + 0.1f * distancia.x, pos1.y -  0.1f *distancia.y));}
                        else{outraEntidade->setPos(sf::Vector2f(pos2.x -  0.1f * distancia.x, pos2.y +  0.1f * distancia.y));}
                    }
                    else{
                        if(!getAndando()){setPos(sf::Vector2f(pos2.x +  0.1f * distancia.x, pos1.y +  0.1f * distancia.y));}
                        else{outraEntidade->setPos(sf::Vector2f(pos2.x -  0.1f * distancia.x, pos2.y -  0.1f * distancia.y));}
                    }
                }
                break;
            case IDOBSTACULO:
                if(pos1.x > pos2.x && pos1.x < pos2.x + tam2.x){
                    setPos(sf::Vector2f(pos2.x + tam2.x, pos1.y));
                }
                else if(pos1.x + tam1.x > pos2.x){
                    setPos(sf::Vector2f(pos2.x - tam1.x, pos1.y));
                }
                if(pos1.y < pos2.y){
                    setPos(sf::Vector2f(pos1.x, pos2.y - tam1.y));
                    velocidade.y = 0;
                    noChao = true;
                }
                break;

            default:
                break;
        }
    }
    void Jogador::inicializar()
    {
        return;
    }
    void Jogador::pular()
    {
        pulando = true;
    }
    void Jogador::setAtacando(bool v){
        atacando=v;
    }
    bool Jogador::getAtacando(){
        return atacando;
    }
 }
