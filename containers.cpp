#include "containers.hpp"

ContainerUsuario* ContainerUsuario::instancia = nullptr;
ContainerAvaliacao* ContainerAvaliacao::instancia = nullptr;
ContainerHospedagem* ContainerHospedagem::instancia = nullptr;

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container usuário.

ContainerUsuario* ContainerUsuario::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerUsuario();
    return instancia;
}

bool ContainerUsuario::incluir(User usuario){
    return container.insert(make_pair(usuario.getEmail().getValue(), usuario)).second;
}

bool ContainerUsuario::remover(Email email){
    map<string, User>::iterator it = container.find(email.getValue());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerUsuario::pesquisar(User* usuario){
    map<string, User>::iterator it = container.find(usuario->getEmail().getValue());
    if(it != container.end()){
        *usuario = it->second;
        return true;
    }
    return false;
}

bool ContainerUsuario::atualizar(User usuario){
    map<string, User>::iterator it = container.find(usuario.getEmail().getValue());
    if(it != container.end()){
        it->second = usuario;
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container avaliação.

ContainerAvaliacao* ContainerAvaliacao::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerAvaliacao();
    return instancia;
}

bool ContainerAvaliacao::incluir(Rating avaliacao){
    return container.insert(make_pair(avaliacao.getCode().getValue(), avaliacao)).second;
}

bool ContainerAvaliacao::remover(Code code){
    map<string, Rating>::iterator it = container.find(code.getValue());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerAvaliacao::pesquisar(Rating* avaliacao){
    map<string, Rating>::iterator it = container.find(avaliacao->getCode().getValue());
    if(it != container.end()){
        *avaliacao = it->second;
        return true;
    }
    return false;
}

bool ContainerAvaliacao::pesquisar_usuario(Rating* avaliacao, Email email){
    for(map<string, Rating>::iterator it = container.begin();it != container.end();it++){
        if (it->second.getEmail().getValue().compare(email.getValue()) == 0){
            *avaliacao = it->second;
            return true;
        }
    }
    return false;
}

bool ContainerAvaliacao::pesquisar_hospedagem(Rating* avaliacao, Code code){
    for(map<string, Rating>::iterator it = container.begin();it != container.end();it++){
        if (it->second.getAccommodationCode().getValue().compare(code.getValue()) == 0){
            *avaliacao = it->second;
            return true;
        }
    }
    return false;
}

bool ContainerAvaliacao::atualizar(Rating avaliacao){
    map<string, Rating>::iterator it = container.find(avaliacao.getCode().getValue());
    if(it != container.end()){
        it->second = avaliacao;
        return true;
    }
    return false;
}

//------------------------------------------------------------------------------------
// Implementações de métodos de classe container hospedagem.

ContainerHospedagem* ContainerHospedagem::getInstancia() {
    if (instancia == nullptr)
        instancia = new ContainerHospedagem();
    return instancia;
}

bool ContainerHospedagem::incluir(Accommodation hospedagem){
    return container.insert(make_pair(hospedagem.getCode().getValue(), hospedagem)).second;
}

bool ContainerHospedagem::remover(Code code){
    map<string, Accommodation>::iterator it = container.find(code.getValue());
    if(it != container.end()){
        container.erase(it);
        return true;
    }
    return false;
}

bool ContainerHospedagem::pesquisar(Accommodation* hospedagem){
    map<string, Accommodation>::iterator it = container.find(hospedagem->getCode().getValue());
    if(it != container.end()){
        *hospedagem = it->second;
        return true;
    }
    return false;
}

bool ContainerHospedagem::pesquisar_anfitriao(Accommodation* hospedagem, Email email){
    for(map<string, Accommodation>::iterator it = container.begin();it != container.end();it++){
        if (it->second.getEmail().getValue().compare(email.getValue()) == 0){
            *hospedagem = it->second;
            return true;
        }
    }
    return false;
}

bool ContainerHospedagem::atualizar(Accommodation hospedagem){
    map<string, Accommodation>::iterator it = container.find(hospedagem.getCode().getValue());
    if(it != container.end()){
        it->second = hospedagem;
        return true;
    }
    return false;
}

