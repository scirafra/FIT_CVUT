#ifndef __PROGTEST__

#include "sample.h"

namespace regexp {

    Alternation::Alternation(RegExp left, RegExp right)
            : m_left(std::move(left)), m_right(std::move(right)) {
    }

    Concatenation::Concatenation(RegExp left, RegExp right)
            : m_left(std::move(left)), m_right(std::move(right)) {
    }

    Iteration::Iteration(RegExp node)
            : m_node(std::move(node)) {
    }

    Symbol::Symbol(alphabet::Symbol symb)
            : m_symbol(std::move(symb)) {
    }


#if 1

/** @brief Example usage of std::variant visitor using overloaded struct and lambda functions */
    void to_string(const regexp::RegExp &r, std::ostream &os) {
        std::visit(overloaded{
                           [&os](const std::shared_ptr<regexp::Alternation> &arg) {
                               os << '(';
                               to_string(arg->m_left, os);
                               os << '+';
                               to_string(arg->m_right, os);
                               os << ')';
                           },
                           [&os](const std::shared_ptr<regexp::Concatenation> &arg) {
                               os << '(';
                               to_string(arg->m_left, os);
                               os << ' ';
                               to_string(arg->m_right, os);
                               os << ')';
                           },
                           [&os](const std::shared_ptr<regexp::Iteration> &arg) {
                               os << '(';
                               to_string(arg->m_node, os);
                               os << ")*";
                           },
                           [&os](const std::shared_ptr<regexp::Symbol> &arg) { os << arg->m_symbol; },
                           [&os](const std::shared_ptr<regexp::Epsilon> &arg) { os << "#E"; },
                           [&os](const std::shared_ptr<regexp::Empty> &arg) { os << "#0"; },
                   },
                   r);
    }

#else
    /** @brief Example usage of std::visitor without overloaded struct with lambdas, using std::holds_alternative and std::get instead */
void to_string(const regexp::RegExp& r, std::ostream& os)
{
    if (std::holds_alternative<std::shared_ptr<regexp::Alternation>>(r)) {
        const auto& node = std::get<std::shared_ptr<regexp::Alternation>>(r);
        os << '(';
        to_string(node->m_left, os);
        os << ' ';
        to_string(node->m_right, os);
        os << ')';
    } else if (std::holds_alternative<std::shared_ptr<regexp::Concatenation>>(r)) {
        const auto& node = std::get<std::shared_ptr<regexp::Concatenation>>(r);
        os << '(';
        to_string(node->m_left, os);
        os << ' ';
        to_string(node->m_right, os);
        os << ')';
    } else if (std::holds_alternative<std::shared_ptr<regexp::Iteration>>(r)) {
        const auto& node = std::get<std::shared_ptr<regexp::Iteration>>(r);
        os << '(';
        to_string(node->m_node, os);
        os << ")*";
    } else if (std::holds_alternative<std::shared_ptr<regexp::Symbol>>(r)) {
        os << std::get<std::shared_ptr<regexp::Symbol>>(r)->m_symbol;
    } else if (std::holds_alternative<std::shared_ptr<regexp::Epsilon>>(r)) {
        os << "#E";
    } else if (std::holds_alternative<std::shared_ptr<regexp::Empty>>(r)) {
        os << "#0";
    } else {
        __builtin_unreachable();
    }
}
#endif

/** @brief Convenient function for converting RegExps into the ALT string format (usable in the ALT tool) */
    std::ostream &operator<<(std::ostream &os, const regexp::RegExp &regexp) {
        to_string(regexp, os);
        return os;
    }
}

