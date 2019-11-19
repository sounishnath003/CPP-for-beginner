#include<iostream>
#include<bits/stdc++.h>

#define max_d 3

using namespace std ;

struct JobSequencingProblem
{
    char id;
    double profit;
    int deadline;
};

vector<JobSequencingProblem> jobbs;

int scheduledJobs(vector<JobSequencingProblem> &jobbs) {
    int maxProfit = 0;

    vector<int> slot(max_d, -1);
    
    cout << "Scheduled Jobs are: "<< endl;
    for (auto &&job : jobbs) {
        for (size_t i = 0; i <= job.deadline; i++)
        {
            if(i <= max_d && slot[i] == -1){
                slot[i] = job.id;
                maxProfit = maxProfit+job.profit;
                break;
            }
        }
        
        for (size_t i = 0; i < max_d; i++)
        {
            if (slot[i] != -1){
                cout << slot[i] << "    ";
            }
        }
    }
    cout << endl;
    return maxProfit;
}


int main(int argc, char const *argv[])
{
    jobbs = {
        {'1', 5, 2},
        {'2', 10, 1},
        {'3', 15, 2},
        {'4', 9, 1},
    };

    sort(jobbs.begin(), jobbs.end(), [](JobSequencingProblem &first, JobSequencingProblem &second) {
        return (first.profit > second.profit);
    });
    cout << scheduledJobs(jobbs) << endl;
    
    return 0;
}
