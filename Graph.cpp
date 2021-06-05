//collaborated with chloe
#include <iostream>
#include <unordered_map>
#include "Graph.h"

using namespace std;

Graph::Graph(){
}

Graph::Graph(ifstream& input){
    int numberOfNodes;
    int numOfEdges;
    int k;
    unsigned int in;
    unsigned prevIndex;
    string temp;
    string anotherTemp;

    input >> numberOfNodes;
    input >> numOfEdges;
    for(int i = 0; i < numberOfNodes; i++){
        input >> temp;
        vertices.push_back(Vertex(temp));
    }
    for(int j = 0; j < numOfEdges; j++){
        input >> temp;
        in = find(temp);
        input >> anotherTemp;
        prevIndex = find(anotherTemp);
        input >> k;
        //vertices.at(in).neighbors(prevIndex, k);
        //vertices.at(in).neighbors(prevIndex);
        int num = 0;
        input >> num;
        pair<int,int> p(prevIndex,num);
        vertices.at(in).neighbors.push_back(p);
    }
}

Graph::~Graph(){
    while(!vertices.empty()){
        vertices.pop_back();
    }
}
/*
void Graph::output_graph(const string& output){
    ofstream file(output.c_str());

    file << "digraph G {\n";
    for(unsigned i = 0; i < vertices.size(); ++i) {
        //initialize dotty object
        file << vertices.at(i).label << "[label =\"" << vertices.at(i).label << ", " << vertices.at(i).distance << "\"]" << endl;
    }

    for(unsigned i = 0; i < vertices.size(); ++i){
        for(list<pair<int, int>>::iterator j = vertices.at(i).neighbors.begin(); j != vertices.at(i).neighbors.end(); ++j) {
            file << vertices.at(i).label << "->" << vertices.at(j -> first).label << endl;
        }
    }

    file << "}";
    file.close();
    string command = "dot -Tpng " + output + ".dot -o " + output + ".jpg";
    system(command.c_str());
}
*/
void Graph::output_graph(const string &outputFilename){
 ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,0);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}

void Graph::visualizeTree(ofstream & outFS, int n){

    if(vertices[n].color == "BLACK")
        return;
    vertices[n].color = "BLACK";
    outFS << vertices[n].label << "[label=\"" << vertices[n].label << ", " << vertices[n].distance << "\"];" << endl;
    for(list<pair<int,int>>::const_iterator it = vertices[n].neighbors.begin(); it != vertices[n].neighbors.end(); it++)
    {
        outFS<< vertices[n].label <<" -> " << vertices[(*it).first].label <<";"<<endl;
        visualizeTree(outFS,(*it).first);
    }
}


void Graph::bfs(){
    queue<int> qVertices;
    int index;

    qVertices.push(0);
    vertices.at(0).distance = 0;

    while(!qVertices.empty()){
        index = qVertices.front();
        qVertices.pop();

        for(list<pair<int, int>>::iterator j = vertices.at(0).neighbors.begin(); j != vertices.at(0).neighbors.end(); ++j) {
            if(vertices.at(j -> first).color == "WHITE"){
                qVertices.push(j -> first);
                vertices.at(j -> first).color = "GRAY";
                vertices.at(j -> first).distance = vertices.at(index).distance + j -> second;
            }
        }
        vertices.at(index).color = "BLACK";
    }
}

unsigned Graph::find(const string& srch){
    for(unsigned int i = 0; i < vertices.size(); i++){
        if(vertices.at(i).label == srch){
            return i;
        }
    }
    return -1;
}
