//
//  dfa.c
//  Proj1_FiniteAutomata
//
//  Created by Ermiyas Liyeh on 9/19/19.
//  Copyright © 2019 Ermiyas Liyeh. All rights reserved.
//

#include <stdlib.h>
#include "dfa.h"


typedef struct DFA {
    int nstates;
    int **transition;
    int initialState;
    bool *finalStates;
}*DFA;

extern DFA new_DFA(int nstates) {
    DFA newDFA = (DFA)malloc(sizeof(struct DFA));
    newDFA->nstates = nstates;
    newDFA->initialState = 0;
    newDFA->transition = (int**)malloc(sizeof(int*)*nstates);  //points to the transition table
    newDFA->finalStates = (bool*)malloc(sizeof(bool)*nstates);
    
    
    for(int i = 0; i<nstates; i++){
        newDFA->transition[i] = (int*)malloc(sizeof(int)*128);
        for(int j = 0; j<128; j++){
            newDFA->transition[i][j] = -1;
        }
    }
    return newDFA;
}

extern int DFA_get_size(DFA dfa){
    return dfa->nstates;
}

extern int DFA_get_transition(DFA dfa, int src, char sym){
    return dfa->transition[src][sym];
}
extern void DFA_set_transition(DFA dfa, int src, char sym, int dst){
    dfa->transition[src][sym] = dst;
}


extern void DFA_set_transition_all(DFA dfa, int src, int dst){
    for(int i = 0; i<128; i++){
        dfa->transition[src][i] = dst;
    }
}

extern bool DFA_get_accepting(DFA dfa, int state){
    return dfa->finalStates[state];
}
extern void DFA_set_accepting(DFA dfa, int state, bool value){
    dfa->finalStates[state] = value;
}

extern bool DFA_execute(DFA dfa, char *input) {
    
    int currentState=dfa->initialState;
    for(int i = 0; i<input[i] != '\0'; i++){
        currentState = DFA_get_transition(dfa, currentState, input[i]);
        if(currentState == -1){
            return false;
        }
    }
    
    return DFA_get_accepting(dfa, currentState);
}

//extern void DFA_set_transition_str(DFA dfa, int src, char *str, int dst) {
//    for(int i = 0; str[i]!='\0'; i++){
//        dfa->transition[src][str[i]] = dst;
//    }
//}



