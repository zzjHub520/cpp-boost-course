// CMakeProject1.cpp: 定义应用程序的入口点。
//

#include "CMakeProject1.h"
#include <boost/lexical_cast.hpp>
#include <boost/timer/timer.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace std;
using namespace boost;
using namespace boost::gregorian;
#pragma comment(lib, "libboost_date_time-vc143-mt-gd-x64-1_78.lib")
int main()
{
	cout << "Hello CMake." << endl;
    string s="12345";
    //timer::cpu_timer at;
    int a=lexical_cast<int>(s);
    cout<<a<<endl;
    date d1(2001, 1, 1);
	return 0;
}
