#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define mp make_pair
#define f first
#define s second
using namespace std;
int n;
vector<pair<int, int>> points1;

bool comp1(pair<int, int> a, pair<int, int> b){
	return (b.f > a.f);
}
bool comp2(pair<int, int> a, pair<int, int> b){
	return (b.s > a.s);
}
double distance(pair<int, int> p1, pair<int, int> p2){
	double pom1 = (p1.f - p2.f);
	double pom2 = (p1.s - p2.s);
	return sqrt(pom1 * pom1 + pom2 * pom2);
}
pair<pair<int, int>, pair<pair<int, int>, double>> pom(double d_min, int len, pair<pair<int, int>, pair<pair<int, int>, double>> res_dot, int l, int r){
	vector<pair<int, int>> Y;
	for (int i = l; i <= r; i++){
		if ((double)abs(points1[l + len - 1].f - points1[i].f) < d_min){
			Y.push_back(points1[i]);
		}
	}
	sort(Y.begin(), Y.end(), comp2);
	int j;
	pair<pair<int, int>, pair<pair<int, int>, double>> res = res_dot;
	for (int i = 0; i < (int)Y.size(); i++){
		j = i + 1;
		while (j - i <= 7 && j < (int)Y.size()){
			if (distance(Y[i], Y[j]) < d_min){
				res = mp(Y[i], mp(Y[j], distance(Y[i], Y[j])));
			}
			j += 1;
		}
	}
	return res;
}

pair<pair<int, int>, pair<pair<int, int>, double>> min_points(int l, int r){
	if (r - l + 1 == 2){
		return mp(points1[l], mp(points1[r], distance(points1[l], points1[r])));
	}
	else if (r - l + 1 == 3){
		double dist1 = distance(points1[l], points1[r]);
		double dist2 = distance(points1[l], points1[l + 1]);
		double dist3 = distance(points1[l + 1], points1[r]);
		if (dist1 < dist2){
			if (dist1 < dist3){
				return mp(points1[l], mp(points1[r], dist1));
			}
			else{
				return mp(points1[l + 1], mp(points1[r], dist3));
			}
		}
		else{
			if (dist2 < dist3){
				return mp(points1[l], mp(points1[l + 1], dist2));
			}
			else{
				return mp(points1[l + 1], mp(points1[r], dist3));
			}
		}
	}
	int len = (r - l + 1) / 2;
	pair<pair<int, int>, pair<pair<int, int>, double>> res1 = min_points(l, l + len - 1);
	pair<pair<int, int>, pair<pair<int, int>, double>> res2 = min_points(l + len, r);
	double d1 = res1.s.s;
	double d2 = res2.s.s;
	pair<pair<int, int>, pair<pair<int, int>, double>> resu;
	if (d1 < d2){
		resu = pom(d1, len, res1, l, r);
	}
	else{
		resu = pom(d2, len, res2, l, r);
	}
	return resu;
}
int main(){
	int a;
	int b;
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d", &a, &b);
		points1.push_back(mp(a, b));
	}
	sort(points1.begin(), points1.end(), comp1);
	pair<pair<int, int>, pair<pair<int, int>, double>> result = min_points(0, (int)points1.size() - 1);
	printf("%d %d\n", result.first.first, result.first.s);
	printf("%d %d\n", result.s.f.f, result.s.f.s);
	return 0;
}