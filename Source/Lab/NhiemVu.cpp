#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent a task
struct Task {
    string start_time;  // starting time of the task
    int duration;       // duration of the task in seconds
};

int main() {
    // Read the sequence of continuous days
    string line;
    vector<string> days;
    while (getline(cin, line)) {
        if (line == "*") {
            break;
        }
        days.push_back(line);
    }

    // Read the tasks
    vector<Task> tasks;
    while (getline(cin, line)) {
        if (line == "***") {
            break;
        }
        Task task;
        cin >> task.start_time >> task.duration;
        tasks.push_back(task);
    }

    // Sort the tasks in increasing order of start time
    sort(tasks.begin(), tasks.end(), [](const Task& a, const Task& b) {
        return a.start_time < b.start_time;
    });

    // Iterate through the tasks and compute the finishing time of each task
    string current_time = days[0] + " 00:00:00";
    for (const Task& task : tasks) {
        // Convert the start time of the task to seconds
        int start_seconds = stoi(task.start_time.substr(11, 2)) * 3600
                          + stoi(task.start_time.substr(14, 2)) * 60
                          + stoi(task.start_time.substr(17, 2));

        // Compute the finishing time of the task
        int finish_seconds = start_seconds + task.duration;
        int finish_hour = finish_seconds / 3600;
        finish_seconds %= 3600;
        int finish_minute = finish_seconds / 60;
        finish_seconds %= 60;
        string finish_time = task.start_time.substr(0, 11)
                           + (finish_hour < 10 ? "0" : "") + to_string(finish_hour) + ":"
                           + (finish_minute < 10 ? "0" : "") + to_string(finish_minute) + ":"
                           + (finish_seconds < 10 ? "0" : "") + to_string(finish_seconds);

        // If the finishing time is on a different day, update the current time
        if (finish_time.substr(0, 10) != current_time.substr(0, 10)) {
            current_time = days[find(days.begin(), days.end(), finish_time.substr(0, 10)) - days.begin()] + " 00:00:00";
        }

        // Print the finishing time of the task
        cout << finish_time << endl;
    }

    return 0;
}
