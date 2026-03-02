#include "Algo.h"

void buildWeightMatrix(int maze[100][100], int m, int n, double weightMatrix[100][100])
{
   int s = m * n; // số phần tư của mảng

   for(int i = 0; i < s;i++){// nếu là s đúng còn nếu là n sai, tại sao
    for(int j = 0; j < s; j++){
        weightMatrix[i][j] = 0;// đánh dấu chưa thăm đỉnh và chưa gán trọng số 
    }
   }

    const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    const double cost[8] = {1, 1, 1, 1, 1.5, 1.5, 1.5, 1.5};
    const std::string dirName[8] = {"Up", "Down", "Left", "Right", "Up-Left", "Up-Right", "Down-Left", "Down-Right"};

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maze[i][j] == 1) continue;

            int from = i * n + j;
            for(int k = 0; k < 8; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];

                if(nr < m && nr >= 0 && nc < n && nc >= 0){
                    int to = nr * n + nc;
                    if(weightMatrix[from][to] == 0 && maze[nr][nc] != 1){
                        if(k > 3) weightMatrix[from][to] = 1.5;
                        else weightMatrix[from][to] = 1;
                    }
                }
            }
        }
    }
}



double manhattan(int x1, int y1, int x2, int y2)
{
    return std::abs(x1 - x2) + std::abs(y1 - y2);
}

PathNode *findPathInMaze2(int maze[100][100], int m, int n, int startX,
                          int startY, int goalX, int goalY, double weightMatrix[100][100])
{
    int coord[100][2];
    int s = m * n; // số phần tư của mảng

   for(int i = 0; i < s;i++){// nếu là s đúng còn nếu là n sai, tại sao
    for(int j = 0; j < s; j++){
        weightMatrix[i][j] = 0;// đánh dấu chưa thăm đỉnh và chưa gán trọng số 
    }
   }

    const int dx[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    const int dy[8] = {0, 0, -1, 1, -1, 1, -1, 1};
    const double cost[8] = {1, 1, 1, 1, 1.5, 1.5, 1.5, 1.5};

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(maze[i][j] == 1) continue;

            int from = i * n + j;
            for(int k = 0; k < 8; k++){
                int nr = i + dx[k];
                int nc = j + dy[k];

                if(nr < m && nr >= 0 && nc < n && nc >= 0){
                    int to = nr * n + nc;
                    if(weightMatrix[from][to] == 0 && maze[nr][nc] != 1){
                        if(k > 3) weightMatrix[from][to] = 1.5;
                        else weightMatrix[from][to] = 1;
                        coord[to][0] = nr; 
                        coord[to][1] = nc;
                    }
                }
            }
        }
    }
    

    int start = startX * n + startY;
    int goal = goalX * n + goalY;
    bool visited[100] = {false};
    double dist[100];// resemble f(x) = g(x) + h(x) in A*......
    int parent[100];
    double heuristic[100];// h(x)
    double gx[100];// g(x)

    // xây ma trận hướng
    for (int i = 0; i < s; i++){// n là số lượng phần tử của mảng
        dist[i] = INFINITY;
        heuristic[i] = -1;
        gx[i] = INFINITY;
        parent[i] = -1;// need for backtracking
    }

    gx[start] = 0;
    heuristic[start] = manhattan(startX, startY, goalX, goalY);
    dist[start] = gx[start] + heuristic[start];

// a*
    while(true){
        double minF = INFINITY;
        double maxG = -1.0; 
        int u = -1;

        // a. Tìm node u tối ưu trong tập mở
        // Ưu tiên: Min F -> Max G -> Min Index
        for (int i = 0; i < s; ++i)
        {
            if (!visited[i] && dist[i] != INFINITY)
            {
                // Trường hợp 1: Tìm thấy F nhỏ hơn hẳn
                if (dist[i] < minF)
                {
                    minF = dist[i];
                    maxG = gx[i];
                    u = i;
                }
                // Trường hợp 2: F bằng nhau
                else if (dist[i] == minF)
                {
                    // Ưu tiên node có G lớn hơn (đi sâu hơn vào nhánh đã chọn)
                    if (gx[i] > maxG)
                    {
                        maxG = gx[i];
                        u = i;
                    }
                }
            }
        }

        if (u == -1 || minF == INFINITY)  return nullptr;
        if (u == goal) break;

        visited[u] = true;

        if(visited[goal] == true) break;// break khi đi đến đích


        for(int vertex = 0; vertex < s; vertex++){// relax các ddinnhr theo khoảng cách mới nhất
            if(visited[vertex] == false && weightMatrix[u][vertex] > 0){
                double h = manhattan(coord[vertex][0], coord[vertex][1], goalX, goalY);
                double new_g = gx[u] + weightMatrix[u][vertex];

                if(new_g < gx[vertex] && h > -1){ 
                    gx[vertex] = new_g;
                    heuristic[vertex] = h;
                    
                    double f = gx[vertex] + h;
                        
                    dist[vertex] = f;
                    parent[vertex] = u;
                }
            }
        }

    }
    //BACK TRACKING
    PathNode* head = nullptr;
        for (int v = goal; v != -1; v = parent[v]) {
            PathNode* node = new PathNode();
            node->name = "(" + to_string(coord[v][0]) + ", " + to_string(coord[v][1]) + ")";
            node->g = gx[v];
            node->h = heuristic[v];
            node->f = node->g + node->h;
            node->next = head;
            head = node;
        }

    return head;
}