#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    string name;
    int priority;
    int burstTime;
};

bool sortByPriority(const Process &a, const Process &b) {
    return a.priority < b.priority;
}

int main() {
    int x, y, z; 
    cout << "Enter the number of processes for Queue X: ";
    cin >> x;
    cout << "Enter the number of processes for Queue Y: ";
    cin >> y;
    cout << "Enter the number of processes for Queue Z: ";
    cin >> z;

    int priorityX, priorityY, priorityZ;
    cout << "Enter the priority for Queue X: ";
    cin >> priorityX;
    cout << "Enter the priority for Queue Y: ";
    cin >> priorityY;
    cout << "Enter the priority for Queue Z: ";
    cin >> priorityZ;

    queue<Process> queueX;
    queue<Process> queueY;
    queue<Process> queueZ;

    for (int i = 1; i <= x; i++) {
        Process process;
        process.name = "X" + to_string(i);
        process.priority = priorityX;

        if (priorityX == 1) {
            cout << "Enter burst time for " << process.name << ": ";
            cin >> process.burstTime;
        } else {
            process.burstTime = 0; 
        }

        queueX.push(process);
    }
    for (int i = 1; i <= y; i++) {
        Process process;
        process.name = "Y" + to_string(i);

        if (priorityY == 2) {
            cout << "Enter priority for " << process.name << ": ";
            cin >> process.priority;
        } else {
            process.priority = priorityY;
        }
        queueY.push(process);
    }
    for (int i = 1; i <= z; i++) {
        Process process;
        cout << "Enter the name for process Z" << i << ": ";
        cin >> process.name;
        queueZ.push(process);
    }

    cout << "Processes in Queue X: ";
    queue<Process> tempQueueX = queueX;
    while (!tempQueueX.empty()) {
        cout << tempQueueX.front().name << " ";
        tempQueueX.pop();
    }
    cout << endl;

    cout << "Processes in Queue Y: ";
    queue<Process> tempQueueY = queueY;
    while (!tempQueueY.empty()) {
        cout << tempQueueY.front().name << " ";
        tempQueueY.pop();
    }
    cout << endl;
    cout << "Processes in Queue Z: ";
    queue<Process> tempQueueZ = queueZ;
    while (!tempQueueZ.empty()) {
        cout << tempQueueZ.front().name << " ";
        tempQueueZ.pop();
    }
    cout << endl;
    int quantum = 4;
    if (priorityX == 1) {
        queue<Process> roundRobinQueueX = queueX;
        cout << "Round Robin Output for Queue X: ";

        while (!roundRobinQueueX.empty()) {
            Process currentProcess = roundRobinQueueX.front();
            roundRobinQueueX.pop();

            cout << currentProcess.name << " ";

            if (currentProcess.burstTime > quantum) {
                currentProcess.burstTime -= quantum;
                roundRobinQueueX.push(currentProcess);
            }
        }
        cout << endl;
    }

    if (priorityY == 2) {
        vector<Process> sortedProcessesY;
        while (!queueY.empty()) {
            sortedProcessesY.push_back(queueY.front());
            queueY.pop();
        }
        sort(sortedProcessesY.begin(), sortedProcessesY.end(), sortByPriority);

        cout << "Processes in Queue Y based on priority (Low Number Highest Priority): ";
        for (const Process &process : sortedProcessesY) {
            cout << process.name << " ";
        }
        cout << endl;
    }
    if(priorityZ == 3){
        cout << "Processes in Queue Z: ";
        queue<Process> tempQueueZ = queueZ;
    while (!tempQueueZ.empty()) {
        cout << tempQueueZ.front().name << " ";
        tempQueueZ.pop();
    }
    cout << endl;

    }
    return 0;
}
