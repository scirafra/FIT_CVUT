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
			}
		for (auto itt = nfa.m_Alphabet.begin(); itt != nfa.m_Alphabet.end(); ++itt)
		{
			s.erase(s.begin(),s.end());
			for (auto itr = d[current].begin(); itr != d[current].end(); ++itr)
			{
				for (auto& a: nfa.m_Transitions) 
				{
					if (get<0>(a.first) == *itr && get<1>(a.first) ==*itt)
					{
						for (auto iti = a.second.begin(); iti != a.second.end(); ++iti)
						{
							s.insert(*iti);
						}
					}
				}
			}	
			bool t=true;
			for (size_t i=0; i<d.size();i++)
			{
				if (s==d[i])
				{
					x.m_Transitions.insert({std::pair <State, Symbol >(current, *itt) , i});
					t=false;
	}	
			}
			if (t)
			{
				x.m_Transitions.insert({std::pair <State, Symbol >(current, *itt), d.size()});
				fronta.push_back(d.size());
				x.m_States.insert(0);
				d.push_back(s);
			}
		}
		current+=1;
		fronta.erase(fronta.begin());
	}
	/*
	cout<<"States: ";
	for (auto itr = nfa.m_States.begin(); 
		itr != nfa.m_States.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto itr = nfa.m_Alphabet.begin(); 
		itr != nfa.m_Alphabet.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto itr = nfa.m_InitialStates.begin(); 
		itr != nfa.m_InitialStates.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto& a: nfa.m_Transitions) 
				{
					
						cout << get<0>(a.first) <<" "<<  get<1>(a.first)<<" : ";//a.second <<endl;
					for (auto itr = a.second.begin(); 
		itr != a.second.end(); ++itr)
		{
			cout << " "<< *itr;
		}
					cout<<endl;
				}
		cout<<endl;
	for (auto itr = nfa.m_FinalStates.begin(); 
		itr != nfa.m_FinalStates.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
		cout<<endl;
	
	*/
	/*cout<<"States: ";
	for (auto itr = x.m_States.begin(); 
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
	
	for (auto& a: x.m_Transitions) 
				{
					
						cout << get<0>(a.first) <<" "<<  get<1>(a.first)<<" : "<<a.second <<endl;
					
					
				}
		//cout<<endl;
	for (auto itr = x.m_FinalStates.begin(); 
		itr != x.m_FinalStates.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	cout<<x.m_InitialState<<endl;
	cout<<"This was determ..."<<endl;*/
	return x; }

