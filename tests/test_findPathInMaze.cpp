#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "src/Algo.h"
#include "src/PathNode.h"
#include <sstream>

using namespace std;

TEST_CASE("test_000")
{
    const int m = 3, n = 3;

    int maze[100][100] = {
        {0, 0, 0}, // row 0
        {1, 0, 0}, // row 1
        {0, 0, 1}, // row 2
    };

    double weightMatrix[100][100];
    buildWeightMatrix(maze, m, n, weightMatrix);

    double weightMatrixResult[9][9] = {
        {0, 1, 0, 0, 1.5, 0, 0, 0, 0},
        {1, 0, 1, 0, 1, 1.5, 0, 0, 0},
        {0, 1, 0, 0, 1.5, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1.5, 1, 1.5, 0, 0, 1, 1.5, 1, 0},
        {0, 1.5, 1, 0, 1, 0, 0, 1.5, 0},
        {0, 0, 0, 0, 1.5, 0, 0, 1, 0},
        {0, 0, 0, 0, 1, 1.5, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int i = 0; i < m * n; ++i)
    {
        for (int j = 0; j < m * n; ++j)
        {
            CHECK(weightMatrix[i][j] == weightMatrixResult[i][j]);
        }
    }
}

TEST_CASE("test_001")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0},
    };

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    // Bạn có thể thay đổi các giá trị tọa độ này tùy theo mục tiêu bài test của mình
    int startX = 0;
    int startY = 0;
    int goalX = 2;
    int goalY = 4;
    int r = 5, c = 5;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n");
    freePath(OutPath);
}

TEST_CASE("test_002")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 0;
    int startY = 0;
    int goalX = 0;
    int goalY = 9;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 10; j < 20; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (0, 0) | f: 9 | g: 0 | h: 9\n"
          "Node: (1, 0) | f: 11 | g: 1 | h: 10\n"
          "Node: (2, 1) | f: 12.5 | g: 2.5 | h: 10\n"
          "Node: (2, 2) | f: 12.5 | g: 3.5 | h: 9\n"
          "Node: (2, 3) | f: 12.5 | g: 4.5 | h: 8\n"
          "Node: (2, 4) | f: 12.5 | g: 5.5 | h: 7\n"
          "Node: (2, 5) | f: 12.5 | g: 6.5 | h: 6\n"
          "Node: (2, 6) | f: 12.5 | g: 7.5 | h: 5\n"
          "Node: (2, 7) | f: 12.5 | g: 8.5 | h: 4\n"
          "Node: (1, 8) | f: 12 | g: 10 | h: 2\n"
          "Node: (0, 9) | f: 11.5 | g: 11.5 | h: 0\n"
          "Part of weight Matrix\n"
          "1 0 0 0 0 0 0 0 0 0 \n"
          "1.5 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 1 1.5 0 0 0 \n"
          "0 0 0 0 0 1.5 1 0 0 0 \n"
          "0 0 0 0 0 0 1.5 0 1.5 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 1.5 1 \n");

    freePath(OutPath);
}

TEST_CASE("test_003")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 4;
    int startY = 5;
    int goalX = 4;
    int goalY = 0;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 10; j < 20; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (4, 5) | f: 5 | g: 0 | h: 5\n"
          "Node: (3, 4) | f: 6.5 | g: 1.5 | h: 5\n"
          "Node: (2, 3) | f: 8 | g: 3 | h: 5\n"
          "Node: (2, 2) | f: 8 | g: 4 | h: 4\n"
          "Node: (2, 1) | f: 8 | g: 5 | h: 3\n"
          "Node: (3, 0) | f: 7.5 | g: 6.5 | h: 1\n"
          "Node: (4, 0) | f: 7.5 | g: 7.5 | h: 0\n"
          "Part of weight Matrix\n"
          "1 0 0 0 0 0 0 0 0 0 \n"
          "1.5 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 1 1.5 0 0 0 \n"
          "0 0 0 0 0 1.5 1 0 0 0 \n"
          "0 0 0 0 0 0 1.5 0 1.5 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 1.5 1 \n");

    freePath(OutPath);
}

TEST_CASE("test_004")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 4;
    int startY = 5;
    int goalX = 0;
    int goalY = 5;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 0; i < 10; i++)
    {
        for (int j = 20; j < 30; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (4, 5) | f: 4 | g: 0 | h: 4\n"
          "Node: (3, 4) | f: 5.5 | g: 1.5 | h: 4\n"
          "Node: (2, 5) | f: 5 | g: 3 | h: 2\n"
          "Node: (1, 5) | f: 5 | g: 4 | h: 1\n"
          "Node: (0, 5) | f: 5 | g: 5 | h: 0\n"
          "Part of weight Matrix\n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n");

    freePath(OutPath);
}

