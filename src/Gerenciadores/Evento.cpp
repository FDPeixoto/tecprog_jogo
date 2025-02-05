#include "Evento.hpp"
#include "FaseState.hpp"
#include "../../include/nlohmann/json.hpp"  // Incluindo a biblioteca JSON
using json = nlohmann::json; 

namespace Gerenciadores{
    Evento* Evento::pGerenciadorEvento = nullptr;

    Evento::Evento(): pJog1(nullptr), pJog2(nullptr), pGerenciadorGrafico(pGerenciadorGrafico->getGerenciadorGrafico()), pEstado(pEstado->getGerenciadorEstado()), nomePartida(""),pFase(nullptr){}
    Evento::~Evento(){
        pGerenciadorGrafico = nullptr;
        //pEstado = nullptr;
        pJog1 = nullptr;
        pJog2 = nullptr;
        fonte.loadFromFile("Fonte/DejaVuSans.ttf");
        //botaoConfirmar.setFonte("ConfirmarNome",fonte);
        textoEntrada.setFont(fonte);
        textoEntrada.setCharacterSize(24);
        textoEntrada.setFillColor(sf::Color::White);
        textoEntrada.setPosition(500, 30);  // Posição na tela*/
        // vetorPortal.clear();
        capturandoNome=true;
        nomePartida="Teste0";
        textoEntrada.setString("Nome da Partida: " + nomePartida);

    }
    
    Evento *Evento::getGerenciadorEvento()
    {
        if(pGerenciadorEvento == nullptr){
            pGerenciadorEvento = new Evento();
        }
        return pGerenciadorEvento;
    }

    void Evento::setJogador1(Entidades::Jogador* jogador){
        pJog1 = jogador;
    }
    void Evento::setJogador2(Entidades::Jogador* jogador){
        pJog2 = jogador;
    }
    void Evento::setNomePartida(const std::string nome){
        nomePartida=nome;
    }
    sf::Text Evento::getTextoEntrada()
  {
    
    return (textoEntrada);
  }



    void Evento::verificaTeclaPressionada(sf::Keyboard::Key tecla){
        if(tecla==sf::Keyboard::A){
            if(pJog2 != nullptr){pJog2->andar(true);}
        }
        else if(tecla==sf::Keyboard::D){
            if(pJog2 != nullptr){pJog2->andar(false);}
        }
        else if(tecla==sf::Keyboard::W){
            if(pJog2 != nullptr){pJog2->pular();}
        }
        else if(tecla==sf::Keyboard::Left){
            if(pJog1 != nullptr){pJog1->andar(true);}
        }
        else if(tecla==sf::Keyboard::Right){
            if(pJog1 != nullptr){pJog1->andar(false);}
        }
        else if(tecla==sf::Keyboard::Up){
            if(pJog1 != nullptr){pJog1->pular();}
        }
        else if(tecla==sf::Keyboard::M){
            if(pJog1 != nullptr){pJog1->setAtacando(true);}
        }
        else if(tecla==sf::Keyboard::S){
            if(pJog2 != nullptr){pJog2->setAtacando(true);}
        }
        else if(tecla==sf::Keyboard::R){
            mostrarRanking(pGerenciadorGrafico->getJanela());
        }
        else if(tecla==sf::Keyboard::Escape){
            pEstado->removerState();
        }
        else if(tecla ==sf::Keyboard::Num1){
            pEstado->addState(IDCASTELOASSOMBRADO);
        }
        else if(tecla ==sf::Keyboard::Num2){
            pEstado->addState(IDPANTANOMALDITO);
        }
    }
    

