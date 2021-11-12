//
//  workplan.hpp
//  CSVtoICS
//
//  Created by swaaws on 12.01.16.
//  Copyright © 2016 swaaws. All rights reserved.
//

#ifndef workplan_hpp
#define workplan_hpp


#endif /* workplan_hpp */
class workplan{
private:
    
    
    
    int ecol;
    
    //ffg
    string day;
    string s2day;
    string jahr;
    string month;
    
    //table info
    int collumns;
    int rows;
    string lasttableupdate;
    
    //table of content
    string** data;
    
    //info of workplan 1.5
    
    
    string F1;
    string bF1;
    string eF1;
    
    string F2;
    string bF2;
    string eF2;
    string S1;
    string bS1;
    string eS1;
    string S2;
    string bS2;
    string eS2;
    string F;
    string bF;
    string eF;
    string S;
    string bS;
    string eS;
    string T;
    string bT;
    string eT;
    string N;
    string bN;
    string eN;
    string K;
    string bK;
    string eK;
    string U;
    string bU;
    string eU;
    
public:
    int bcol;
    string btime;
    string etime;
    int user = 1; //collum of users
    int timeline = 0;
    int monthline = 0;
    int dateline = 3;
    string userid; //130
    int userline;//145
    string username; //myname
    int plancol=1;
    
    void setuserinfo();
    void getdata(string** data,string csvdata);
    void setuserid();
    void getinfo();
    void timescope();
    void setdate(int);
    int getdiff();
    void timeconverter();
    string beventtime(int idx);
    string eeventtime(int idx);
    string beventdate();
    string eeventdate(int idx);
    string eventname(int idx);
};

void workplan::setuserinfo(){
    //2TODO: user input over CLI
    cout <<"USER Info"<< endl;
    cout <<"---------"<< endl;
    cout << "Dein Name(z.B Sebastian Heitzer):";
    getline(cin, username);
    
    
    cout << setw(sizeof("Dein Name(z.B Sebastian Heitzer):")-1);
    cout << "Zeitraum vom (MM.JJ/min):";
    getline(cin, btime);
    
    
    cout << setw(sizeof("Dein Name(z.B Sebastian Heitzer):")-1);
    cout << "bis (MM.JJ/max):";
    getline(cin, etime);
    
    
}//1

void workplan::getdata(string **ndata,string csvdata){
    data=ndata;
    
    ifstream file(csvdata);
    collumns=0;
    rows=0;
    string datazeile;
    string dataspalte;
    
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
    
}//2

void workplan::setuserid(){
    
    string Afirstname = username.substr(0,username.find(' '));
    string Alastname = username.substr(username.find(' ')+1,username.find('\n'));
    
    username = Alastname + ",-" + Afirstname;
    
    userid="";
    for (int i=0;i<rows;i++){
        if (data[i][user]==username){
            userid = data[i+1][user];
            userline=i;
            if (userid==""){
                userid="Leider wurde dir noch keine ID zugewiesen. Läuft aber trozdem! ;D\n";
            }
            
            return;
        }
    }
    cerr <<"Name didn\'t found :( "<<endl;
    exit(1);
}//3

void workplan::getinfo(){
    lasttableupdate= data[2][0];
    cout<<"Schichtplan generiert: " << lasttableupdate<<endl <<endl;
    //get work time
    /*
     for (int i=0;i<rows;i++){
     if(data[i][0]=="F1"){
     F1= data[i][1];
     } else if(data[i][0]=="F2"){
     F2= data[i][1];
     } else if(data[i][0]=="S1"){
     S1= data[i][1];
     } else if(data[i][0]=="S2"){
     S2= data[i][1];
     } else if(data[i][0]=="F"){
     F= data[i][1];
     } else if(data[i][0]=="S"){
     S= data[i][1];
     } else if(data[i][0]=="K"){
     K= data[i][1];
     } else if(data[i][0]=="U"){
     U= data[i][1];
     } else if(data[i][0]=="T"){
     T= data[i][1];
     } else if(data[i][0]=="N"){
     N= data[i][1];
     }
     }*/
    
    
}//4

