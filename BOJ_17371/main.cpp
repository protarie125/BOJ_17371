#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

class Point {
public:
	ll x{};
	ll y{};
};

double dist(const Point& p, const Point& q) {
	const auto dx = p.x - q.x;
	const auto dy = p.y - q.y;

	return sqrt(pow(dx, 2) + pow(dy, 2));
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;

	vector<Point> pts(n);
	for (auto&& p : pts) {
		cin >> p.x >> p.y;
	}

	if (1 == n) {
		const auto& ans = pts[0];
		cout << fixed << setprecision(8) << ans.x << ' ' << ans.y;
		return 0;
	}

	auto minDist = numeric_limits<double>::infinity();
	Point ans{};
	for (auto i = 0; i < n; ++i) {
		const auto& p = pts[i];

		auto maxDist = double{ 0 };
		for (auto j = 0; j < n; ++j) {
			if (i == j) {
				continue;
			}

			const auto& q = pts[j];

			const auto d = dist(p, q);

			maxDist = max(maxDist, d);
		}

		if (maxDist < minDist) {
			minDist = maxDist;
			ans = p;
		}
	}

	cout << fixed << setprecision(8) << ans.x << ' ' << ans.y;

	return 0;
}