#include "cntrService.hpp"
#include "../lib/Curses/curses.h"
#include "../lib/Domains/domain.hpp"
#include "../lib/Entities/entity.hpp"
#include "../containers.hpp"

//--------------------------------------------------------------------------------------------
// Implementações de métodos de classes controladoras da camada de serviço.

bool CntrSAutenticacao::autenticar(Email email, Password senha){

    // Instancia container de usuários.
    ContainerUsuario *container;

    User usuario;

    container = ContainerUsuario::getInstancia();
    usuario.setEmail(email);

    //recupera usuario
    if (container->pesquisar(&usuario)){ 
        if (usuario.getPassword().getValue().compare(senha.getValue()) == 0)
            return true;  // sucesso na autenticação
        else 
            return false; // falha na autenticação
        
    } 
    return false;
}

//--------------------------------------------------------------------------------------------

bool CntrSUsuario::cadastrar(User usuario){

    // Instancia container de usuários.
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    if (container->pesquisar(&usuario))
        return false;

    return container->incluir(usuario);
}

// falta implemetar
bool CntrSUsuario::descadastrarConta(Email email){
    return true;
}

//falta implementar
bool CntrSUsuario::editarConta(User usuario){
    return true;
}

//falta implementar
User CntrSUsuario::consultarDadosPessoais(Email email){
    User usuario;
    
    return usuario;
}

//--------------------------------------------------------------------------------------------


