#include <iostream>
#include <stdio.h>
#include <iomanip>

using namespace std;

class Graph
{
    int adjMatrix[20][20];
    int side;

  public:
    Graph(int n){
      side = n;
      for(int i=0; i<n; i++)
        adjMatrix[i][i]= 0;
    }

    void makeEdge(int from, int to){
      adjMatrix[from][to] = 1;
    }
    void displayMatrix(){
      for(int i=0; i<side; i++){
        if(i==0){
          cout<<setw(8)<<"| 0 ";
          for(int i=1; i<side; i++)
            cout<<i<<" ";
          cout<<endl;
          cout<<setw(4);
          for(int i=0; i<side; i++)
            cout<<"__";
          cout<<endl;
        }
        cout<<setw(4)<<i<<"| ";
        for(int j=0; j<side; j++)
          cout<<adjMatrix[i][j]<<" ";
        cout<<endl;
      }
    }
};
int main(){
  int n;
  cout<<"Enter the desired number of vertices in graph (should be less than 20): ";
  cin>>n;
  // creating Graph
  Graph g(n);

  //asking the user to add edges
  char ch;
  cout<<"Enter your first edge: \n";
  do{
    int x, y;

    cout<<"enter vertice 1 for edge: ";
    cin>>x;
    cout<<"enter vertice 2 for edge: ";
    cin>>y;

    g.makeEdge(x , y);

    //checking to continue the loop
    cout<<"Do you want to add another edge (y/n)? ";
    cin>>ch;
  }while(ch=='y'||ch=='Y');

  g.displayMatrix();

  return 0;

}
