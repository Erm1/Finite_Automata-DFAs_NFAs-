
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "dfa.h"
#include "BitSet.h"
#include "nfa.h"

#define MAX 256

void print_excuted(int i, char *input){
    printf("\nYour input is == %s",input);
    if(i == 1){
        
        printf("\n----TRUE!!----\n");
    } else {
        printf("\n----FALSE!!----\n");
    }
}

int main(void){
    
    
    printf("CSC173 Project 1 part 1 by Ermiyas Liyeh & Benson Gathee\n\nTesting DFAs\n");
    
  
    printf("Test for a string which is exactly 'csc173': ");
    DFA csc173 = new_DFA(7);
    DFA_set_transition(csc173,0,'c',1);
    DFA_set_transition(csc173,1,'s',2);
    DFA_set_transition(csc173,2,'c',3);
    DFA_set_transition(csc173,3,'1',4);
    DFA_set_transition(csc173,4,'7',5);
    DFA_set_transition(csc173,5,'3',6);
    DFA_set_accepting(csc173, 6, true);
    char *input1 = "csc173";
    print_excuted(DFA_execute(csc173, input1),input1);

    printf("Any string that starts with the characters cat ? : ");
    DFA startscat = new_DFA(4);
    DFA_set_transition(startscat, 0, 'c', 1);
    DFA_set_transition(startscat, 1, 'a', 2);
    DFA_set_transition(startscat, 2, 't', 3);
    DFA_set_transition_all(startscat, 3, 3);
    DFA_set_accepting(startscat, 3, true);
    char *input2 = "ccatkjdsn";
    print_excuted(DFA_execute(startscat, input2),input2);

    printf("Binary input with an even number of 0’s ? : ");
    DFA evenZeros = new_DFA(2);
    DFA_set_transition(evenZeros, 0, '1', 0);
    DFA_set_transition(evenZeros, 0, '0', 1);
    DFA_set_transition(evenZeros, 1, '1', 1);
    DFA_set_transition(evenZeros, 1, '0', 0);
    DFA_set_accepting(evenZeros, 0, true);
    char *input3 = "00100101011110";
    print_excuted(DFA_execute(evenZeros, input3),input3);

    printf("Binary input with an even number of both 0’s and 1’s ? : ");
    DFA even0and1 = new_DFA(4);
    DFA_set_transition(even0and1, 0, '0', 1);
    DFA_set_transition(even0and1, 1, '0', 0);
    DFA_set_transition(even0and1, 0, '1', 2);
    DFA_set_transition(even0and1, 2, '1', 0);
    DFA_set_transition(even0and1, 1, '1', 3);
    DFA_set_transition(even0and1, 3, '1', 1);
    DFA_set_transition(even0and1, 2, '0', 3);
    DFA_set_transition(even0and1, 3, '0', 2);
    DFA_set_accepting(even0and1, 0, true);
    char *input4 = "001111";
    print_excuted(DFA_execute(even0and1, input4),input4);

    printf("Binary input with odd number of both 0’s and 1’s ? : ");
    DFA odd0and1 = new_DFA(4);
    DFA_set_transition(odd0and1, 0, '0', 1);
    DFA_set_transition(odd0and1, 1, '0', 0);
    DFA_set_transition(odd0and1, 0, '1', 2);
    DFA_set_transition(odd0and1, 2, '1', 0);
    DFA_set_transition(odd0and1, 1, '1', 3);
    DFA_set_transition(odd0and1, 3, '1', 1);
    DFA_set_transition(odd0and1, 2, '0', 3);
    DFA_set_transition(odd0and1, 3, '0', 2);
    DFA_set_accepting(odd0and1, 3, true);
    char *input5 = "0111";
    print_excuted(DFA_execute(odd0and1, input5),input5);
    
    
    
    
    
    
    printf("\n\nTesting a NFA whose language is \"Strings ending in code\"...\n");
    NFA nfa = new_NFA(5);
    NFA_add_transition(nfa, 0, 'c', 0);
    NFA_add_transition(nfa, 0, 'c', 1);
    NFA_add_transition_all(nfa, 0, 0);
    NFA_add_transition(nfa, 1, 'o', 2);
    NFA_add_transition(nfa, 2, 'd', 3);
    NFA_add_transition(nfa, 3, 'e', 4);
    NFA_set_accepting(nfa, 4, true);
    char input6[] = "codede";
    printf("%d\n",NFA_execute(nfa, input6));
//    NFAUser_Control(nfa);
    
//    printf("\n\nTesting a NFA whose language is \"Strings containing code\"...\n");
//    NFA nfa2 = new_NFA(5);
//    NFA_add_transition(nfa2, 0, 'c', 0);
//    NFA_add_transition(nfa2, 0, 'c', 1);
//    NFA_add_transition_all(nfa2, 0, 0);
//    NFA_add_transition(nfa2, 1, 'o', 2);
//    NFA_add_transition(nfa2, 2, 'd', 3);
//    NFA_add_transition(nfa2, 3, 'e', 4);
//    NFA_add_transition_all(nfa2, 4, 4);
//    NFA_set_accepting(nfa2, 4, true);
//    NFAUser_Control(nfa2);
    
    
    
    
    
    
    
    
    
//    printf("\n\nTesting a NFA with more than one a,g,h,i,o,s,t, or w, or more than two n’s\"...\n");
//        NFA nfa3 = new_NFA(20);
//        NFA_add_transition_all(nfa3, 0, 0);
//        NFA_add_transition(nfa3, 0, 'a', 1);
//        NFA_add_transition_all(nfa3, 1, 1);
//        NFA_add_transition(nfa3, 1, 'a', 2);
//        NFA_add_transition_all(nfa3, 2, 2);
//    
//        NFA_add_transition(nfa3, 0, 'g', 3);
//        NFA_add_transition_all(nfa3, 3, 3);
//        NFA_add_transition(nfa3, 3, 'g', 4);
//        NFA_add_transition_all(nfa3, 4, 4);
//    
//        NFA_add_transition(nfa3, 0, 'h', 5);
//        NFA_add_transition_all(nfa3, 5, 5);
//        NFA_add_transition(nfa3, 5, 'h', 6);
//        NFA_add_transition_all(nfa3, 6, 6);
//    
//        NFA_add_transition(nfa3, 0, 'i', 7);
//        NFA_add_transition_all(nfa3, 7, 7);
//        NFA_add_transition(nfa3, 7, 'i', 8);
//        NFA_add_transition_all(nfa3, 8, 8);
//    
//        NFA_add_transition(nfa3, 0, 'o', 9);
//        NFA_add_transition_all(nfa3, 9, 9);
//        NFA_add_transition(nfa3, 9, 'o', 10);
//        NFA_add_transition_all(nfa3, 10, 10);
//    
//        NFA_add_transition(nfa3, 0, 's', 11);
//        NFA_add_transition_all(nfa3, 11, 11);
//        NFA_add_transition(nfa3, 11, 's', 12);
//        NFA_add_transition_all(nfa3, 12, 12);
//    
//        NFA_add_transition(nfa3, 0, 't', 13);
//        NFA_add_transition_all(nfa3, 13, 13);
//        NFA_add_transition(nfa3, 13, 't', 14);
//        NFA_add_transition_all(nfa3, 14, 14);
//    
//        NFA_add_transition(nfa3, 0, 'w', 15);
//        NFA_add_transition_all(nfa3, 15, 15);
//        NFA_add_transition(nfa3, 15, 'w', 16);
//        NFA_add_transition_all(nfa3, 16, 16);
//    
//        NFA_add_transition(nfa3, 0, 'n', 17);
//        NFA_add_transition_all(nfa3, 17, 17);
//        NFA_add_transition(nfa3, 17, 'n', 18);
//        NFA_add_transition_all(nfa3, 18, 18);
//        NFA_add_transition(nfa3, 18, 'n', 19);
//        NFA_add_transition_all(nfa3, 19, 19);
//    
//        NFA_set_accepting(nfa3, 2, true);
//        NFA_set_accepting(nfa3, 4, true);
//        NFA_set_accepting(nfa3, 6, true);
//        NFA_set_accepting(nfa3, 8, true);
//        NFA_set_accepting(nfa3, 10, true);
//        NFA_set_accepting(nfa3, 12, true);
//        NFA_set_accepting(nfa3, 14, true);
//        NFA_set_accepting(nfa3, 16, true);
//        NFA_set_accepting(nfa3, 19, true);
//    
//        NFAUser_Control(nfa3);
// 
//    
//    
//    
//    NFA nfa4 = new_NFA(8);
//    
//    NFA_add_transition(nfa4, 0, 'b', 1);
//    NFA_add_transition(nfa4, 1, 'e', 2);
//    NFA_add_transition(nfa4, 2, 'n', 3);
//    
//    NFA_add_transition(nfa4, 0, 'e', 4);
//    NFA_add_transition(nfa4, 4, 'r', 5);
//    NFA_add_transition(nfa4, 5, 'm', 6);
//    NFA_add_transition(nfa4, 5, 'i', 6);
//    
//    NFA_add_transition_all(nfa4, 0, 0);
//    NFA_set_accepting(nfa4, 3, true);
//    NFA_set_accepting(nfa4, 7, true);
//    NFAUser_Control(nfa4);
    
    
}



