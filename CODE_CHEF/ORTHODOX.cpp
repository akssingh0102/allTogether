#include<iostream>
#include<bits/stdc++.h>
#include<unordered_set>
#include<unordered_map>
using namespace std;
int
main ()
{
  int t;
  cin >> t;
  while (t--)
    {
      int n;
      cin >> n;
      bool flag = true;

      int a[n];
      for (int i = 0; i < n; i++)
	{
	  cin >> a[i];
	}
      if (n > 60)
	{
	  cout << "NO" << endl;
	  flag = false;
	}

      if (flag == true)
	{
	  unordered_set < int >se;
	  for (int i = 0; i < n; i++)
	    {
	      long long curr = 0;
	      for (int j = i; j < n; j++)
		{
		  curr |= a[j];
		  if (se.find (curr) != se.end ())
		    {
		      cout << "NO" << endl;
		      flag = false;
		      break;
		    }
		  se.insert (curr);

		}
	      if (flag == false)
		{
		  break;
		}

	    }
	  if (flag == true)
	    cout << "YES" << endl;


	}
    }

  return 0;
}
