#include<iostream>
#include "HUMania.hpp"
#include <vector>
using namespace std;

Unit pigeon = {{7,88,155,103}, {30, 40, 50, 50}};
Unit pigeonMid = {{0,237,153,84}, {30, 40, 50, 50}};
Unit pigeonFin = {{2,361,159,124}, {30, 40, 50, 50}};

Unit butterfly = {{257,24,173,134}, {40,40,50,50}};
Unit butterflyMid = {{257,182,192,214}, {40,40,50,50}};
Unit butterflyFin = {{248,432,248,179}, {40,40,50,50}};

Unit bee = {{527,138,194,115}, {50,40,50,50}};
Unit beeMid = {{527,253,194,115}, {50,40,50,50}};
Unit beeFin = {{540,370,193,115}, {50,40,50,50}};
// First rectangle is srcRect, second is moverRect
// use spritecow.com to find exact values of other asset images



//define presets
vector<Unit> pigeons {pigeon, pigeonMid, pigeonFin}; 
vector<Unit> butterflies {butterfly, butterflyMid, butterflyFin};
vector<Unit> bees {bee, beeMid, beeFin};

int count {0}; //Which frame to draw


vector<Unit> draw{pigeons};

void drawObjects(SDL_Renderer* gRenderer, SDL_Texture* assets){
    //draw object
    Unit * temp; 
    temp = &draw[count];
    SDL_RenderCopy(gRenderer, assets, &(temp->srcRect), &(temp->moverRect));

    temp->moverRect.x+=20; 

    //update position
    count++;
    count = count % 3;
}

void createObject(int x, int y){
  int choice = rand() % 3; //random object created
  switch (choice) { //choose base on randomness
    case 0 :
      draw = pigeons;
      break;
    case 1 : 
      draw = butterflies;
      break;
    case 2 :
      draw = bees;
      break;
  };

  count = 0; //set the first frame

  for (int i = 0; i < 3; ++i) {
  draw[i].moverRect.x = x; //define all of the assets to start at mouse click
  draw[i].moverRect.y = y;
  };


  std::cout<<"Mouse clicked at: "<<x<<" -- "<<y<<std::endl;
}

