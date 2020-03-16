#include<bits/stdc++.h>
using namespace std ;

// problem 2
void print_skills(vector<pair<string, vector<string>> > &person_with_skills){
    for (auto &&i : person_with_skills) {
        std::cout << i.first << " have ";
        for (auto &&m : i.second)
        {
            std::cout << m << ",  ";
        }
        std::cout << std::endl;
    }
}

void print_team(set<vector<pair<string, vector<string>>>> member_name){
    for (auto&& i : member_name) {
        for (auto&& mem : i) {
            std::cout << mem.first << " with " ;
            for(auto&& ski : mem.second) {
                std::cout << ski << "  " ;
            }
        }std::cout << std::endl ;
    }
    std::cout << std::endl;
}

void teamMakeUp(vector<string> &req_skils, vector<pair<string, vector<string>>> &person_with_skills) {
    sort(begin(person_with_skills), end(person_with_skills), [&](pair<string, vector<string> > a, pair<string, vector<string> > b) {
        return a.second.size() > b.second.size() ;
    });

    int member_count = 0 ;
    set<string> skill_holded ;
    set<vector<pair<string, vector<string>>>> member_name ;

    for (auto&& person : person_with_skills) {
        for (auto && person_skill : person.second) {
            for (string skill : req_skils) {
                if (person_skill.find(skill) != string::npos) {
                    if (skill_holded.find(skill) != skill_holded.end()){break;}
                    skill_holded.insert(skill);
                    member_name.insert({{person.first, person.second}});
                }
            }
        }
    }
    print_team(member_name) ;
    std::cout << "total team-mates - " << member_name.size() << std::endl ;
}

int main(int argc, char const *argv[]){

    vector<string> req_skils { "Node Js", "Java", "Angular" } ;
    vector<pair<string, vector<string>>> person_with_skills {
        {"Sounish", {"Ruby"} },
        {"Aysuh", {"Node Js", "Java"} },
        {"Sayan", {"Angular"} },
        {"Nirmalya", {"Java", "Node Js"} },
    };

    teamMakeUp(req_skils, person_with_skills) ;

    return 0;
}
