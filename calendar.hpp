//
//  calendar.hpp
//  CSVtoICS
//
//  Created by Sebastian Heitzer on 06.01.16.
//  Copyright © 2016 Sebastian Heitzer. All rights reserved.
//

#ifndef calendar_hpp
#define calendar_hpp


#endif /* calendar_hpp */

using namespace std;

class calendar
{
private:
    int bdate;
    int edate;

    int btime;
    int etime;

    string eventname;


    string calendarname;


public:
    void init(string calendername);
    void addevent(string bdate, string edate, string btime, string etime, string eventname);
    //     idx       01012015   01022015   000000     235959,    F1
    void end();
};

void calendar::init(string ncalendarname)
{
    calendarname= ncalendarname;
    ofstream textDatei(calendarname);
    if(textDatei)
    {
        textDatei << "BEGIN:VCALENDAR\n" << "VERSION:2.0\n" << "X-WR-CALNAME:"<<calendarname <<"\n" << "X-WR-TIMEZONE:Europe/Berlin\n" << "METHOD:PUBLISH\n";
    }

}

void calendar::end()
{
    ofstream textDatei(calendarname, ios::app);
    if(textDatei)
    {
        textDatei <<"END:VCALENDAR";
        textDatei.close();
    }
}
//1TODO: LOCATION: DESCRIPTION:URL;VALUE=URI:http://
void calendar::addevent(string bdate,string edate, string btime, string etime, string eventname)
{
    ofstream textDatei(calendarname, ios::app);
    textDatei << "BEGIN:VEVENT\n"
              << "UID:" << bdate << "\n"
              << "SUMMARY:"<< eventname << "\n"
              << "CLASS:PUBLIC\n"
              << "DTSTART:" << bdate << "T" << btime << "Z\n"
              << "DTEND:" << edate << "T" << etime << "Z\n"
              << "DTSTAMP:" << bdate << "T" << btime << "Z\n"
              << "END:VEVENT\n";
}


