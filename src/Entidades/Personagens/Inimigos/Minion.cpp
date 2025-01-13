#include "../../../../include/Entidades/Personagens/Inimigos/Minion.hpp"
//include "Minion.hpp"

float distance(const sf::Vector2f& a, const sf::Vector2f& b) {
    return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

Personagens::Inimigos::Minion::Minion()
{
    retangulo.setSize(sf::Vector2f(20.f, 20.f));
    retangulo.setFillColor(sf::Color::Red);
    retangulo.setPosition(x, y);
    velocidade= 50.f;
}

Personagens::Inimigos::Minion::~Minion()
{
}

void Personagens::Inimigos::Minion::perseguir(Jogador *p)
{
}
void Personagens::Inimigos::Minion::salvar()
{
}

void Personagens::Inimigos::Minion::salvarDataBuffer()
{
}

void Personagens::Inimigos::Minion::atualizar(float deltaTime, Jogador* jogador1, Jogador* jogador2, sf::RectangleShape& plataforma) 
{
    // Calculando a distância entre o Minion e os jogadores
    float dist1 = distance(retangulo.getPosition(), jogador1->getRetangulo().getPosition());
    float dist2 = distance(retangulo.getPosition(), jogador2->getRetangulo().getPosition());
    
    // Escolhendo o jogador mais próximo
    Jogador* alvo = (dist1 < dist2) ? jogador1 : jogador2; //Jogador& alvo -->> Jogador* alvo

    // Calculando a direção do movimento (apenas no eixo X)
    sf::Vector2f direcao = alvo->getRetangulo().getPosition() - retangulo.getPosition();
    float comprimento = std::sqrt(direcao.x * direcao.x + direcao.y * direcao.y);

    // Normalizando a direção para ter uma unidade em X
    if (comprimento != 0.f) {
        direcao /= comprimento;
    }
    
    // Movendo o Minion horizontalmente, sem alterar a posição Y
    retangulo.move(direcao.x * velocidade * deltaTime, 0.f);//direção.x ser apenas para ver a direção, já que é unitário

    // Verifica se o Minion está sobre a plataforma
    if (retangulo.getPosition().y + retangulo.getSize().y >= plataforma.getPosition().y) {
        retangulo.setPosition(retangulo.getPosition().x, plataforma.getPosition().y - retangulo.getSize().y);
    }
}

void Personagens::Inimigos::Minion::executar()
{
}

int Personagens::Inimigos::Minion::get_tam_grupo()
{
    return tam_grupo;
}

sf::RectangleShape &Personagens::Inimigos::Minion::getRetangulo()
{
    return retangulo;
}
int Personagens::Inimigos::Minion::tam_grupo=1;

