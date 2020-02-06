#include "the3.h"


// You  can define extra functions here


void helper( int i, bool *visited,int **graph, int n)
{
	visited[i] = true;

	for(int k = 0; k < n ; k++){
		if(graph[i][k]!=0 && visited[k]==false){
			helper(k,visited,graph,n);
		}
	}

}	


int countDisconnect(int **graph,int n) 
{ 
    bool* visited = new bool[n]; 
  
    int count = 0; 
    for (int v = 0; v < n; v++) {
        visited[v] = false; 
    }
    // her vertexi dolas. o vertexin komsusu varsa recursive sekilde git.
    // gittiklerine tekrar gitme. i.e (visited = true ise gitme)
    for (int v = 0; v < n; v++) { 
        if (visited[v] == false) { 
            helper(v, visited,graph, n); 
            count += 1; 
        } 
    } 

    return count; 
} 

// INPUT :
//            n         : number of nodes in the graph
//            edgeList  : edges in the graph
//            scores    : importance scores
// return value : 
//                 number of disconnected components
int Important(int n, int**& edgeList, double*& scores)
{ 
	for(int i = 0; i<n ; i++){
		scores[i] = 0;
	}

	int  i, j, k;
	for (k = 0; k < n; k++) 
	{ 
		for (i = 0; i < n; i++) 
		{ 
			for (j = 0; j < n; j++) 
			{ 
				// If vertex k is on the shortest path from 
				// i to j, then update the value of edgeList[i][j]
				// but there are constraints!!
				// If there is no connection through k do nothing
				if(!(edgeList[i][k]==0 && k!=i) && !(edgeList[k][j]==0 && k!=j)){
					//if one of the left side of the equality is infinity do nothing
					if (edgeList[i][k] + edgeList[k][j] < edgeList[i][j]) {
						//cout << "degismeden once: " << edgeList[i][j] << endl;
						edgeList[i][j] = edgeList[i][k] + edgeList[k][j]; 
						//cout << "degistikten sonra:" << edgeList[i][j] << endl;
					}
					else if((edgeList[i][j] == 0 && i !=j))
					{
                        // aralarinda baglanti yoksa ve baglantiyi saglayacak kye giden yollar sonsuz degilse
						if(!(edgeList[i][k]==0 && k!=i) && !(edgeList[k][j]==0 && k!=j)){
							//cout << "else" << endl;
							//cout << edgeList[i][j] << endl;
							edgeList[i][j] = edgeList[i][k] + edgeList[k][j]; 
			
					 	}
					}
				}

			} 
		} 
	} 
	for( int k = 0; k <n ; k++){
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j <n; ++j)
			{
				if(k!=i && k!=j){
					// shortest path =1
					if(i==j){
						scores[k] += edgeList[i][k] + edgeList[k][j]; 
					}
					//aralarında baglanti yoksa hala. disconnecttir.
					else if(i!=j && edgeList[i][j]==0){

					}
					//
					else{
						// i ile j arasinda baglanti var ama i ile k veya k ile j arasi baglanti yoksa bulasma.
						if(edgeList[i][k]==0 || edgeList[k][j]==0){
						}
						else{
							scores[k] += double (edgeList[i][k] + edgeList[k][j]) / edgeList[i][j]; 
						}
					}
				}
			}
		}
	}

   	return countDisconnect(edgeList, n);  
}