void workplan::timescope(){
    string time;
    string bmonth = btime.substr(0,btime.find('.'));
    string bjahr = btime.substr(btime.find('.')+1,btime.find('\n'));
    
    string emonth = etime.substr(0,etime.find('.'));
    string ejahr = etime.substr(etime.find('.')+1,etime.find('\n'));
    
    if (bmonth=="01"||bmonth=="Jan"||bmonth=="Januar"){
        bmonth="Januar";
    }else if (bmonth=="02"||bmonth=="Feb"||bmonth=="Februar"){
        bmonth="Februar";
    }else if (bmonth=="03"||bmonth=="Mrz"||bmonth=="März"){
        bmonth="März";
    }else if (bmonth=="04"||bmonth=="Apr"||bmonth=="April"){
        bmonth="April";
    }else if (bmonth=="05"||bmonth=="Mai"){
        bmonth="Mai";
    }else if (bmonth=="06"||bmonth=="Jun"||bmonth=="Juni"){
        bmonth="Juni";
    }else if (bmonth=="07"||bmonth=="Jul"||bmonth=="Juli"){
        bmonth="Juli";
    }else if (bmonth=="08"||bmonth=="Aug"||bmonth=="August"){
        bmonth="August";
    }else if (bmonth=="09"||bmonth=="Sep"||bmonth=="September"){
        bmonth="September";
    }else if (bmonth=="10"||bmonth=="Okt"||bmonth=="Oktober"){
        bmonth="Oktober";
    }else if (bmonth=="11"||bmonth=="Nov"||bmonth=="November"){
        bmonth="November";
    }else if (bmonth=="12"||bmonth=="Dez"||bmonth=="Dezember"){
        bmonth="Dezember";
    }
    btime= bmonth + "-20"+ bjahr;
    
    
    if (emonth=="01"||emonth=="Jan"||emonth=="Januar"){
        emonth="Januar";
    }else if (emonth=="02"||emonth=="Feb"||emonth=="Februar"){
        emonth="Februar";
    }else if (emonth=="03"||emonth=="Mrz"||emonth=="März"){
        emonth="März";
    }else if (emonth=="04"||emonth=="Apr"||emonth=="April"){
        emonth="April";
    }else if (emonth=="05"||emonth=="Mai"){
        emonth="Mai";
    }else if (emonth=="06"||emonth=="Jun"||emonth=="Juni"){
        emonth="Juni";
    }else if (emonth=="07"||emonth=="Jul"||emonth=="Juli"){
        emonth="Juli";
    }else if (emonth=="08"||emonth=="Aug"||emonth=="August"){
        emonth="August";
    }else if (emonth=="09"||emonth=="Sep"||emonth=="September"){
        emonth="September";
    }else if (emonth=="10"||emonth=="Okt"||emonth=="Oktober"){
        emonth="Oktober";
    }else if (emonth=="11"||emonth=="Nov"||emonth=="November"){
        emonth="November";
    }else if (emonth=="12"||emonth=="Dez"||emonth=="Dezember"){
        emonth="Dezember";
    }else {
        
    }
    etime= emonth + "-20"+ ejahr;
    
    
    for (int i=0;i<collumns;i++){
        if (data[timeline][i]==btime)
            bcol=i-1;
        else if (btime=="max")
            bcol=collumns;
        if (data[timeline][i]==etime)
            ecol=i+31;
        else if (etime=="max")
            ecol=collumns;
    }
}//5

void workplan::setdate(int idx){
    string date;
    string month1;
    string jahr1;
    int lcol =bcol+idx;
    
    if(data[timeline][lcol]!=""){
        if(data[timeline][lcol]!="SOLL"){
            jahr1 = data[timeline][lcol];
            
            jahr = jahr1.substr(jahr1.find('2'),jahr1.length());
        }
    }
    
    if(data[timeline][lcol]!=""){
        if(data[timeline][lcol]!="SOLL"){
            month1 = data[timeline][lcol];
            month = month1.substr(0,month1.find('-'));
        }
    }
    string lday = data[dateline][lcol];
    
    int liday = stoi(lday);
    if(liday<32)
        day =lday;
}//6

