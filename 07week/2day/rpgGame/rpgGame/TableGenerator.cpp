#include "TableGenerator.h"

TableGenerator::TableGenerator() {
  srand(time(NULL));
  for (int i = 0; i < 10; i++) {
    vector<int> victor;
    generatedTable.push_back(victor);
    for (int j = 0; j < 10; j++) {
      generatedTable[i].push_back(0);
    }
  }
  fillRandom();
  writeToFile();
}

int TableGenerator::checkNeighbours(int x, int y) {
  int upperLeft, left, upper;
  if (y == 0) {
    upperLeft = 0;
    upper = generatedTable[x - 1][y];
    left = 0;
  } else {
    upperLeft = generatedTable[x - 1][y - 1];
    upper = generatedTable[x - 1][y];
    left = generatedTable[x][y - 1];
  }

  int neigbourValue = upperLeft*100 + upper*10 + left;
  /*IF 000 then rand
    IF 001 then rand
    IF 010 then 1
    IF 011 then 1
    IF 100 then 0
    IF 101 then rand
    IF 110 then rand
    IF 111 then rand*/
  switch (neigbourValue) {
    case 0 : {
      return rand() % 2;
    }
    case 1: {
      return rand() % 2;
    }
    case 10: {
      return 1;
    }
    case 11: {
      return 1;
    }
    case 100: {
      return 0;
    }
    case 101: {
      return rand() % 2;
    }
    case 110: {
      return rand() % 2;
    }
    case 111: {
      return rand() % 2;
    }
  }
  return -1; //shuld never reach this point
}

void TableGenerator::fillRandom() {
  for (int i = 0; i < 10; i++) {
    if (i == 0) {
      for (int j = 0; j < 10; j++) {
        generatedTable[i][j] = rand() % 2;
      }
    } else if (i == 9) {
      for (int j = 0; j < 10; j++) {
        generatedTable[i][j] = 1;
      }
    } else {
      for (int j = 0; j < 10; j++) {
        generatedTable[i][j] = checkNeighbours(i, j);
      }
    }
  }
}

void TableGenerator::writeToFile() {
  ofstream map;
  map.open("map.txt");
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      string toFile = "";
      if (generatedTable[i][j] == 0) {
        toFile = '0';
      }
      else if (generatedTable[i][j] == 1) {
        toFile = '1';
      }
      else {
        toFile = '2';
      }
      map << toFile;
    } if (i != 9) {
      map << "\n";
    }
  }
}

TableGenerator::~TableGenerator() {
}
