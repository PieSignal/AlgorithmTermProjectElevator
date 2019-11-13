#include <map>
#include <vector>
#include <Elevator.h>

class Controller
{
private:
    int elevatorCount, maxFloor, distributerCount;
    time_t startTime;
    map<int, Elevator *> elevators;
    map<int, vector<int>> jobsPerFloor;
    vector<int> jobsCountPerFloor;
    FILE *inputFile;
    void makeLog();
    void ourWay();
public:
    enum distributers
    {
        OurWay
    };
    Controller(int floors, int elevatorCount, int maxPerson);
    void DistributeJobs(distributers distributerName);
    void AddElevator(int maxPerson);
    void PushData(pair<int, int> *data);
    bool IsJobEmpty();
    bool bAllFinished();
    int InsertJob(int floor, int target);
    int GetmaxFloor();
    int GetElevatorCount();
    int GetJobCount(int floor);
    vector<int> GetJobCount();
    time_t GetStartTime();
    time_t Excutes();
    int SetInputFile(FILE *fptr);
    int SetInputFile(string fileName);
    int GetWorks();
};