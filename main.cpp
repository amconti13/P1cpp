//
//  main.cpp
//  P1AriannaConti
//
//  Created by Arianna on 8/31/16.
//  Copyright © 2016 Arianna. All rights reserved.
//

#include "tools.hpp"

int main(void) {
    banner();
    
    //variables:----------------------------------------------------------------
    ifstream inFile;
    string fileName;
    int count = 0;
    vector<int> nums;
    double x, median, mean = 0, mode = 0, sum = 0, array[100] = {0};
    
    //input and initialize vector:----------------------------------------------
    cout << "Please input random integer textfile to calculate mean, median\n"
    << "and mode. (randInts.txt): ";
    cin >> fileName;
    inFile.open(fileName);
    if (!inFile) fatal ("Could not open randInts.txt");
    for(;;){
        inFile >> x;
        if ( inFile.eof() ) break;
        nums.push_back( x );
    }
    
    //sort and cacluate:--------------------------------------------------------
    sort( nums.begin(), nums.end() );
    for( int k = 0; k < nums.size(); k++, sum += nums[k], array[nums[k]]++ )
    mean = sum / nums.size();           //^amt of nums^ | ^amt of each num^
    median = nums[ nums.size() / 2 ];
    for(int k = 0; k < 100; k++){ //will not output +1 modes if there are any
        if (array[k] > count){
            count = array[k];
            mode = k;
        }
    }
    
    //output:-------------------------------------------------------------------
    cout << "\nMean:\t" << mean << endl;
    cout << "Median:\t" << median << endl;
    cout << "Mode:\t" << mode << endl;
    bye();
}
