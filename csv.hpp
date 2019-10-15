//
//  csv.hpp
//  CSVtoICS
//
//  Created by Sebastian Heitzer on 07.01.16.
//  Copyright © 2016 Sebastian Heitzer. All rights reserved.
//

#ifndef csv_hpp
#define csv_hpp


#endif /* csv_hpp */


using namespace std;

class csv{
private:
    string filename;
    string datazeile;
    string dataspalte;
    int collumns=0;
    int rows=0;
    
public:
    void init(string);
    ~csv();
    void getinfo();
    string** ary;//contain all csv collumns,rows
};

void csv::init(string csvdata){
    filename = csvdata;
    ifstream file(csvdata);
    
    //get table size
    getline(file, datazeile, '\n');
    for (int i=0; i<datazeile.length(); i++) {
        if (datazeile[i]==';')
            collumns++;
    }
    
    getline(file, dataspalte, '\0');
    for (int i=0; i<dataspalte.length(); i++) {
        if (dataspalte[i]=='\n')
            rows++;
    }
    file.close();
    
    //create Table
    ary = new string*[rows];
    for(int i = 0; i < rows; ++i)
        ary[i] = new string[collumns];
    
    
    // fill table
    ifstream data(csvdata);
    for(int row = 0; row < rows; ++row){
        if(data.good()){
            std::string line;
            std::getline(data, line);
            replace(line.begin(), line.end(), ' ', '-');
            std::stringstream iss(line);
            for (int col = 0; col < collumns; ++col){
                if(iss.good()){
                    std::string val;
                    std::getline(iss, val, ';');
                    replace(line.begin(), line.end(), ' ', '-');
                    
                    std::stringstream convertor(val);
                    convertor >> ary[row][col];
                }
            }
        }
    }
    file.close();
}
csv::~csv(){
    printf("Cleaning up memory...\n");
    free(ary);
    ary=0;
    printf("Ready.\n");
    
}

void csv::getinfo(){
    cout << "CSV Stats"<< endl;
    cout << "---------" << endl;
    cout << setw(sizeof("Spalten: "));
    cout << "Name: "<< filename << endl;
    cout << setw(sizeof("Spalten: "));
    cout << "Zeilen: " << rows<< endl;
    cout << setw(sizeof("Spalten: "));
    cout << "Spalten: " << collumns<< endl;
    cout << endl;
    
}//CSV Stats



