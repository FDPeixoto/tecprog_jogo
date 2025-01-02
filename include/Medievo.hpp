//#include "Entidades/Personagens/Jogador.hpp"
class Jogador;
//#include "Entidades/Entidade.hpp"
#include "Fases/Pantano_Maldito.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
class Medievo {
    private:
    Personagens::Jogador* pJog1;
    Personagens::Jogador* pJog2;
    Fases::Pantano_Maldito primeiraFase;
    //Gerenciadores::Grafico GG;

    public:
    float distance(const sf::Vector2f& a, const sf::Vector2f& b);
    Medievo();
    ~Medievo();
    void executar();
    void setJog(Personagens::Jogador* p, int num);

};
