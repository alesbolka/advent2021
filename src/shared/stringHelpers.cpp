#include <string>
#include "./stringHelpers.h"

using namespace stringHelpers;
using std::string;

string stringHelpers::strDiff(string s1, string s2)
{
  string res = "";
  for (int ii = 0; ii < s1.size(); ++ii)
  {
    if (s2.find(s1[ii]) == string::npos && res.find(s1[ii]) == string::npos)
    {
      res += s1[ii];
    }
  }

  for (int ii = 0; ii < s2.size(); ++ii)
  {
    if (s1.find(s2[ii]) == string::npos && res.find(s2[ii]) == string::npos)
    {
      res += s2[ii];
    }
  }

  std::sort(res.begin(), res.end());
  return res;
}

string stringHelpers::strCommon(string s1, string s2)
{
  string res = "";

  for (int ii = 0; ii < s1.size(); ++ii)
  {
    if (s2.find(s1[ii]) != string::npos && res.find(s1[ii]) == string::npos)
    {
      res += s1[ii];
    }
  }

  std::sort(res.begin(), res.end());
  return res;
}