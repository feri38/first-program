#include <iostream>
#include <string>

using namespace std;

int address[50]={-1};

int search_cs(string, string, bool);
int search(string, string, bool);
void address_print(int);
void replace(string, string, int);

int main(void){
	string goal;
	string text;
	string answer;
	bool sep=false;
	int tedad=0;
	cout<<"Welcome to text search\n";
	cout<<"Enter your text : \n";
	getline(cin, text);
	cout <<"what do you want to find ? ";
	cin >> goal;
	cout<<"do you want to search separated word ?(yes/no)\n";
	cin>>answer;
	if(answer=="yes")
		sep=true;
	cout<<"is case_sensitive(cs) important for you ?(yes/no)\n";
	cin>>answer;
	if(answer=="no")
	{
		tedad = search(text, goal, sep);
		cout <<"there is "<<tedad<<" '"<<goal<<"' in your text"<<'\n';
	}
	else
	{
		tedad = search_cs(text, goal, sep);
		cout <<"there is "<<tedad<<" '"<<goal<<"' in your text(cs)"<<'\n';
	}
	cout<<"do you what to see the number of location of your word in text ?(yes/no)\n";
	cin>>answer;
	if(answer=="yes")
		address_print(tedad);
	cout<<"do you what to replace it with new word ?(yes/no)\n";
	cin>>answer;
	if(answer=="no")
	{
		cout<<"bye";
		return 1;
	}
	else
		replace(text, goal, tedad);
	return 1;
}

int search_cs(string text, string goal, bool sep){
	int x=0;
	int s_goal=goal.length();
	int s_text=text.size();
	for(int i=0;i<s_text;i++)
	{
		if(text[i]==goal[0])
		{
			address[x]=i;
			for(int j=0;j<s_goal;j++,i++)
			{
				if(text[i]==goal[j])
					continue;
				i=address[x];
				address[x]=-1;
				break;
			}
			if(address[x]!=-1)
				if(sep)
				{
					if((address[x]==0||text[address[x]-1]==' ')&&(text[address[x]+s_goal]==' '||address[x]+s_goal==s_text))
						x++;
					else
					{
						i=address[x];
						address[x]=-1;
					}
				}
				else
					x++;
		}
	}
	return x;
}

int search(string text, string goal, bool sep){
	int x=0;
	int s_goal=goal.length();
	int s_text=text.size();
	for(int i=0;i<s_text;i++)
	{
		if(toupper(text[i])==toupper(goal[0]))
		{
			address[x]=i;
			for(int j=0;j<s_goal;j++,i++)
			{
				if(toupper(text[i])==toupper(goal[j]))
					continue;
				i=address[x];
				address[x]=-1;
				break;
			}
			if(address[x]!=-1)
				if(sep)
				{
					if((address[x]==0||text[address[x]-1]==' ')&&(text[address[x]+s_goal]==' '||address[x]+s_goal==s_text))
						x++;
					else
					{
						i=address[x];
						address[x]=-1;
					}
				}
				else
					x++;
		}
	}
	return x;
}

void address_print(int tedad){
	
	for(int i=0;i<tedad;i++)
	{
		cout<<"the '"<<i+1<<"th' word is the '"<<address[i]+1<<"th' char in text\n";
	}
}

void replace(string text, string goal, int tedad){
	int s_text=text.size();
	int s_goal=goal.length();
	string n_goal;
	int s_n_goal;
	cout<<"Enter your new word : ";
	cin>>n_goal;
	s_n_goal=n_goal.size();
	int s_n_text=(s_n_goal-s_goal)*tedad+s_text;
	string n_text[s_n_text];
	int x=0;
	int i=0;
	for(int j=0;i<s_n_text;i++,j++)
	{
		if(j==address[x])
		{
			for(int k=0;k<s_n_goal;i++,k++)
			{
				n_text[i]=n_goal[k];
				cout<<n_text[i];
			}
			x++;
			j+=s_goal;
		}
		n_text[i]=text[j];
		cout<<n_text[i];
	}
}
