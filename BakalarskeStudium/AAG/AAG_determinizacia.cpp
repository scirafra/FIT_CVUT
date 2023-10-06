#ifndef __PROGTEST__
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <optional>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

using State = unsigned int;
using Symbol = char;

struct MISNFA {
	std::set < State > m_States;
	std::set < Symbol > m_Alphabet;
	std::map < std::pair < State, Symbol >, std::set < State > > m_Transitions;
	std::set < State > m_InitialStates;
	std::set < State > m_FinalStates;
};

struct DFA {
	std::set < State > m_States;
	std::set < Symbol > m_Alphabet;
	std::map < std::pair < State, Symbol >, State > m_Transitions;
	State m_InitialState;
	std::set < State > m_FinalStates;

	bool operator== ( const DFA & other ) {
	return
		std::tie ( m_States, m_Alphabet, m_Transitions, m_InitialState, m_FinalStates ) ==
		std::tie ( other.m_States, other.m_Alphabet, other.m_Transitions, other.m_InitialState, other.m_FinalStates );
	}
};
#endif


// TODO: Implement these functions

DFA determinize ( const MISNFA & nfa ) { 
	DFA x;
	State current=0;
	vector <bool> f;
	vector <State> fronta;
	vector<std::set < State >> d;
	std::set < State >s;
	d.push_back(nfa.m_InitialStates);
	std::set < State >::iterator it;
	x.m_Alphabet=nfa.m_Alphabet;
	x.m_InitialState=0;
	x.m_States.insert(0);
	fronta.push_back(0);
	//cout<<nfa.m_Transitions[0,'e']<<endl;
	while (fronta.size()!=0)
	{
		x.m_States.insert(current);
		for (auto itr = nfa.m_FinalStates.begin(); 
			itr != nfa.m_FinalStates.end(); ++itr)
			{
				for (auto itt = d[current].begin(); 
				itt != d[current].end(); ++itt)
				{if (*itr ==*itt )
				{
					x.m_FinalStates.insert(current);
					break;
				}}
				
				//cout << "fin "<< *itr;
			}
		//cout<<"here"<<endl;
		for (auto itt = nfa.m_Alphabet.begin(); itt != nfa.m_Alphabet.end(); ++itt)
		{
			s.erase(s.begin(),s.end());
			//if (d[current].size()!=0)
			for (auto itr = d[current].begin(); itr != d[current].end(); ++itr)
			{
				//s.erase(s.begin(),s.end());
				/*for (auto iti = d[0].begin(); 
				iti != d[0].end(); ++iti)
				{
							
				//cout << "fin "<< *itr;     get<0>(p)
				}*/
				
				
				for (auto& a: nfa.m_Transitions) 
				{
					if (get<0>(a.first) == *itr && get<1>(a.first) ==*itt)
					{
						for (auto iti = a.second.begin(); iti != a.second.end(); ++iti)
						{
							s.insert(*iti);
						}
						//cout << get<0>(a.first) <<" "<<*itr<< " : " <<*itt<<" "<<  get<1>(a.first)<< endl;
					}
					
				}
				
				
				//cout << "fin "<< *itr;     get<0>(p)
			}	
			bool t=true;
			for (size_t i=0; i<d.size();i++)
			{
				if (s==d[i])
				{
					x.m_Transitions.insert({std::pair <State, Symbol >(current, *itt) , i});
					t=false;
					/*cout<<"+|";
		for (auto itr = d[i].begin(); 
		itr != d[i].end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<"|+"<<endl;
		cout<<"+|";
		for (auto itr = s.begin(); 
		itr != s.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<"|+"<<endl;
					break;
				}
				else{
					cout<<"|";
		for (auto itr = d[i].begin(); 
		itr != d[i].end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<"|"<<endl;
		cout<<"|";
		for (auto itr = s.begin(); 
		itr != s.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<"|"<<endl;*/
	}	
				
			}
			if (t)
			{
				x.m_Transitions.insert({std::pair <State, Symbol >(current, *itt), d.size()});
					fronta.push_back(d.size());
					x.m_States.insert(0);
					d.push_back(s);
					//break;
			}
				//x.m_FinalStates.insert(current);
				
				//cout << "fin "<< *itt<<endl;
		}
		current+=1;
		fronta.erase(fronta.begin());
		//break;
		//cout << endl;
	}
	/*for (auto itr = x.m_States.begin(); 
		itr != x.m_States.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto itr = x.m_Alphabet.begin(); 
		itr != x.m_Alphabet.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto itr = x.m_FinalStates.begin(); 
		itr != x.m_FinalStates.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto& a: x.m_Transitions) 
				{
					
						cout << get<0>(a.first) <<" "<<  get<1>(a.first)<<" : "<<a.second <<endl;
					
					
				}
		//cout<<endl;
	cout<<x.m_InitialState<<endl;
	for (size_t i=0;i<d.size();i++)
	{
		cout<<"|";
		for (auto itr = d[i].begin(); 
		itr != d[i].end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<"|"<<endl;
	}*/
	return x; }

