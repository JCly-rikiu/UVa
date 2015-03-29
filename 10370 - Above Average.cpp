#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    
    int c;
    scanf("%d", &c);

    while(c--) {
        int n;
        scanf("%d", &n);

        vector<int> score;
        double sum = 0;
        for(int i = 0; i < n; i++) {
            int num;
            scanf("%d", &num);

            score.push_back(num);
            sum += num;
        }

        sort(score.begin(), score.end());
        sum /= n;
        int cnt = n - (upper_bound(score.begin(), score.end(), sum) - score.begin());

        printf("%.3lf%%\n", double(cnt) / n * 100);
    }

    return 0;
}