DFA etrim ( const DFA & dfa ) 
{ 
	/*cout<<endl;
	cout<<"Start triming in Old Trim"<<endl;
	cout<<endl;*/
	DFA x;
	if (dfa.m_FinalStates.size()==0)
	{
		x.m_InitialState=0;
		x.m_Alphabet=dfa.m_Alphabet;
		x.m_States.insert(0);
		return x;
	}
	//x=dfa;
	vector<size_t> same;
	vector<State>wrong;
	vector<State>good;
	vector<bool> vali;
	vector<bool> vas;
	vector<size_t> mfr;
	vector<size_t> mwh;
	vector<size_t> vv;
	//size_t s=0;
	for (auto itr = dfa.m_States.begin(); itr != dfa.m_States.end(); ++itr)
	{
		same.push_back(dfa.m_Alphabet.size());
		vas.push_back(false);
	}
	for (auto& a: dfa.m_Transitions) 
	{
		if (get<0>(a.first) == a.second)
		{
			same[a.second]-=1;
		}
		vali.push_back(false);
		mfr.push_back(0);
		mwh.push_back(0);
	}
	
	vector<State> bf;
	bf.push_back(dfa.m_InitialState);
	vas[dfa.m_InitialState]=true;
	while(bf.size()>0)
	{
		size_t i=0;
		for (auto& a: dfa.m_Transitions) 
		{
			if (get<0>(a.first) == bf[0]  )
			{
				if (vas[a.second]==false)
				{
					bf.push_back(a.second);
					vas[a.second]=true;
				}
				vali[i]=true;
				
			}
			i++;
			
		}
		bf.erase(bf.begin());
	}
	
	for (size_t i=0; i<vas.size();i++)
	{
		//cout<<i<<" "<<same[i]<<" "<<vas[i]<<endl;
		if ((same[i]==0 || vas[i]==false) && i!=dfa.m_InitialState)
		{
			wrong.push_back(i);
		}
		else
		{
			good.push_back(i);
		}
	}
	
	while(wrong.size()>0)
	{
		/*cout<<"Wrong: ";
		for (size_t i=0;i<wrong.size();i++)
		{
			cout<<" "<<wrong[i];
		}
		cout<<endl;*/
		size_t t=0;
		for (auto& a: dfa.m_Transitions) 
		{
			if (get<0>(a.first) == wrong[0] || a.second == wrong[0])
			{
				vali[t]=false;
				//cout<<get<0>(a.first)<<" to "<< a.second<<endl;
			}
			else if (get<0>(a.first) > wrong[0])
			{
				mfr[t]+=1;
			}
			if (a.second > wrong[0])
			{
				mwh[t]+=1;
			}
			t++;
		}
		vv.erase(vv.begin(),vv.end());
		bool a=false;
		//cout<<"here 1"<<endl;
		for (size_t g=0;g<good.size();g++)
		{
			a=true;
			vv.push_back(0);
			size_t i=0;
			for (auto& a: dfa.m_Transitions) 
			{
				if (vali[i])
				{
					if (get<0>(a.first)==good[g])
						{
							vv[g]+=1;
							break;
						}
					
				}
				i++;
			}
			//cout<<"vv "<<vv[g]<<endl;
			//same[i]=dfa.m_Alphabet.size();
		}
		
		//cout<<"here 2"<<endl;
		if (a)
		for (size_t i=vv.size();i>0;i--)
		{
			//cout<<"vv pos "<<i-1<<" "<<vv[i-1]<<endl;
			if (vv[i-1]==0)
			{
				bool p=true;
				for (auto itr = dfa.m_FinalStates.begin(); 
					itr != dfa.m_FinalStates.end(); ++itr)
					{
						
						if (*itr == good[i-1])
						{
							p=false;
							break;
						}
					}
				if(p)
				{
					
					//cout<<"Out here a "<<good[i-1]<<endl;
					wrong.push_back(good[i-1]);
					good.erase(good.begin()+i-1);
					
				}
			}
		}
		
		same.erase(same.begin(),same.end());
		for (auto itr = dfa.m_States.begin(); itr != dfa.m_States.end(); ++itr)
		{
			same.push_back(dfa.m_Alphabet.size());
		}
		size_t u=0;
		for (auto& a: dfa.m_Transitions) 
		{
			if (vali[u]==false)
			{
				same[get<0>(a.first)]-=1;
			}
			else if (get<0>(a.first) == a.second )
			{
				same[a.second]-=1;
			}
			u++;
		}
		/*for (size_t i=0;i<same.size();i++) 
		{
			cout<<"Same "<<i<<": "<<same[i]<<endl;
		}*/
		for (size_t i=same.size();i>0;i--)
		{
			//cout<<"S: "<<same[i-1]<<endl;
			if (same[i-1]==0)
			{
				for(size_t g=good.size();g>0;g--)
				{
					if ((i-1)==good[g-1])
					{
						//cout<<"good"<<endl;
						bool p=true;
						
						for (auto itr = dfa.m_FinalStates.begin(); 
							itr != dfa.m_FinalStates.end(); ++itr)
							{
								//cout<<"Fin: "<<*itr<<" "<<i-1<<endl;
								if (*itr == (i-1))
								{
									//cout<<"a"<<endl;
									same[i-1]+=1;
									p=false;
									break;
								}
							}
						if (p)
						{
							//cout<<"Out here 2"<<endl;
							wrong.push_back(i-1);
							
							good.erase(good.begin()+g-1);
							//cout<<"aa"<<endl;
							//break;
						}
					}
				}
			}
		}
		
		//cout<<"ajaj"<<endl;
		wrong.erase(wrong.begin());
	}
	
	//same.erase(same.begin(),same.end());
	//wrong.erase(wrong.begin(),wrong.end());
	size_t s=0;
	/*for (auto itr = x.m_States.begin(); itr != x.m_States.end(); ++itr)
	{
		
		same.push_back(0);
		
	}*/
	x.m_Alphabet=dfa.m_Alphabet;
	x.m_InitialState=dfa.m_InitialState;
	for (size_t i=0;i<same.size();i++) 
	{
		if (same[i] != 0)
		{
			//cout<<vas[i]<<endl;
			if (vas[i]==true)
			{
			x.m_States.insert(s);
			
			for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
			{
				if (*itr == i)
				{
					x.m_FinalStates.insert(s);
					break;
				}
			}
			}
			s++;
		}
		//cout<<same[i]<<endl;
	}
	if (x.m_FinalStates.size()==0 || x.m_States.size() == 0)
	{
		x.m_InitialState=0;
		x.m_Alphabet=dfa.m_Alphabet;
		x.m_States.insert(0);
		return x;
	}
	size_t i=0;
	for (auto& a: dfa.m_Transitions) 
	{
		if (vali[i])
		{
			x.m_Transitions.insert({std::pair <State, Symbol >(get<0>(a.first)-mfr[i], get<1>(a.first)), a.second-mwh[i]});
		}
		//cout<<vali[i]<<" "<<mfr[i]<<" "<<mwh[i]<<endl;
		i++;
	}
	
	//cout<<wrong[0]<<endl;
	//cout<<endl;
	/*cout<<"Ori States: ";
	for (auto itr = x.m_States.begin(); 
		itr != x.m_States.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	cout<<"Alpha: ";
	for (auto itr = x.m_Alphabet.begin(); 
		itr != x.m_Alphabet.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	cout<<"Fin: ";
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
	cout<<"Ini: ";
	cout<<x.m_InitialState<<endl;
	cout<<endl;*/
	return x; 
}
DFA trim ( const DFA & dfa ) 
{ 
	//DFA dfa=etrim(ddd);
	//cout<<"Start triming in gtrim"<<endl;
	DFA x;
	if (dfa.m_FinalStates.size()==0)
	{
		x.m_InitialState=0;
		x.m_Alphabet=dfa.m_Alphabet;
		x.m_States.insert(0);
		return x;
	}
	//x=dfa;
	vector<size_t> same;
	vector<State>wrong;
	vector<State>good;
	vector<bool> vali;
	vector<bool> valif;
	vector<bool> vas;
	vector<bool> vasf;
	vector<size_t> mfr;
	vector<size_t> mwh;
	vector<size_t> vv;
	//size_t s=0;
	//cout<<"States are "<<dfa.m_States.size()<<endl;
	for (auto itr = dfa.m_States.begin(); itr != dfa.m_States.end(); ++itr)
	{
		same.push_back(dfa.m_Alphabet.size());
		vas.push_back(false);
		vasf.push_back(false);
	}
	for (auto& a: dfa.m_Transitions) 
	{
		if (get<0>(a.first) == a.second)
		{
			same[a.second]-=1;
		}
		vali.push_back(false);
		valif.push_back(false);
		mfr.push_back(0);
		mwh.push_back(0);
	}
	
	vector<State> bf;
	bf.push_back(dfa.m_InitialState);
	vas[dfa.m_InitialState]=true;
	while(bf.size()>0)
	{
		size_t i=0;
		for (auto& a: dfa.m_Transitions) 
		{
			if (get<0>(a.first) == bf[0]  )
			{
				if (vas[a.second]==false)
				{
					bf.push_back(a.second);
					vas[a.second]=true;
				}
				vali[i]=true;
				
			}
			i++;
			
		}
		bf.erase(bf.begin());
	}
	
	for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
	{
		bf.push_back(*itr);
		vas[*itr]=true;
	}
	
	while(bf.size()>0)
	{
		size_t i=0;
		for (auto& a: dfa.m_Transitions) 
		{
			if (a.second == bf[0]  )
			{
				if (vasf[get<0>(a.first)]==false)
				{
					bf.push_back(get<0>(a.first));
					vasf[get<0>(a.first)]=true;
				}
				valif[i]=true;
				
			}
			i++;
			
		}
		bf.erase(bf.begin());
	}
	
	
	
	
	for (size_t i=0; i<vas.size();i++)
	{
		//cout<<i<<" "<<same[i]<<" "<<vas[i]<<" "<<vasf[i]<<endl;
		if ((same[i]==0 || vas[i]==false) && i!=dfa.m_InitialState)
		{
			wrong.push_back(i);
		}
		else
		{
			good.push_back(i);
		}
	}
	while(wrong.size()>0)
	{
		size_t t=0;
		for (auto& a: dfa.m_Transitions) 
		{
			if (get<0>(a.first) == wrong[0] || a.second == wrong[0])
			{
				vali[t]=false;
				//cout<<get<0>(a.first)<<" to "<< a.second<<endl;
			}
			else if (get<0>(a.first) > wrong[0])
			{
				mfr[t]+=1;
			}
			if (a.second > wrong[0])
			{
				mwh[t]+=1;
			}
			t++;
		}
		wrong.erase(wrong.begin());
	}
	
	
	
	
	x.m_Alphabet=dfa.m_Alphabet;
	x.m_InitialState=dfa.m_InitialState;
	//cout<<wrong.size()<<endl;
	vector<State> best;
	size_t s=0;
	for (size_t i=0;i<same.size();i++) 
	{
		if (same[i] != 0)
		{
			//cout<<vas[i]<<endl;
			if (vas[i]==true && vasf[i]==true)
			{
			x.m_States.insert(s);
			best.push_back(i);
			//cout<<i<<endl;
			for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
			{
				if (*itr == i)
				{
					
					x.m_FinalStates.insert(s);
					//cout<<"fin "<<x.m_FinalStates.size()<<" "<<i<<endl;
					break;
				}
			}
			s++;
			}
			
			
		}
		//cout<<same[i]<<endl;
	}
	/*if (x.m_FinalStates.size()==0 || x.m_States.size() == 0)
	{
		x.m_InitialState=0;
		x.m_Alphabet=dfa.m_Alphabet;
		x.m_States.insert(0);
		return x;
	}*/
	size_t i=0;
	//for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
	//		{cout<<*itr<<endl;}
	//cout<<"Goo "<<best.size()<<endl;
	bool add=false;
	for (auto& a: dfa.m_Transitions) 
	{
		if (vali[i]==true && valif[i]==true)
		{
			size_t b=best.size();
			size_t f=best.size();
			
			for (size_t g=0;g<best.size();g++)
			{
				if (best[g] == get<0>(a.first))
				{
					b=g;
					//cout<<g<<endl;
				}
				if (best[g] == a.second)
					f=g;
				
				//x.m_Transitions.insert({std::pair <State, Symbol >(get<0>(a.first)-mfr[i], get<1>(a.first)), a.second-mwh[i]});
			}
			if (f == best.size())
			{add=true;}
			x.m_Transitions.insert({std::pair <State, Symbol >(b, get<1>(a.first)), f});
		}
		
		//cout<<vali[i]<<" "<<mfr[i]<<" "<<mwh[i]<<endl;
		i++;
	}
	
	if (add || best.size()==0)
	{
		x.m_States.insert(best.size());
		if(best.size() != 0)
		{
		x.m_FinalStates.insert(best.size());
		}
		if (x.m_FinalStates.size()==0)
		{
			for (auto itr = dfa.m_FinalStates.begin(); 
			itr != dfa.m_FinalStates.end(); ++itr)
			{
				if (*itr==dfa.m_InitialState)
				{
					x.m_FinalStates.insert(0);
					break;
				}
			}
		}
	}
	//cout<<wrong[0]<<endl;
	
	/*cout<<"BFS States: ";
	for (auto itr = x.m_States.begin(); 
		itr != x.m_States.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	cout<<"Alpha: ";
	for (auto itr = x.m_Alphabet.begin(); 
		itr != x.m_Alphabet.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	cout<<"Fin: ";
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
	cout<<"Ini: ";
	cout<<x.m_InitialState<<endl;
	cout<<endl;*/
	return x; 
}
DFA minimize ( const DFA & dfa ) 
{ 
	//cout<<endl;
	//cout<<"Start minimize right now"<<endl;
	//cout<<endl;
	vector<vector<vector<State>>>x;
	vector<State>s;
	vector<vector<State>>m;
	vector<char> alp;
	x.reserve(500);
	
	for (auto itr = dfa.m_Alphabet.begin(); itr != dfa.m_Alphabet.end(); ++itr)
	{
		alp.push_back(*itr);
	}
	for (auto itr = dfa.m_States.begin(); itr != dfa.m_States.end(); ++itr)
	{
		s.push_back(*itr);
	}
	m.push_back(s);
	
	s.erase(s.begin(),s.end());
	/*for (size_t i=0;i<500;i++)
	{
		x[i].reserve(dfa.m_Alphabet.size()+1);
		cout<<"tu"<<endl;
		for (size_t j=0;j<(dfa.m_Alphabet.size()+1);j++)
		{
			x[i][j].reserve(dfa.m_States.size());
			
		}
	}*/
	
	for (size_t j=0;j<(dfa.m_Alphabet.size());j++)
		{
			for (size_t i=0;i<dfa.m_States.size();i++)
			{
				bool fo=true;
				for (auto& a: dfa.m_Transitions) 
				{
					
					if (m[0][i] == get<0>(a.first) && alp[j] == get<1>(a.first))
					{
						//cout<<"add "<<m[0][i]<<" | "<<alp[j] <<"   "<< a.second<<endl;
						s.push_back(a.second);
						fo=false;
						break;
					}
				//i++;
				}
				if(fo)
				{
					s.push_back(dfa.m_States.size());
				}
			//x[0][j][i]=
			}
			m.push_back(s);
			s.erase(s.begin(),s.end());
		}
	x.push_back(m);
	m.erase(m.begin(),m.end());
	size_t p=1;
	//cout<<"tu "<<dfa.m_States.size()<<" "<<m[0].size()<<" "<<x[0][0].size()<<endl;
	//cout<<x.size()<<endl;
	while(true)
	{
		//cout<<"size "<<x[p-1][0].size()<<" "<<x[p-1][1].size()<<" "<<x[p-1][2].size()<<endl;
			
		/*for (size_t i=0;i<x[0][0].size();i++)
		{
			cout << x[p-1][0][i];
			for (size_t a=0;a<alp.size();a++)
			{
				cout <<" "<< x[p-1][a+1][i];
			}
			cout<<endl;
		}*/
		if (p==1)
		{
			size_t st=2, fi=2;
			s.push_back(x[0][0][0]);
			//cout<<endl;
			for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
			{
				//cout<<*itr<<" ";
				if (*itr == x[0][0][0])
				{
					fi=x[0][0][0];
				}
			}
			//cout<<endl;
			//cout<<endl;
			if (fi==2)
			{
				st=x[0][0][0];
			}
			for (size_t i=1;i<x[0][0].size();i++)
			{
				//bool found=true;
				for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
				{
					if (*itr == x[0][0][i])
					{
						if (fi == 2)
						{
							fi=x[0][0][i];
						}
						//found=false;
						s.push_back(fi);
						break;
					}
				}
				if ( s.size() == i)
				{
					if (st == 2)
					{
						st=x[0][0][i];
						
					}
					s.push_back(st);
				}
				
				
				
			}
		}
		else
		{
			//cout<<"Do S pridavam "<<x[0][0][0];
			s.push_back(x[0][0][0]);
			for (size_t i=1;i<x[0][0].size();i++)
			{
				bool fo=true;
				
				if (i==x[p-1][0][i])
				{
					//cout<<i<<" je rovne s "<<x[p-1][0][i]<<endl;
					s.push_back(i);
				}
				else
				{
					for (size_t j=0;j<i;j++)
					{
						bool tr=true;
						if(x[p-1][0][j]==x[p-1][0][i] && j==s[j])
						{
							for (size_t a=0;a<alp.size();a++)
							{
								if (x[p-1][a+1][j] != x[p-1][a+1][i])
								{
									tr=false;
									break;
								}
							}
							if (tr)
							{
								s.push_back(s[j]);
								//cout<<" a"<<x[p-1][0][j];
								//cout<<" c"<<s[j];
							
								fo=false;
								break;
							}
						}
					}
					if (fo)
					{
						s.push_back(x[0][0][i]);
						//cout<<" b"<<x[0][0][i];
					}
				}
				/*else
				{
					cout<<i<<" je rovne s "<<x[p-1][0][i]<<endl;
					s.push_back(i);
				}*/
				
				
			}
			//cout<<endl;
			
		}
		
		
		//cout<<"s "<<s.size()<<endl;
		if (s==x[p-1][0])
		{
			//cout<<p<<endl;
			break;
		}
		m.push_back(s);
		s.erase(s.begin(),s.end());
		for (size_t j=0;j<(dfa.m_Alphabet.size());j++)
		{
			for (size_t i=0;i<dfa.m_States.size();i++)
			{
			//size_t i=0
				bool fo=true;
				for (auto& a: dfa.m_Transitions) 
				{
				
					if (x[0][0][i] == get<0>(a.first) && alp[j] == get<1>(a.first))
					{
						//cout<<"ADD "<<x[0][0][i]<<" "<<x[0][j+1][get<0>(a.first)] <<" "<<get<0>(a.first)<<" "<<alp[j]<<endl;
						//cout<<"Toto "<<m[0][a.second]<<endl;
						s.push_back(m[0][a.second]);
						fo=false;
						break;
					}
				//i++;
				}
				if (fo)
				{
					s.push_back(dfa.m_States.size());
				}
			//x[0][j][i]=
			}
			m.push_back(s);
			s.erase(s.begin(),s.end());
		}
	//	cout<<"s2 "<<s.size()<<endl;
		x.push_back(m);
		m.erase(m.begin(),m.end());
	//	cout<<x.size()<<endl;
		p++;
		
	}
	DFA df;
	df.m_InitialState=0;
	df.m_Alphabet=dfa.m_Alphabet;
	size_t a=0;
	//cout<<endl;
	vector<size_t> min;
	vector<bool> val;
	for (size_t i=0;i<dfa.m_States.size();i++)
	{
		if (x[p-1][0][i]==i)
		{
			min.push_back(a);
			val.push_back(true);
			df.m_States.insert(i-a);
			//cout<<i-a<<endl;
			for (auto itr = dfa.m_FinalStates.begin(); itr != dfa.m_FinalStates.end(); ++itr)
			{
				if (*itr == i)
				{
					//cout<<" fin"<<endl;
					df.m_FinalStates.insert(i-a);
					break;
				}
			}
			//cout<<endl;
			
			
		}
		else
		{
			a++;
			min.push_back(a);
			val.push_back(false);
		}
	}
	for (size_t i=0;i<dfa.m_States.size();i++)
	{
		if (val[i])
		{
		for (size_t j=0;j<(dfa.m_Alphabet.size());j++)
		{
			if (x[p-1][j+1][i] != dfa.m_States.size())
			{
				//cout<<i-min[i]<<" "<<alp[j]<<" "<<(x[p-1][j+1][i]-min[x[p-1][j+1][i]])<<" "<<a<<endl;
				df.m_Transitions.insert({std::pair <State, Symbol >(i-min[i],alp[j]), (x[p-1][j+1][i]-min[x[p-1][j+1][i]])});
			}
		}
		}
	}
	/*cout<<endl;
	cout<<"States: ";
	for (auto itr = df.m_States.begin(); 
		itr != df.m_States.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto itr = df.m_Alphabet.begin(); 
		itr != df.m_Alphabet.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto itr = df.m_FinalStates.begin(); 
		itr != df.m_FinalStates.end(); ++itr)
		{
			cout << " "<< *itr;
		}
		cout<<endl;
	for (auto& a: df.m_Transitions) 
				{
					
						cout << get<0>(a.first) <<" "<<  get<1>(a.first)<<" : "<<a.second <<endl;
					
					
				}
		//cout<<endl;
	cout<<df.m_InitialState<<endl;*/
	return df; 
}


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
	/*assert ( determinize ( in0 ) == outD0 );
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
	*/
