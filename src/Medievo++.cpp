#include "Jogador.hpp"
#include <iostream>

class Medievo {
    private:
    Personagens::Jogador* pJog1;
    Personagens::Jogador* pJog2;
    //Gerenciadores::Grafico GG;

    public:
    Medievo(): pJog1(nullptr),pJog2(nullptr){};
    ~Medievo(){
        pJog1=nullptr;
        pJog2=nullptr;
    }
    void setJog(Personagens::Jogador* p, int num){
        if(p!=nullptr){
            if(num==1){
                pJog1=p;
            }
            else if(num==2){
                pJog2=p;
            }
            else{
                std::cout<<"Numero nao eh valido para incializar ponteiro de jogador"<<std::endl;
            }
        }
    }

};