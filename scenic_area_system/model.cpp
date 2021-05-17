#include "model.h"
#include <QFileDialog>
#include <QDebug>
#include <ctime>

Model::Model()
{
    this->startPoint = 0;
    this->endPoint = 0;
    QString filename = QFileDialog::getOpenFileName();
    QFile file(filename);
    file.open(QIODevice::ReadOnly);
    char temp;
    for(int i = 0; i < 7; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            file.getChar(&temp);
            this->matrix[i][j] = temp - 48;
        }
    }
    file.close();
}

void Model::setStartPoint(int point)
{
    this->startPoint = point;
}

void Model::setEndPoint(int point)
{
    this->endPoint = point;
}

QString Model::calculateShortestPath()//Dijkstra
{
    if(this->endPoint == startPoint)
        return "";
    int total[7] = {0,0,0,0,0,0,0};
    int remain[7] = {999,999,999,999,999,999,999};
    int beyondpoint[7] = {0,0,0,0,0,0,0};

    int currentMinPath;
    int currentTotalPath;
    int currentReleasepoint;

    currentReleasepoint = startPoint;
    beyondpoint[startPoint - 1] = 0;
    while (total[endPoint - 1] == 0)//找要释放的点
    {
        currentMinPath = 0;
        currentTotalPath = 0;
        for(int i = 0; i < 7; i++)
        {
            if(beyondpoint[i] != 0 && total[i] == 0)
            {
                currentTotalPath = total[beyondpoint[i] - 1] + remain[i];
                if(currentTotalPath <= currentMinPath || currentMinPath == 0)
                {
                    currentReleasepoint = i + 1;
                    currentMinPath = currentTotalPath;
                }
            }
        }
        total[currentReleasepoint - 1] = currentMinPath;

        for(int i = 0; i < 7; i++)//更新释放点相邻各点的beyondpoint 和 remaindistance
        {
            if(i != startPoint - 1 && matrix[currentReleasepoint - 1][i] != 0)
            {
                if(beyondpoint[i] == 0 || matrix[currentReleasepoint - 1][i] + total[currentReleasepoint - 1] <= total[beyondpoint[i] - 1] + remain[i])
                {
                    remain[i] = matrix[currentReleasepoint - 1][i];
                    beyondpoint[i] = currentReleasepoint;
                }
            }
        }
    }

    QString path = "";//从终点向beyondpoint找 直到起点
    int currentpoint = endPoint;
    path = QChar::fromLatin1((currentpoint + 48));
    while(currentpoint != startPoint)
    {
        currentpoint = beyondpoint[currentpoint - 1];
        path.insert(0, "-");
        path.insert(0, currentpoint + 48);
        path.insert(0, ",");
        path.insert(0, currentpoint + 48);

    }
    path = path.mid(2);
    return path;
}

QString Model::travel()//DFS
{
    QString path = "";
    int visit[7] = {0,0,0,0,0,0,0};

    int matrix2[7][7];
    for(int i = 0; i < 7; i++)
        for(int j = 0; j < 7; j++)
            matrix2[i][j] = matrix[i][j];

    int currentPoint = startPoint;
    visit[currentPoint - 1] = 1;

    bool find = false;

    for(int k = 0; k < 6; k++)//要找的边数
    {
        find = false;//true:有 false:没有
        for(int i = 0; i < 7; i++)//currentpoint是否有下一个point
        {
            if(visit[i] == 0 && matrix2[currentPoint - 1][i] != 0)
            {
                visit[i] = 1;
                matrix2[currentPoint - 1][i] = 0;
                path = path + (currentPoint + 48) + "-" + (i + 1 + 48) + ",";
                currentPoint = i + 1;
                find = true;
                break;
            }
        }
        if(!find)//没有时，回溯
        {
            for(int i = 0; i < 7; i++)
                matrix2[currentPoint - 1][i] = matrix[currentPoint - 1][i];//还原
            visit[currentPoint - 1] = 0;
            currentPoint = path[path.length() - 4].toLatin1() - 48;
            path = path.mid(0, path.length() - 4);
            k -= 2;
        }
    }
    path = path.mid(0, path.length() - 1);
    return path;
}

QString Model::pathPlan()//Prim
{
    bool visit[7] = {0,0,0,0,0,0,0};
    visit[startPoint - 1] = 1;
    QPoint * edges = new QPoint[6];
    for(int i = 0; i < 7; i++)
    {
        edges[i].setX(0);
        edges[i].setY(0);
    }

    for(int k = 0; k < 6; k++)//要添加的边数
    {
        int minPath = 0;
        for(int i = 0; i < 7; i++)//找所有的联通树的点
        {
            if(visit[i] == 1)
            {
                for(int j = 0; j < 7; j++)//点的邻边的最小边
                {
                    if(visit[j] == 0 && matrix[i][j] != 0)
                    {
                        if(matrix[i][j] <= minPath || minPath == 0)
                        {
                            minPath = matrix[i][j];
                            edges[k].setX(i + 1);
                            edges[k].setY(j + 1);
                        }
                    }
                }
            }
        }
        visit[edges[k].y() - 1] = 1;
    }

    QString result = "";
    for(int i = 0; i < 6; i++)
    {
        result = result + (edges[i].x() + 48) + "-" + (edges[i].y() + 48) + ",";
    }
    result = result.mid(0, result.length() - 1);
    return result;
}
