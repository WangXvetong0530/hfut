#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <vector>

using namespace std;

class DisjSet{

private:
    vector<int> parent;
    vector<int> rank;
    int size;

public:
    DisjSet(int max_size) : parent(vector<int>(max_size)),rank(vector<int>(max_size)),size(max_size){
        for(int i = 0; i < max_size; i++){
            parent[i] = i;
        }
    }
    int find(int x){
        return x == parent[x] ? x : (parent[x] = find(parent[x]));
    }


    void to_union(int x1,int x2){
        int f1 = find(x1);
        int f2 = find(x2);
        if(rank[f1] > rank[f2])
            parent[f2] = f1;
        else{
            parent[f1] = f2;
            if(rank[f1] == rank[f2])
                rank[f2]++;
        }
    }

    bool is_same(int x1,int x2){
        return find(x1) == find(x2);
    }


};

int main(void){


    system("pause");
    return 0;
}