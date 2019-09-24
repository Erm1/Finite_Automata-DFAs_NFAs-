#include "nfa.h"
#include "BitSet.h"
#include <string.h>
#include <stdlib.h>
//#include "Set.h"
/**
 * The data structure used to represent a nondeterministic finite automaton.
 * @see FOCS Section 10.3
 * @see Comments for DFA in dfa.h
 */
struct NFA {
    int states;
    Set **transition;
    int initialState;
    bool *finalStates;
};

/**
 * Allocate and return a new NFA containing the given number of states.
 */
extern NFA new_NFA(int nstates){
    NFA this = (NFA)malloc(sizeof(struct NFA));
    this->transition = (Set **)malloc(nstates * sizeof(Set*));
    for(int i = 0; i < nstates; i++){
        (this->transition)[i] = (Set *)malloc(128*sizeof(Set));
        for(int j = 0; j < 128; j++)
            *(*(this->transition+i)+j) = new_Set();
    }
    this->initialState = 0;
    this->states = nstates;
    this->finalStates = (bool *)malloc(nstates * sizeof(bool));
    for(int i = 0; i < nstates; i++)
        *(this->finalStates + i) = false;
    return this;
}

/**
 * Free the given NFA.
 */
extern void NFA_free(NFA nfa){
    free(nfa);
}

/**
 * Return the number of states in the given NFA.
 */
extern int NFA_get_size(NFA nfa){
    return nfa->states;
}

/**
 * Return the set of next states specified by the given NFA's transition
 * function from the given state on input symbol sym.
 */
extern Set NFA_get_transitions(NFA nfa, int state, char sym){
    return *(nfa->transition[state]+sym);
}

/**
 * For the given NFA, add the state dst to the set of next states from
 * state src on input symbol sym.
 */
extern void NFA_add_transition(NFA nfa, int src, char sym, int dst){
    Set_insert(*(nfa->transition[src]+sym),dst);
}

/**
 * Add a transition for the given NFA for each symbol in the given str.
 */
extern void NFA_add_transition_str(NFA nfa, int src, char *str, int dst);

/**
 * Add a transition for the given NFA for each input symbol.
 */
extern void NFA_add_transition_all(NFA nfa, int src, int dst){
    for(int i = 0 ; i < 128; i++)
        if(Set_isEmpty(*(nfa->transition[src]+i)))
            Set_insert(*(nfa->transition[src]+i),dst);
}

/**
 * Set whether the given NFA's state is accepting or not.
 */
extern void NFA_set_accepting(NFA nfa, int state, bool value){
    *(nfa->finalStates+state) = true;
}

/**
 * Return true if the given NFA's state is an accepting state.
 */
extern bool NFA_get_accepting(NFA nfa, int state){
    return *(nfa ->finalStates+state);
}

/**
 * Run the given NFA on the given input string, and return true if it accepts
 * the input, otherwise false.
 */
extern bool NFA_execute(NFA nfa, char *input){
    int state = nfa->initialState;
    if(strlen(input) == 1){
        Set set = NFA_get_transitions(nfa, state, input[0]);
        if(Set_isEmpty(set))
            return false;
        SetIterator iterator= Set_iterator(set);
        while(SetIterator_hasNext(iterator)){
            int comp = SetIterator_next(iterator);
            if(NFA_get_accepting(nfa, comp))
                return true;
        }
        return false;
    }
    Set set = NFA_get_transitions(nfa, state, input[0]);
    if(Set_isEmpty(set))
        return false;
    SetIterator iterator= Set_iterator(set);
    while(SetIterator_hasNext(iterator)){
        state = SetIterator_next(iterator);
        if(state < 32){
            nfa->initialState = state;
            if(NFA_execute(nfa, input+1)) return true;
        }
    }
    return false;
}
/**
 * Print the given NFA to System.out.
 */
extern void NFA_print(NFA nfa);
