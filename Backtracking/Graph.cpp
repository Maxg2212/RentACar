//
// Created by marcelo on 20/10/21.
//

#include "Graph.h"

Graph::Graph(int size) {
    int i=0;
    while(i!=size){
        NodeLogistic newNode(i+1);
        Nodes.push_back(newNode);
        this->Adminconections(i);
        i++;
    }
}

void Graph::Adminconections(int index) {
    int repetition=0;
    int firstconection=rand()%this->Nodes.size();//índice de la primera conexión del nodo
    if (this->Nodes.size()==1){
        //No hay nodos con los que conectar
    }else{
        while (repetition<=this->Nodes.size()){
            int peso=rand()%25+1;//Peso entre 1-25
            if (repetition==0){//Asegura que un nodo esté conectado mínimo a un nodo
                this->makeconnection(index,firstconection,peso);
                repetition++;
                continue;
            }else{//Conexión aleatoria con el resto de nodos
                if((repetition-1==firstconection)||(repetition-1==index)){//conexión inicial se ignora, ya está hecha
                    repetition++;
                    continue;
                }else{
                    int probability=rand()%4+1;
                    if(probability==1){//el nodo debe conectar (probabilidad 25%)
                        this->makeconnection(index,repetition-1,peso);
                        repetition++;
                        continue;
                    }else{
                        repetition++;
                        continue;
                    }
                }
            }
        }
    }
}

void Graph::makeconnection(int Node1, int Node2, int peso) {
    this->Nodes.at(Node1).makeconnection(Node2+1,peso);
    this->Nodes.at(Node2).makeconnection(Node1+1,peso);
}


NodeLogistic Graph::searchnode(int ID) {
    for(auto i=this->Nodes.begin(); i!=this->Nodes.end();i++){
        if(i->getid()==ID){
            return *i;
        }else{
            continue;
        }
    }
}



