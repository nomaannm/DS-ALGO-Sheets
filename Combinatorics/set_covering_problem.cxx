#define SET unordered_set<string>
#define GRAPH map<string, unordered_set<string>>
#include <algorithm>
#include<iostream>
#include<set>
#include<map>
#include<ranges>
#include<string>
#include<vector>
#include<unordered_set>
using namespace std;

vector<string> min_radio_stations(SET states, GRAPH states_frequencies_pairs ) {
    vector<string> stations;
    while (!states.empty()) {
        string best_station;
        set<string> states_covered;
        for (auto& [station, coverage] : states_frequencies_pairs) {
            set<string> covered;
            set_intersection(states.begin(), states.end(), coverage.begin(), coverage.end(),
                            std::inserter(covered, covered.begin()));

            if (covered.size() > states_covered.size()) {
                best_station = station;
                states_covered = covered;
            }

        }

        if (!best_station.empty()) {
            for (const auto& state : states_covered) {
                states.erase(state);
            }
            stations.emplace_back(best_station);
        } else {
            break; // Avoid infinite loop if no station can cover remaining states
        }
    }
    return stations;
}


int main(){
    SET states = {"UP", "UK", "MP", "HP", "Tamil Nadu", "Maharashtra"};
    GRAPH graph = {
        {"FOne", {"UP", "UK", "MP"}},
        {"FTwo", {"UP", "HP"}},
        {"F3", {"Tamil Nadu", "Maharashtra"}},
        {"F4", {"Tamil Nadu", "HP"}}
    };

    vector<string> stations = min_radio_stations(states, graph);
    for (auto& freq : stations) {
        cout << freq << endl;
    }



}
