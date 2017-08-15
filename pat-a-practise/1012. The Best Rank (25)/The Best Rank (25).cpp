#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

struct S{
	int num;
	int c;
	int m;
	int e;
	int a;
	int c_rank;
	int m_rank;
	int e_rank;
	int a_rank;
	S(){
		num = 0;
		c = 0;
		m = 0;
		e = 0;
		a = 0;
		c_rank = 0;
		m_rank = 0;
		e_rank = 0;
		a_rank = 0;
	}
};

bool cmpc(S a, S b){
	return a.c > b.c;
}
bool cmpm(S a, S b){
	return a.m > b.m;
}
bool cmpe(S a, S b){
	return a.e > b.e;
}
bool cmpa(S a, S b){
	return a.a > b.a;
}

int main(int argc, char * argv[]){
	int n, m;
	cin >> n >> m;
	vector<S> stu;
	int num[m];
	map<int, S> rank;
	for(int i = 0 ; i < n; i ++){
		S temp;
		cin >> temp.num >> temp.c >> temp.m >> temp.e;
		temp.a = (temp.c + temp.m + temp.e) / 3;
		stu.push_back(temp);
		rank[temp.num] = temp;
	}
	for(int i = 0; i < m; i ++){
		cin >> num[i];
	}
	sort(stu.begin(), stu.end(), cmpc);
	stu[0].c_rank = 1;
	rank[stu[0].num].c_rank = 1;
	for(int i = 1; i < stu.size(); i ++){
		if(stu[i].c == stu[i - 1].c){
			stu[i].c_rank = stu[i - 1].c_rank;
			rank[stu[i].num].c_rank = stu[i - 1].c_rank;
		}
		else{
			stu[i].c_rank = i + 1;
			rank[stu[i].num].c_rank = i + 1;
		}
	}
	sort(stu.begin(), stu.end(), cmpe);
	stu[0].e_rank = 1;
	rank[stu[0].num].e_rank = 1;
	for(int i = 0; i < n ; i ++){
		if(stu[i].e == stu[i - 1].e){
			stu[i].e_rank = stu[i - 1].e_rank;
			rank[stu[i].num].e_rank = stu[i - 1].e_rank;
		}
		else{
			stu[i].e_rank = i + 1;
			rank[stu[i].num].e_rank = i + 1;
		}
	}
	sort(stu.begin(), stu.end(), cmpm);
	stu[0].m_rank = 1;
	rank[stu[0].num].m_rank = 1;
	for(int i = 0; i < n ; i ++){
		if(stu[i].e == stu[i - 1].e){
			stu[i].m_rank = stu[i - 1].m_rank;
			rank[stu[i].num].m_rank = stu[i - 1].m_rank;
		}
		else{
			stu[i].m_rank = i + 1;
			rank[stu[i].num].m_rank = i + 1;
		}
	}
	sort(stu.begin(), stu.end(), cmpa);
	stu[0].a_rank = 1;
	rank[stu[0].num].a_rank = 1;
	for(int i = 0; i < n ; i ++){
		if(stu[i].e == stu[i - 1].e){
			stu[i].a_rank = stu[i - 1].a_rank;
			rank[stu[i].num].a_rank = stu[i - 1].a_rank;
		}
		else{
			stu[i].a_rank = i + 1;
			rank[stu[i].num].a_rank = i + 1;
		}
	}
	for(int i = 0; i < m; i ++){
		if(rank.find(num[i]) != rank.end()){
			int best = rank[num[i]].a_rank;
			char res = 'A';
			if(best > rank[num[i]].c_rank){
				best = rank[num[i]].c_rank;
				res = 'C';
			}
			if(best > rank[num[i]].m_rank){
				best = rank[num[i]].m_rank;
				res = 'M';
			}
			if(best > rank[num[i]].e_rank){
				best = rank[num[i]].e_rank;
				res = 'E';
			}
			cout << best << ' ' << res;
		}
		else{
			cout << "N/A";
		}
		if(i != m-1){
			cout << endl;
		}
	}
	return 0;
}