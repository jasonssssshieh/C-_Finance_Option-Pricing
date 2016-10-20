#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

double option_price_call_euro_single_period(const double& S,// Spot price
                                            const double& K,
                                            const double& r,
                                            const double& u,
                                            const double& d){
    double p_up = (exp(r) - d)/(u - d);
    double p_down = 1.0 - p_up;
    double c_up = max(0.0, u*S - K);
    double c_down = max(0.0, d*S - K);
    double euro_call = exp(-r)*(p_up*c_up + p_down * c_down);
    return euro_call;
}

//construct a bin-tree for euro call option
vector<vector<double>> construct_option_price_call_euro_multi_period(const double &S0,
                                           const double& u,
                                           const double& d,
                                           const int& steps){
    vector<vector<double>> bintree;
    for(int i = 1; i <= steps; ++i){
        vector<double> S(i);
        for(int j = 0; j < i; ++j){
            S[j] = S0*pow(u,j)*pow(i - j - 1, d);
        };
        bintree.push_back(S);
    }
    return bintree;
}