namespace automaton {
/** @brief Convenient function for converting NFAs into the ALT string format (usable in the ALT tool) */
    std::ostream &operator<<(std::ostream &os, const automaton::NFA &nfa) {
        os << "NFA ";
        for (const auto &symb : nfa.m_Alphabet)
            os << symb << " ";
        os << '\n';

        for (const auto &state : nfa.m_States) {
            os << (nfa.m_InitialState == state ? ">" : " ") << (nfa.m_FinalStates.count(state) ? "<" : " ") << state;

            for (const auto &symbol : nfa.m_Alphabet) {
                if (auto iter = nfa.m_Transitions.find({state, symbol}); iter != nfa.m_Transitions.end()) {
                    os << " ";
                    for (auto i = iter->second.begin(); i != iter->second.end(); ++i) {
                        os << (i != iter->second.begin() ? "|" : "") << *i;
                    }
                } else {
                    os << " -";
                }
            }
            os << std::endl;
        }
        return os;
    }

    bool operator==(const automaton::NFA &a, const automaton::NFA &b) {
        return std::tie(a.m_States, a.m_Alphabet, a.m_Transitions, a.m_InitialState, a.m_FinalStates) ==
               std::tie(b.m_States, b.m_Alphabet, b.m_Transitions, b.m_InitialState, b.m_FinalStates);
    }
}
#endif


