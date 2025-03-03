int minCost(int* cost, int costSize, int i);
int memo[1001]; // memorize min cost to i

int minCostClimbingStairs(int* cost, int costSize) {

    for(int i = 0; i < 1001; i++) memo[i] = -1;

    int min0 = minCost(cost, costSize, 0);
    int min1 = minCost(cost, costSize, 1);

    return min0 < min1 ? min0 : min1;
}

int minCost(int* cost, int costSize, int i) {

    if (memo[i] != -1) return memo[i];
    if(i >= costSize) return 0;

    int one_step = minCost(cost, costSize, i + 1);
    int two_step = (i + 2 < costSize) ? minCost(cost, costSize, i + 2) : 0;

    memo[i] = cost[i] + (one_step < two_step ? one_step : two_step);
    return memo[i];
}