#ifndef ALGO_H
#define ALGO_H

#include "PathNode.h"
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

PathNode *findPathInMaze2(int maze[100][100], int m, int n,
                          int startX, int startY, int goalX, int goalY, double weightMatrix[100][100]);
void buildWeightMatrix(int maze[100][100], int m, int n, double weightMatrix[100][100]);
#endif
