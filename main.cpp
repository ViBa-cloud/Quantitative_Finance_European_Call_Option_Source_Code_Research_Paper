#include "random.cpp"
#include<iostream>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
	cout<<"\n ***START First Equation: Monte Carlo European Call *** \n";
//Step1: INPUT PARAMETERS
	double t{1}; //maturity
	double k{100};//strike
	double s0{100};//spot
	double sigma{0.10};//volatility
	double r{0.05};//interest rate
	int n{500};//number of steps
	int m{10000};//number of simulations
	double s[n+1];
	double sumpayoff{0};
	double premium{0};
	double dt= t/n;

//Step2: Main Simulation Loop
	for(auto j=0; j<m; j++){
		s[0]=s0;//Initialize each path for simulation
	
	//Step3: Time Integration Loop
		for(auto i=0; i<n; i++){
			double epsilon = SampleBoxMuller();//Get Gaussian draw
			s[i+1]= s[i]*(1+r*dt+sigma*sqrt(dt)*epsilon);
		}

	//Step4: Compute Payoff
	sumpayoff += max(s[n]-k, 0.0);//compute and add payoff
	}

	//Step5: Compute discounted expected payoff
	premium = exp(-r*t)*(sumpayoff/m);

	//Step6: Output Results
	cout<<"premium= "<< premium<< "\n";
	cout<<"\n *** End of Equation1: Monte Carlo Single Asset *** \n";

	return 0;
}


