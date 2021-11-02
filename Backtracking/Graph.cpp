//
// Created by marcelo on 20/10/21.
//

#include "Graph.h"

Graph::Graph(int size) {
    this->NumStep=0;
    this->Totalstep=0;
    this->setNameList();
    int i=0;
    while(i!=size){
        NodeLogistic newNode(i+1);
        Nodes.push_back(newNode);
        this->Adminconections(i);
        i++;
    }
    this->Graphsaver();
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

NodeLogistic Graph::searchnode(int ID) { //este metodo tiene un error porque no tiene valor de retorno
    //for(auto i=this->Nodes.begin(); i!=this->Nodes.end();i++){
        //if(i->getid()==ID){
           // return *i;
       // }else{
            //continue;
       // }
    //}
    return 0;
}

string Graph::Short(int Init, int Fin) {
    vector<int> Initialvector;
    Initialvector.push_back(Init);
    this->resetbacktracking(Fin);
    this->backtracking(--Init,--Fin,Initialvector);
    this->Nodes.at(Fin).path.push_back(Fin+1);
    string Answer=this->StringifyAnswer(this->Nodes.at(Fin).path,this->Nodes.at(Fin).getgas());
    return Answer;
}

string Graph::StringifyAnswer(vector<int> Path,int GAS) {
    string Answer;
    string Gasanswer= to_string(GAS);
    Answer.append("G=");
    Answer.append(Gasanswer);
    Answer.append("/P=");
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
            //----Registrar el paso----
            string paso;
            paso.append(to_string(Init+1));
            paso.append("T");
            paso.append(to_string(itr->first));
            paso.append("F-");
            this->Totalstep++;
            paso.append(to_string(Init+1));
            paso.append("D");
            paso.append(to_string(itr->first));
            paso.append("F-");
            this->Totalstep++;
            this->Decitions.append(paso);
            //--------------------------------------
            continue;
        }else if(itr->first-1==End){//El nodo por visitar es el objetivo
            //----Registrar el paso----
            string paso;
            paso.append(to_string(Init+1));
            paso.append("T");
            paso.append(to_string(itr->first));
            paso.append("T-");
            this->Totalstep++;
            paso.append(to_string(Init+1));
            paso.append("D");
            paso.append(to_string(itr->first));
            paso.append("T-");
            this->Totalstep++;
            this->Decitions.append(paso);
            //--------------------------------------
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
            //----Registrar el paso----
            string paso;
            paso.append(to_string(Init+1));
            paso.append("T");
            paso.append(to_string(itr->first));
            paso.append("T-");
            this->Totalstep++;
            this->Decitions.append(paso);
            //--------------------------------------
            VisitedNodes.push_back(this->backtracking(itr->first-1,End,UnvisitedNodes)+1);
            UnvisitedNodes.pop_back();
            //----Registrar el paso----
            paso="";
            paso.append(to_string(Init+1));
            paso.append("D");
            paso.append(to_string(itr->first));
            paso.append("T-");
            this->Totalstep++;
            this->Decitions.append(paso);
            //--------------------------------------

        }
    }
    return Init;
}

string Graph::step() {
    string nextstep;
    int index=5*this->NumStep;
    if (this->NumStep==this->Totalstep){
        return "Fin";
    }else{
        for(int i=0;i<4;i++){
            nextstep.push_back(this->Decitions[index+i]);
        }
        this->NumStep++;
        return nextstep;
    }
}

void Graph::setNameList() {
    this->NameList.push_back("San Francisco");//1
    this->NameList.push_back("Venecia");//2
    this->NameList.push_back("Las Vegas");//3
    this->NameList.push_back("Los Angeles");//4
    this->NameList.push_back("Nueva York");//5
    this->NameList.push_back("Nueva Delhi");//6
    this->NameList.push_back("San Jose");//7
    this->NameList.push_back("San Pedro");//8
    this->NameList.push_back("Paris");//9
    this->NameList.push_back("Berlin");//10
    this->NameList.push_back("Munich");//11
    this->NameList.push_back("Tokio");//12
    this->NameList.push_back("Hong Kong");//13
    this->NameList.push_back("Sydney");//14
    this->NameList.push_back("Barcelona");//15
    this->NameList.push_back("Van Gogh");//16
    this->NameList.push_back("Florencia");//17
    this->NameList.push_back("Wuhan");//18
    this->NameList.push_back("Caracas");//19
    this->NameList.push_back("Medellin");//20
    this->NameList.push_back("Lima");//21
    this->NameList.push_back("Toronto");//22
    this->NameList.push_back("Cancun");//23
    this->NameList.push_back("Belmopan");//24
    this->NameList.push_back("La Paz");//25
    this->NameList.push_back("Tegucigalpa");//26
    this->NameList.push_back("La Habana");//27
    this->NameList.push_back("Puerto Principe");//28
    this->NameList.push_back("San Juan");//29
    this->NameList.push_back("Santo Domingo");//30
    this->NameList.push_back("Bueno Aires");//31
    this->NameList.push_back("Sao Paolo");//32
    this->NameList.push_back("Santiago");//33
    this->NameList.push_back("Quito");//34
    this->NameList.push_back("Berna");//35
    this->NameList.push_back("Vienna");//36
    this->NameList.push_back("Amsterdam");//37
    this->NameList.push_back("Bruselas");//38
    this->NameList.push_back("Madrid");//39
    this->NameList.push_back("Atenas");//40
    this->NameList.push_back("Budapest");//41
    this->NameList.push_back("Dublin");//42
    this->NameList.push_back("Lyon");//43
    this->NameList.push_back("Kingston");//44
    this->NameList.push_back("Roma");//45
    this->NameList.push_back("Montevideo");//46
    this->NameList.push_back("Oslo");//47
    this->NameList.push_back("Helsinki");//48
    this->NameList.push_back("Moscu");//49
    this->NameList.push_back("Turin");//50
}

string Graph::getname(int ID) {
    if(this->Names[ID]==""){
        int index=rand()%this->NameList.size();
        this->Names[ID]=this->NameList.at(index);
        this->NameList.erase(next(this->NameList.begin(),index));
        return this->Names[ID];
    }else{
        return this->Names[ID];
    }
}

void Graph::Graphsaver() {
    ofstream Graphfile;
    Graphfile.open("Graph.txt");
    map<int,int>::iterator itr;
    for(int i=0;i<this->Nodes.size();i++){
        NodeLogistic currentNode=this->Nodes.at(i);
        Graphfile<<to_string(currentNode.getid());
        Graphfile<<"(";
        for(itr=currentNode.connections.begin();itr!=currentNode.connections.end();++itr){
            Graphfile<<to_string(itr->first);
            Graphfile<<":";
            Graphfile<<to_string(itr->second);
            if(++itr==currentNode.connections.end()){
            }else{
                Graphfile<<",";
            }
            itr--;
        }
        Graphfile<<")\n";
    }
    Graphfile.close();
}