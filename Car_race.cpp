#include <bits/stdc++.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
void sleep(int delay)
{
	time_t now, later;
	now=time(NULL);
	later= now + delay;
	while(now<=later)
	{
		now=time(NULL);
	}
}
char waitForInput(long long int seconds)
{
    char c='#';
    while(seconds!=0)
    {
        if(_kbhit())
        {
            c=_getch();
            fflush(stdin);
            break;
        }
        fflush(stdin);
        --seconds;
    }
    fflush(stdin);
    return c;
}

int Print_kar(int car_num, int speed, int dist_covered, int timer)
{
	cout<<"[CAR "<<car_num<<"]";
	if(timer>0) {
	//cout<<"* "<<speed<<"* ";
	for(int i=0;i<dist_covered;i++)
		cout<<"=";
	}
	cout<<">";
	cout<<endl;
}
int main(int argc, char const *argv[])
{
	if(argc < 3)
	{
		cout<<"\nIncorrect number of arguments passed, please pass 2 arguments\nN(number of cars) & M(distance to be covered)\n";
		return 0;
	}
	int n,m;
 	n=atoi(argv[1]);
 	m=atoi(argv[2]);
 	system("cls");
	vector<int> v(n+1);
	vector<int> d(n+1);
 	for(int i=1;i<=n;i++)
	{
 		v[i]=1;
 		d[i]=0;
 	}
 	char x;
 	int IncCar;
 	int timer=0;
 	int my_flag=0;
 	int winning_car=0;
    while(1)
    {
		x=waitForInput(10);
		if(x!='#')
		{
			IncCar = x-'0';
			if(IncCar>=1 && IncCar<=9)
			{
				fflush(stdin);
				v[IncCar]<<=1;
				//cout<<"\nInc for: "<<IncCar<<" --- "<<v[IncCar]<<endl;
			}
		}
		for(int i=1;i<=n;i++)
    	{
    		Print_kar(i,v[i],d[i],timer);
    		d[i]+=v[i];
    		if(d[i] >= m && !my_flag)
    		{
    			my_flag=1;
    			winning_car=i;
    		}
    		cout<<endl;
    	}
    	timer++;
    	cout<<"\ntime elapsed = "<<(timer-1);
    	if(my_flag)
    		break;
    	sleep(1);
    	system("cls");
	}
	cout<<"\n\n[CAR "<<winning_car<<"] won the race in "<<timer-1<<" seconds";
    return 0;
}