MISNFA mz2 = {
	{ 0, 1, 2, 3},
	{ 'a', 'b' },
	{
		{ { 0, 'a' }, {0,1}},
		{ { 0, 'b' }, {0}},
		{ { 1, 'b' }, {2}},
		{ { 2, 'a' }, {2}},
		{ { 2, 'b' }, {2}},
		{ { 3, 'a' }, {2}}
		
	},
	{ 0 },
	{ 3 }
};
	MISNFA mz1 = {
	{ 0, 1, 2, 3, 4, 5},
	{ 'a', 'b' },
	{
		{ { 0, 'a' }, {0}},
		{ { 0, 'b' }, {0}},
		{ { 1, 'b' }, {2}},
		{ { 2, 'a' }, {3}},
		{ { 3, 'a' }, {3}},
		{ { 3, 'b' }, {3}},
		{ { 4, 'a' }, {5}},
		{ { 4, 'b' }, {5}}
		
	},
	{ 0 },
	{ 5 }
};
MISNFA mz3 = {
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28 },
	{ 'a', 'b' },
	{
		{ { 0, 'a' }, {2,4,8,17}},
		{ { 0, 'b' }, {5,6,8}},
		{ { 1, 'a' }, {1,2,6,20}},
		{ { 1, 'b' }, {0,2,27}},
		{ { 2, 'a' }, {6,19,22}},
		{ { 2, 'b' }, {19,17}},
		{ { 3, 'a' }, {1,2,17}},
		{ { 3, 'b' }, {0,17}},
		{ { 4, 'a' }, {2,6,18}},
		{ { 4, 'b' }, {0,19}},
		{ { 5, 'a' }, {3,7,8,19,20}},
		{ { 5, 'b' }, {0,6,118,28}},
		{ { 6, 'a' }, {6,17}},
		{ { 6, 'b' }, {0,1,6,7,8,18}},
		{ { 7, 'a' }, {0,6,22}},
		{ { 7, 'b' }, {0,27}},
		{ { 8, 'a' }, {0,2,4,7,8}},
		{ { 8, 'b' }, {27}},
		{ { 9, 'a' }, {2,3,14,19}},
		{ { 9, 'b' }, {3,8,16,17,24}},
		{ { 10, 'a' }, {3,6,9,14,28}},
		{ { 10, 'b' }, {0,9,11,14,15,17,18}},
		{ { 11, 'a' }, {0,3,15,16,19,28}},
		{ { 11, 'b' }, {4,10,15,16,20}},
		{ { 12, 'a' }, {0,1,17}},
		{ { 12, 'b' }, {2,18,21,23,25}},
		{ { 13, 'a' }, {2,7,8,11,15,19,27}},
		{ { 13, 'b' }, {5,19}},
		{ { 14, 'a' }, {0,10,13,15,17,25}},
		{ { 14, 'b' }, {1,9}},
		{ { 15, 'a' }, {0,3,6,16}},
		{ { 15, 'b' }, {8,14,15}},
		{ { 16, 'a' }, {1,4,6,13}},
		{ { 16, 'b' }, {0,1,6,8,14,17}},
		{ { 17, 'b' }, {17,19}},
		{ { 19, 'a' }, {17,18}},
		{ { 20, 'a' }, {3,8,19,20,27}},
		{ { 20, 'b' }, {0,4,6,18}},
		{ { 21, 'a' }, {2,14,19,22}},
		{ { 21, 'b' }, {3,8,11,16,17}},
		{ { 22, 'a' }, {1,2,17}},
		{ { 22, 'b' }, {0,17}},
		{ { 23, 'a' }, {0,4,15,16,19,22}},
		{ { 23, 'b' }, {5,10,15,16,28}},
		{ { 24, 'a' }, {0,3,4,15,16,19}},
		{ { 24, 'b' }, {4,10,15,16,28}},
		{ { 25, 'a' }, {3,4,6,9,14}},
		{ { 25, 'b' }, {0,11,14,15,17,18,21}},
		{ { 26, 'a' }, {0,1,17}},
		{ { 26, 'b' }, {2,9,18,21,24,25}},
		{ { 27, 'a' }, {0,6,22}},
		{ { 27, 'b' }, {0,27}},
		{ { 28, 'a' }, {2,6,18}},
		{ { 28, 'b' }, {0,19}},
		
	},
	{ 1,2,3,4,5,6,7,18,19,20,22,27,28},
	{ 16 }
};
DFA vy = {
	{ 0 },
	{ 'a', 'b' },
	{},
	0,
	{ },
};	
	/*assert ( etrim ( determinize ( mz1 ) ) == vy );
	assert ( etrim ( determinize ( mz2 ) ) == vy );
	assert ( trim ( determinize ( mz2 ) ) == vy );
	assert ( trim ( determinize ( mz2 ) ) == vy );
	assert ( trim ( determinize ( mz3 ) ) == etrim ( determinize ( mz3 ) ) );*/
	MISNFA inX = {
	{ 0, 1, 2 },
	{ 'a', 'b' },
	{ 
		{ { 0, 'a' }, { 2 } },
	},
	{ 0, 1 },
	{ 1, 2 },
};
	DFA outMX = {
	{ 1, 2 },
	{ 'a', 'b' },
	{
		{ { 1, 'a' }, 2},
	},
	1,
	{ 1, 2 },
};
//assert ( trim ( determinize ( inX ) ) == etrim ( determinize ( inX ) ) );

MISNFA iX = {
	{ 0, 1 },
	{ 'a' },
	{ 
		{ { 1, 'a' }, { 1 } },
	},
	{ 0 },
	{ 1, 0 }
};
assert ( trim ( determinize ( iX ) ) == etrim ( determinize ( iX ) ) );


	return 0;
}
#endif
