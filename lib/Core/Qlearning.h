//
// Created by wj on 9/19/20.
//

#include <string>
#include <vector>
#include <map>

#ifndef KLEE_QLEARNING_H
#define KLEE_QLEARNING_H



class Qlearning{
public:
    std::map<std::string,std::pair<double,double>>  q_table;
    bool  conflict;
    std::string  action_str;
    std::string  next_str;
    std::string  state;
    int action;
    std::vector<std::string>  state_list;
//map<string,double> candidate_list;
    std::vector<std::string>  candidate_list;

    double  alpha;
    double  e_greedy;

    void init();
    double get_rand(int digit);
    void check_state_exist(std::string state);
    int choose_action();
    void env_update();
    void learn(double reward);
    void re_init();
    bool check_if_valid();
    std::string choose_candidate();
    std::string action_after_fail();
    bool if_in_qtable();

};


#endif //KLEE_QLEARNING_H