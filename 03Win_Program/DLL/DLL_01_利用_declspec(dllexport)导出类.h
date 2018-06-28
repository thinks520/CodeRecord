#ifdef MAZE_API
#else
#define MAZE_API _declspec(dllimport)    // 定义导出标识符
#endif

#include <iostream>
using namespace std;

#define M 10
#define N 10

class MAZE_API Maze                     // 导出类声明
{
public:
	Maze();//构造函数
	~Maze(){}//析构函数
	void PrintMaze();//打印迷宫
	void GetPos();//获取出入口位置
	void SearchMaze();//获取迷宫路径
	bool EvaluateMaze(int i,int j);//判断当前点是否可行
private:
	int maze[M][N];//迷宫
	int start_row;//入口行
	int start_col;//入口列
	int end_row;//出口行
	int end_col;//出口列
	bool succeed;//是否找到出口
};