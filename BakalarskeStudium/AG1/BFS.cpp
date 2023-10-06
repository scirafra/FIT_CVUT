#include<iostream>
#include<string>
#include<vector>
using namespace std;
//10*1+10,90*2+90,
struct lines
{
	vector<int> planet;
	int ways=0;
};
struct planet
{
	int washere=0;
	
	bool inf = false;
	//bool drug = false;
	vector<int> way;
	int ways=0;
};

struct cureplanet
{
	int washere=0;
	int id=0;
	vector<vector<int>> line;
	vector<int> way;
	int ways=0;
	vector<int> lw;
	int rways=0;
	vector<int> revs;
};

int cureroute (int minf, vector<int> &str, vector<cureplanet> &p)
{
	for (int i=0;i<minf;i++)
	{p[i].washere=0;}
	str.push_back(1);
	p[1].washere=1;
	while (str.begin()!=str.end())
	{
		
	//cout<<endl;
		for (int i=0; i<p[str[0]].ways;i++)
		{
			//cout<<"aa "<<p[str[0]].way[i]<<" "<<p[p[str[0]].way[i]].washere<<endl;
			if (p[p[str[0]].way[i]].washere == 0)
			{
				//cout<<p[str[0]].washere<<endl;
				
				p[p[str[0]].way[i]].washere=(p[str[0]].washere+1);
				str.push_back(p[str[0]].way[i]);
				
			}
			
			//p[from].washere=0;
		}
		str.erase(str.begin());
	}
	//cout<<"haha"<<endl;
	return p[0].washere;
}

int route (int from, int where, int minf, int inf, vector<int> &str, vector<planet> &p)
{
	for (int i=0;i<minf;i++)
	{p[i].washere=0;}
	str.push_back(from);
	p[from].washere=1;
	while (str.begin()!=str.end())
	{
		
	//cout<<endl;
		for (int i=0; i<p[str[0]].ways;i++)
		{
			//cout<<"aa "<<p[str[0]].way[i]<<" "<<p[p[str[0]].way[i]].washere<<endl;
			if (p[p[str[0]].way[i]].washere == 0)
			{
				//cout<<p[str[0]].washere<<endl;
				if (p[str[0]].washere <= inf || p[p[str[0]].way[i]].inf==false)
				{
					p[p[str[0]].way[i]].washere=(p[str[0]].washere+1);
					str.push_back(p[str[0]].way[i]);
				}
			}
			
			//p[from].washere=0;
		}
		str.erase(str.begin());
	}
	//cout<<"haha"<<endl;
	return p[where].washere;
}

