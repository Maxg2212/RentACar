//
// Created by marcelo on 20/10/21.
//

#include "Graph.h"

Graph::Graph(int size) {
    this->number=0;
    int i=0;
    while(i!=size){
        NodeLogistic newNode(i+1);
        Nodes.push_back(newNode);
        this->Adminconections(i);
        i++;
    }
}

void Graph::Adminconections(int index) {
    if (this->Nodes.size()==1){
        //No hay nodos con los que conectar
    }else{
        int repetition=0;
        int limit=this->Nodes.size()-1;
        int firstconection=rand()%limit;//índice de la primera conexión del nodo
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

string Graph::Short(int Init, int Fin) {
    vector<int> Initialvector;
    Initialvector.push_back(Init);
    this->resetbacktracking(Fin);
    this->backtracking(--Init,--Fin,Initialvector);
    this->Nodes.at(Fin).path.push_back(Fin+1);
    string Answer=this->StringifyAnswer(this->Nodes.at(Fin).path);
    return Answer;
}

string Graph::StringifyAnswer(vector<int> Path) {
    string Answer;
    for(auto i=Path.begin();i!=Path.end();++i) {
        string add = to_string(*i);
        Answer.append(add);
        Answer.append("-");
    }
    return Answer;
}

void Graph::resetbacktracking(int Final) {
    vector<int> reset;
    for(auto i=this->Nodes.begin();i!=this->Nodes.end();++i){
        if(Final==i->getid()){
            this->Nodes.at(Final-1).setgas(100);
            this->Nodes.at(Final-1).path=reset;
        }else{
            continue;
        }
    }
}

int Graph::backtracking(int Init, int End,vector<int> UnvisitedNodes) {
    vector<int> VisitedNodes;
    map<int,int>::iterator itr;
    for(itr= this->Nodes.at(Init).connections.begin();itr!=this->Nodes.at(Init).connections.end();++itr){
        if((find(VisitedNodes.begin(),VisitedNodes.end(),itr->first)!=VisitedNodes.end())||(find(UnvisitedNodes.begin(),UnvisitedNodes.end(),itr->first)!=UnvisitedNodes.end())){//El nodo ya fue visitado o está siendo evaluado
            continue;
        }else if(itr->first-1==End){//El nodo por visitar es el objetivo
            int ActualGas=this->Nodes.at(Init).getgas();//Capacidad que se requiere para llegar al nodo actual
            int Endgas=this->Nodes.at(End).getgas();//Capacidad en el nodo
            int Travelgas=itr->second;
            if((ActualGas<Endgas)&&(Travelgas<Endgas)){//El camino requiere menot capacidad que el actual
                this->Nodes.at(End).path=UnvisitedNodes;
                VisitedNodes.push_back(End);
                if(ActualGas<Travelgas) {//El camino del nodo hacia el final es la máxima capacidad requerida
                    this->Nodes.at(End).setgas(Travelgas);
                    continue;
                }else{//El camino que requiere mayor capacidad se mantiene como el anterior
                    this->Nodes.at(End).setgas(ActualGas);
                    continue;
                }
            }else{//El nodo final tiene un cam mas corto
                VisitedNodes.push_back(End);
                continue;
            }
        }else{//El nodo No es el final se debe de evaluar
            UnvisitedNodes.push_back(itr->first);
            if(this->Nodes.at(Init).getgas()<itr->second){
                this->Nodes.at(itr->first-1).setgas(itr->second);
            }else{
                this->Nodes.at(itr->first-1).setgas(this->Nodes.at(Init).getgas());
            }
            VisitedNodes.push_back(this->backtracking(itr->first-1,End,UnvisitedNodes)+1);
            UnvisitedNodes.pop_back();
        }
    }
    return Init;
}