automaton::NFA helpa(int &stav, const regexp::RegExp &r ) {
    automaton::NFA fauto;
    stav++;
    std::visit(overloaded{
                       [&stav,&fauto](const std::shared_ptr<regexp::Alternation> &arg) {

                           auto l=helpa(stav, arg->m_left);
                           auto r=helpa(stav, arg->m_right);
                           fauto.m_InitialState=++stav;
                           fauto.m_States.insert(stav);
                           for (auto &a: l.m_Transitions)
                           {
                               for (auto &c: a.second){
                                   fauto.m_Transitions[{a.first.first,a.first.second}].insert({c});}
                               //fauto.m_Transitions.insert(a);
                               if (l.m_InitialState==a.first.first)
                               {
                                   for (auto &c: a.second){
                                       fauto.m_Transitions[{stav,a.first.second}].insert({c});}

                               }

                           }
                           for (auto &a: r.m_Transitions)
                           {
                               for (auto &c: a.second){
                                   fauto.m_Transitions[{a.first.first,a.first.second}].insert({c});}
                               //fauto.m_Transitions.insert(a);
                               if (r.m_InitialState==a.first.first)
                               {
                                   for (auto &c: a.second){
                                       fauto.m_Transitions[{stav,a.first.second}].insert({c});}

                               }

                           }
                           for (auto &a: l.m_States)
                           {
                               fauto.m_States.insert(a);
                           }
                           for (auto &a: r.m_States)
                           {
                               fauto.m_States.insert(a);
                           }

                           for (auto &a: l.m_FinalStates)
                           {
                               fauto.m_FinalStates.insert(a);
                               if (l.m_InitialState==a){
                                   fauto.m_FinalStates.insert(stav);
                               }
                           }
                           for (auto &a: r.m_FinalStates)
                           {
                               fauto.m_FinalStates.insert(a);
                               if (r.m_InitialState==a){
                                   fauto.m_FinalStates.insert(stav);
                               }
                           }
                           for (auto &a: l.m_Alphabet)
                           {
                               fauto.m_Alphabet.insert(a);
                           }
                           for (auto &a: r.m_Alphabet)
                           {
                               fauto.m_Alphabet.insert(a);
                           }


                       },
                       [&stav,&fauto](const std::shared_ptr<regexp::Concatenation> &arg) {
                           auto l=helpa(stav, arg->m_left);
                           auto r=helpa(stav, arg->m_right);
                           fauto.m_InitialState=l.m_InitialState;
                           for (auto &a: l.m_States)
                           {
                               fauto.m_States.insert(a);
                           }
                           for (auto &a: r.m_States)
                           {
                               fauto.m_States.insert(a);
                           }
                           for (auto &a: l.m_Alphabet)
                           {
                               fauto.m_Alphabet.insert(a);
                           }
                           for (auto &a: r.m_Alphabet)
                           {
                               fauto.m_Alphabet.insert(a);
                           }
                           for (auto &a : l.m_Transitions) {
                               for (auto &b : a.second) {
                                   fauto.m_Transitions[{a.first.first, a.first.second}].insert({b});
                               }
                           }
                           for (auto &a : r.m_Transitions) {
                               for (auto &b : a.second) {
                                   fauto.m_Transitions[{a.first.first, a.first.second}].insert({b});
                               }
                               if (a.first.first == r.m_InitialState){
                                   for(auto &b : a.second) {
                                       for (auto &c : l.m_FinalStates){
                                           fauto.m_Transitions[{c, a.first.second}].insert({b});
                                       }
                                   }
                               }
                           }
                           for(auto &a : r.m_FinalStates) {
                               fauto.m_FinalStates.insert(a);
                               if (a == r.m_InitialState ) {
                                    for (auto &b : l.m_FinalStates) {
                                          fauto.m_FinalStates.insert(b);
                                     }
                                }
                           }
                       },
                       [&stav,&fauto](const std::shared_ptr<regexp::Iteration> &arg) {
                           auto l=helpa(stav, arg->m_node);
                           fauto.m_InitialState = l.m_InitialState;
                           fauto.m_States.insert(++stav);
                           fauto.m_FinalStates.insert(fauto.m_InitialState);
                           for (auto &a: l.m_States)
                           {
                               fauto.m_States.insert(a);
                           }
                           for (auto &a: l.m_Alphabet)
                           {
                               fauto.m_Alphabet.insert(a);
                           }
                           for (auto &a: l.m_FinalStates)
                           {
                               fauto.m_FinalStates.insert(a);
                           }
                           for (auto &a : l.m_Transitions) {
                               for (auto &b : a.second) {
                                   fauto.m_Transitions[{a.first.first, a.first.second}].insert({b});
                                   for (auto &c : l.m_FinalStates){
                                       if (c==b){
                                           fauto.m_Transitions[{a.first.first, a.first.second}].insert({stav});
                                       }
                                   }
                               }
                           }
                           for (auto &a : fauto.m_Transitions) {
                               if(a.first.first == fauto.m_InitialState){
                                   for (auto &b : a.second) {
                                       fauto.m_Transitions[{stav, a.first.second}].insert({b});
                                   }
                               }
                           }
                       },
                       [&stav,&fauto](const std::shared_ptr<regexp::Symbol> &arg) {
                           fauto.m_Alphabet = {arg->m_symbol};
                           fauto.m_InitialState=stav;
                           fauto.m_States.insert(stav);
                           fauto.m_States.insert(++stav);
                           fauto.m_FinalStates = {stav};
                           fauto.m_Transitions.insert({{stav-1,arg->m_symbol},{stav}});
                           },
                       [&stav,&fauto](const std::shared_ptr<regexp::Epsilon> &arg) {
                           fauto.m_InitialState = stav;
                           fauto.m_States = {stav};
                           fauto.m_FinalStates = {stav};
                           },
                       [&stav,&fauto](const std::shared_ptr<regexp::Empty> &arg) {
                           fauto.m_InitialState=stav;
                           fauto.m_States = {stav};
                           },
               },
               r);
    return fauto;


}


automaton::NFA convert(const regexp::RegExp &regexp) {
    int x=0;
    return helpa(x,regexp);
}

