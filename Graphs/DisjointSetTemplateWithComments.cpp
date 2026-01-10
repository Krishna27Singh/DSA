#include<iostream>
using namespace std;

class DisjointSet{
    vector<int> rank, parent, size;

public: 
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findUltimateParent(int node){
        if(node == parent[node])
            return node;
        return parent[node] = findUltimateParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int ultimateParentOfU = findUltimateParent(u);
        int ultimateParentOfV = findUltimateParent(v);
        if(ultimateParentOfU == ultimateParentOfV) return; //no need to do anyting
        if(rank[ultimateParentOfU] < rank[ultimateParentOfV]){
            parent[ultimateParentOfU] = ultimateParentOfV;
        }
        else if(rank[ultimateParentOfV] < rank[ultimateParentOfU]){
            parent[ultimateParentOfV] = ultimateParentOfU;
        }
        else{
            parent[ultimateParentOfV] = ultimateParentOfU; // attach anyone to anyone
            rank[ultimateParentOfU]++; 
            // rank only increases of both have the same rank, if ones rank is smaller and others rank is higher than rank does not increase for the higher one 
        }
    }

    void unionBySize(int u, int v){
            int ultimateParentOfU = findUltimateParent(u);
            int ultimateParentOfV = findUltimateParent(v);
            if(ultimateParentOfU == ultimateParentOfV) return; //no need to do anyting
            if(size[ultimateParentOfU] < size[ultimateParentOfV]){
                parent[ultimateParentOfU] = ultimateParentOfV;
                size[ultimateParentOfV] += size[ultimateParentOfU];
            }
            else{ // (size[ultimateParentOfU] >= size[ultimateParentOfV])
                parent[ultimateParentOfV] = ultimateParentOfU;
                size[ultimateParentOfU] += size[ultimateParentOfV];
            }
        }
};

int main(){

    DisjointSet ds1(7);
    ds1.unionByRank(1, 2);
    ds1.unionByRank(2, 3);
    ds1.unionByRank(4, 5);
    ds1.unionByRank(6, 7);
    ds1.unionByRank(5, 6);
    //checking if 3 and 7 belong to the same component or not
    if(ds1.findUltimateParent(3) == ds1.findUltimateParent(7))
        cout<<"SAME"<<endl;
    else    
        cout<<"NOT SAME"<<endl;
    ds1.unionByRank(3, 7);
    if(ds1.findUltimateParent(3) == ds1.findUltimateParent(7))
        cout<<"SAME"<<endl;
    else    
        cout<<"NOT SAME"<<endl;


    

    DisjointSet ds2(7);
    ds2.unionBySize(1, 2);
    ds2.unionBySize(2, 3);
    ds2.unionBySize(4, 5);
    ds2.unionBySize(6, 7);
    ds2.unionBySize(5, 6);
    //checking if 3 and 7 belong to the same component or not
    if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7))
        cout<<"SAME"<<endl;
    else    
        cout<<"NOT SAME"<<endl;
    ds2.unionBySize(3, 7);
    if(ds2.findUltimateParent(3) == ds2.findUltimateParent(7))
        cout<<"SAME"<<endl;
    else    
        cout<<"NOT SAME"<<endl;

    return 0;
}