    void Evento::verificaTeclaSolta(sf::Keyboard::Key tecla){
        if( (tecla==sf::Keyboard::A)||(tecla==sf::Keyboard::D)){
            if(pJog2 != nullptr){pJog2->parar();}
        }
        if(tecla==sf::Keyboard::S){
            if(pJog2 != nullptr){pJog2->setAtacando(false);}
        }
        if( (tecla==sf::Keyboard::Left)||(tecla==sf::Keyboard::Right)){
            if(pJog1 != nullptr){pJog1->parar();}
        }
        if(tecla==sf::Keyboard::M){
            if(pJog1 != nullptr){pJog1->setAtacando(false);}
        }
    }
    void Evento::salvarNaFase(){
        if(pFase!=nullptr){
            pFase->setNomePartida(nomePartida);  // Define o nome da partida na fase
            
    }}
    void Evento::executar(){
        pFase=pEstado->getStateAtual()->getFase();
        sf::Event evento;
        while(pGerenciadorGrafico->getJanela()->pollEvent(evento)){
            //botaoConfirmar.desenhar(pGerenciadorGrafico->getJanela());
            if(evento.type == sf::Event::KeyPressed){
                verificaTeclaPressionada(evento.key.code);
            }
            else if(evento.type==sf::Event::KeyReleased){
                verificaTeclaSolta(evento.key.code);
            }
            else if(evento.type==sf::Event::Closed){
                pGerenciadorGrafico->fecharJanela();
            }
            salvarNaFase();
            /*if(capturandoNome==true){
            if (evento.type == sf::Event::TextEntered) {
                if (evento.text.unicode == 13) {  // 13 é o código ASCII para Enter
                    setNomePartida(nomePartida);
                    if(pFase!=nullptr){
                    pFase->setNomePartida(nomePartida);
                    pFase->salvarRanking("ranking.json");
                    }
                    capturandoNome = false;  // Termina a captura do nome
                }
                else if (evento.text.unicode < 128 && evento.text.unicode != 8) {  // Ignora backspace
                    nomePartida += static_cast<char>(evento.text.unicode);
                }
                else if (evento.text.unicode == 8 && nomePartida.size() > 0) {
                    nomePartida.pop_back();
                }

                textoEntrada.setString("Nome da Partida: " + nomePartida);
            }*/
        if(pFase!=nullptr){
        if (pFase->completouFase()==true) {
            pFase->salvarRanking("ranking.json");  // Salva o ranking no arquivo JSON
        }
        }
        
         //pGerenciadorGrafico->desenharTexto(textoEntrada);
         
         //else {
            //mostrarRanking(pGerenciadorGrafico->getJanela());
        //}

            }
        /*if (botaoConfirmar.foiClicado(pGerenciadorGrafico->getJanela())) {
            if(pFase!=nullptr){
            pFase->setNomePartida(nomePartida);  // Define o nome da partida na fase
            pFase->salvarRanking("ranking.json");  // Salva o ranking no arquivo JSON
            }
            capturandoNome = false;  // Termina a captura do nome
        }*/
        
    }
    

    void Evento::mostrarRanking(sf::RenderWindow* janela) {
    std::ifstream arquivo("ranking.json");
    if (arquivo.is_open()) {
        json ranking;
        arquivo >> ranking;
        arquivo.close();

        sf::Text textoRanking;
        textoRanking.setFont(fonte);
        textoRanking.setCharacterSize(24);
        textoRanking.setFillColor(sf::Color::White);

        int yPos = 50;
        for (int i = 0; i < ranking.size(); ++i) {
            std::string texto = "Partida: " + ranking[i]["nomePartida"].get<std::string>();
            textoRanking.setString(texto);
            textoRanking.setPosition(50, yPos);
            pGerenciadorGrafico->desenharTexto(textoRanking); 
            yPos += 40;

            for (const auto& jogador : ranking[i]["jogadores"]) {
                texto = jogador["nome"].get<std::string>() + " - " +
                        std::to_string(jogador["pontuacao"].get<int>());
                textoRanking.setString(texto);
                textoRanking.setPosition(50, yPos);
                janela->draw(textoRanking);  // Modificado para usar o ponteiro
                yPos += 40;
            }
            yPos += 20;
        }
    }
    }
}
    
    