//
//  main.cpp
//  CSVtoICS
//
//  Created by swaaws on 06.01.16.
//  Copyright © 2016 swaaws. All rights reserved.
//
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <array>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <chrono>
#include <numeric>
#include "calendar.hpp"
#include "csv.hpp"
#include "workplan.hpp"


int main(int argc, const char * argv[]) {
     if (argc<=5){
        cout << "Usage: Version 1.5 [.csv] [firstname] [lastname] [begin] [end]"<< endl;
         cout << "Example: max muster 01.15 01.15"<< endl;
         cout << "[begin] 01|Jan|Januar.15" << endl;
         cout << "[end]   01|Jan|Januar.15" << endl;
        exit(1);
    }
    
    //import csv data
csv newcsv;
    newcsv.init(argv[1]);
    newcsv.getinfo();
    
    
    
    //my workplan
workplan myplan;
    myplan.getdata(newcsv.ary, argv[1]);
    myplan.getinfo();
   
    
        string name1= argv[2];
        string name2= " ";
        string name3= argv[3];
        string name=name1+name2+name3;
    myplan.username = name;
    
    myplan.btime=argv[4];
    myplan.etime=argv[5];
    myplan.setuserid();
    myplan.timescope();
    
    
    // std::time_t result = std::time(nullptr);
    // std::cout << std::asctime(std::localtime(&result))<< endl;
    
    //new calendar
calendar cal;
    cal.init("Arbeit.ics");
        for (int i=1; i<myplan.getdiff(); i++) {
        myplan.setdate(i);
        myplan.timeconverter();
        int lcol= myplan.bcol+i;
        if (newcsv.ary[myplan.userline][lcol]==""){}
        else{
            i--;
            cal.addevent(myplan.beventdate(), myplan.eeventdate(i), myplan.beventtime(i), myplan.eeventtime(i), myplan.eventname(i));
            i++;
        }
    }
    cal.end();
}