int workplan::getdiff(){;
    int i= ecol-bcol;
    return i;
}


void workplan::timeconverter(){
    if (month=="Januar")
        month="01";
    if (month=="Februar")
        month="02";
    if (month=="März")
        month="03";
    if (month=="April")
        month="04";
    if (month=="Mai")
        month="05";
    if (month=="Juni")
        month="06";
    if (month=="Juli")
        month="07";
    if (month=="August")
        month="08";
    if (month=="September")
        month="09";
    if (month=="Oktober")
        month="10";
    if (month=="November")
        month="11";
    if (month=="Dezember")
        month="12";
    if (day=="1")
        day="01";
    if (day=="2")
        day="02";
    if (day=="3")
        day="03";
    if (day=="4")
        day="04";
    if (day=="5")
        day="05";
    if (day=="6")
        day="06";
    if (day=="7")
        day="07";
    if (day=="8")
        day="08";
    if (day=="9")
        day="09";
    
    
    bF1="030000";
    eF1="130000";
    
    
    bF2="053000";
    eF2="154500";
    
    bS1="130000";
    eS1="230000";
    
    bS2="154500";
    eS2="014500";
    
    bF="";
    eF="";
    
    bS="";
    eS="";
    
    bT="";
    eT="";
    
    bN="";
    eN="";
    
    bK="";
    eK="";
    
    bU="";
    eU="";
    
    
    /*
     
     bhF1 = F1.substr(0, F1.find(':'));
     string bmF1 = F1.substr(F1.find(':')+1, F1.find('-')-3);
     
     int tmp = stoi(bhF1);
     tmp++;
     bhF1= to_string(tmp);
     bF2 = bhF1+bmF1+"00";
     
     
     string tehF1 = F1.substr(6, 7);
     string ehF1 = tehF1.substr(0, tehF1.find(':'));
     string emF1 = F1.substr(9,13);
     tmp = stoi(ehF1);
     tmp++;
     ehF1= to_string(tmp);
     eF2 = ehF1+emF1+"00";
     
     
     
     string bhF2 = F2.substr(0, F2.find(':'));
     string bmF2 = F2.substr(F2.find(':')+1, F2.find('-')-3);
     tmp = stoi(bhF2);
     tmp++;
     bhF2= to_string(tmp);
     bF2 = bhF2+bmF2+"00";
     
     
     string tehF2 = F2.substr(6, 7);
     string ehF2 = tehF2.substr(0, tehF1.find(':'));
     string emF2 = F2.substr(9,13);
     tmp = stoi(ehF2);
     tmp++;
     ehF2= to_string(tmp);
     eF2 = ehF2+emF2+"00";
     
     //S1
     string bhS1 = S1.substr(0, S1.find(':'));
     string bmS1 = S1.substr(S1.find(':')+1, S1.find('-')-3);
     tmp = stoi(bhS1);
     tmp++;
     bhS1= to_string(tmp);
     bS1 = bhS1+bmS1+"00";
     string tehS1 = S1.substr(6, 7);
     string ehS1 = tehS1.substr(0, tehS1.find(':'));
     string emS1 = S1.substr(9,13);
     tmp = stoi(ehS1);
     tmp++;
     ehS1= to_string(tmp);
     eS1 = ehS1+emS1+"00";
     
     //S2
     string bhS2 = S2.substr(0, S2.find(':'));
     string bmS2 = S2.substr(S2.find(':')+1, S2.find('-')-3);
     tmp = stoi(bhS2);
     tmp++;
     bhS2= to_string(tmp);
     bS2 = bhS2+bmS2+"00";
     string tehS2 = S2.substr(6, 7);
     string ehS2 = tehS2.substr(0, tehS1.find(':'));
     string emS2 = S2.substr(9,13);
     tmp = stoi(ehS2);
     tmp++;
     ehS2= to_string(tmp);
     eS2 = ehF2+emS2+"00";
     
     string bhS = S.substr(0, S.find(':'));
     string bmS = S.substr(S.find(':')+1, S.find('-')-3);
     tmp = stoi(bhS);
     tmp++;
     bhS= to_string(tmp);
     bS = bhS+bmS+"00";
     string tehS = S.substr(6, 7);
     string ehS = tehS.substr(0, tehS.find(':'));
     string emS = S.substr(9,13);
     tmp = stoi(ehS);
     tmp++;
     ehS= to_string(tmp);
     eS = ehS+emS+"00";
     
     string bhF = F.substr(0, F.find(':'));
     string bmF = F.substr(F.find(':')+1, F.find('-')-3);
     tmp = stoi(bhF);
     tmp++;
     bhF= to_string(tmp);
     bF = bhF+bmF+"00";
     string tehF = F.substr(6, 7);
     string ehF = tehF.substr(0, tehF.find(':'));
     string emF = F.substr(9,13);
     tmp = stoi(ehF);
     tmp++;
     ehF= to_string(tmp);
     eF = ehF2+emF2+"00";
     
     string bhT = T.substr(0, T.find(':'));
     string bmT = T.substr(T.find(':')+1, T.find('-')-3);
     tmp = stoi(bhT);
     tmp++;
     bhT= to_string(tmp);
     bT = bhT+bmT+"00";
     string tehT = T.substr(6, 7);
     string ehT = tehT.substr(0, tehT.find(':'));
     string emT = T.substr(9,13);
     tmp = stoi(ehT);
     tmp++;
     ehT= to_string(tmp);
     eT = ehT+emT+"00";
     
     string bhN = N.substr(0, N.find(':'));
     string bmN = N.substr(N.find(':')+1, N.find('-')-3);
     tmp = stoi(bhN);
     tmp++;
     bhN= to_string(tmp);
     bN = bhN+bmN+"00";
     string tehN = N.substr(6, 7);
     string ehN = tehN.substr(0, tehN.find(':'));
     string emN = N.substr(9,13);
     tmp = stoi(ehN);
     tmp++;
     ehN= to_string(tmp);
     eN = ehN+emN+"00";
     */
    
    bK="000000";
    bU="000000";
    eK="000000";
    eU="000000";
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}

