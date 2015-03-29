#include <cstdio>

struct Hotel{
    int price;
    int bed[15];
};

int main() {
    int n, b, h, w;
    while(scanf("%d%d%d%d", &n, &b, &h, &w) != EOF) {

        Hotel hotel[20]; 

        for(int i = 0; i < h; i++) {
            scanf("%d", &hotel[i].price);

            for(int j = 0; j < w; j++) 
                scanf("%d", &hotel[i].bed[j]);
        }

        int cost = b + 1;
        for(int i = 0; i < h; i++) {
            for(int j = 0; j < w; j++) {
                if(hotel[i].bed[j] < n)
                    continue;

                int buf = n * hotel[i].price;
                if(cost > buf)
                    cost = buf;
            }
        }

        if(cost > b)
            printf("stay home\n");
        else
            printf("%d\n", cost);
    }

    return 0;
}