TEST_CASE("test_005")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 4;
    int startY = 8;
    int goalX = 5;
    int goalY = 0;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 10; i < 20; i++)
    {
        for (int j = 20; j < 30; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (4, 8) | f: 9 | g: 0 | h: 9\n"
          "Node: (3, 7) | f: 10.5 | g: 1.5 | h: 9\n"
          "Node: (3, 6) | f: 10.5 | g: 2.5 | h: 8\n"
          "Node: (2, 5) | f: 12 | g: 4 | h: 8\n"
          "Node: (2, 4) | f: 12 | g: 5 | h: 7\n"
          "Node: (2, 3) | f: 12 | g: 6 | h: 6\n"
          "Node: (2, 2) | f: 12 | g: 7 | h: 5\n"
          "Node: (2, 1) | f: 12 | g: 8 | h: 4\n"
          "Node: (3, 0) | f: 11.5 | g: 9.5 | h: 2\n"
          "Node: (4, 0) | f: 11.5 | g: 10.5 | h: 1\n"
          "Node: (5, 0) | f: 11.5 | g: 11.5 | h: 0\n"
          "Part of weight Matrix\n"
          "1 1.5 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 1.5 1 1.5 0 0 0 \n"
          "0 0 0 0 0 1.5 1 1.5 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 1.5 1 1.5 \n"
          "0 0 0 0 0 0 0 0 1.5 1 \n");

    freePath(OutPath);
}

TEST_CASE("test_006")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 4;
    int startY = 8;
    int goalX = 0;
    int goalY = 3;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 20; i < 30; i++)
    {
        for (int j = 20; j < 30; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (4, 8) | f: 9 | g: 0 | h: 9\n"
          "Node: (3, 7) | f: 8.5 | g: 1.5 | h: 7\n"
          "Node: (2, 6) | f: 8 | g: 3 | h: 5\n"
          "Node: (2, 5) | f: 8 | g: 4 | h: 4\n"
          "Node: (2, 4) | f: 8 | g: 5 | h: 3\n"
          "Node: (2, 3) | f: 8 | g: 6 | h: 2\n"
          "Node: (2, 2) | f: 10 | g: 7 | h: 3\n"
          "Node: (2, 1) | f: 12 | g: 8 | h: 4\n"
          "Node: (1, 0) | f: 13.5 | g: 9.5 | h: 4\n"
          "Node: (0, 1) | f: 13 | g: 11 | h: 2\n"
          "Node: (0, 2) | f: 13 | g: 12 | h: 1\n"
          "Node: (0, 3) | f: 13 | g: 13 | h: 0\n"
          "Part of weight Matrix\n"
          "0 1 0 0 0 0 0 0 0 0 \n"
          "1 0 1 0 0 0 0 0 0 0 \n"
          "0 1 0 1 0 0 0 0 0 0 \n"
          "0 0 1 0 1 0 0 0 0 0 \n"
          "0 0 0 1 0 1 0 0 0 0 \n"
          "0 0 0 0 1 0 1 0 0 0 \n"
          "0 0 0 0 0 1 0 1 0 0 \n"
          "0 0 0 0 0 0 1 0 1 0 \n"
          "0 0 0 0 0 0 0 1 0 1 \n"
          "0 0 0 0 0 0 0 0 1 0 \n");

    freePath(OutPath);
}

TEST_CASE("test_007")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 8;
    int startY = 0;
    int goalX = 0;
    int goalY = 9;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 30; i < 40; i++)
    {
        for (int j = 10; j < 20; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (8, 0) | f: 17 | g: 0 | h: 17\n"
          "Node: (7, 1) | f: 16.5 | g: 1.5 | h: 15\n"
          "Node: (6, 2) | f: 16 | g: 3 | h: 13\n"
          "Node: (5, 3) | f: 15.5 | g: 4.5 | h: 11\n"
          "Node: (4, 3) | f: 15.5 | g: 5.5 | h: 10\n"
          "Node: (3, 4) | f: 15 | g: 7 | h: 8\n"
          "Node: (2, 5) | f: 14.5 | g: 8.5 | h: 6\n"
          "Node: (2, 6) | f: 14.5 | g: 9.5 | h: 5\n"
          "Node: (2, 7) | f: 14.5 | g: 10.5 | h: 4\n"
          "Node: (1, 8) | f: 14 | g: 12 | h: 2\n"
          "Node: (0, 9) | f: 13.5 | g: 13.5 | h: 0\n"
          "Part of weight Matrix\n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n");

    freePath(OutPath);
}

