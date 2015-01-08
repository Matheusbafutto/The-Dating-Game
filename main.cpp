
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>

using namespace std;

int main()
{
   string sec_str,min_str,h_str,day_str,mon_str,year_str, teste;
   int sec_int,min_int,h_int,day_int,mon_int,year_int, period;
   tm result, result2;
   time_t sec_result;
   
   //teste = "1991-07-03T15:29:00.000Z";
   //period = 64267306;
   cin >> teste;
   cin >> period;
   
   //converting string to integer
   sec_str = teste.substr(17,2);
   sec_int = atoi(sec_str.c_str());
   min_str = teste.substr(14,2);
   min_int = atoi(min_str.c_str());
   h_str = teste.substr(11,2);
   h_int = atoi(h_str.c_str());
   day_str = teste.substr(8,2);
   day_int = atoi(day_str.c_str());
   mon_str = teste.substr(5,2);
   mon_int = atoi(mon_str.c_str());
   year_str = teste.substr(0,4);
   year_int = atoi(year_str.c_str());
   //cout << mon_int << endl;

    result.tm_hour = h_int;
    result.tm_min = min_int;
    result.tm_sec = sec_int;
    result.tm_mday = day_int;
    result.tm_mon = mon_int - 1;
    result.tm_year = year_int - 1900;
    
    // 1991-07-03T15:29:00.000Z
    
    sec_result = period + mktime(&result);
    
    tm *final_result = gmtime(&sec_result);
    
    char dt[80];
    
    
    
    strftime(dt, 80, "%FT%T.000Z", final_result);
    
    cout << dt << endl;
    
    

return 0;   
}
