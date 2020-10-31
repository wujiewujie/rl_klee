//
// Created by wj on 9/19/20.
//
#include <iostream>
#include "Qlearning.h"
#include <algorithm>
#include <llvm/Support/raw_ostream.h>

void Qlearning::init(){
    conflict = false;
    action_str = "";
    next_str = "0";
    state = "0";
    alpha = 0.1;
    e_greedy = 0.65;
    state_list.push_back("0");
}
double Qlearning::get_rand(int digit) {
    srand(time(NULL));
    return rand()% digit / (float)digit;
}
void Qlearning::check_state_exist(std::string state){
    if(!count(state_list.begin(),state_list.end(),state)){
//        llvm::errs() << "state:" <<state << "\n";
        std::pair<double,double> reward(0,0);
        q_table.insert(make_pair(state,reward));
        state_list.push_back(state);
//        llvm::errs() << "\n";
    }
}
int Qlearning::choose_action(){
    check_state_exist(state);
    //0~1 random number
    if (get_rand(100) < e_greedy){
        return q_table[state].first > q_table[state].second ? 1 : 2;
    }else{
        if (get_rand(10) < 0.5){
            return 1;
        } else{
            return 2;
        }
    }

}
void Qlearning::env_update(){

    if (action == 1){
        action_str += '1';
        next_str += '1';
    }else{
        action_str += '2';
        next_str += '2';
    }

}
void Qlearning::learn(double reward){

    double q_predict = action == 1 ? q_table[state].first : q_table[state].second;

    double next = q_table[next_str].first > q_table[next_str].second ? q_table[next_str].first : q_table[next_str].second;
    double q_target = reward + next;

    if (action == 1){
        q_table[state].first += alpha * (q_target - q_predict);
    }else{
        q_table[state].second += alpha * (q_target - q_predict);
    }
    state = next_str;
}
bool Qlearning::check_if_valid(){

    std::string str = "0" + action_str;
    if(count(state_list.begin(),state_list.end(),str)){
        return true;
    } else{
        std::string state_candidate = str.substr(1,state.length());
        if (count(candidate_list.begin(),candidate_list.end(),state_candidate)){
            for(std::vector<std::string>::iterator iter = candidate_list.begin();iter!=candidate_list.end();iter++){
                if(*iter == state_candidate){
                    candidate_list.erase(iter);
                    break;
                }
            }
            return false;
        } else{
            conflict = true;
            return false;
        }
    }
}
std::string Qlearning::choose_candidate(){

    random_shuffle(candidate_list.begin(),candidate_list.end());
    std::string res = candidate_list.back();
    candidate_list.pop_back();
    return res;
}
std::string Qlearning::action_after_fail(){

    re_init();
    action = choose_action();
    env_update();
    conflict = false;
    while (check_if_valid()){
        action = choose_action();
        env_update();
    }
    if(conflict == true){
        action_str = choose_candidate();
        next_str = "0" + action_str;
    }
    state = "0" + action_str.substr(0,action_str.length() - 1);
//    llvm::errs()<<"action_str:"<<action_str<<"\n";
    return action_str;
}

void Qlearning::re_init(){
    action_str = "";
    next_str = "0";
    state = "0";
}

bool Qlearning::if_in_qtable() {
    std::string str = "0" + action_str;
    if(count(state_list.begin(),state_list.end(),str)){
        return true;
    }else{
        return false;
    }
}