string workplan::beventtime(int idx){
    string time = "";
    int lcol =bcol+plancol+idx;
    if (data[userline][lcol]=="F1")
        time = bF1;
    else if (data[userline][lcol]=="F2")
        time = bF2;
    else if (data[userline][lcol]=="S1")
        time = bS1;
    else if (data[userline][lcol]=="S2")
        time = bS2;
    else if (data[userline][lcol]=="F")
        time = bF;
    else if (data[userline][lcol]=="S")
        time = bS;
    else if (data[userline][lcol]=="N")
        time = bN;
    else if (data[userline][lcol]=="T")
        time = bT;
    else if (data[userline][lcol]=="U")
        time = bU;
    else if (data[userline][lcol]=="K")
        time = bK;
    
    
    return time;
}

string workplan::eeventtime(int idx){
    string time = "";
    int lcol =bcol+plancol+idx;
    if (data[userline][lcol]=="F1")
        time = eF1;
    else if (data[userline][lcol]=="F2")
        time = eF2;
    else if (data[userline][lcol]=="S1")
        time = eS1;
    else if (data[userline][lcol]=="S2")
        time = eS2;
    else if (data[userline][lcol]=="F")
        time = eF;
    else if (data[userline][lcol]=="S")
        time = eS;
    else if (data[userline][lcol]=="N")
        time = eN;
    else if (data[userline][lcol]=="T")
        time = eT;
    else if (data[userline][lcol]=="U")
        time = eU;
    else if (data[userline][lcol]=="K")
        time = eK;
    
    return time;
}


string workplan::beventdate(){
    return jahr+month+day;
}


string workplan::eeventdate(int idx){
    string lmonth;
    string lday;
    int lcol= bcol+plancol+idx;
    string event = data[userline][lcol];
    if (event=="S2"){
        int iday =0;
        iday = stoi(day);
        iday++;
        string jday= to_string(iday);
        return jahr+month+jday;
        
    }
    return jahr+month+day;
}

string workplan::eventname(int idx){
    int lcol= bcol+plancol+idx;
    return data[userline][lcol];
}