TEST_CASE("test_008")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 8;
    int startY = 0;
    int goalX = 0;
    int goalY = 7;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 30; i < 40; i++)
    {
        for (int j = 20; j < 30; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (8, 0) | f: 15 | g: 0 | h: 15\n"
          "Node: (7, 1) | f: 14.5 | g: 1.5 | h: 13\n"
          "Node: (6, 2) | f: 14 | g: 3 | h: 11\n"
          "Node: (5, 3) | f: 13.5 | g: 4.5 | h: 9\n"
          "Node: (4, 3) | f: 13.5 | g: 5.5 | h: 8\n"
          "Node: (3, 4) | f: 13 | g: 7 | h: 6\n"
          "Node: (2, 5) | f: 12.5 | g: 8.5 | h: 4\n"
          "Node: (1, 6) | f: 12 | g: 10 | h: 2\n"
          "Node: (0, 7) | f: 11.5 | g: 11.5 | h: 0\n"
          "Part of weight Matrix\n"
          "1 1.5 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 1.5 1 1.5 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 1.5 1 1.5 0 0 \n"
          "0 0 0 0 0 0 1.5 1 1.5 0 \n"
          "0 0 0 0 0 0 0 1.5 1 1.5 \n"
          "0 0 0 0 0 0 0 0 0 0 \n");

    freePath(OutPath);
}

TEST_CASE("test_009")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 5;
    int startY = 7;
    int goalX = 0;
    int goalY = 3;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 30; i < 40; i++)
    {
        for (int j = 30; j < 40; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (5, 7) | f: 9 | g: 0 | h: 9\n"
          "Node: (4, 8) | f: 10.5 | g: 1.5 | h: 9\n"
          "Node: (3, 7) | f: 10 | g: 3 | h: 7\n"
          "Node: (2, 6) | f: 9.5 | g: 4.5 | h: 5\n"
          "Node: (2, 5) | f: 9.5 | g: 5.5 | h: 4\n"
          "Node: (2, 4) | f: 9.5 | g: 6.5 | h: 3\n"
          "Node: (2, 3) | f: 9.5 | g: 7.5 | h: 2\n"
          "Node: (2, 2) | f: 11.5 | g: 8.5 | h: 3\n"
          "Node: (2, 1) | f: 13.5 | g: 9.5 | h: 4\n"
          "Node: (1, 0) | f: 15 | g: 11 | h: 4\n"
          "Node: (0, 1) | f: 14.5 | g: 12.5 | h: 2\n"
          "Node: (0, 2) | f: 14.5 | g: 13.5 | h: 1\n"
          "Node: (0, 3) | f: 14.5 | g: 14.5 | h: 0\n"
          "Part of weight Matrix\n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 1 0 0 \n"
          "0 0 0 0 0 0 1 0 1 0 \n"
          "0 0 0 0 0 0 0 1 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n");

    freePath(OutPath);
}

TEST_CASE("test_010")
{
    int Maze1[100][100] = {
        {0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
        {0, 1, 1, 1, 1, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 1, 0, 1, 0, 1, 1, 0, 0},
        {0, 1, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    std::ostringstream buffer;
    std::streambuf *oldCout = std::cout.rdbuf(buffer.rdbuf());

    int startX = 7;
    int startY = 2;
    int goalX = 0;
    int goalY = 3;
    int r = 9, c = 10;
    double weightMatrix[100][100];
    PathNode *OutPath;
    OutPath = findPathInMaze2(Maze1, r, c, startX, startY, goalX, goalY, weightMatrix);
    printPath(OutPath);
    cout << "Part of weight Matrix\n";
    for (int i = 70; i < 80; i++)
    {
        for (int j = 80; j < 90; j++)
            cout << weightMatrix[i][j] << " ";
        cout << endl;
    }
    std::cout.rdbuf(oldCout);

    CHECK(buffer.str() ==
          "Solution Path:\n"
          "Node: (7, 2) | f: 8 | g: 0 | h: 8\n"
          "Node: (7, 1) | f: 10 | g: 1 | h: 9\n"
          "Node: (6, 0) | f: 11.5 | g: 2.5 | h: 9\n"
          "Node: (5, 0) | f: 11.5 | g: 3.5 | h: 8\n"
          "Node: (4, 0) | f: 11.5 | g: 4.5 | h: 7\n"
          "Node: (3, 0) | f: 11.5 | g: 5.5 | h: 6\n"
          "Node: (2, 0) | f: 11.5 | g: 6.5 | h: 5\n"
          "Node: (1, 0) | f: 11.5 | g: 7.5 | h: 4\n"
          "Node: (0, 1) | f: 11 | g: 9 | h: 2\n"
          "Node: (0, 2) | f: 11 | g: 10 | h: 1\n"
          "Node: (0, 3) | f: 11 | g: 11 | h: 0\n"
          "Part of weight Matrix\n"
          "1 1.5 0 0 0 0 0 0 0 0 \n"
          "1.5 1 1.5 0 0 0 0 0 0 0 \n"
          "0 1.5 1 1.5 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 0 0 0 0 0 0 \n"
          "0 0 0 0 1.5 1 1.5 0 0 0 \n"
          "0 0 0 0 0 1.5 1 1.5 0 0 \n"
          "0 0 0 0 0 0 1.5 1 1.5 0 \n"
          "0 0 0 0 0 0 0 1.5 1 1.5 \n"
          "0 0 0 0 0 0 0 0 0 0 \n");

    freePath(OutPath);
}
