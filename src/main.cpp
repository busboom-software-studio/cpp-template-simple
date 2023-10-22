// CSCI 1300 Fall 2023
// Author: Max Busboom
// TA: Aditya
// Question 5b
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
void calculateDistanceMatrix(double distance[][3], double clue[][2], double region[][2], 
                            int CLUE_ROWS, int CLUE_COLS, int REG_ROWS, int REG_COLS){
    for(int i = 0; i<CLUE_ROWS;i++){
        for(int j=0;j<REG_ROWS;j++){
            double rx = region[j][0];
            double ry = region[j][1];
            double cx = clue[i][0];
            double cy = clue[i][1];
            distance[i][j]=sqrt(pow((rx-cx),2)+pow((ry-cy),2));
        }
    }
}
void findClueRegion(double distance[][3], int clue_regions[], int DISTANCE_ROWS, int DISTANCE_COLS){
    for(int i = 0;i<DISTANCE_ROWS;i++){
        int min_col = 0;
        double min_val = distance[i][0];
        for(int j = 0; j<DISTANCE_COLS; j++){
            float d = distance[i][j];
            if(distance[i][j]<min_val){
                min_val = d;
                min_col = j;
            }

        }
        clue_regions[i]=min_col+1;

    }

}
void findTreasure(int clue_regions[], double region[][2], int CLUE_REGIONS_SIZE, int REG_ROWS, int REG_COLS){


    int min_col = 0;
    
    int region_count[REG_ROWS];

    for(int i = 0; i<REG_ROWS;i++){
        region_count[i] = 0;
    }

    for(int i = 0; i<CLUE_REGIONS_SIZE;i++){
        region_count[clue_regions[i]-1]+=1;
    }


    int min_reg_count=region_count[0];
    int min_reg = 0;

    for(int i=0;i<REG_ROWS;i++){
        if(region_count[i]<min_reg_count){
            min_reg_count = region_count[i];
            min_reg = i;
        }
    }

    cout << "Region "<<min_reg+1<<" had the least number of clues : "<<min_reg_count<<endl;
    cout << "Treasure must be buried in the coordinates ( "<<fixed<<setprecision(2)<<region[min_reg][0]<<", "<<region[min_reg][1]<<" )"<<endl;
    
}
int main(){
    const int CLUE_ROWS = 5;
    const int CLUE_COLS = 2;
    const int REG_ROWS = 3;
    const int REG_COLS = 2;
    double clue[CLUE_ROWS][CLUE_COLS] = {{2, 10}, {2, 5}, {8, 4}, {5, 8}, {1, 2}};
    double region[REG_ROWS][REG_COLS] = {{0, 0}, {5, -1}, {-1, -2}};

    double distance[CLUE_ROWS][REG_ROWS];  
    
    calculateDistanceMatrix(distance, clue, region, CLUE_ROWS, CLUE_COLS, REG_ROWS, REG_COLS);
    for(int i = 0; i<CLUE_ROWS;i++){
        for(int j=0;j<REG_ROWS;j++){
            cout <<fixed<<setprecision(3)<< distance[i][j]<<" ";
            
        }
        cout <<endl;
    }

    int clue_regions[CLUE_ROWS];
    findClueRegion(distance, clue_regions, CLUE_ROWS,REG_ROWS);
    for(int i = 0; i<CLUE_ROWS;i++){
        cout << clue_regions[i]<<" ";
   }
   cout << endl;
    
    findTreasure(clue_regions,region,CLUE_ROWS,REG_ROWS,REG_COLS);
}

