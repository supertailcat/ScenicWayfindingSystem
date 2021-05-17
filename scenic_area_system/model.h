#ifndef MODEL_H
#define MODEL_H
#include <QString>

class Model
{
public:
    Model();
    void setStartPoint(int point);
    void setEndPoint(int point);

    QString calculateShortestPath();
    QString travel();
    QString pathPlan();
private:
    int matrix[7][7];
    int startPoint;
    int endPoint;
};

#endif // MODEL_H
