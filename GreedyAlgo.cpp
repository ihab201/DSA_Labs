#include <iostream>
#include <cctype>

using namespace std;

const unsigned max1 = 100;

typedef unsigned graph[max1][max1];
graph g; unsigned nb; //nb actual number of nodes
bool colored[max1]; unsigned color[max1];

void init(){
    for(int i= 0; i< max1; i++){
        for(int j = 0; j< max1; j++){
            g[i][j] = 0;
        }
    }
    for(int i = 0; i< nb-1; i++){
        for(int j= 0; j< nb; j++){
            cout<<"Inside Init"<< endl;
            cout<< i << "," <<j;
            char answer;
            cout <<"Is "<< i << " adjacent to " <<j<< ", Enter Y(y) or N(n): ";
            cin >> answer;
            if(toupper(answer)== 'Y')
                g[i][j] = g[j][i] = 1;
        }
    }
}

void coloring(){
    unsigned i = 0; //First uncolored vertex
    unsigned j = 0; // First Color.
    unsigned size = 0, adj[nb-1]; //a node can be adjacent to maximum of nb -1 nodes
    bool candidate;

    

    while(i < nb){
        colored[0] = true; color[j] = j;

        //looking for nodes that can have same color as i
        unsigned k = i+1, size = 0;
        while(k < nb){
            candidate = true;
            while(!colored[k] && !g[i][k]){
                if(size == 0){
                    colored[k] = true; color[k] = j;
                    adj[size++] = k;
                }
                else { //size > 0
                    candidate = true;
                    for(int l = 0; l < size; l++){
                        if(g[l][adj[l]]){
                            candidate = false;
                            break;
                        }
                        if(candidate){
                            colored[k] = true; color[k] = j;
                            adj[size++] = k;
                        }
                        k++;
                    }

                }
                //look for the first uncolored vertex.
                k = i+1;
                while(colored[k]){
                    k++;              
                    i = k; j++; 
                }
            }
        }
    }
}

void display(){
    for(int i = 0; i< nb; i++){
        cout << "The color of the node "<< i<< "is: "<< color[i] << endl;
    }
}


int main(int argc, char const *argv[])
{
    cout << "Enter the number of nodes (this number should be less then or equal to " << max1 << " )";
    cin >> nb;
    init();
    coloring();
    display();
    return 0;
}