int main ()
{
	vector<int>a;
	vector<int>fin;
	vector<cureplanet>cure;
	int planeta, draha, splanet, eplanet, save_travels, iplanet, dplanet, tmp, tmp2;
	cin>>planeta>>draha;
	vector<planet> p;
	p.reserve(planeta);
	cin>>splanet>>eplanet>>save_travels;
	cin>>iplanet;
	for (int i=0; i<iplanet; i++)
	{
		cin>>tmp;
		p[tmp].inf=true;
	}
	cin>>dplanet;
	if (dplanet > 0){
	cure.reserve(dplanet+2);
	cure[0].id=splanet;
	cure[1].id=eplanet;
	for (int i=2; i<dplanet+2; i++)
	{
		cin>>tmp;
		cure[i].id=tmp;
		//cout<<i<<" "<<cure[i].id<<endl;
	}}
	for (int i=0; i<draha; i++)
	{
		cin>>tmp>>tmp2;
		p[tmp].way.push_back(tmp2);
		p[tmp].ways++;
		p[tmp2].way.push_back(tmp);
		p[tmp2].ways++;
	}
	
	//cout<<"here"<<endl;
	if (dplanet > 0)
	{
		//int cur=-1;
		for (int i=0; i<dplanet+2;i++)
		{
			
			route(cure[i].id,splanet,planeta,save_travels,a,p);
			/*for (int j=0; j<planeta;j++)
			{
				cout<<j<<" is "<<p[j].washere<<endl;
			}*/
			for (int j=0; j<dplanet+2;j++)
			{
				if (p[cure[j].id].washere>1)
				{
					vector<int> x;
					//x.push_back(eplanet);
					int aa=cure[j].id;
					for (int h=0;h<(p[cure[j].id].washere-1);h++)
					{
						//cout<<aa<<" "<<p[aa].washere<<endl;
						for (int j=0;j<p[aa].ways;j++)
						{
							if (p[p[aa].way[j]].washere==(p[aa].washere-1))
							{
				
								x.push_back(p[aa].way[j]);
								aa=p[aa].way[j];
								break;
							}
						}
						if (aa==cure[i].id)
						{
							break;
						}
					}
					
					cure[i].ways+=1;
					cure[i].lw.push_back(p[cure[j].id].washere-2);
					//cure[j].way.push_back(cure[i].id);
					cure[i].way.push_back(j);
					cure[i].line.push_back(x);
					cure[j].rways+=1;
					cure[j].revs.push_back(i);
					/*cout<<i<<" and "<<j<<"  "<<cure[i].lw[cure[i].ways-1];
					for (int h=0;h<(p[cure[j].id].washere-1);h++)
					{
						cout<<" "<<x[h];
					}
					cout<<endl;*/
				}
			}
			//cout<<cure[0].ways<<endl;
			//cout<<cure[i].id<<" "<<cure[i].ways<<" "<<endl;
				//cout<<"ano "<<cure[i]<<endl;
				//cur=cure[i];
				
	/*			
				
				
				vector<int> x;
	//x.push_back(eplanet);
	int aa=splanet;
	for (int h=0;h<(p[splanet].washere-1);h++)
	{
		//cout<<p[aa].washere<<endl;
		for (int j=0;j<p[aa].ways;j++)
		{
			if (p[p[aa].way[j]].washere==(p[aa].washere-1))
			{
				
				x.push_back(p[aa].way[j]);
				aa=p[aa].way[j];
				break;
			}
		}
		if (aa==cur)
		{
			break;
		}
	}
	//cout<<endl;
	fin=x;
	int fi=p[splanet].washere-1;
	x.erase(x.begin(),x.end());
	for (int f=0;f<planeta;f++)
		{p[f].inf=false;}
		
		
	if (route(eplanet,cure[i],planeta,save_travels,a,p)!=0)
			{	
		
	aa=cur;
	for (int h=0;h<(p[cur].washere-1);h++)
	{
		//cout<<p[aa].washere<<endl;
		for (int j=0;j<p[aa].ways;j++)
		{
			if (p[p[aa].way[j]].washere==(p[aa].washere-1))
			{
				
				x.push_back(p[aa].way[j]);
				aa=p[aa].way[j];
				break;
			}
		}
		if (aa==eplanet)
		{
			break;
		}
	}
	
	
	
	cout<<splanet;
	for (int h=0;h<(fi);h++)
	{
		cout<<" "<<fin[h];
	}
	//cout<<" xx ";
	for (int h=0;h<(p[cur].washere-1);h++)
	{
		cout<<" "<<x[h];
	}
	cout<<endl;
				
				
				
	return 1;			
				
}	
				
				
		*/		
				
			
		}
	/*for (int i=0;i<dplanet+2;i++)
	{
		cout<<"ID: "<<cure[i].id<<" "<<cure[i].ways<<endl;
		for (int j=0; j<cure[i].ways;j++)
		{
			cout<<cure[i].way[j]<<" "<<cure[i].lw[j]<<" -";
			for (int h=0; h<cure[i].lw[j];h++)
			{
				cout<<" "<<cure[i].line[j][h];
			}
			cout<<endl;
		}
	}*/
	//x.erase(x.begin(),x.end());
	if (cureroute(dplanet+2,a,cure)==0)
	{
		cout<<"-1"<<endl;
		return 0;
	}
	else
	{
		/*for (int h=0;h<(dplanet+2);h++)
		{
			cout<<h<<" "<<cure[h].washere<<endl;
		}*/
		vector<int> x;
		//x.push_back(eplanet);
		//cout<<cure[0].ways<<endl;
		int aa=0;
		for (int h=0;h<(cure[0].washere-1);h++)
		{
			
			//cout<<aa<<" "<<cure[aa].ways<<" "<<cure[aa].washere<<endl;
			for (int j=0;j<cure[aa].rways;j++)
			{
				/*cout<<"here"<<endl;
				cout<<cure[cure[aa].revs[j]].washere<<endl;
				cout<<(cure[aa].washere-1)<<endl;
				cout<<endl;*/
				if (cure[cure[aa].revs[j]].washere==(cure[aa].washere-1))
				{
					//cout<<"here"<<endl;
					x.push_back(cure[aa].revs[j]);
					aa=cure[aa].revs[j];
					break;
				}
				//cout<<"ou"<<endl;
			}
			//cout<<"aj tu"<<endl;
			if (aa==1)
			{
				break;
			}
			
		}
		//cout<<cure[0].id;
		//cout<<x.size()<<endl;
		//cout<<x[0]<<" "<<x[1]<<" "<<" "<<endl;
		x.insert(x.begin(),0);
		for (int h=0;h<(cure[0].washere);h++)
		{
			if (x[h]!=0)
			{
				cout<<" ";
			}
			cout<<cure[x[h]].id;
			//cout<<"here"<<endl;
			if (x[h]!=1)
			{
				for (int f=0;f<cure[x[h+1]].ways;f++)
				{
					if (cure[x[h+1]].way[f]==x[h])
					{
						for (int t=0;t<cure[x[h+1]].lw[f];t++)
						{
							cout<<" "<<cure[x[h+1]].line[f][t];
						}
					}
				}
			}
			//for (int f=0;f<)
		}
		cout<<endl;
		return 0;
	}
	//cout<<"-1"<<endl;
	return 0;
	}
	else
	{
	route(eplanet,splanet,planeta,save_travels,a,p);
	if (p[splanet].washere==0)
		{
			cout<<"-1"<<endl;
			return 0;
		}
	/*for (int i=0; i<planeta; i++)
	{
		
		cout<<i<<" "<<p[i].washere<<" "<<endl;
	
	}*/
	vector<int> x;
	//x.push_back(eplanet);
	int aa=splanet;
	for (int i=0;i<(p[splanet].washere-1);i++)
	{
		//cout<<p[aa].washere<<endl;
		for (int j=0;j<p[aa].ways;j++)
		{
			if (p[p[aa].way[j]].washere==(p[aa].washere-1))
			{
				
				x.push_back(p[aa].way[j]);
				aa=p[aa].way[j];
				break;
			}
		}
		if (aa==eplanet)
		{
			break;
		}
	}
	//cout<<endl;
	cout<<splanet;
	for (int i=0;i<(p[splanet].washere-1);i++)
	{
		cout<<" "<<x[i];
	}
	cout<<endl;
	}
	return 0;
}