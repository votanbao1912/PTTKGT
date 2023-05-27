#include <iostream>
#include <vector>
#include <algorithm>

// C?u trúc bi?u di?n m?t s? ki?n
struct Event {
    std::string name;
    int start_time;
    int end_time;
};

// Hàm so sánh s? ki?n theo th?i gian k?t thúc
bool compareEvents(const Event& event1, const Event& event2) {
    return event1.end_time < event2.end_time;
}

// Hàm x?p l?ch s? ki?n
std::vector<Event> scheduleEvents(std::vector<Event>& events) {
    std::vector<Event> schedule;
    std::sort(events.begin(), events.end(), compareEvents);

    if (events.empty()) {
        return schedule;
    }

    schedule.push_back(events[0]);
    int last_end_time = events[0].end_time;

    for (int i = 1; i < events.size(); i++) {
        if (events[i].start_time >= last_end_time) {
            schedule.push_back(events[i]);
            last_end_time = events[i].end_time;
        }
    }

    return schedule;
}

// Hàm in k?t qu? x?p l?ch
void printSchedule(const std::vector<Event>& schedule) {
    std::cout << "Schedule:\n";
    for (const auto& event : schedule) {
        std::cout << event.name << " (" << event.start_time << " - " << event.end_time << ")\n";
    }
}

int main() {
    std::vector<Event> events = {
        {"Event 1", 1, 3},
        {"Event 2", 2, 5},
        {"Event 3", 4, 7},
        {"Event 4", 6, 9},
        {"Event 5", 8, 10}
    };

    std::vector<Event> schedule = scheduleEvents(events);
    printSchedule(schedule);

    return 0;
}

