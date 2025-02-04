#include "Projetil.hpp"

namespace Entidades
{
    Projetil::Projetil(const sf::Vector2f posicao) : Entidade(sf::Vector2f(TAM_X_PROJETIL, TAM_Y_PROJETIL), posicao, ID_PROJETIL), vxP(0.0f), velocidade(sf::Vector2f(500.0f, 0.0f))
    {
    }
    Projetil::~Projetil() {}
    // void Projetil::atirar(Jogador* pAlvo){}
    void Projetil::setVelocidade(sf::Vector2f vel)
    {
        velocidade = vel;
    }
    void Projetil::atirar(const sf::Vector2f posicaoInimigo, bool direita)
    {
        setPos(posicaoInimigo); // O projétil começa na posição do inimigo (Durahan)
        if (direita == true)
        {
            setVelocidade(sf::Vector2f(VEL_X_P, 0.f));
            setCor(sf::Color::White); 
            if (!textura.loadFromFile("Texturas/proj-Dir.png")) {}
            Entidade::carregarTextura(&textura);
        }
        else
        {
            setCor(sf::Color::White); 
            if (!textura.loadFromFile("Texturas/proj-Esq.png")) {}
            Entidade::carregarTextura(&textura);
            setVelocidade(sf::Vector2f(-VEL_X_P, 0.f));
        }
        setCor(sf::Color::Red);
    }
    void Projetil::executar()
    {
        return;
    }
    void Projetil::inicializar()
    {
        return;
    }
    void Projetil::atualizar(float dt)
    {
        float ds = velocidade.x * dt; // ou velocidadeFinal.x
        corpo.move(ds, 0.001f);
        return;
    }
    void Projetil::atualizarPosicao(float dt) {}
    void Projetil::colisao(Entidade *outraEntidade) {}
    void Projetil::salvar() {}
}