#include <stdio.h>
struct Coin {
    int m;      
    int v;    
    double rate; 
};

int main() {
int N, T;
scanf("%d %d", &N, &T);
struct Coin coins[105];
for (int i = 0; i < N; i++) {
scanf("%d %d", &coins[i].m, &coins[i].v);
coins[i].rate = (double)coins[i].v / coins[i].m;
    }
for (int i = 0; i < N - 1; i++) {
for (int j = 0; j < N - 1 - i; j++) {
if (coins[j].rate < coins[j + 1].rate) {
struct Coin temp = coins[j];
coins[j] = coins[j + 1];
coins[j + 1] = temp;
            }
        }
    }
double totalValue = 0.0; 
int remaining = T;     
for (int i = 0; i < N && remaining > 0; i++) {
if (coins[i].m <= remaining) {
totalValue += coins[i].v;
remaining -= coins[i].m;
        } 
else {
totalValue+=coins[i].rate * remaining;
remaining = 0; 
        }
    }
printf("%.2f\n",totalValue);

    return 0;
}