#ifndef __PROGTEST__
regexp::RegExp tests[] = {
    std::make_shared<regexp::Iteration>(
        std::make_shared<regexp::Concatenation>(
            std::make_shared<regexp::Iteration>(
                std::make_shared<regexp::Alternation>(
                    std::make_shared<regexp::Symbol>('a'),
                    std::make_shared<regexp::Symbol>('b'))),
            std::make_shared<regexp::Concatenation>(
                std::make_shared<regexp::Symbol>('a'),
                std::make_shared<regexp::Concatenation>(
                    std::make_shared<regexp::Symbol>('b'),
                    std::make_shared<regexp::Iteration>(
                        std::make_shared<regexp::Alternation>(
                            std::make_shared<regexp::Symbol>('a'),
                            std::make_shared<regexp::Symbol>('b'))))))),

    std::make_shared<regexp::Iteration>(
        std::make_shared<regexp::Alternation>(
            std::make_shared<regexp::Alternation>(
                std::make_shared<regexp::Symbol>('a'),
                std::make_shared<regexp::Epsilon>()),
            std::make_shared<regexp::Alternation>(
                std::make_shared<regexp::Symbol>('b'),
                std::make_shared<regexp::Empty>()))),

    std::make_shared<regexp::Concatenation>(
        std::make_shared<regexp::Iteration>(
            std::make_shared<regexp::Concatenation>(
                std::make_shared<regexp::Symbol>('a'),
                std::make_shared<regexp::Concatenation>(
                    std::make_shared<regexp::Alternation>(
                        std::make_shared<regexp::Empty>(),
                        std::make_shared<regexp::Epsilon>()),
                    std::make_shared<regexp::Concatenation>(
                        std::make_shared<regexp::Iteration>(
                            std::make_shared<regexp::Symbol>('b')),
                        std::make_shared<regexp::Symbol>('a'))))),
        std::make_shared<regexp::Alternation>(
            std::make_shared<regexp::Concatenation>(
                std::make_shared<regexp::Symbol>('b'),
                std::make_shared<regexp::Iteration>(
                    std::make_shared<regexp::Symbol>('c'))),
            std::make_shared<regexp::Concatenation>(
                std::make_shared<regexp::Iteration>(
                    std::make_shared<regexp::Symbol>('a')),
                std::make_shared<regexp::Alternation>(
                    std::make_shared<regexp::Epsilon>(),
                    std::make_shared<regexp::Concatenation>(
                        std::make_shared<regexp::Symbol>('b'),
                        std::make_shared<regexp::Empty>()))))),
};

// Your solution might give another (equivalent) answers. See task details.
automaton::NFA results[] = {
    {{0, 1, 2, 3, 4, 5, 6},
     {'a', 'b'},
     {
         {{0, 'a'}, {1, 3}},
         {{0, 'b'}, {2}},
         {{1, 'a'}, {1, 3}},
         {{1, 'b'}, {2}},
         {{2, 'a'}, {1, 3}},
         {{2, 'b'}, {2}},
         {{3, 'b'}, {4}},
         {{4, 'a'}, {1, 3, 5}},
         {{4, 'b'}, {2, 6}},
         {{5, 'a'}, {1, 3, 5}},
         {{5, 'b'}, {2, 6}},
         {{6, 'a'}, {1, 3, 5}},
         {{6, 'b'}, {2, 6}},
     },
     0,
     {0, 4, 5, 6}},

    {{0, 1, 2},
     {'a', 'b'},
     {
         {{0, 'a'}, {1}},
         {{0, 'b'}, {2}},
         {{1, 'a'}, {1}},
         {{1, 'b'}, {2}},
         {{2, 'a'}, {1}},
         {{2, 'b'}, {2}},
     },
     0,
     {0, 1, 2}},

    {{0, 1, 2, 3, 4, 5, 6, 7},
     {'a', 'b', 'c'},
     {
         {{0, 'a'}, {1, 6}},
         {{0, 'b'}, {4, 7}},
         {{1, 'a'}, {3}},
         {{1, 'b'}, {2}},
         {{2, 'a'}, {3}},
         {{2, 'b'}, {2}},
         {{3, 'a'}, {1, 6}},
         {{3, 'b'}, {4, 7}},
         {{4, 'c'}, {5}},
         {{5, 'c'}, {5}},
         {{6, 'a'}, {6}},
         {{6, 'b'}, {7}},
     },
     0,
     {0, 3, 4, 5, 6}},
};

int main()
{
    assert(convert(tests[0]) == results[0]);
    assert(convert(tests[1]) == results[1]);
    assert(convert(tests[2]) == results[2]);
}
#endif