DFA trim ( const DFA & dfa ) { return dfa; }

DFA minimize ( const DFA & dfa ) { return dfa; }


#ifndef __PROGTEST__

#include "sample.h"

int main ( ) {
	/* IMPORTANT NOTE:
	 *
	 * Do not forget that automata equivalence (i.e., the regular language equivalence) is algorithmically decidable by
	 * checking for the isomorphism of two minimal DFAs.
	 *
	 * Your determinization algorithm *may* give you a result that is different from the test output used in the asserts below.
	 * This *may* not be wrong. If the automaton still accepts the same language, it will be accepted by Progtest. Progtest
	 * will minimize the automaton you returned from determinize() and/or trim() functions and compare it with the reference solution.
	 *
	 * Also note that the naming of the states does not play a role.
	 * The solutions (outD/outT/outM) for the simple "assert" tests are based upon one of our reference solutions.
	 * It is very much possible that your solutions uses a different naming scheme.
	 * Progtest accepts automata that use a different naming scheme.
	 *
	 * If your are unsure about the correct result of any algorithm on any input, you are welcome to use https://alt.fit.cvut.cz/webui/ tool.
	 */

	// determinize
	assert ( determinize ( in0 ) == outD0 );
	assert ( determinize ( in1 ) == outD1 );
	assert ( determinize ( in2 ) == outD2 );
	assert ( determinize ( in3 ) == outD3 );
	assert ( determinize ( in4 ) == outD4 );
	assert ( determinize ( in5 ) == outD5 );
	assert ( determinize ( in6 ) == outD6 );
	assert ( determinize ( in7 ) == outD7 );
	assert ( determinize ( in8 ) == outD8 );
	assert ( determinize ( in9 ) == outD9 );
	assert ( determinize ( in10 ) == outD10 );
	assert ( determinize ( in11 ) == outD11 );
	assert ( determinize ( in12 ) == outD12 );
	assert ( determinize ( in13 ) == outD13 );

	// trim
	assert ( trim ( determinize ( in0 ) ) == outT0 );
	assert ( trim ( determinize ( in1 ) ) == outT1 );
	assert ( trim ( determinize ( in2 ) ) == outT2 );
	assert ( trim ( determinize ( in3 ) ) == outT3 );
	assert ( trim ( determinize ( in4 ) ) == outT4 );
	assert ( trim ( determinize ( in5 ) ) == outT5 );
	assert ( trim ( determinize ( in6 ) ) == outT6 );
	assert ( trim ( determinize ( in7 ) ) == outT7 );
	assert ( trim ( determinize ( in8 ) ) == outT8 );
	assert ( trim ( determinize ( in9 ) ) == outT9 );
	assert ( trim ( determinize ( in10 ) ) == outT10 );
	assert ( trim ( determinize ( in11 ) ) == outT11 );
	assert ( trim ( determinize ( in12 ) ) == outT12 );
	assert ( trim ( determinize ( in13 ) ) == outT13 );


	// minimize
	assert ( minimize ( trim ( determinize ( in0 ) ) ) == outM0 );
	assert ( minimize ( trim ( determinize ( in1 ) ) ) == outM1 );
	assert ( minimize ( trim ( determinize ( in2 ) ) ) == outM2 );
	assert ( minimize ( trim ( determinize ( in3 ) ) ) == outM3 );
	assert ( minimize ( trim ( determinize ( in4 ) ) ) == outM4 );
	assert ( minimize ( trim ( determinize ( in5 ) ) ) == outM5 );
	assert ( minimize ( trim ( determinize ( in6 ) ) ) == outM6 );
	assert ( minimize ( trim ( determinize ( in7 ) ) ) == outM7 );
	assert ( minimize ( trim ( determinize ( in8 ) ) ) == outM8 );
	assert ( minimize ( trim ( determinize ( in9 ) ) ) == outM9 );
	assert ( minimize ( trim ( determinize ( in10 ) ) ) == outM10 );
	assert ( minimize ( trim ( determinize ( in11 ) ) ) == outM11 );
	assert ( minimize ( trim ( determinize ( in12 ) ) ) == outM12 );
	assert ( minimize ( trim ( determinize ( in13 ) ) ) == outM13 );

	return 0;
}
#endif
