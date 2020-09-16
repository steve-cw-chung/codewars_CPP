#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'getNumberOfOptions' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY priceOfJeans
 *  2. INTEGER_ARRAY priceOfShoes
 *  3. INTEGER_ARRAY priceOfSkirts
 *  4. INTEGER_ARRAY priceOfTops
 *  5. INTEGER budgeted
 */

long getNumberOfOptions(vector<int> priceOfJeans, vector<int> priceOfShoes, vector<int> priceOfSkirts, vector<int> priceOfTops, int budgeted) {
    //cout << "budgeted: " <<budgeted << endl;
    //First approach is brute force approach 
    //O(n*m*s*t)
    //for loop 4 times
    //Faster way?
    // 
    //get size of each vector and if equals to 1 then skip for loop. Just need to subtract budgeted - price
    //for loop the rest. first sort subtract the first item check if we can buy all 4 items with budgeted if not then return
    /*
        Even more Faster way?
        1. Add Lowest from Tops, Skirts, and Shoes.
        2. Find highest from Jeans which makes budgeted >= total.
        3. Loop Through Jeans from value found from step 2 to 0
        4. Loop Through the Tops Skirts and Shoes 0 to size()-1 and if ( budgeted >= total ) totalComination++ else break;
        5. return totalCombination 
    */
   

    long totalCombination = 0;
    long total = 0;
    //sort
    sort(priceOfJeans.begin(),priceOfJeans.end());
    sort(priceOfShoes.begin(),priceOfShoes.end());
    sort(priceOfSkirts.begin(),priceOfSkirts.end());
    sort(priceOfTops.begin(),priceOfTops.end());
   /*  long maximum = priceOfJeans[priceOfJeans.size()-1] + priceOfShoes[priceOfShoes.size()-1] + priceOfSkirts[priceOfSkirts.size()-1]+priceOfTops[priceOfTops.size()-1];
    if(budgeted>=maximum){
        return (long)((long)priceOfJeans.size() * (long)priceOfShoes.size() * (long)priceOfSkirts.size() * (long)priceOfTops.size());
    } */
    //Brute Force 
    for(int i = 0 ; i < priceOfJeans.size(); i ++){
        
        total += priceOfJeans[i];
        //cout << "total after Jean: " <<total<<endl;
        if(total > budgeted){
            total -= priceOfJeans[i];
            break;
        }
        for(int j = 0; j < priceOfShoes.size();j++){
            total += priceOfShoes[j];
            //cout << "total after Jean + Shoes: " <<total<<endl;
            if(total > budgeted){
                total -= priceOfShoes[j];
                break;
            }
            for(int k = 0; k < priceOfSkirts.size();k++){
                total += priceOfSkirts[k];
                //cout << "total after Jean + Shoes + Skirts: " <<total<<endl;
                if(total > budgeted){
                    total -= priceOfSkirts[k];
                    break;
                }
                for(int l = 0; l < priceOfTops.size();l++){
                    //total = priceOfJeans[i] + priceOfShoes[j]+priceOfSkirts[k]+priceOfTops[l];
                    total += priceOfTops[l]; 
                    //cout << "total after Jean + Shoes + Skirts + Tops: " <<total<<endl;
                    if(total <= budgeted){
                        //add to the combination
                        totalCombination++;
                        total -=priceOfTops[l];
                    } else {
                        // need to check if it breaks out of price of Tops.
                        total -=priceOfTops[l];
                        break;
                    }
                }
                total -= priceOfSkirts[k];
            }
            total -= priceOfShoes[j];
        }
        total -= priceOfJeans[i];
    }




/*     //get minimum total to purchase each
    int minimumTotal = priceOfJeans[0]+priceOfShoes[0]+priceOfSkirts[0]+priceOfTops[0];
    //extra budget 
    int extraBudget = budgeted - minimumTotal;
    if(extraBudget>=0){
        totalCombination++;
    }
    
    for (int i = 1 ; i < priceOfJeans.size(); i++){
        if(extraBudget+priceOfJeans[i-1]-priceOfJeans[i]>=0){
            totalCombination++;
        } else {
            //need to check if breaks out of for loop for priceOfJeans
            break;
        }
    }
    for (int i = 1 ; i < priceOfShoes.size(); i++){
        if(extraBudget+priceOfShoes[i-1]-priceOfShoes[i]>=0){
            totalCombination++;
        } else {
            //need to check if breaks out of for loop for priceOfJeans
            break;
        }
    } */

    return totalCombination;

}

int main()