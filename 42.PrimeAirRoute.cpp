// each shipping route is identified by an unique integer identifier, requires a fixed non-zero amount of travel distance between airports, and is defeind to be either a forward shipping route or a return shipping route.
// 1 forward route and 1 return route
// maximum opperating travel distance
// GOAL : optimize the total operating travel distance of a given aircraft 
// "optimal " means if there does not exist another pair that has a higher operating travel distance than this pair 
// Total less than equal to the maximum operating travel distance 

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> routePairs(int maxTravelDist, vector<vector<int>> forwardRouteList, vector<vector<int>> returnRouteList){
    vector<vector<int>> optimalRoutes;
    int distanceDiff = INT_MAX;// Distance Difference to keep track of most optimal route

    for(size_t i =0; i < forwardRouteList.size(); ++i ){
        for(size_t j = 0; j < returnRouteList.size(); ++j){
            // better optimal route found
            if( maxTravelDist - forwardRouteList[i][1] - returnRouteList[j][1] < distanceDiff && maxTravelDist - forwardRouteList[i][1] - returnRouteList[j][1] >=0){
                //create new optimalRoute with current routes
                optimalRoutes = {{forwardRouteList[i][0],returnRouteList[j][0]}};
                //update distancediff
                distanceDiff = maxTravelDist - forwardRouteList[i][1] - returnRouteList[j][1];
            }
            // same optimal route found
            else if ( maxTravelDist - forwardRouteList[i][1] - returnRouteList[j][1] == distanceDiff){
                //add current routes to current optimalRoute
                optimalRoutes.push_back({forwardRouteList[i][0],returnRouteList[j][0]});
                
            }
        }
    }

    return optimalRoutes;
}

int main(){
    int maxTravelDist = 10000;
    vector<vector<int>> forwardRouteList = {{1,3000}, {2,5000},{3,7000},{4,10000}};
    vector<vector<int>> returnRouteList = {{1,2000},{2,3000},{3,4000},{4,5000}};
    vector<vector<int>> optimalRoutes = routePairs(maxTravelDist, forwardRouteList, returnRouteList);
    for ( size_t i = 0 ; i < optimalRoutes.size() ; ++i){
        cout << "optimalRoutes[i][0]: " << optimalRoutes[i][0] << "    optimalRoutes[i][1] : " << optimalRoutes[i][1] <<endl;
    }
}



/*

I used double for loop to match each item of forward route list to return route list in order to calculate the all possible combinations of the optimal routes 




*/
