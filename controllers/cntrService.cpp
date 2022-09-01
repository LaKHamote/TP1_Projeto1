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

// falta implementar
bool CntrSUsuario::descadastrarConta(Email email){
    ContainerUsuario *container_usuario;
    ContainerHospedagem *container_hospedagem;
    ContainerAvaliacao *container_avaliacao;

    container_usuario = ContainerUsuario::getInstancia();
    container_hospedagem = ContainerHospedagem::getInstancia();
    container_avaliacao = ContainerAvaliacao::getInstancia();

    User usuario;
    Accommodation hospedagem;
    Rating avaliacao;

    usuario.setEmail(email);
    
    if (container_usuario->pesquisar(&usuario)){
        while (container_hospedagem->pesquisar_anfitriao(&hospedagem, usuario.getEmail())){         // busca hospedagens do usuario (enquanto houver)
            container_hospedagem->remover(hospedagem.getCode());                                    // remove hospedagem
            while (container_avaliacao->pesquisar_hospedagem(&avaliacao, hospedagem.getCode())){    // busca avaliacoes relacionada a hospedagem encontrada (enquanto houver)
                container_avaliacao->remover(avaliacao.getCode());                                  // remove avaliacao
            }
        }
        while (container_avaliacao->pesquisar_usuario(&avaliacao, usuario.getEmail())){
            container_avaliacao->remover(avaliacao.getCode());
        }
        return container_usuario->remover(usuario.getEmail());
    }
    return false;
}

bool CntrSUsuario::editarConta(User usuario){
    // Instancia container de usuários.
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    User usuario_antes_da_edicao;

    usuario_antes_da_edicao.setEmail(usuario.getEmail());
    container->pesquisar(&usuario_antes_da_edicao);
    if (usuario.getName().getValue() == "")
        usuario.setName(usuario_antes_da_edicao.getName());
    if (usuario.getPassword().getValue() == "")
        usuario.setPassword(usuario_antes_da_edicao.getPassword());
    if (usuario.getLanguage().getValue() == "")
        usuario.setLanguage(usuario_antes_da_edicao.getLanguage());
    if (usuario.getDate().getValue() == "")
        usuario.setDate(usuario_antes_da_edicao.getDate());
    if (usuario.getDescription().getValue() == "")
        usuario.setDescription(usuario_antes_da_edicao.getDescription());

    return container->atualizar(usuario);
}

User CntrSUsuario::consultarDadosPessoais(Email email){
    ContainerUsuario *container;

    container = ContainerUsuario::getInstancia();

    User usuario;

    usuario.setEmail(email);
    container->pesquisar(&usuario);

    return usuario;
}

//--------------------------------------------------------------------------------------------

bool CntrSHospedagem::cadastrarHospedagem(Accommodation hospedagem){

    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    if (container->pesquisar(&hospedagem))
        return false;

    return container->incluir(hospedagem);
}

bool CntrSHospedagem::descadastrarHospedagem(Code codigo){

    ContainerHospedagem *container_hospedagem;
    ContainerAvaliacao *container_avaliacao;

    container_hospedagem = ContainerHospedagem::getInstancia();
    container_avaliacao = ContainerAvaliacao::getInstancia();

    Rating avaliacao;

    while (container_avaliacao->pesquisar_hospedagem(&avaliacao, codigo)){    // busca avaliacoes relacionada a hospedagem encontrada (enquanto houver)
        container_avaliacao->remover(avaliacao.getCode());                                  // remove avaliacao
    }

    container_hospedagem->remover(codigo);
    return false;
}

bool CntrSHospedagem::editarHospedagem(Accommodation hospedagem){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    Accommodation hospedagem_antes_da_edicao;

    hospedagem_antes_da_edicao.setCode(hospedagem.getCode());
    container->pesquisar(&hospedagem_antes_da_edicao); // n entendi
    if (hospedagem.getCity().getValue() == "")
        hospedagem.setCity(hospedagem_antes_da_edicao.getCity());
    if (hospedagem.getCountry().getValue() == "")
        hospedagem.setCountry(hospedagem_antes_da_edicao.getCountry());
    if (hospedagem.getGrade().getValue() == "")
        hospedagem.setGrade(hospedagem_antes_da_edicao.getGrade());
    if (hospedagem.getEmail().getValue() == "")
        hospedagem.setEmail(hospedagem_antes_da_edicao.getEmail());
    if (hospedagem.getDescription().getValue() == "")
        hospedagem.setDescription(hospedagem_antes_da_edicao.getDescription());

    return container->atualizar(hospedagem);
}

Accommodation CntrSHospedagem::consultarHospedagem(Code code){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    Accommodation hospedagem;

    hospedagem.setCode(code);
    container->pesquisar(&hospedagem);

    return hospedagem;
}

bool CntrSHospedagem::cadastrarAvaliacao(Rating avaliacao){

    ContainerAvaliacao *container;

    container = ContainerAvaliacao::getInstancia();

    if (container->pesquisar(&avaliacao))
        return false;

    return container->incluir(avaliacao);
}

bool CntrSHospedagem::descadastrarAvaliacao(Code codigo){
    ContainerAvaliacao *container_hospedagem;

    container_hospedagem = ContainerAvaliacao::getInstancia();

    container_hospedagem->remover(codigo);

    return false;
}

bool CntrSHospedagem::editarAvaliacao(Rating avaliacao){
    ContainerAvaliacao *container;

    container = ContainerAvaliacao::getInstancia();

    Rating avaliacao_antes_da_edicao;

    avaliacao_antes_da_edicao.setCode(avaliacao.getCode());
    container->pesquisar(&avaliacao_antes_da_edicao);
    if (avaliacao.getGrade().getValue() == "")
        avaliacao.setGrade(avaliacao_antes_da_edicao.getGrade());
    if (avaliacao.getDescription().getValue() == "")
        avaliacao.setDescription(avaliacao_antes_da_edicao.getDescription());

    return container->atualizar(avaliacao);
}

map<string, Accommodation> CntrSHospedagem::listarHospedagens(){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();

    return container->getContainer();
}

User CntrSHospedagem::acessarDadosAnfitriaoHospedagem(Code code){
    ContainerHospedagem *container;

    container = ContainerHospedagem::getInstancia();
    /////////////////////////////
    ///////////////////////////
    /////////////////////////////

    User user;
    return user;
}