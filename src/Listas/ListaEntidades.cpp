#include "ListaEntidades.hpp"


Listas::ListaEntidades::ListaEntidades():
objLEs()
{
}

Listas::ListaEntidades::~ListaEntidades()
{
    objLEs.limpar();
}

void Listas::ListaEntidades::incluir(Entidade* entidade)
{
    objLEs.incluir(entidade);
}

void Listas::ListaEntidades::remover(Entidade *entidade)
{
    objLEs.removerElemento(entidade);
}

void Listas::ListaEntidades::executar()
{
int tam = objLEs.getTam();
    Entidade* aux = nullptr;
        for(int i = 0; i < tam; i++){
            
            aux = objLEs.operator[](i);
            aux->executar();
                
        }
}

const int Listas::ListaEntidades::getTam(){
    return objLEs.getTam();
 }

 Entidade *Listas::ListaEntidades::operator[](int pos)
 {
    return objLEs.operator[](pos);
 }

void Listas::ListaEntidades::limparLista(){
    objLEs.limpar();
}
