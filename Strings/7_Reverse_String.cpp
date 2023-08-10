/*
// C++ program to reverse a string
// using while loop
#include <bits/stdc++.h>
using namespace std;

// Function to reverse a string
void reverseStr(string& str)
{
	int len = str.length();
	int n = len-1;
	int i = 0;
	while(i<=n){
		//Using the swap method to switch values at each index
		swap(str[i],str[n]);
		n = n-1;
		i = i+1;
}

}

// Driver program
int main()
{
	string str = "geeksforgeeks";
	reverseStr(str);
	cout << str;
	return 0;
}*/

/*
// C++ program to illustrate the
// reversing of a string using
// reverse() function
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str = "geeksforgeeks";
 
    // Reverse str[begin..end]
    reverse(str.begin(), str.end());
 
    cout << str;
    return 0;
}
*/



// C++ program to reverse a string
// using first to last approach
// 'for' loop
#include <bits/stdc++.h>
using namespace std;
 
// Function to reverse a string
void reverseStr(string& str)
{
    int n = str.length();
 
    // Swap character starting from two
    // corners
    for (int i = 0; i < n / 2; i++)
        swap(str[i], str[n - i - 1]);
}
 
// Driver program
int main()
{
    string str = "geeksforgeeks";
    reverseStr(str);
    cout << str;
    return 0;
}